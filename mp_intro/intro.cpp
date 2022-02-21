#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>

using cs225::HSLAPixel;
using cs225::PNG;

void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  cs225::PNG png1, png2;
  png1.readFromFile(inputFile);
  unsigned int rowNum = png1.width();
  unsigned int colNum = png1.height();
  png2.readFromFile(inputFile);
  //HSLAPixel pixelArray = [rowNum][colNum];
  for (unsigned i = 0; i < rowNum; i++) {
    for (unsigned j = 0; j < colNum; j++) {
      //HSLAPixel & pixel1 = png1.getPixel(i, j);
      HSLAPixel & pixel2 = png2.getPixel(i, j);
      pixel2 = png1.getPixel(rowNum-1-i, colNum-1-j);
    }
  }
  // HSLAPixel pixelArrayCopy = PNG(PNG const & pixelArray); 
  // for (unsigned i = 0; i < rowNum; i++) {
  //   for (unsigned j = 0; j < colNum; j++) {
  //     pixelArrayCopy[i][j] = pixelArray[rowNum - i][colNum - j];
  //   }
  // }
  
  png2.writeToFile(outputFile);
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  for (unsigned x = 540; x < 700; x++) {
    for (unsigned y = 260; y < 540; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = 178;
      pixel.s = 0.31;
      pixel.l = 0.52;
    }
  }
  for (unsigned x = 540; x < 800; x++) {
    for (unsigned y = 0; y < 240; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = 0;
      pixel.s = 0.33;
      pixel.l = 0.96;
    }
  }
  for (unsigned x = 0; x < 540; x++) {
    for (unsigned y = 540; y < 800; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = 170;
      pixel.s = 0.34;
      pixel.l = 0.73;
    }
  }
  for (unsigned x = 720; x < 800; x++) {
    for (unsigned y = 640; y < 800; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = 22;
      pixel.s = 0.91;
      pixel.l = 0.48;
    }
  }
  for (unsigned x = 540; x < 720; x++) {
    for (unsigned y = 540; y < 800; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = 0;
      pixel.s = 0.33;
      pixel.l = 0.96;
    }
  }
  for (unsigned x = 720; x < 800; x++) {
    for (unsigned y = 540; y < 620; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = 0;
      pixel.s = 0.33;
      pixel.l = 0.96;
    }
  }
  for (unsigned x = 520; x < 540; x++) {
    for (unsigned y = 0; y < height; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.l = 0;
    }
  }
  for (unsigned x = 0; x < width; x++) {
    for (unsigned y = 520; y < 540; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.l = 0;
    }
  }


  for (unsigned x = 0; x < 520; x++) {
    for (unsigned y = 0; y < 520; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = 22;
      pixel.s = 0.91;
      pixel.l = 0.48;
    }
  }

  for (unsigned x = 720; x < 800; x++) {
    for (unsigned y = 260; y < 520; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = 216;
      pixel.s = 63;
      pixel.l = 36;
    }
  }

  

  for (unsigned x = 700; x < 720; x++) {
    for (unsigned y = 240; y < 800; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.l = 0;
    }
  }

  for (unsigned x = 720; x < 800; x++) {
    for (unsigned y = 620; y < 640; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.l = 0;
    }
  }

  for (unsigned x = 540; x < 800; x++) {
    for (unsigned y = 240; y < 260; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.l = 0;
    }
  }

  

  

  return png;
}
