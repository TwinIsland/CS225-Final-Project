#pragma once
#include "include.hpp"

using std::string;
using std::set;
using std::vector;
using std::pair;
using std::list;

//template<class T>
 
typedef vector<string> inputVertex;

struct Edge {
        inputVertex from;
        inputVertex to;
        double weight = INT64_MAX;
};

class Graph_directed{
    private:
    ////////////////////////////
    // private struct //
    class Vertex {
        public:
        int name_ = -1; // id of the air port
        vector<string> other_data;
        // not sure wether vector or list is better @TODO!!!
        vector<pair<Vertex, double>> neighors_;

        private: 
        bool operator==(Vertex& v) {
            return v.name_ == this->name_;
        };

        bool operator!=(Vertex& v) {
            return v.name_ != this->name_;
        };
    };

    ///////////////////////////
    // private data //
    set<Vertex> all_node;
    set<Edge> all_edge;

    ///////////////////////////
    // helper function //
    
    /* funtion used for set neighbor */
    void insert_in_order(vector<pair<Vertex, double>>&, pair<Vertex, double>);
    
    /* function used to support insert in order */
    bool sortbysec(const pair<Vertex,double> &a,
              const pair<Vertex,double> &b) {
        return (a.second < b.second);
    }

    /// @brief start of public function

    public:
    ////////////////////////////
    // constructor //
    Graph_directed();

    /**
     * initilize the whole graph with node and edge as input
     * 
     * @param input_node input of vertex, this mp should be array<string>, Vertex[0] is airfield name
     * @param input_edge input of edge, including weight
    */
    Graph_directed(vector<inputVertex>, vector<Edge>);

    ////////////////////////////
    // function //
    /**
     * @param int the id of the air port
    */
    Vertex getVertex(int&);
    set<Vertex>::iterator getVertex_it(int& id) {
        Vertex temp;
        temp.name_ = id;
        // have not found better way to do this
        auto it = all_node.find(temp);
        if (it != all_node.end()) return it;
    }
};