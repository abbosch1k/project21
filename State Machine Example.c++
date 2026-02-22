#include <iostream>
using namespace std;

enum State {Idle, Running, Stopped};

int main(){
    State s = Idle;

    s = Running;
    if(s==Running)
        cout<<"Machine Running\n";

    s = Stopped;
    if(s==Stopped)
        cout<<"Machine Stopped\n";
}
