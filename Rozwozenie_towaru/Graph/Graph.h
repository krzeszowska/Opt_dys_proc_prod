#ifndef GRAPH_H
#define GRAPH_H

#include "Operators.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <algorithm>

template <class T>
std::ostream& operator<<(std::ostream& str, const std::vector<std::vector<T> >& vect){

    for(unsigned int i=0;i<vect.size();++i){
        str<<i<<". "<<vect.at(i);
        if(i!=vect.size()-1) str<<std::endl;
    }

    return str;
}


class Graph
{
    //lista krawedzi
    std::vector<std::vector<double>> edges;

    //wylaczenie operacji konstruktora kopiujacego i operatora przyrownania
    Graph(const Graph &g);
    Graph& operator=(const Graph& g);
public:

    Graph(){}
    ~Graph(){}

    void setSize (unsigned int vertices);


    const double& edge(unsigned int begin, unsigned int end) const;

    double& edge(unsigned int begin, unsigned int end);


    void random(unsigned int n);

    unsigned int size() const;

    void writeToFile(const std::string& path) const ;

    void readFromFile(const std::string& path);

    double computeShortestComplexPath(unsigned int begin, std::vector<unsigned int> vertices, double*shortestPathVal = nullptr) const;

    friend std::istream& operator>>(std::istream& str, Graph& graph);
};

inline std::ostream& operator<<(std::ostream& str, const Graph& graph){
    str<<graph.size()<< " " <<std::endl;

    //headers
    str<<"    ";
    for(unsigned int i=0;i<graph.size();++i){
        str<<" " << std::setw(4) <<i;
    }
    str<<std::endl;

    //print graph
    for(unsigned int i=0;i<graph.size();++i){
        str<< std::setw(4) <<i;
        for(unsigned int j=0;j<graph.size();++j){
            str<<" "<<std::setw(4)<<graph.edge(i,j);
        }
        str<<std::endl;
    }

    //return stream for pipelining
    return str;
}

inline std::istream& operator>>(std::istream& str, Graph& graph){

    //load config size and flags
    unsigned int size;
    str>>size;
    graph.setSize(size);

    double buf;
    //skip header
    for(unsigned int i=0;i<size;++i){
        str >> buf;
    }

    for(unsigned int i=0;i<size;++i){
        //skip vertex label
        str >> buf;
        //load vertex edges
        for(unsigned int j=0;j<size;++j){
            str >> buf;
            //this is available via friendship
            graph.edges[j][i] = buf;
        }
    }


    return str;
}


#endif // GRAPH_H
