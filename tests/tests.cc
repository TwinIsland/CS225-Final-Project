#include "catch.hpp"
#include "../includes/graph.h"
#include "../includes/utils.h"
#include "../includes/image.h"
#include "../includes/HeatMap.h"

using std::string;
using std::set;
using std::vector;
using std::pair;
using std::list;
using std::cout;
using std::endl;

// global object graph (save runtime)
Graph_directed graph ("./data/test_g_v_1.csv" , "./data/test_g_e_1.csv");

void print_neighbors(std::vector<std::pair<std::string, double>> neighbors) {
    for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
        std::cout << it->first << " ";
    }
}

// TEST_CASE("# neighbors on exists") {
//     std::vector<std::pair<std::string, double>> neighbors = graph.get_neighbors("POR");
//     REQUIRE(neighbors.size() == 3);

//     neighbors = graph.get_neighbors("YQQ");
//     REQUIRE(neighbors.size() == 4);
//     print_neighbors(neighbors);

//     neighbors = graph.get_neighbors("NBC");
//     REQUIRE(neighbors.size() == 7);
// }

// TEST_CASE("# neighbors on non_exist") {
//     std::vector<std::pair<std::string, double>> neighbors = graph.get_neighbors("HZK");
//     REQUIRE(neighbors.size() == 0);

//     neighbors = graph.get_neighbors("AAA");
//     REQUIRE(neighbors.size() == 0);
// }

TEST_CASE("shortest path table test") {
    std::vector<string> path1;
    // make the path
    path1.push_back("a");
    path1.push_back("b");
    path1.push_back("c");
    
    auto out = graph.gen_shortest_path_table();

    REQUIRE(out["a"]["b"].first == path1);
    REQUIRE(out["a"]["b"].second == 0.3);
}

TEST_CASE("shortest path table test2") {
    std::vector<string> path1;
    // make the path
    path1.push_back("d");
    path1.push_back("c");
    
    auto out = graph.gen_shortest_path_table();

    REQUIRE(out["d"]["c"].first == path1);
    REQUIRE(out["a"]["b"].second == 0.5);
}

TEST_CASE("shortest path table test3") {
    std::vector<string> path1;
    // make the path
    path1.push_back("a");
    path1.push_back("b");
    
    auto out = graph.gen_shortest_path_table();

    REQUIRE(out["a"]["b"].first == path1);
    REQUIRE(out["a"]["b"].second == 0.1);
}
