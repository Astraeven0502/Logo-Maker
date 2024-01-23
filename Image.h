//
// Created by astraeven on 2022/4/28.
//

#ifndef SFML_TEMPLATE_IMAGE_H
#define SFML_TEMPLATE_IMAGE_H
#include <map>
#include "ImageNames.h"
#include <SFML/Graphics.hpp>

class Image {
private:
    static std::map<ImageNames, sf::Texture> images;
    static void loadImages(ImageNames imageNames);
    static std::string getImagePath(ImageNames imageNames);
public:
    static sf::Texture& getImage(ImageNames imageNames);
};


#endif //SFML_TEMPLATE_IMAGE_H
