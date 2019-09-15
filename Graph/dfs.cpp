#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 3;

vector <int> g[MAX];
bool vis[MAX];

void dfs(int u){
    vis[u] = true;

    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        
        if(!vis[v])
            dfs(v);
    }
}

int main(){
    int n, m;

    cin >> n >> m;

    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    if(vis[5]) cout << "Yes, we can reach to 6 from 1";
    else cout << "We can't reach";

    return 0;
}