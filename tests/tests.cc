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
Graph_directed graph ("./data/vertex.csv" , "./data/edge.csv");

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

TEST_CASE("stupid test") {
    REQUIRE(true == true);
}
