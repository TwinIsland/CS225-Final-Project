#include "graph.h"
#include "utils.h"
#include "image.h"
#include "heatmap.h"

using std::string;
using std::set;
using std::vector;
using std::pair;
using std::list;
using std::cout;
using std::endl;

int main(){
    // Graph_directed g("./data/vertex_sm.csv" , "./data/edge_sm.csv");
    Graph_directed g("./data/vertex.csv" , "./data/edge.csv", "./bc_whole_data.csv");

    // for (string s : g.getAll_airfield()) {
    //     cout << "name: " << s << endl;
        
    //     cout << "num_of_neighbors: " << g.get_num_of_neighbors(s) << endl;
    //     // if(g.get_num_of_neighbors(s) > 10000) {
    //     //     break;
    //     // }
    //     if (g.get_num_of_neighbors(s) == 0) {
    //         cout << endl;
    //         continue;
    //     }
    //     for (pair<string,double> p : g.get_neighbors(s)) {
    //         cout << "neighbor: " << p.first << " weight: " << p.second << " ";
    //     }
    //     cout << "0th clothest neighbor " << g.get_ith_closest_neighbor(s, 0).first << endl;
    //     cout << endl;
    // }
    // string airport = "CMI";
    // cout << airport << " as departure: " << g.get_num_of_neighbors(airport) << endl;
    // cout << airport << " as dest: " << g.get_num_as_dest(airport) << endl;

    // string airport1 = "DME";
    // string airport2 = "UUA";

    // shortestPathTable sp_table = g.gen_shortest_path_table();
    
    // std::vector<string> shortest_path = g.get_shortest_path(sp_table, airport1, airport2);
    // double shortest_path_weight = g.get_shortest_weight(sp_table, airport1, airport2);

    // cout << "Shortest path from: " << airport1 << " to " << airport2 << " is: ";
    // cout << airport1 << " -> ";
    // for (auto i : shortest_path) {
    //     if (i == shortest_path.back())
    //         cout << i;
    //     else
    //         cout << i << " -> ";
    // }
    // cout << " with weight: " << shortest_path_weight << endl;
    // g.UpdateBC();
    // for (auto i : g.getAll_vertex()) {
    //     cout << i << " has bc weight: " <<g.get_bc(i) << endl;
    // }
    // g.dump_bc_to_csv("result.csv");
    // testing print canvas image
    
    Image image; 
    image.readFromFile("small_canvas.png");
    HeatMap map(image, g); 
    map.render().writeToFile("output.PNG");
    // return 0;
}
