#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

queue<int> buffer;
mutex mtx;
condition_variable cv;

void producer() {
    for(int i=1;i<=5;i++){
        unique_lock<mutex> lock(mtx);
        buffer.push(i);
        cout<<"Produced "<<i<<endl;
        cv.notify_one();
    }
}

void consumer() {
    for(int i=1;i<=5;i++){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{ return !buffer.empty(); });
        cout<<"Consumed "<<buffer.front()<<endl;
        buffer.pop();
    }
}

int main(){
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
}
