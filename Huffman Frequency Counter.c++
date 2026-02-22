#include <iostream>
#include <map>
using namespace std;

int main(){
    string text="hello world";
    map<char,int> freq;

    for(char c:text)
        freq[c]++;

    for(auto &p:freq)
        cout<<p.first<<" : "<<p.second<<endl;
}
