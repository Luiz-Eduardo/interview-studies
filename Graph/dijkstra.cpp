#include<bits/stdc++.h>
#define MAX 260
using namespace std;

vector < pair <int, int> > g[MAX];
vector <int> dist(MAX);

const long long INF = 0x3f3f3f3f;

int dijskstra(int source, int target){
    dist.assign(MAX, INF);
    set < pair <int, int> > q;
    dist[source] = 0;

    q.insert(make_pair(0, source));

    while(!q.empty()){
        pair <int, int> topo = *q.begin();
        q.erase(q.begin());

        int v = topo.second, d = topo.first;

        for(int i = 0; i < g[v].size(); i++){
            int v2 = g[v][i].first, custo = g[v][i].second;

            if(dist[v2] > dist[v] + custo){
                if(dist[v2] != INF){
                    q.erase(q.find(make_pair(dist[v2], v2)));
                }

                dist[v2] = dist[v] + custo;
                q.insert(make_pair(dist[v2], v2));
            }
        }
    }

    return dist[target];
}

int main(){
    int v, e;

    cin >> v >> e;

    for(int i = 0, u, k, w; i < e; i++){
        cin >> u >> k >> w;

        g[u].push_back(make_pair(k, w));
        g[k].push_back(make_pair(u, w));
    }

    int custo = dijskstra(1, 5);

    cout << custo << endl;
    return 0;
}