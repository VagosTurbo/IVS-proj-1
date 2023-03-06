//======== Copyright (c) 2023, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - graph
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     BORIS SEMANCO <xseman06@stud.fit.vutbr.cz>
// $Date:       $2023-03-07
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author Martin Dočekal
 * @author Karel Ondřej
 *
 * @brief Implementace metod tridy reprezentujici graf.
 */

#include "tdd_code.h"


Graph::Graph(){}

Graph::~Graph(){}

std::vector<Node*> Graph::nodes() {
    std::vector<Node*> nodes;
    //skopiruje do nodes vsetky uzly z v_nodes
    for(int i = 0; i < nodeCount(); i++){
        nodes.push_back(&v_nodes[i]);
    }

    return nodes;
}

std::vector<Edge> Graph::edges() const{
    std::vector<Edge> edges;
    //skopiruje vsetky hrany z v_edges do edges
    for(int i = 0; i < edgeCount(); i++){
        edges.push_back(v_edges[i]);
    }

    return edges;
}

Node* Graph::addNode(size_t nodeId) {
    //kontrola ci uz uzol s rovnakym id nieje v grafe
    for(auto node : v_nodes){
        if(node.id == nodeId){
            return nullptr;
        }
    }

    //vytvori uzol a prida ho do vektoru uzlov
    Node node;
    node.id = nodeId;
    node.color = 0;
    v_nodes.push_back(node);
    return &v_nodes.back();
}

bool Graph::addEdge(const Edge& edge){
    //kontrola ci zadana hrana nieje smycka alebo ci sa uz nenachadza v grafe
    if(edge.a == edge.b || containsEdge(edge)){
        return false;
    }

    //ak je v hrane uzol ktory este nieje v grafe tak vytvori aj uzol
    addNode(edge.a);
    addNode(edge.b);

    //zapise novu hranu do vektoru hran
    v_edges.push_back(edge);
    return true;

}

void Graph::addMultipleEdges(const std::vector<Edge>& edges) {
    for(auto edge : edges){
        addEdge(edge);
    }
}

Node* Graph::getNode(size_t nodeId){
    //postupne prechadza voktor uzlov kym nenajde uzol so zadanym id a vrati jeho adresu
    for (int i = 0; i < nodeCount(); i++){
        if(v_nodes[i].id == nodeId){
            return &v_nodes[i];
        }
    }
    return nullptr;
}

bool Graph::containsEdge(const Edge& edge) const{
    //prejde kazdu hranu vo vektore v_edges a skontroluje ci sa tam uz nenachadza zadana hrana
    for(auto v_edge : v_edges){
        if((edge.a == v_edge.a && edge.b == v_edge.b) || (edge.a == v_edge.b && edge.b == v_edge.a)){
            return true;
        }
    }
    return false;
}

void Graph::removeNode(size_t nodeId){

    //kontrola ci sa vobec uzol nachadza v grafe
    if(getNode(nodeId) == nullptr){
        throw std::out_of_range("Node not in graph");
    }

    for (int i = 0; i < nodeCount(); i++){
        if (v_nodes[i].id == nodeId){
            v_nodes.erase(v_nodes.begin() + i);
            for (int j = 0; j < edgeCount(); j++){
                if(v_edges[j].a == nodeId || v_edges[j].b == nodeId){
                    removeEdge(v_edges[j]);
                    j--;
                }
            }
        }
    }
    return;
}

void Graph::removeEdge(const Edge& edge){
    for (int i = 0; i < edgeCount(); i++){
        if(containsEdge(edge)){
            v_edges.erase(v_edges.begin() + i);
            //ak vymaze hranu s uzlom ktory sa nachadzal len v tejto hrane tak vymaze aj uzol
            if(nodeDegree(edge.a) < 1){
                removeNode(edge.a);
            }
            if(nodeDegree(edge.b) < 1){
                removeNode(edge.b);
            }
            return;
        }
    }
    throw std::out_of_range("Edge not in graph");
}

size_t Graph::nodeCount() const{
    return v_nodes.size();
}

size_t Graph::edgeCount() const{
    return v_edges.size();
}

size_t Graph::nodeDegree(size_t nodeId) const{
    int count = 0;
    for (auto edge : v_edges){
        if (edge.a == nodeId || edge.b == nodeId){
            count++;
        }
    }
    if(count == 0){
        throw std::out_of_range("Node not in list to test degree");
    }
    return count;
}

size_t Graph::graphDegree() const{
    
    int max_degree = 0;
    for (auto node : v_nodes){
        if (nodeDegree(node.id) >= max_degree){
            max_degree = nodeDegree(node.id);
        }
    }
    return max_degree;
    
}

void Graph::coloring(){
}

void Graph::clear() {
    v_nodes.clear();
    v_edges.clear();
}

/*** Konec souboru tdd_code.cpp ***/
