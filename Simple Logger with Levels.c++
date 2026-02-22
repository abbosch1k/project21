#include <iostream>
using namespace std;

enum Level {INFO, WARNING, ERROR};

void log(string msg, Level l){
    if(l==INFO) cout<<"[INFO] ";
    if(l==WARNING) cout<<"[WARNING] ";
    if(l==ERROR) cout<<"[ERROR] ";
    cout<<msg<<endl;
}

int main(){
    log("System started", INFO);
    log("Low memory", WARNING);
    log("Crash detected", ERROR);
}
