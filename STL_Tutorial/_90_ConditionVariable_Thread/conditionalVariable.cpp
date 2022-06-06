#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <chrono>

using namespace std;

struct DataSource{
    mutex m;
    condition_variable cv;
    queue<int> workUnits;
};

void consumer(DataSource& ds){
    while(true){
        unique_lock lock(ds.m);
        cout<<"Thread: "<<this_thread::get_id()<<" waiting...\n";
        ds.cv.wait(lock,[&ds]{return ds.workUnits.size()>0;}); //add predicate to be sure the alarm of cv

        int workUnit=ds.workUnits.front();
        ds.workUnits.pop();

        cout<<"Thread: "<<this_thread::get_id()<<" processing unit: "<<workUnit<<"\n";

        lock.unlock();//allow something else to work
        this_thread::sleep_for(1s);
    }
}

void producer(DataSource& ds){
    int i=0;
    while(true){

        {
            unique_lock lock(ds.m);
            if(ds.workUnits.size()>40){
                cout<<"Halting production until worker catch up...\n";
            }
            else{
                cout<<"Producing "<<i<<"...\n";
                ds.workUnits.push(i++);
            }
        } //unlock
        ds.cv.notify_all();
        this_thread::sleep_for(200ms);

    }
}

int main(){

    DataSource ds;

    for(int i=0; i<5; i++){
        thread t(&consumer, std::ref(ds));
        t.detach();
    }

    thread t(&producer,std::ref(ds));
    t.join();

    return 0;
}
