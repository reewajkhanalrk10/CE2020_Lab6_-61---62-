struct Vertex
{
    int data;
    Vertex *nextNeighbour;
    Vertex *prevNeighbour;
    Vertex *upVertex;
    Vertex *downVertex;
    Vertex():nextNeighbour(nullptr), prevNeighbour(nullptr), upVertex(nullptr), downVertex(nullptr){}; 
    Vertex(int data):data(data), nextNeighbour(nullptr), prevNeighbour(nullptr), upVertex(nullptr), downVertex(nullptr){};
};

class Graph{
private:
    Vertex *HEAD;
public:
    Graph();
    bool isEmpty();
    bool isDirected();
    void addVertex(int newVertex);
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int toremoveVertex);
    void removeEdge(int vertex1, int vertex2);
    void numVertices();
    void numEdges();
    bool neighbour(int vertex1, int vertex2);
};
