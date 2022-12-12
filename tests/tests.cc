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

TEST_CASE("constructor") {
    std::vector<string> all_n = graph.getAll_vertex();

    REQUIRE(all_n.size() == 4);
}

TEST_CASE("bfs") {
    std::vector<string> a = graph.bfs_one_component("A");

    REQUIRE(a.size() == 4);

    std::vector<string> b = graph.bfs_one_component("B");

    REQUIRE(b.size() == 3);

    std::vector<string> c = graph.bfs_one_component("C");

    REQUIRE(c.size() == 2);

    std::vector<string> d = graph.bfs_one_component("D");

    REQUIRE(d.size() == 2);
}



TEST_CASE("shortest path table test") {
    std::vector<string> path1;
    // make the path
    path1.push_back("B");
    path1.push_back("C");
    
    auto spt = graph.gen_shortest_path_table();

    auto out = graph.get_shortest_path(spt, "A", "C");
    double out2 = graph.get_shortest_weight(spt, "A", "C");

    REQUIRE(out == path1);
    REQUIRE(out2 - 0.3 < 0.01);
}

TEST_CASE("shortest path table test3") {
    std::vector<string> path1;
    // make the path
    path1.push_back("B");
    
//     auto out = graph.gen_shortest_path_table();

    REQUIRE(out["A"]["B"].first == path1);
    REQUIRE(out["A"]["B"].second == 0.1);
}

TEST_CASE("weightColorConvert") {
    const double kRedHSLA = 0; // hsl = 0, 100, 50
    const double kYellowHSLA = 60; // hsl = 60, 100, 50
    const double kGreenHSLA = 120; // hsl = 120, 100, 50

    std::vector<double> centrality_vect {4.0, 2.0, 1.0};
    std::sort(centrality_vect.begin(), centrality_vect.end());

    int greenPivotIdx = centrality_vect.size() / 3;
    double greenPivotCent = centrality_vect.at(greenPivotIdx);

    int yellowPivotIdx = (centrality_vect.size() / 3) * 2;
    double yellowPivotCent = centrality_vect.at(yellowPivotIdx);

    std::vector<HSLAPixel> hsla_colors;
    for (size_t idx = 0; idx < 3; idx++) {
        double curr_centrality = centrality_vect.at(idx);
        HSLAPixel hsla;
        if (curr_centrality <= greenPivotCent) { // green
            hsla.h = kGreenHSLA;
        } else if (curr_centrality > greenPivotCent && curr_centrality <= yellowPivotCent) { // yellow
            hsla.h = kYellowHSLA;
        } else { // red
            hsla.h = kRedHSLA;
        }
        hsla.s = 1;
        hsla.l = 0.5;
        hsla_colors.push_back(hsla);
    }
    REQUIRE(hsla_colors.at(0).h == 120);
    REQUIRE(hsla_colors.at(1).h == 120);
    REQUIRE(hsla_colors.at(2).h == 0);
}
