#include "graph.h"
#include <iostream>
using namespace std;

int main(){
    Graph G;
    G.addVertex(2);
    G.addVertex(4);
    G.addVertex(6);
    if(G.isEmpty()){
        cout<<"The Graph is empty."<<endl;
    }
    else{
        cout<<"The Graph is not empty."<<endl;
    }
    G.numVertices();
    G.addEdge(2,4);
    G.addEdge(3,9);
    G.addEdge(1,5);
    G.numEdges();
    G.removeVertex(6);
    G.numVertices();
}
