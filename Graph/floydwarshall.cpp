#include<bits/stdc++.h>

using namespace std;

#define MAX 100

int dist[MAX][MAX];

void floydwarshall(int n){
    // caminhos de i ate j, passando por k, tentam ser atualizados
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    int v, e;
    
    cin >> v >> e;

    for(int i = 0, u, k, w; i < e; i++){
        cin >> u >> k >> w;

        dist[u][k] = w;
        //dist[k][u] = w;
    }
}