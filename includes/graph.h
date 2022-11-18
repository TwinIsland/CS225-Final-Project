#pragma once
#include "include.hpp"

using std::string;
using std::set;
using std::vector;
using std::pair;
using std::list;
using std::map;
using std::unordered_map;

//template<class T>
 
typedef vector<string> inputVertex;



class Graph_directed{
    private:
    ////////////////////////////
    // private struct //
    struct Edge {
        inputVertex from;
        inputVertex to;
        double weight = 0;
    };

    class Vertex {
        public:
        string name_ = "-1"; // id of the air port
        vector<string> other_data;
        // store the neighbor index and the corresponding weight
        vector<pair<string, double>> neighbors_;
        unsigned num_of_neighbor = 0;

        bool operator==(Vertex& v) {
            return v.name_ == this->name_;
        };

        bool operator!=(Vertex& v) {
            return v.name_ != this->name_;
        };

        Vertex operator=(Vertex& v) {
            name_ = v.name_;
            other_data = v.other_data;
            neighbors_ = v.neighbors_;
            return *this;
        };

        Vertex (const Vertex& v) {
            name_ = v.name_;
            other_data = v.other_data;
            neighbors_ = v.neighbors_;
        };

        Vertex(){
            
        }

    };

    ///////////////////////////
    // private data //
    unordered_map<string,Vertex> graph;
    set<Edge> all_edge;
    vector<string> nodes;

    ///////////////////////////
    // helper function //
    
    /* funtion used for set neighbor */
    void insert_in_order(vector<pair<string, double>>&, pair<string, double>);
    
    /* function used to support insert in order */
    static bool sortbysec(const pair<string,double> &a,
              const pair<string,double> &b) {
        return (a.second < b.second);
    }

    /**
     * initilize the whole graph with node and edge as input
     * 
     * @param input_node input of vertex, this mp should be array<string>, Vertex[0] is airfield name
     * @param input_edge input of edge, including weight
    */
    void create_helper(vector<inputVertex>, vector<Edge>);

    /// @brief start of public function

    public:
    ////////////////////////////
    // constructor //
    Graph_directed();

    /**
     * initilize the whole graph with node and edge as input
     * 
     * @param vertex_file input of vertex_file, this should be csv
     * @param edge_file input of edge_file, should be csv
    */
    Graph_directed(const std::string & vertex_file, const std::string & edge_file);

    ////////////////////////////
    // function //
    /**
     * @param int the id of the air port
     * @return vector<string> the vector of string containing the air port name and its neighbor
    */
    vector<pair<string, double>> get_neighbors(const string& id) const;

    /**
     * @param id the id of the air port
     * @param i the ith' closest of the air port
     * @return vector<string> the vector of string containing the air port name and its neighbor
    */
    pair<string, double> get_ith_closest_neighbor(const string& id,const unsigned i) const;

    /**
     * @param int the id of the air port
     * @return number of neighbors airfield this airfield have
    */
    unsigned get_num_of_neighbors(const string& id) const;

    vector<string> getAll_airfield() const;
};