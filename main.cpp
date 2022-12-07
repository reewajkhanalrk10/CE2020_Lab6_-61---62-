#include "graph.cpp"
#include <iostream>
using namespace std;

int main()
{
    Graph G;
    if (G.isEmpty())
    {
        cout << "The Graph is empty." << endl;
    }
    else
    {
        cout << "The Graph isn't empty." << endl;
    }
    G.addVertex(1);
    G.addVertex(3);
    G.addVertex(4);
    G.addVertex(5);
    if (G.isEmpty())
    {
        cout << "The Graph is empty." << endl;
    }
    else
    {
        cout << "The Graph isn't empty." << endl;
    }
    G.addEdge(1, 3);
    G.numEdges();
    G.indegree(1);
    cout << "The no of indegree is " << G.indegree(3) << endl
         << endl;

    cout << "The no of outdegree is " << G.outdegree(1) << endl;
    cout << "The degree of 3 is " << G.degree(3) << endl;

    cout << G.neighbours(5) << endl;
    G.neighbour(1, 3);
}