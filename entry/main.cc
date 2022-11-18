#include "solution.hpp"

#include "include.hpp"
#include "graph.h"
#include "utils.h"

using std::string;
using std::set;
using std::vector;
using std::pair;
using std::list;
using std::cout;
using std::endl;

int main(){
    Graph_directed g("./data/vertex.csv" , "./data/edge.csv");
    for (string s : g.nodes) {
        Graph_directed::Vertex v = g.getVertex(s);
        cout << v.name_ << endl;
        for (pair<string,double> p : v.neighors_) {
            cout << "neighbor: " << p.first << " weight: " << p.second << " ";
        }
        cout << endl;
    }

    return 0;
}