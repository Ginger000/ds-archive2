#include "StickerSheet.h"
#include "Image.h"
#include <algorithm>
using namespace std; 


StickerSheet::StickerSheet	(const Image & picture, unsigned max) {
    base_ = new Image(picture);
    max_ = max;
}

StickerSheet::~StickerSheet (){
    delete base_;
    delete sheet_;
}

StickerSheet::StickerSheet (const StickerSheet &other){
    sheet_ = new StickerSheet(other);
    this->stickers = other.stickers;
    *base_ = *(other.base_);
    
}

const StickerSheet & StickerSheet::operator= (const StickerSheet &other){
    delete base_;
    sheet_ = new StickerSheet(other);
    this->stickers = other.stickers;
    *base_ = *(other.base_);
    return *this;
}

int StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y){
    int oldLayer = stickers.size() - 1;
    Image* sticker_ = new Image(sticker);
    //Image* sticker_ = &sticker;

    //stickers.push_back(std::make_tuple<sticker_, x, y>);
    auto object = std::make_tuple(sticker_, x, y);
    stickers.push_back(object);
    int newLayer = stickers.size() - 1;
    if (newLayer == oldLayer)
    {
        return -1;
    } else {
        return newLayer;
    }
}

//vector
//size, capacity, max_size, resize
void StickerSheet::changeMaxStickers (unsigned max){ 
    if(max < max_) {
        // for (int i = max, i < max_ ; i++) {
        //     delete get<0>(stickers[i]);
        // }
        this->stickers.resize(max);
        max_ = max;       
        
    } else {
        max_ = max;
    }   
}

Image * StickerSheet::getSticker (unsigned index){
    return get<0>(stickers[index]);
}

//How the pointer of img to use png descructor?
//when to call destructor?
//how to polymophsim dectructor
void StickerSheet::removeSticker (unsigned index){
    delete get<0>(stickers[index]);
}

Image StickerSheet::render () const{
    //find the largest x,y of stickers
    //decide whether to extra transparent space if there is sticker outside base.
    std::vector<int> xCoordinates;
    std::vector<int> yCoordinates;
    for(unsigned int i = 0; i < stickers.size(); i++) {
        if (get<0>(stickers[i]) != nullptr) {
            xCoordinates.push_back(get<1>(stickers[i]) + get<0>(stickers[i])->width());
            yCoordinates.push_back(get<2>(stickers[i]) + get<0>(stickers[i])->height());

        }
    }
    unsigned int maxX = *std::max_element(xCoordinates.begin(), xCoordinates.end());
    unsigned int maxY = *std::max_element(xCoordinates.begin(), xCoordinates.end());
    unsigned int finalWidth;
    unsigned int finalHeight;
    if (maxX > base_->width())
    {
        finalWidth = maxX;
    } else { 
        finalWidth = base_->width();
    }

    if (maxY > base_->height())
    {
        finalHeight = maxY;
    } else { 
        finalHeight = base_->height();
    }
    //draw a transparent layer & draw base layer
    //use constructor in parent class cs225::PNG
    //cs225::PNG myTransparentBase(finalWidth,finalHeight);
    // Image myTransparentBase = cs225::PNG::PNG(finalWidth,finalHeight);
    // Image* myTransparentBase = new Image(finalWidth,finalHeight);
    // Image myTransparentBase = Image(finalWidth,finalHeight);
    // Image myTransparentBase;
    // myTransparentBase.resize(finalWidth, finalHeight);


    Image myTransparentBase(*base_);
    myTransparentBase.resize(finalWidth, finalHeight);
  
    
    // for (unsigned x = 0; x < finalWidth; x++) {
    //     for (unsigned y = 0; y < finalHeight; y++) {
    //             cs225::HSLAPixel & pixel = myTransparentBase.getPixel(x, y);
    //             if(x <= base_->width() && y <= base_->height())
    //             pixel = base_->getPixel(x, y);

    //     }
    // }


    //Then draw stickers on myTransparentBase
    for(unsigned int i = 0; i < stickers.size(); i++) {
        if (get<0>(stickers[i]) != nullptr)
        {
            
            unsigned int startXCor = get<1>(stickers[i]);
            unsigned int startYCor = get<2>(stickers[i]);
            // std::cout << startXCor << " " << startYCor<<std::endl;
            // std::cout << " " << myTransparentBase.width() << " " << myTransparentBase.height() << std::endl;

            unsigned int width = get<0>(stickers[i])->width();
            unsigned int height = get<0>(stickers[i])->height();
            for (unsigned x = startXCor; x < startXCor + width; x++) {
                for (unsigned y = startYCor; y < startYCor + height; y++) {
            // std::cout << x << " " << y << std::endl;

                    cs225::HSLAPixel & oldPixel = myTransparentBase.getPixel(x, y);
                    cs225::HSLAPixel & newPixel = get<0>(stickers[i])->getPixel(x-startXCor,y-startYCor);
                    if(newPixel.a != 0) {
                        oldPixel = newPixel;
                    }
                }
            }
        } else {
            continue;
        }
    }

    return myTransparentBase;
}

bool StickerSheet::translate (unsigned index, unsigned x, unsigned y){
    if(get<0>(stickers[index])!= NULL){
        return false;
    } else if(index > stickers.capacity() || index < 0) {
        return false;
    } else {
        get<1>(stickers[index]) = x;
        get<2>(stickers[index]) = y;
    }
    return true;   
}
