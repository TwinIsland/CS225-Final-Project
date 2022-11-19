#include "graph.h"
#include "utils.h"


/////////////////////////////////
// constructor //
/////////////////
void Graph_directed::create_helper(vector<inputVertex> input_node, vector<Edge> input_edge) {
    for (inputVertex v : input_node) {
        Vertex topush;
        topush.name_ = v[0];
        topush.other_data = v;
        graph.insert(pair<string, Vertex>(v[0], topush)); //initilize graph
        nodes.push_back(v[0]); // pushed all nodes
    }
    // all nodes inserted
    for (Edge e : input_edge) {
        string from_id = e.from[0];
        string to_id = e.to[0];
        double weight = e.weight;
        // all three data fetched
        insert_in_order(graph[from_id].neighbors_, pair<string, double>(to_id, weight));
        graph[from_id].num_of_neighbor++;
        graph[to_id].num_as_dest++;
    }
}

Graph_directed::Graph_directed(const std::string & vertex_file, const std::string & edge_file) {
    vector<inputVertex> i_node;
    vector<Edge> i_edge;
    string n_string = file_to_string(vertex_file);
    string e_string = file_to_string(edge_file);

    vector<string> line_node;
    SplitString(n_string, '\n', line_node);
    vector<string> line_edge;
    SplitString(e_string, '\n', line_edge);

    for (string s : line_node) {
        inputVertex iv;
        SplitString(s, ',', iv);
        if (iv[0].empty()) continue; // empty input
        i_node.push_back(iv);
    }
    for (string s : line_edge) {
        inputVertex ivfrom;
        inputVertex ivto;
        vector<string> temp;
        SplitString(s, ',', temp);
        if (temp.size() <= 2) {
            // invalid line
            continue;
        }
        ivfrom.push_back(temp[0]);
        ivto.push_back(temp[1]);
        double wei = std::stod(temp[2]);
        Edge edge__;
        edge__.from = ivfrom;
        edge__.to = ivto;
        edge__.weight = wei;
        i_edge.push_back(edge__);
    }
    create_helper(i_node,i_edge);
}


///////////////////////////////////////
// function  private //

/**
 * should insert the element in the ascending order;
*/
void Graph_directed::insert_in_order(vector<pair<string, double>>& toinsert, pair<string, double> data) {
    //
    toinsert.insert(
        // upper bound and lower bound have no influence
        std::upper_bound(toinsert.begin(), toinsert.end(), data, sortbysec),
        data
    );
}



///////////////////////////////////////
// function  public //

vector<pair<string, double>> Graph_directed::get_neighbors(const string& id) const {
    return graph.at(id).neighbors_;
     
}

pair<string, double> Graph_directed::get_ith_closest_neighbor(const string& id,const unsigned i) const {
    if (i >= graph.at(id).num_of_neighbor) return pair<string, double>("not exist", -1);
    return graph.at(id).neighbors_[i];
}

unsigned Graph_directed::get_num_of_neighbors(const string& id) const {
        return graph.at(id).num_of_neighbor;
}

vector<string> Graph_directed::getAll_vertex() const {
    return nodes;
}

vector<string> Graph_directed::bfs_one_component(const string& id) const {
    queue<string> qu;
    
}