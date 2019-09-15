#include <bits/stdc++.h>
#define MAXL 25
#define MAXN 100005

using namespace std;

long long n, q;
long long pai[MAXN], nivel[MAXN], ancestral[MAXN][MAXL], dist[MAXN];
vector < pair<long long, long long > > grafo[MAXN];

void dfs(long long u){
    for(int i = 0; i < (int)grafo[u].size(); i++){
        long long v = grafo[u][i].first;

        if(nivel[v] == -1){
            pai[v] = u;
            dist[v] = dist[u] + grafo[u][i].second;
            nivel[v] = nivel[u] + 1;

            dfs(v);
        }
    }
}

long long LCA(long long u, long long v){
    if(nivel[u] < nivel[v]) swap(u, v);

    for(int i = MAXL-1; i >= 0; i--)
        if(nivel[u] - (1<<i) >= nivel[v])
            u = ancestral[u][i];

    if(u == v) return u;

    for(int i = MAXL-1; i >= 0; i--)
        if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return pai[u];
}

int main(){
    while(scanf("%lld", &n), n){
        for(long long i = 1, a, b; i < n; i++){
            scanf("%lld %lld", &a, &b);

            grafo[i].push_back(make_pair(a, b));
            grafo[a].push_back(make_pair(i, b));
        }

        for(long long i = 0; i <= n; i++)
            pai[i] = nivel[i] = -1;

        memset(ancestral, -1, sizeof ancestral);

        nivel[0] = 0;
        dfs(0);

        for(long long i = 0; i <= n;i++)
            ancestral[i][0] = pai[i];

        for(long long j = 1; j < MAXL; j++)
            for(long long i = 0; i <= n; i++)
                if(ancestral[i][j-1] != -1)
                    ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];

        scanf("%lld", &q);

        for(long long i = 1, s, t; i <= q; i++){
            scanf("%lld %lld", &s, &t);

            if(i != q) printf("%lld ", dist[s]+dist[t]-2*dist[LCA(s, t)]);
            else printf("%lld\n", dist[s]+dist[t]-2*dist[LCA(s, t)]);
        }

        for(int i = 0; i <= n; i++) grafo[i].clear();
    }

    return 0;
}