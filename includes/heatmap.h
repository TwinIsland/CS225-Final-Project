#pragma once

#include "image.h"
#include "graph.h"
#include "utils.h"
#include <cmath>
#include <algorithm>


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

        void weightColorConvert(Graph_directed graph);

        void convertToPixelLocation(Graph_directed graph);


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
        std::vector<std::string> all_string_tags_;
        std::vector<HSLAPixel> hsla_colors_;
        std::vector<std::pair<double, double>> locations_;
};