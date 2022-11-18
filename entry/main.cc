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
        
        cout << "num_of_neighbors: " << g.get_num_of_neighbors(s) << endl;
        // if(g.get_num_of_neighbors(s) > 10000) {
        //     break;
        // }
        for (pair<string,double> p : g.get_neighbors(s)) {
            cout << "neighbor: " << p.first << " weight: " << p.second << " ";
        }
        cout << "0th clothest neighbor " << g.get_ith_closest_neighbor(s, 0).first << endl;
        cout << endl;
    }

    return 0;
}