#include <bits/stdc++.h>
#define MAX 100

using namespace std;

vector <int> g[MAX];
int vis[MAX];
int flag = false;

void dfs(int v, int n){
    vis[v] = true;

    if(v > n-1)
      flag =  true;
    
    for(int i = 0; i < g[v].size(); i++){
        if(!vis[g[v][i]])
            dfs(g[v][i], n);
    }

}

int main(){
    int towers[] = {4, 2, 0, 0, 2, 0};
    int n = 6;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < towers[i]; j++){
            g[i].push_back(i + j + 1);
            //cout << "Vertex " << i << " has a edge with " << i + j + 1 << endl;
        }
    }

    dfs(0, n);

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}