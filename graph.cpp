#include "graph.h"
#include <iostream>
#include <array>

Graph::Graph()
{
    HEAD = nullptr;
}
bool Graph::isEmpty()
{
    if (HEAD == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Graph::addVertex(int newVertex)
{
    Vertex *vertex = new Vertex(newVertex);
    if (isEmpty())
    {
        HEAD = vertex;
        std::cout << "Vertex has been added" << std::endl;
    }
    else
    {
        Vertex *temp = new Vertex();
        temp = HEAD;

        while (temp->downVertex != nullptr && temp->data != newVertex)
        {
            temp = temp->downVertex;
        }

        if (temp->downVertex == nullptr)
        {
            temp->downVertex = vertex;
            vertex->upVertex = temp;
            std::cout << "Vertex has been added" << std::endl;
        }
        else
        {
            std::cout << "Vertex already exists" << std::endl;
        }
    }
}
void Graph::addEdge(int vertex1, int vertex2)
{
    Vertex *temp = new Vertex();
    Vertex *newVertex = new Vertex(vertex2);
    temp = HEAD;

    while (temp != nullptr && temp->data != vertex1)
    {
        temp = temp->downVertex;
    }

    if (temp == nullptr)
    {
        std::cout << "Vertex doesn't exists." << std::endl;
    }

    else
    {
        while (temp->nextNeighbor != nullptr && temp->nextNeighbor->data != vertex2)
        {
            temp = temp->nextNeighbor;
        }
        if (temp->nextNeighbor == nullptr)
        {
            temp->nextNeighbor = newVertex;
            newVertex->prevNeighbor = temp;
            std::cout << "Edge has been added." << std::endl;
        }

        else
        {
            std::cout << "Edge already exists." << std::endl;
        }
    }
}
void Graph::numEdges()
{
    int e = 0;
    Vertex *trackVer = new Vertex();
    Vertex *trackNei = new Vertex();
    trackVer = HEAD;
    while (trackVer != nullptr)
    {
        trackNei = trackVer->nextNeighbor;
        while (trackNei != nullptr)
        {
            e++;
            trackNei = trackNei->nextNeighbor;
        }
        trackVer = trackVer->downVertex;
    }
    std::cout << "The number of edges in the Graph is " << e << std::endl;
}

int Graph::indegree(int vertex)
{
    Vertex *temp = HEAD;
    int count = 0;

    while (temp->downVertex != nullptr)
    {
        Vertex *otherTemp = temp;

        while (otherTemp->nextNeighbor != nullptr)
        {
            otherTemp = otherTemp->nextNeighbor;
            if (otherTemp->data == vertex)
            {
                count++;
            }
        }
        temp = temp->downVertex;
    }
    return count;
}

int Graph::outdegree(int vertex)
{
    Vertex *temp = HEAD;
    int count = 0;

    if (!isEmpty())
    {
        while (temp->data != vertex)
        {
            temp = temp->downVertex;
        }
        Vertex *otherTemp = temp;

        while (otherTemp->nextNeighbor != nullptr)
        {
            count++;
            otherTemp = otherTemp->nextNeighbor;
        }
        return count;
    }
    else
    {
        return 0;
    }
}

int Graph::degree(int vertex)
{
    return this->indegree(vertex) + this->outdegree(vertex);
}

int *Graph::neighbours(int vertex)
{
    int *neighbour;
    int i = 0;
    Vertex *temp = new Vertex();
    temp = HEAD;
    while (temp != nullptr && temp->data != vertex)
    {
        temp = temp->downVertex;
    }
    if (temp == nullptr)
    {
        std::cout << "Vertex doesn't exist." << std::endl;
    }
    else
    {
        while (temp->nextNeighbor != nullptr)
        {
            neighbour[i] = temp->nextNeighbor->data;
            i++;
            temp = temp->nextNeighbor;
        }
    }
    return neighbour;
}

bool Graph::neighbour(int vertex1, int vertex2)
{
    Vertex *temp = new Vertex();
    Vertex *otherTemp = new Vertex(vertex2);
    temp = HEAD;

    while (temp != nullptr && temp->data != vertex1)
    {
        temp = temp->downVertex;
    }

    if (temp == nullptr)
    {
        std::cout << "Vertex doesn't exist." << std::endl;
        return false;
    }
    else
    {
        while (temp->nextNeighbor != nullptr && temp->nextNeighbor->data != vertex2)
        {
            temp = temp->nextNeighbor;
        }
        if (temp->nextNeighbor == nullptr)
        {
            return false;
        }
        else
        {
            std::cout << vertex1 << " and " << vertex2 << " are neighbours.\n";
            return true;
        }
    }
}