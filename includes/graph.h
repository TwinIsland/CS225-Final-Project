#pragma once
#include "include.hpp"

using std::string;
using std::set;
using std::vector;
using std::pair;

//template<class T>
struct Vertex {
        string name;
};

struct Edge {
        Vertex from;
        Vertex to;
        double weight = INT64_MAX;
};

class Graph_directed{
    public:
    ////////////////////////////
    // constructor //
    Graph_directed();
    Graph_directed(vector<Vertex>, vector<Edge>);
    

    private:
    ////////////////////////////
    // private struct //
    struct Node {
        string name_;
        vector<pair<Node, double>> neighors_;
    };

    ///////////////////////////
    // private data //
    set<Node> all_node;
    set<Edge> all_edge;

    ///////////////////////////
    // helper function //
    void insert_in_order(vector<pair<Node, double>>&, pair<Node, double>);


};