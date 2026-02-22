#include <iostream>
using namespace std;

class Strategy {
public:
    virtual int execute(int a,int b)=0;
};

class Add : public Strategy {
public:
    int execute(int a,int b){ return a+b; }
};

class Multiply : public Strategy {
public:
    int execute(int a,int b){ return a*b; }
};

int main(){
    Strategy* s = new Add();
    cout<<s->execute(3,4)<<endl;
    delete s;
}
