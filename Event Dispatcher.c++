#include <iostream>
#include <map>
#include <functional>
using namespace std;

int main(){
    map<string,function<void()>> events;

    events["start"] = [](){ cout<<"Started\n"; };
    events["stop"]  = [](){ cout<<"Stopped\n"; };

    string cmd;
    cin>>cmd;
    if(events.count(cmd))
        events[cmd]();
}
