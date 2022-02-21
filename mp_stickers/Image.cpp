#include "Image.h"
// Image::Image(){}
// Image::Image(unsigned int width, unsigned int height) : PNG(width,height){}

void Image::lighten(){
    for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);

      double after = pixel.l + 0.1;
      if (after <= 1 )
      {
          pixel.l += 0.1;
      } else {
          pixel.l = 1;
      }
    }
  }
}

void Image::lighten(double amount){
    for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      double after = pixel.l + amount;
      if (after <= 1 )
      {
          pixel.l +=amount;
      } else {
          pixel.l = 1;
      }
    }
  }
}

void Image::darken(){
    for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      double after = pixel.l - 0.1;
      if (after >= 0 )
      {
          pixel.l = after;
      } else {
          pixel.l = 0;
      }
    }
  }
}

void Image::darken(double amount){
    for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      double after = pixel.l - amount;
      if (after >= 0 )
      {
          pixel.l = after;
      } else {
          pixel.l = 0;
      }
    }
  }
}

void Image::saturate(){
    for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      double after = pixel.s + 0.1;
      if (after <= 1 )
      {
          pixel.s = after;
      } else {
          pixel.s = 1;
      }
    }
  }
}

void Image::saturate(double amount){
    for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      double after = pixel.s + amount;
      if (after <= 1 )
      {
          pixel.s = after;
      } else {
          pixel.s = 1;
      }
    }
  }
}

void Image::desaturate(){
    for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      double after = pixel.s - 0.1;
      if (after >= 0 )
      {
          pixel.s = after;
      } else {
          pixel.s = 0;
      }
    }
  }
}

void Image::desaturate(double amount){
    for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      double after = pixel.s - amount;
      if (after >= 0 )
      {
          pixel.s = after;
      } else {
          pixel.s = 0;
      }
    }
  }
}

void Image::grayscale(){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      pixel.s = 0;
    }
  }
}

void Image::rotateColor(double degrees){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      int after = pixel.h + degrees;

      if (after <= 360 && after >=0) {
        pixel.h = after;
      } else if (after <= 0) {
        pixel.h = after % 360 + 360;
      } else {
        pixel.h = after % 360;
      }
    }
  }
}

void Image::illinify(){
  int illiniOrange = 11;
  int illiniBlue = 216;
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      int diff1 = abs(pixel.h - illiniBlue);
      if (diff1 >= 180) {
        diff1 = 360 - diff1;
      }
      int diff2 = abs(pixel.h - illiniOrange);
      if (diff2 >= 180) {
        diff2 = 360 - diff2;
      }
      if (diff1 >= diff2) {
        pixel.h = 11;
      } else {
        pixel.h = 216;
      }
    }
  }
}

void Image::scale(double factor){

    PNG temp = *this;
    unsigned int originalWidth = temp.width();
    unsigned int originalHeight = temp.height();
    unsigned int newWidth = factor * originalWidth;
    unsigned int newHeight = factor * originalHeight;
    this->resize(newWidth, newHeight);
    for (unsigned x = 0; x < originalWidth; x++) {
        for (unsigned y = 0; y < originalHeight; y++) {
            cs225::HSLAPixel & originalPixel = temp.getPixel(x, y);
            for (unsigned i = x*factor; i < (x+1)*factor; i++) {
                for (unsigned j = y*factor; j < (y+1)*factor; j++) {
                    cs225::HSLAPixel & newPixel = this->getPixel(i, j);
                    newPixel = originalPixel;
                }
            }
        }
    }

}
void Image::scale(unsigned w, unsigned h){

    PNG temp = *this;
    unsigned int originalWidth = temp.width();
    unsigned int originalHeight = temp.height();
    double factor1 = w / originalWidth;
    double factor2 = h / originalHeight;
    double factor;
    if (factor1 >= factor2) {
      factor = factor2;
    } else {
      factor = factor1;
    }
    unsigned int newWidth = factor * originalWidth;
    unsigned int newHeight = factor * originalHeight;
    this->resize(newWidth, newHeight);
    for (unsigned x = 0; x < originalWidth; x++) {
        for (unsigned y = 0; y < originalHeight; y++) {
            cs225::HSLAPixel & originalPixel = temp.getPixel(x, y);
            for (unsigned i = x*factor; i < (x+1)*factor; i++) {
                for (unsigned j = y*factor; j < (y+1)*factor; j++) {
                    cs225::HSLAPixel & newPixel = this->getPixel(i, j);
                    newPixel = originalPixel;
                }
            }
        }
    }
}