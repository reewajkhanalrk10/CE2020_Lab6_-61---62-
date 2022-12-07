struct Vertex
{
    int data;

    Vertex *nextNeighbor;
    Vertex *prevNeighbor;
    Vertex *upVertex;
    Vertex *downVertex;

    Vertex() : nextNeighbor(nullptr), prevNeighbor(nullptr), upVertex(nullptr), downVertex(nullptr){};
    Vertex(int data) : data(data), nextNeighbor(nullptr), prevNeighbor(nullptr), upVertex(nullptr), downVertex(nullptr){};
};

class Graph
{
private:
    Vertex *HEAD;

public:
    Graph();
    bool isEmpty();
    void addVertex(int newVertex);
    void addEdge(int vertex1, int vertex2);
    void numEdges();
    int indegree(int vertex);
    int outdegree(int vertex);
    int degree(int vertex);
    int *neighbours(int vertex);
    bool neighbour(int vertex1, int vertex2);
};