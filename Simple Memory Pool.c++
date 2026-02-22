#include <iostream>
using namespace std;

class MemoryPool {
    char pool[1024];
    int offset = 0;

public:
    void* allocate(int size) {
        void* ptr = pool + offset;
        offset += size;
        return ptr;
    }
};

int main(){
    MemoryPool mp;
    int* a = (int*)mp.allocate(sizeof(int));
    *a = 42;
    cout<<*a<<endl;
}
