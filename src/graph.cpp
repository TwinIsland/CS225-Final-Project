#include "graph.h"



Graph_directed::Graph_directed(vector<inputVertex> input_node, vector<Edge> input_edge) {
    for (inputVertex v : input_node) {
        Vertex topush;
        topush.name_ = std::stoi(v[0]);
        all_node.insert(topush);
    }
    // all nodes inserted
    for (Edge e : input_edge) {
        int from_id = std::stoi(e.from[0]);
        int to_id = std::stoi(e.to[0]);
        double weight = e.weight;
        // all three data fetched
        auto it_from = getVertex_it(from_id);
        Vertex updated = *it_from;
        all_node.erase(it_from);
        insert_in_order(updated.neighors_, pair<int,double>(to_id, weight));
        all_node.insert(updated);
    }
}

/**
 * should inset the element in the ascending order;
*/
void Graph_directed::insert_in_order(vector<pair<int, double>>& toinsert, pair<int, double> data) {
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

