#include <iostream>
#include <thread>
#include <mutex>

#define TRANSACTIONS 100000

using namespace std;

void deposit(int& account, mutex& m) {
  for (int i = 0; i < TRANSACTIONS; i++) {
    lock_guard<mutex> lock(m); //scoped lock, at the end of scope, it releases the lock
    ++account;
  }
}

void widthdraw(int& account, mutex& m) {
  for (int i = 0; i < TRANSACTIONS; i++) {
    lock_guard<mutex> lock(m); //scoped lock, at the end of scope, it releases the lock
    --account;
  }
}

int main(){
    
    unsigned int threads = thread::hardware_concurrency(); // to learn threads number
    cout<<threads<<" Threads supported\n";

    int account=0;
    mutex m;

    thread t1(deposit,std::ref(account),std::ref(m)); // give real account, not local copy of account
    thread t2(widthdraw,std::ref(account),std::ref(m));

    //Main program is also another thread, we expect main thread should finish after our other threads
    //So, to be sure that t1 and t2 thread finish before main thread, use "join()".
    t1.join();
    t2.join();

    cout<<"After the threads, account value is "<<account<<"\n";

    return 0;
}