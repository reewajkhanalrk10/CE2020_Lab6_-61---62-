#include "graph.h"
#include <iostream>
#include <array>

Graph::Graph(){
    HEAD = nullptr;
}

bool Graph::isEmpty(){
    if(HEAD==nullptr){
        return true;
    }
    else{
        return false;
    }
}

bool Graph::isDirected(){
    bool isDirected;
    Vertex *temp = new Vertex();
    Vertex *otherTemp = new Vertex();
    temp = HEAD;
    while (temp != nullptr){
        otherTemp = temp->nextNeighbour;
        while (otherTemp != nullptr){
            
            if (this->neighbour(temp->data, otherTemp->data) && this->neighbour(otherTemp->data, temp->data)){
                isDirected = false;
            }
            else{
                isDirected = true;
            }
            otherTemp = otherTemp->nextNeighbour;
        }
        temp = temp->downVertex;
    }
    return isDirected;
}

void Graph::addVertex(int newVertex){
    Vertex *vertex = new Vertex(newVertex);
    if(isEmpty()){
        HEAD = vertex;
        std::cout<<"Vertex is now added: "<<std::endl;
    }
    else{
        Vertex *temp = new Vertex();
        temp = HEAD;
        while(temp->downVertex!=nullptr && temp->data!=newVertex){
            temp=temp->downVertex;
        }        
        if(temp->downVertex==nullptr){
            temp->downVertex=vertex;
            vertex->upVertex=temp;
            std::cout<<"Vertex is now added: "<<std::endl;
        }
        else{
            std::cout<<"Vertex already found."<<std::endl;
        }
    }
}

void Graph::addEdge(int vertex1, int vertex2){
    Vertex *temp=new Vertex();
    Vertex *newVertex=new Vertex(vertex2);
    temp=HEAD;
    while (temp!=nullptr && temp->data!=vertex1){
        temp=temp->downVertex;
    }
    if (temp==nullptr){
        std::cout<<"Vertex hasn't been found."<<std::endl;
    }
        else{
        while(temp->nextNeighbour!=nullptr&&temp->nextNeighbour->data!=vertex2){
            temp=temp->nextNeighbour;
        }
        if(temp->nextNeighbour == nullptr){
            temp->nextNeighbour=newVertex;
            newVertex->prevNeighbour=temp;
            std::cout << "Edge has been added." << std::endl;
        }
        else{
            std::cout<<"Edge already found."<<std::endl;
        }
    }
}

void Graph::removeVertex(int toremoveVertex){
    Vertex *temp=new Vertex();
    temp=HEAD;
    while(temp!=nullptr && temp->data!=toremoveVertex){
        temp=temp->downVertex;
    }
    if(temp==nullptr){
        std::cout<<"Vertex hasn't been found."<<std::endl;
    }
    else{
        if(temp->downVertex==nullptr){
            temp->upVertex->downVertex=nullptr;
        }
        else{
            temp->downVertex->upVertex=temp->upVertex;
            temp->upVertex->downVertex=temp->downVertex;
            delete temp;
        }
        Vertex *remove=new Vertex();
        remove=HEAD;
        while(remove!=nullptr){
            if(neighbour(remove->data, toremoveVertex)){
                removeEdge(remove->data, toremoveVertex);
            }
            remove=remove->downVertex;
        }
    }
}

void Graph::removeEdge(int vertex1, int vertex2){
    Vertex *temp=new Vertex();
    temp=HEAD;
    while(temp!=nullptr && temp->data!=vertex1){
        temp=temp->downVertex;
    }
    if(temp==nullptr){
        std::cout<<"Vertex"<<vertex1<<"hasn't been found."<<std::endl;    
    }
    else{
        temp=temp->nextNeighbour;
        while (temp!=nullptr && temp->data!=vertex2){
            temp=temp->nextNeighbour;
        }
        if(temp==nullptr){
            std::cout<<"Edge hasn't been found"<<std::endl;
        }
        else{
            if (temp->nextNeighbour==nullptr)
            {
                delete temp;
                std::cout<<"Edge has been deleted"<<std::endl;
            }
            else{
                temp->prevNeighbour->nextNeighbour=temp->nextNeighbour;
                temp->nextNeighbour->prevNeighbour=temp->prevNeighbour;
                delete temp;
                std::cout<<"Edge has been deleted"<<std::endl;
            }
        }
    }
}

void Graph::numVertices(){
    int x=0;
    Vertex *temp = new Vertex();
    temp = HEAD;
    while(temp!=nullptr){
        x++;
        temp=temp->downVertex;
    }
    std::cout<<"The number of vertices in the Graph is: "<<x<<std::endl;
}

void Graph::numEdges()
{
    int a = 0;
    Vertex *trackV=new Vertex();
    Vertex *trackN=new Vertex();
    trackV=HEAD;
    while (trackV!=nullptr)
    {
        trackN=trackV->nextNeighbour;
        while (trackN!=nullptr)
        {
            a++;
            trackN=trackN->nextNeighbour;
        }
        trackV=trackV->downVertex;
    }
    std::cout<<"The number of edges in the Graph is: "<<a<<std::endl;
}
bool Graph::neighbour(int vertex1, int vertex2){
    Vertex *temp = new Vertex();
    Vertex *otherTemp = new Vertex(vertex2);
    temp = HEAD;

    while (temp != nullptr && temp->data != vertex1){
        temp = temp->downVertex;
    }

    if (temp == nullptr){
        std::cout<<"Vertex doesn't exist."<<std::endl;    
        return false;
    }
    else{
        while (temp->nextNeighbour != nullptr && temp->nextNeighbour->data != vertex2){
            temp = temp->nextNeighbour;
        }
        if (temp->nextNeighbour == nullptr){
            return false;
        }
        else{
            std::cout << vertex1 <<" and "<< vertex2 <<" are neighbours.\n";
            return true;
        }
    }
}
