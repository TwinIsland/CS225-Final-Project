#include "HeatMap.h"
#include <limits>
#include <cassert>

using namespace cs225;


HeatMap::HeatMap (const Image &picture, Graph_directed graph) {
    // deep copy the base image
    pic_width_ = picture.width();
    pic_height_ = picture.height();
    base_ = new Image(pic_width_, pic_height_);
    for (int width = 0; width < pic_width_; width++) {
        for (int height = 0; height < pic_height_; height++) {
            base_->getPixel(width, height) = picture.getPixel(width, height);
        }
    }

    // construct all_string_tags_ vect
    std::vector<std::string> all_string_tags = graph.getAll_vertex();
    for (auto& string_tag : all_string_tags) {
        all_string_tags_.push_back(string_tag);
    }

    // find the max and min weight of this graph
    findMinMaxCentrality(graph);
    weightColorConvert(graph);
    // convertToPixelLocation();
}

void HeatMap::findMinMaxCentrality(Graph_directed graph) {
    max_centrality_ = std::numeric_limits<double>::lowest();
    min_centrality_ = std::numeric_limits<double>::max();

    for (auto& string_tag : all_string_tags_) {
        double curr_centrality = graph.get_bc(string_tag);
        if (max_centrality_ < curr_centrality) {
            max_centrality_ = curr_centrality;
        }

        if (min_centrality_ > curr_centrality) {
            min_centrality_ = curr_centrality;
        }
    }
}

void HeatMap::weightColorConvert(Graph_directed graph) {
    const double kRedHSLA = 0; // hsl = 0, 100, 50
    const double kGreenHSLA = 120; // hsl = 120, 100, 50

    double numerator = kRedHSLA - kGreenHSLA;
    double denominator = max_centrality_ - min_centrality_;

    for (auto& string_tag : all_string_tags_) {
        double curr_centrality = graph.get_bc(string_tag);
        HSLAPixel hsla;
        // double slope = (numerator / denominator) * x + kGreenHSLA;
        hsla.h = (numerator / denominator) * curr_centrality + kGreenHSLA;
        hsla.s = 1;
        hsla.l = 0.5;
        hsla_colors_.push_back(hsla);
    }
}

void HeatMap::convertToPixelLocation(std::vector<std::string> vertexs) {

}

Image HeatMap::render () const {
    // create a blank canvas
    int result_width = pic_width_;
    int result_height = pic_height_;
    Image result (result_width, result_height);

    // draw the base image first
    for (size_t width = 0; width < base_->width(); width++) {
        for (size_t height = 0; height < base_->height(); height++) {
            // copy base image's pixels
            result.getPixel(width, height) = base_->getPixel(width, height);
        }
    }
    return result;
}

HeatMap::~HeatMap () {
    // reset all the variables
    if (base_ != nullptr) {
        delete base_;
        base_ = nullptr;
    }
    all_string_tags_.clear();
    hsla_colors_.clear();
    locations_.clear();
}