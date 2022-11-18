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
    for (string s : g.getAll_airfield()) {
        cout << "name: " << s << endl;
        for (pair<string,double> p : g.get_neighbors(s)) {
            cout << "neighbor: " << p.first << " weight: " << p.second << " ";
        }
        cout << endl;
    }

    return 0;
}