#pragma once

#include "image.h"
#include "graph.h"
#include "utils.h"


// (Graph graph)
// getAllVertex() -> std::vector<std::string>   string = vertex
// g.get_bc(std::string vertex_id) -> double weight
// 

class HeatMap {
    public:
        /**
         * @brief Construct a new Heat Map object
         * 
         * @param picture takes an image in as the base of the map
         * @param graph takes in a constructed graph
         */
        HeatMap(const Image &picture, Graph_directed graph);

        /**
         * @brief find the max and min centraility of the graph as bounds for future color mapping
         * 
         * @param graph takes in constructed graph
         */
        void findMinMaxCentrality(Graph_directed graph);

        void convertToPixelLocation(std::vector<std::string> vertexs);

        void weightColorConvert(Graph_directed graph);


        /**
         * @brief render the final heat map to image format
         * 
         * @return heat map in image format
         */
        Image render() const;

        /**
         * @brief release the memory for the base image, and clear
         * all the in-used vectors
         * 
         */
        ~HeatMap(); 
        
    private:
        Image* base_;
        int pic_width_;
        int pic_height_;
        double min_centrality_;
        double max_centrality_;
        std::vector<std::string> all_string_tags_;
        std::vector<HSLAPixel&> hsla_colors_;
        std::vector<std::pair<unsigned, unsigned>> locations_;
};