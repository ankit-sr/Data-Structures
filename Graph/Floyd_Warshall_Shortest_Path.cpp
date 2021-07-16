#include<bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;
    vector<vector<int>> path;

    public:
        Graph(int vertices){
            this->vertices = vertices;

            path.assign(vertices, vector<int>(vertices, INT_MAX));

            for(int i = 0; i<vertices; i++){
                path[i][i] = 0;
            }
        }

        void floyd_warshall();
        void addEdge(int, int, int);
        void printGraph();
};

void Graph::addEdge(int source, int destination, int weight){
    path[source][destination] = weight;
}

void Graph::floyd_warshall(){

    for(int k=0; k<vertices; k++){
        for(int i=0; i<vertices; i++){
            for(int j=0; j<vertices; j++){

                // if(path[i][j] > (path[i][k] + path[k][j]))
                //     path[i][j] = path[i][k] + path[k][j];

                if (path[i][j] > (path[i][k] + path[k][j])
                    && (path[k][j] != INT_MAX
                        && path[i][k] != INT_MAX))
                    path[i][j] = path[i][k] + path[k][j];
            }
        }
    }
}

void Graph::printGraph(){
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            if(path[i][j] == INT_MAX)
                cout<<"INF  ";
            else    
                cout<<path[i][j]<<"  ";
        }
        cout<<endl;
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

    cout<<"\nDistance from each vertex : "<<endl;
    graph.printGraph();
    graph.floyd_warshall();
    cout<<"\nShortest distance by Floyd Wrashall Algorithm is : "<<endl;
    graph.printGraph();
    return 0;
}