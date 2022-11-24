#pragma once
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "utils.h"

using namespace cs225;

class Image: public PNG {
    public: 
        Image();
        Image(unsigned int width, unsigned int height);
        Image(Image const & other);
};