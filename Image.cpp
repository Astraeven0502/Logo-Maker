//
// Created by astraeven on 2022/4/28.
//

#include "Image.h"
std::map<ImageNames, sf::Texture> Image::images;

void Image::loadImages(ImageNames imageNames) {
    if(!images[imageNames].loadFromFile(getImagePath(imageNames))){
        exit(30);
    }
}

std::string Image::getImagePath(ImageNames imageNames) {
    switch (imageNames) {
        case FILEPNG: return "images/file.png";
        case FOLDERPNG: return "images/folder.png";
    }
}

sf::Texture &Image::getImage(ImageNames imageNames) {
    loadImages(imageNames);
    return images[imageNames];
}
