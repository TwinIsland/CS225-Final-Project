#include "HeatMap.h"
#include <cassert>
#include <iostream>

using namespace cs225;


HeatMap::HeatMap (const Image &picture) {
    pic_width_ = picture.width();
    pic_height_ = picture.height();
    base_ = new Image(pic_width_, pic_height_);
    for (int width = 0; width < pic_width_; width++) {
        for (int height = 0; height < pic_height_; height++) {
            base_->getPixel(width, height) = picture.getPixel(width, height);
        }
    }
}

HeatMap::~HeatMap () {
    // reset all the variables
    if (base_ != nullptr) {
        delete base_;
        base_ = nullptr;
    }
    locations_.clear();
}

Image HeatMap::render () const {
    // create a blank canvas
    int result_width = pic_width_;
    int result_height = pic_height_;
    Image result (result_width, result_height);

    // draw the base image first
    // for (size_t width = 0; width < base_->width(); width++) {
    //     for (size_t height = 0; height < base_->height(); height++) {
    //         // copy base image's pixels
    //         result.getPixel(width, height) = base_->getPixel(width, height);
    //     }
    // }

    for (size_t width = 0; width < base_->width(); width++) {
        for (size_t height = 0; height < base_->height(); height++) {
            // copy base image's pixels
            result.getPixel(width, height).h = 0;
            result.getPixel(width, height).s = 1;
            result.getPixel(width, height).l = 0.5;
        }
    }
    return result;
}