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
         */
        HeatMap(const Image &picture);

        void convertToPixelLocation(std::vector<std::string> vertexs);

        /**
         * @brief based on the max and min weight of the data, dynamically map the 
         *  weight of each airport to the color ranges (green to red)
         * 
         * @param vertex 
         * @return HSLAPixel mapping for current inputVertex 
         */
        HSLAPixel weightColorMapping(inputVertex vertex);

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
        std::vector<std::pair<unsigned, unsigned>> locations_;
};