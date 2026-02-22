#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    vector<vector<pair<int,int>>> graph(3);
    graph[0].push_back({1,4});
    graph[0].push_back({2,1});
    graph[2].push_back({1,2});

    vector<int> dist(3,1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[0]=0;
    pq.push({0,0});

    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        for(auto [v,w]:graph[u]){
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }

    cout<<"Distance to 1: "<<dist[1]<<endl;
}
