#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> *graph;
    public:
        Graph(int v)
        {
            this->V = v;
            this->graph = new vector<int>[V];
        }

        void addEdge(int u, int v)
        {
            graph[u].push_back(v);
            graph[v].push_back(u);
            
        }

        void articulation_points(int source, vector<int>& discovery, vector<int>& low, vector<int>& parent, vector<bool>& ap)
        {
            int childCount = 0;
            static int time = 0;
            discovery[source] = low[source] = time++;

            for(auto v : graph[source])
            {
                if(discovery[v] == -1)
                {
                    childCount++;
                    parent[v] = source;
                    articulation_points(v, discovery, low, parent, ap);
                    low[source] = min(low[source], low[v]);

                    // is source is root
                    if((parent[source] == -1 && childCount>1) || (parent[source] != -1 && low[v] >= discovery[source]))
                    {
                        ap[source] = true;
                    }

                    // not root but component gets separated
                    // if(parent[source] != -1 && low[v] >= discovery[source])
                    // {
                    //     ap[source] = true;
                    // }
                }
                else if(v != parent[source])
                {
                    low[source] = min(low[source], discovery[v]);
                }
            }
        }

        void APUtil()
        {
            vector<int> discovery(V, -1), low(V,-1), parent(V, -1);
            vector<bool> ap(V, false);

            for(int i = 0; i < V; i++)
            {
                if(discovery[i] == -1)
                {
                    articulation_points(i, discovery, low, parent, ap);
                }
            }

            cout<<"\nArticulation points are : ";
            for(int i=0; i<V; i++)
            {
                if(ap[i])
                {
                    cout<<i<<" ";
                }
            }
        }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.APUtil();
}