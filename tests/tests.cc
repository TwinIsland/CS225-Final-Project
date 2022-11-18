#include "catch.hpp"
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
using 


TEST_CASE("test1") {
    REQUIRE(true == true);
}

TEST_CASE("readfile and map construct") {
    vector<inputVertex> i_node;
    vector<Edge> i_edge;
    string n_string = file_to_string("../data/vertex.csv");
    string e_string = file_to_string("../data/edge.csv");

    vector<string> line_node;
    SplitString(n_string, '\n', line_node);
    vector<string> line_edge;
    SplitString(n_string, '\n', line_edge);

    for (string s : line_node) {
        inputVertex iv();
        SplitString(s, '\n', iv);
        i_node.push_back(iv);
    }
    for (string s : line_edge) {
        inputVertex ivfrom;
        inputVertex ivto;
        vector<string> temp;
        SplitString(s, '\n', temp);
        ivfrom.push_back(temp[0]);
        ivto.push_back(temp[1]);
        double = std::stod(temp[2]);
        Edge edge__;
        edge__.from = ivfrom;
        edge__.to = ivto;
        edge__.weight = 0;
        i_edge.push_back(edge__);
    }

    Graph_directed(i_node,i_edge);

}