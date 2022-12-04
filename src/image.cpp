#include "image.h"

Image::Image(): PNG::PNG() {}

Image::Image(unsigned int width, unsigned int height): PNG::PNG(width, height) {}

Image::Image(Image const & other): PNG::PNG(other) {}