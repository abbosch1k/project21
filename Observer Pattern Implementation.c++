#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    virtual void update(int value)=0;
};

class ConcreteObserver : public Observer {
public:
    void update(int value) override {
        cout<<"Updated value: "<<value<<endl;
    }
};

class Subject {
    vector<Observer*> observers;
    int state;
public:
    void attach(Observer* o){
        observers.push_back(o);
    }
    void setState(int s){
        state=s;
        for(auto o:observers)
            o->update(state);
    }
};

int main(){
    Subject s;
    ConcreteObserver o1,o2;
    s.attach(&o1);
    s.attach(&o2);
    s.setState(42);
}
