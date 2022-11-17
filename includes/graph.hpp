#pragma once
#include "include.hpp"

using std::string;
using std::set;
using std::vector;

typedef vector<vector<string>> GIP;

class Graph_directed{
    public:
    Graph_directed();
    Graph_directed(GIP);

    private:
    struct Vertex {
        string name;
    };
    struct Edge {
        string from;
        string to;
        double weight;
    };
    //
    set<Vertex> all_vertex;
    set<Edge> all_edge;


};