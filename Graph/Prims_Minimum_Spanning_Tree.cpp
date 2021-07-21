#include<bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;

    vector<vector<int>> adjacency;

    public:
        Graph(int vertices)
        {
            this->vertices = vertices;

            adjacency.assign(vertices, vector<int>(vertices, INT_MAX));
        }

        void primsMST();
        int findMinKey(int[], bool[]);
        void addEdge(int, int, int);
        void printMST(int[]);
};

void Graph::addEdge(int source, int destination, int weight)
{
    adjacency[source][destination] = weight;
    adjacency[destination][source] = weight;
}

int Graph::findMinKey(int key[], bool mstSet[]){

    int min_index, min = INT_MAX;

    for(int i=0; i<vertices; i++){
        if(!mstSet[i] && key[i]<min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void Graph::primsMST()
{
    // Array to store the vertex with respective source vertex as index and destination vertex as value.
    // i.e. Minimum Spanning Tree
    int MST[vertices];

    // Array to pick the minimum weight pair from graph
    int  key[vertices];

    // Array to check whether an vertex is included in the MST or not.
    bool mstSet[vertices];

    // Iniitializing key and mstSet with infinity and false as the default value
    for(int i=0; i<vertices; i++){
        key[i] = INT_MAX, mstSet[i] = false;
    }

    // Initial vertex is set to 0, so that it is picked first.
    key[0] = 0;
    MST[0] = -1;

    for(int i = 0; i < vertices-1; i++)
    {
        // Finding the minimum weighted edge.
        int u = findMinKey(key, mstSet);

        // Set the included status(mstSet) of returned vertex (u) as true.
        mstSet[u] = true;

        // Adding all the adjacent vertex into the MST, if it follows following conditions
        for(int v = 0; v < vertices; v++)
        {
            // 1. the mstSet status if false i.e. vertex is not already included
            // 2. distance should not be infinite, i.e. the vertex should be adjacent to u
            // 3. adjacency[u][v] < key[v]
            if( !mstSet[v] && adjacency[u][v]!=INT_MAX && adjacency[u][v] < key[v])
            {
                MST[v] = u;
                key[v] = adjacency[u][v];
            }
        }
    }

    printMST(MST);
}

// Method to print the minimum spanning tree
// or priniting the vertices included in the minimum spanning tree.
void Graph::printMST(int MST[])
{
    cout<<"\nThe minimum spanning tree for the created graph will be : "<<endl;
    cout<<"Edge \t Weight"<<endl;
    
    for(int i=1; i < vertices; i++)
    {
        cout<< MST[i] <<" - "<< i << "\t  " << adjacency[MST[i]][i] << endl;
    }
}

int main(){
    // Object of graph with 5 vertices.
    Graph graph(5);

    // Adding edges to the graph.
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 4, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 4, 10);

// Calling the dijkstra algortihm to find the minimum distance from a vertex.
    graph.primsMST();

    return 0;
}