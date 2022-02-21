/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */

    // return NULL;
    int rows=theSource.getRows();
     int cols=theSource.getColumns();
     MosaicCanvas* result=new MosaicCanvas(rows,cols);
     vector<Point<3>> temp;
     temp.resize(theTiles.size());
     std::map<Point<3>, size_t> map;
     
     for(unsigned i=0;i<theTiles.size();i++){
      LUVAPixel tilePixel=theTiles[i].getAverageColor();
      Point<3> tilePoint=convertToXYZ(tilePixel);
      temp[i]=tilePoint;
      map.insert(std::pair<Point<3>,size_t>(tilePoint,i));
     }
     KDTree<3> TheKDTree=KDTree<3>(temp);
     for(int x=0;x<rows;x++){
       for(int y=0;y<cols;y++){
         LUVAPixel pixel=theSource.getRegionColor(x,y);
         Point<3> source=convertToXYZ(pixel);
         Point<3> resultPoint=TheKDTree.findNearestNeighbor(source);
         size_t index=map[resultPoint];
         result->setTile(x,y,&theTiles[index]);
       }
     }
     return result;
}

