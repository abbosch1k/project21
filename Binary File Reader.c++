#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream out("data.bin", ios::binary);
    int x=123;
    out.write((char*)&x,sizeof(x));
    out.close();

    ifstream in("data.bin", ios::binary);
    int y;
    in.read((char*)&y,sizeof(y));
    cout<<y<<endl;
}
