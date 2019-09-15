#include <bits/stdc++.h>
#define union acbcxabdbasdfsadf
#define MAX 500050

using namespace std;

vector <pair <long long, pair <long long, long long> > > grafo;
long long n, m;
long long pai[MAX];

inline long long find(int n){
	return pai[n] == n ? n : pai[n] = find(pai[n]);
}

inline void union(int a, int b){
	pai[find(a)] = find(b);
}

int main(){
	while(scanf("%lld%lld", &n, &m), n|m){
		grafo.clear();
		
		for(int i = 0; i <= n; ++i) pai[i] = i;

		long long v1, v2, p;

		for(int i = 0; i < m; ++i){
			scanf("%lld%lld%lld", &v1, &v2, &p);
			
			grafo.push_back(make_pair(p, make_pair(v1, v2)));
		}

		sort(grafo.begin(), grafo.end());

		long long ans = 0;

	    for(int i = 0; i < m; i++){
	        if(find(grafo[i].second.first) != find(grafo[i].second.second)){
	            union(grafo[i].second.first, grafo[i].second.second);
	            ans += grafo[i].first;
	        }
	    }

	    printf("%lld\n", ans);
	}

	return 0;
}
