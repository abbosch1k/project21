#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    vector<vector<int>> graph = {
        {1,2},
        {3},
        {3},
        {}
    };

    vector<bool> visited(4,false);
    queue<int> q;
    q.push(0);
    visited[0]=true;

    while(!q.empty()){
        int node=q.front(); q.pop();
        cout<<node<<" ";

        for(int neigh:graph[node]){
            if(!visited[neigh]){
                visited[neigh]=true;
                q.push(neigh);
            }
        }
    }
}
