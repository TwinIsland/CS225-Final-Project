#include "graph.h"



Graph_directed::Graph_directed(vector<inputVertex> input_node, vector<Edge> input_edge) {

}

/**
 * should inset the element in the ascending order;
*/
void Graph_directed::insert_in_order(vector<pair<Vertex, double>>& toinsert, pair<Vertex, double> data) {
    //
    toinsert.insert(
        // upper bound and lower bound have no influence
        std::upper_bound(toinsert.begin(), toinsert.end(), data, sortbysec),
        data
    );
}

Graph_directed::Vertex Graph_directed::getVertex(int& id) {
    Vertex temp;
    temp.name_ = id;
    // have not found better way to do this
    auto it = all_node.find(temp);
    if (it != all_node.end()) return *it;
    return Vertex();
}

