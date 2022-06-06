#include <iostream>
#include <thread>

#define TRANSACTIONS 100000

using namespace std;

void deposit(int& account) {
  for (int i = 0; i < TRANSACTIONS; i++) {
    ++account;
  }
}

void widthdraw(int& account) {
  for (int i = 0; i < TRANSACTIONS; i++) {
    --account;
  }
}

int main(){
    
    unsigned int threads = thread::hardware_concurrency(); // to learn threads number
    cout<<threads<<" Threads supported\n";

    int account=0;
    thread t1(deposit,std::ref(account)); // give real account, not local copy of account
    thread t2(widthdraw,std::ref(account));

    //Main program is also another thread, we expect main thread should finish after our other threads
    //So, to be sure that t1 and t2 thread finish before main thread, use "join()".
    t1.join();
    t2.join();

    cout<<"After the threads, account value is "<<account<<"\n";

    return 0;
}