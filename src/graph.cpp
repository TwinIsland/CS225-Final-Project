#include "graph.h"



Graph_directed::Graph_directed(vector<inputVertex> input_node, vector<Edge> input_edge) {
    for (inputVertex v : input_node) {
        Vertex topush;
        topush.name_ = v[0];
        graph.insert(pair<string, Vertex>(v[0], topush)); //initilize graph
        nodes.push_back(v[0]); // pushed all nodes
    }
    // all nodes inserted
    for (Edge e : input_edge) {
        string from_id = e.from[0];
        string to_id = e.to[0];
        double weight = e.weight;
        // all three data fetched
        insert_in_order(graph[from_id].neighors_, pair<string, double>(to_id, weight));
    }
}

/**
 * should inset the element in the ascending order;
*/
void Graph_directed::insert_in_order(vector<pair<string, double>>& toinsert, pair<string, double> data) {
    //
    toinsert.insert(
        // upper bound and lower bound have no influence
        std::upper_bound(toinsert.begin(), toinsert.end(), data, sortbysec),
        data
    );
}

Graph_directed::Vertex Graph_directed::getVertex(string& id) {
    return graph[id];
}

