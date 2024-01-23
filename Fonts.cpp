//
// Created by astra on 2022/2/15.
//

#include "Fonts.h"
std::map<FontNames, sf::Font> Fonts::fonts;

void Fonts::loadFont(FontNames fontName) {
    if(!fonts[fontName].loadFromFile(getFontPath(fontName))){
     exit(28);
    }
}

std::string Fonts::getFontPath(FontNames fontName) {
    switch (fontName) {
        case OPENSANSBOLD: return "Fonts/OpenSans-Bold.ttf";
        case ARIAL: return "Fonts/Arial.ttf";
        case STAMPERCMUP: return "Fonts/StamperCmUp.TTF";
        case BRAGGATITULDCFR: return "Fonts/BraggaTitulDcFr.Ttf";
        case ANTIQUASH_ITALIC: return "Fonts/AntiquaSh-Italic.ttf";
    }
}

sf::Font &Fonts::getFont(FontNames fontName){
    loadFont(fontName);
    return fonts[fontName];
}
