//
// Created by astra on 2022/4/28.
//

#ifndef SFML_PROJECT_LOGOMAKER_H
#define SFML_PROJECT_LOGOMAKER_H
#include <dirent.h>
#include <SFML/Graphics.hpp>
#include "Slider.h"
#include "TextInput.h"
#include "DropdownMenu.h"
#include "MenuBar.h"
#include "ColorPicker.h"
#include <fstream>
#include "FileTree.h"


class LogoMaker {
public:
    LogoMaker();
    ~LogoMaker();
    void run();


private:
    sf::RenderWindow window;
    sf::Text displayText;
    sf::Text displayText_shadow;
    sf::Text fontSetting_text, backgroundColor_text;
    sf::RectangleShape background;
    TextInput logoText;
    const float INITIAL_X_AXIS = 300, INITIAL_Y_AXIS = 10, INITIAL_FONT_SIZE = 100;
    const sf::Vector2f MENUBARSIZE = {300 ,50};
    Slider text_x_axis, text_y_axis, shadow_x_axis, shadow_y_axis, text_opacity, shadow_opacity;
    Slider font_size, shadow_skew, background_opacity;
    DropdownMenu fontMenu;
    FontNames fontNames;
    MenuBar menuBar;
    std::string command = " ";
    bool isCommandExecute = false;
    sf::Color textColor, backgroundColor;
    ColorPicker textColorMenu;
    ColorPicker backgroundColorMenu;

    void addMenuBar();
    bool updateFont(const std::string& font);
    void executeCommand();
    void exportImage();
    void newProject();
    void openProject();
    void saveProject();
    std::vector<std::string> getDirectory(const char *from);
    void createFileTree(FileTree& fileTree, const std::string& directory);
    void createSubFileTree(FileTree& fileTree, const std::string& subDirectory, const std::string& directory);
    void openFile(std::string directory);


    void processInput();
    void update();
    void render();
};


#endif //SFML_PROJECT_LOGOMAKER_H
