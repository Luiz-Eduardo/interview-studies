#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
#define MAXN 500

using namespace std;

pair<int,int> p[MAXN];
int n, c;
int pai[MAXN];

double grafo[MAXN][MAXN], arvore[MAXN], dist[MAXN];
double custo;

void prim (){
	int v0;
	custo = 0;
	for (int i = 1; i < n; ++i){
		pai[i] = -1;
		arvore[i] = 0;
		dist[i] = grafo[0][i];
	}

	pai[0] = 0;
	while (1){
		double mincost = INF;
		for (int i = 0; i < n; ++i)
			if (pai[i] == -1 && mincost > dist[i])
				mincost = dist[v0 = i];
		if (mincost == INF)
			break;
		pai[v0] = arvore[v0];
		custo += mincost;
		for (int i = 0; i < n; ++i)
			if (pai[i] == -1 && dist[i] > grafo[v0][i]){
				dist[i] = grafo[v0][i];
				arvore[i] = v0;
			}
	}
}

int main(){
	scanf("%d", &c);

	while(c--){
		scanf("%d", &n);

		for (int i = 0; i < n; ++i)
            scanf("%d%d", &p[i].first, &p[i].second);

		memset(grafo, INF, sizeof(grafo));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				grafo[i][j] = hypot(p[i].first-p[j].first, p[i].second-p[j].second);

		prim();
		printf("%.2f\n", custo/100.0);
	}
}
