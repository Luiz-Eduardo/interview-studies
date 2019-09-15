#include <bits/stdc++.h>

using namespace std;

class Graph{
    private:
        int vertex;
        int edges;

    class Edge{
        public:
            int source;
            int target;
            int weight;
    };

    class Subset{
        public:
            int parent;
            int rank;
    };

    int find(Subset subsets[], int i){
        if(subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }

    void Union(Subset subsets[], int a, int b){
        int x = find(subsets, a);
        int y = find(subsets, b);

        if(subsets[x].rank < subsets[y].rank)
            subsets[x].parent = y;
        else if (subsets[x].rank > subsets[y].rank)  
            subsets[y].parent = x;  
        else {  
            subsets[y].parent = x;  
            subsets[x].rank++;  
        }  
    }

    public:
        Edge *edge;

        Graph(int vertex, int edges){
            this->vertex = vertex;
            this->edges = edges;
            this->edge = new Edge[edges];
        }

        void kruskal(){
            int v = this->vertex;
            Edge answer[v];            

            sort(this->edge, this->edge + this->edges, [](Edge &a, Edge &b){
                return a.weight < b.weight;
            });

            Subset *subsets = new Subset[ (v * sizeof(Subset)) ];

            for(int i = 0; i < v; i++){
                subsets[i].parent = i;
                subsets[i].rank = 0;
            }

            int i = 0, e = 0;

            while(e < v-1 && i < this->edges){
                Edge next = this->edge[i++];

                int x = find(subsets, next.source);
                int y = find(subsets, next.target);

                if(x != y){
                    answer[e++] = next;
                    Union(subsets, x, y);
                }
            }

            cout << "Following are the edges in the constructed MST" << endl;
            for(i = 0; i < e; i++){
                cout << answer[i].source << " -- " << answer[i].target << " == " << answer[i].weight << endl;
            }

            return;
        }
};

int main(){
    int v, e;

    cin >> v >> e;

    Graph *g = new Graph(v, e);

    for(int i = 0, source, target, weight; i < e; i++){
        cin >> source >> target >> weight;
        
        g->edge[i].source = source;
        g->edge[i].target = target;
        g->edge[i].weight = weight;
    }

    g->kruskal();
   
    return 0;
}