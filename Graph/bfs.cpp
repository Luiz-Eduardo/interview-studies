#include <bits/stdc++.h>
#define MAX 101010

using namespace std;

vector <int> g[MAX];
int vis[MAX];

void bfs(int u){
    queue <int> q;

    q.push(u);
    vis[u] = true;

    while(!q.empty()){
        int v = q.front();
        cout << v << " "; 
        q.pop();    

        for(int i = 0; i < g[v].size(); i++){
            if(!vis[g[v][i]]){
                vis[g[v][i]] = true;
                q.push(g[v][i]);
            }
        }
    }
}

int main(){
    int v, e;

    cin >> v >> e;

    for(int i = 0, u, k; i < e; i++){
        cin >> u >> k;

        g[u].push_back(k);
        //g[k].push_back(u);
    }

    bfs(2);
}