//
// Created by astra on 2022/2/15.
//

#ifndef SFML_PROJECT_FONTS_H
#define SFML_PROJECT_FONTS_H
#include <map>
#include "FontNames.h"
#include <SFML/Graphics.hpp>

class Fonts {
private:
    static std::map<FontNames, sf::Font> fonts;
    static void loadFont(FontNames fontName);
    static std::string getFontPath(FontNames fontName);

public:
    static sf::Font& getFont(FontNames fontName);
};


#endif //SFML_PROJECT_FONTS_H
