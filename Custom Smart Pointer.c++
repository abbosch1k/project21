#include <iostream>
using namespace std;

template<typename T>
class SmartPtr {
    T* ptr;
public:
    SmartPtr(T* p) : ptr(p) {}
    ~SmartPtr() { delete ptr; }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
};

int main(){
    SmartPtr<int> p(new int(10));
    cout<<*p<<endl;
}
