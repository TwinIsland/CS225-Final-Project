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
    public:
    ////////////////////////////
    // private struct //
    class Vertex {
        public:
        string name_ = "-1"; // id of the air port
        vector<string> other_data;
        // store the neighbor index and the corresponding weight
        vector<pair<string, double>> neighors_;

        private: 
        bool operator==(Vertex& v) {
            return v.name_ == this->name_;
        };

        bool operator!=(Vertex& v) {
            return v.name_ != this->name_;
        };

        Vertex operator=(Vertex& v) {
            name_ == v.name_;
            other_data = v.other_data;
            neighors_ = v.neighors_;
        };

    };

    ///////////////////////////
    // private data //
    set<Vertex> all_node;
    set<Edge> all_edge;

    ///////////////////////////
    // helper function //
    
    /* funtion used for set neighbor */
    void insert_in_order(vector<pair<string, double>>&, pair<string, double>);
    
    /* function used to support insert in order */
    bool sortbysec(const pair<string,double> &a,
              const pair<string,double> &b) {
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
    Vertex getVertex(string&);
    set<Vertex>::iterator getVertex_it(string& id) {
        Vertex temp;
        temp.name_ = id;
        // have not found better way to do this
        auto it = all_node.find(temp);
        if (it != all_node.end()) return it;
    }
};