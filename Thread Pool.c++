#include <iostream>
#include <vector>
#include <thread>
using namespace std;

void task(int id){
    cout<<"Task "<<id<<" running\n";
}

int main(){
    vector<thread> pool;
    for(int i=0;i<5;i++)
        pool.emplace_back(task,i);

    for(auto &t:pool)
        t.join();
}
