#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  tolerance_ = 0.0;
}

ImageTraversal::Iterator::Iterator(ImageTraversal* traversal, Point &start, double tolerance, PNG & png)
{
  t = traversal;
  start_ = start;
  tolerance_ = tolerance;
  png_ = png;
  cur = t->peek();
  int total = png_.width()*png_.height();
  visited = std::vector<bool>(total, false);

}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  // return *this;
  if(!t->empty()){
    HSLAPixel start = png_.getPixel(start_.x, start_.y);
    cur = t->pop();

    int index = cur.x+cur.y*png_.width();
    visited[index]=true;
    Point right, below, left, above;
    right = Point(cur.x+1, cur.y);
    below = Point(cur.x, cur.y+1);
    left = Point(cur.x-1,cur.y);
    above = Point(cur.x, cur.y-1);

    //right
    //0<=right.x && right.x<image_.width() && 0<=right.y && right.y<image_.height()
    if(right.x<png_.width()){
      HSLAPixel curr = png_.getPixel(right.x, right.y);
      if(calculateDelta(start, curr) < tolerance_ && visited[right.x+right.y*png_.width()] == false){
          t->add(right);
      }
    }

    //below
    if(below.y<png_.height()){
      HSLAPixel curr = png_.getPixel(below.x, below.y);
      if(calculateDelta(start, curr) < tolerance_ && visited[below.x+below.y*png_.width()] == false){
          t->add(below);
      }
    }

    //left
    if(left.x<png_.width()){
      HSLAPixel curr = png_.getPixel(left.x, left.y);
      if(calculateDelta(start, curr) < tolerance_ && visited[left.x+left.y*png_.width()] == false){
          t->add(left);
      }
    }

    //above
    if(above.y<png_.height() ){
      HSLAPixel curr = png_.getPixel(above.x, above.y);
      if(calculateDelta(start, curr) < tolerance_ && visited[above.x+above.y*png_.width()] == false){
          t->add(above);
      }
    }
    
    cur = t->peek();
    while(!t->empty() && visited[cur.x+cur.y*png_.width()] ){
      t->pop();
      if(!t->empty()){
        cur = t->peek();
      }
    }
} 
    return *this;
 
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  // return Point(0, 0);
  return cur;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */

  //from the lab_tree
  bool thisEmpty = false;
  bool otherEmpty = false;

  if (t == NULL) { thisEmpty = true; }
  if (other.t == NULL) { otherEmpty = true; }

  if (!thisEmpty)  { thisEmpty = t->empty(); }
  if (!otherEmpty) { otherEmpty = other.t->empty(); }

  if (thisEmpty && otherEmpty) return false; 
  else if ((!thisEmpty)&&(!otherEmpty)) return (t != other.t); 
  else return true; 
}

