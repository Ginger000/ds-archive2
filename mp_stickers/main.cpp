#include "Image.h"
#include "StickerSheet.h"

int main() {
   
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  //StickerSheet (const Image &picture, unsigned max);
  Image alien;
  alien.readFromFile("alien.png");
  alien.scale(4);
  Image cat1;
  cat1.readFromFile("shockCat_1.png");
  Image cat2;
  cat2.readFromFile("shockCat_2.png");
  Image cat3;
  cat3.readFromFile("shockCat_3.png");
  Image cat4;
  cat4.readFromFile("shockCat_4.png");
  StickerSheet sheet(alien, 6);
  // sheet.addSticker(cat1, 0, 0);
  sheet.addSticker(cat1, 1500, 30);
  sheet.addSticker(cat2, 20, 50);
  sheet.addSticker(cat3, 400, 600);
  sheet.addSticker(cat4, 100, 900);
  Image myImage = sheet.render();
  myImage.writeToFile("myImage.png");
  
  return 0;
}
