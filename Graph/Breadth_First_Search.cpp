#include<bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;
    vector<int> *adjacency;

    public:
        Graph(){
            vertices = 0;
        }

        Graph(int vertices){
            this->vertices = vertices;
            
            adjacency = new vector<int>[vertices];
            
        }

        void addedge(int , int);
        void breadth_first_search();
};

void Graph::addedge(int source, int destination){
    adjacency[source].emplace_back(destination);
}

void Graph::breadth_first_search(){
    vector<bool> visited(adjacency->size(), false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int vertex = q.front();
        cout<< "V" << vertex <<" ";
        q.pop();

        for(auto i = adjacency[vertex].begin(); i != adjacency[vertex].end(); i++){
            if(!visited[*i]){
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}

int main(){
    Graph graph(5);
    graph.addedge(0, 1);
    graph.addedge(0, 2);
    graph.addedge(1, 2);
    graph.addedge(1, 4);
    graph.addedge(1, 3);
    graph.addedge(2, 4);
    graph.addedge(3, 4);

    cout<<"Breadth First Search Traversal : ";
    graph.breadth_first_search();
    return 0;
}

