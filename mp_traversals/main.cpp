
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  
  
  PNG png;
  MyColorPicker mp (.25);
  RainbowColorPicker rp (.15);

  png.readFromFile("tests/pacman.png");

  FloodFilledImage flood (png);
  BFS bfs (png, Point(30, 25), 0.5);

  flood.addFloodFill(bfs, mp);

  Animation anima = flood.animate(100);
  PNG frame = animation.getFrame( animation.frameCount() - 50 );

  frame.writeToFile("myFloodFill.png");
  anima.write("myFloodFill.gif");
  return 0;
}
