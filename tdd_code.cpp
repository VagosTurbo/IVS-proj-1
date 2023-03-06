//======== Copyright (c) 2023, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - graph
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
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
    for(int i = 0; i < m_nodes.size(); i++){
        nodes.push_back(&m_nodes[i]);
    }

    return nodes;
}

std::vector<Edge> Graph::edges() const{
    std::vector<Edge> edges;
    for(int i = 0; i < m_edges.size(); i++){
        edges.push_back(m_edges[i]);
    }

    return edges;
}

Node* Graph::addNode(size_t nodeId) {

    for(auto node : m_nodes){
        if(node.id == nodeId){
            return nullptr;
        }
    }

    Node node;
    node.id = nodeId;
    node.color = 0;
    m_nodes.push_back(node);
    return &m_nodes.back();
}

bool Graph::addEdge(const Edge& edge){
    if(edge.a == edge.b || containsEdge(edge)){
        return false;
    }

    addNode(edge.a);
    addNode(edge.b);

    m_edges.push_back(edge);
    return true;

}

void Graph::addMultipleEdges(const std::vector<Edge>& edges) {
    for(auto edge : edges){
        addEdge(edge);
    }
}

Node* Graph::getNode(size_t nodeId){
    for (int i = 0; i < m_nodes.size(); i++){
        if(m_nodes[i].id == nodeId){
            return &m_nodes[i];
        }
    }
    return nullptr;
}

bool Graph::containsEdge(const Edge& edge) const{
    for(auto m_edge : m_edges){
        if((edge.a == m_edge.a && edge.b == m_edge.b) || (edge.a == m_edge.b && edge.b == m_edge.a)){
            return true;
        }
    }
    return false;
}

void Graph::removeNode(size_t nodeId){

    if(getNode(nodeId) == nullptr){
        throw std::out_of_range("Node not in graph");
    }

    for (int i = 0; i < m_nodes.size(); i++){
        if (m_nodes[i].id == nodeId){
            m_nodes.erase(m_nodes.begin() + i);
            for (int j = 0; j < m_edges.size(); j++){
                if(m_edges[j].a == nodeId || m_edges[j].b == nodeId){
                    removeEdge(m_edges[j]);
                    j--;
                }
            }
        }
    }
    return;
}

void Graph::removeEdge(const Edge& edge){
    for (int i = 0; i < m_edges.size(); i++){
        if(containsEdge(edge)){
            m_edges.erase(m_edges.begin() + i);
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
    return m_nodes.size();
}

size_t Graph::edgeCount() const{
    return m_edges.size();
}

size_t Graph::nodeDegree(size_t nodeId) const{
    int count = 0;
    for (auto edge : m_edges){
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
    for (auto node : m_nodes){
        if (nodeDegree(node.id) >= max_degree){
            max_degree = nodeDegree(node.id);
        }
    }
    return max_degree;
    
}

void Graph::coloring(){
    int max_color = graphDegree() + 1;
    std::vector<int> Colors;
    for (int i = 0; i < max_color; i++){
        Colors[i] = i;
    }
    for(int i = 0; i < m_nodes.size(); i++){
        
    }
}

void Graph::clear() {
    m_nodes.clear();
    m_edges.clear();
}

/*** Konec souboru tdd_code.cpp ***/
