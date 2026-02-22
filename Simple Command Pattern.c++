#include <iostream>
using namespace std;

class Command{
public:
    virtual void execute()=0;
};

class Light{
public:
    void on(){ cout<<"Light ON\n"; }
};

class LightOnCommand : public Command{
    Light& light;
public:
    LightOnCommand(Light& l):light(l){}
    void execute(){ light.on(); }
};

int main(){
    Light light;
    LightOnCommand cmd(light);
    cmd.execute();
}
