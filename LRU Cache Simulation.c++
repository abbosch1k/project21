#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRU {
    int capacity;
    list<int> dq;
    unordered_map<int, list<int>::iterator> map;

public:
    LRU(int cap) : capacity(cap) {}

    void access(int key) {
        if (map.find(key) != map.end()) {
            dq.erase(map[key]);
        }
        else if (dq.size() == capacity) {
            int last = dq.back();
            dq.pop_back();
            map.erase(last);
        }

        dq.push_front(key);
        map[key] = dq.begin();
    }

    void print() {
        for (int x : dq)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    LRU cache(3);
    cache.access(1);
    cache.access(2);
    cache.access(3);
    cache.access(2);
    cache.access(4);
    cache.print();
}
