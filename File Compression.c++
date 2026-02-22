#include <iostream>
using namespace std;

int main(){
    string s="aaabbbbcc";
    for(int i=0;i<s.size();){
        int count=1;
        while(i+1<s.size() && s[i]==s[i+1]){
            count++;
            i++;
        }
        cout<<s[i]<<count;
        i++;
    }
}
