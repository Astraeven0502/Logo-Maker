//
// Created by astra on 2022/4/28.
//
#include "LogoMaker.h"

LogoMaker::LogoMaker() {
    textColor = {sf::Color::White};
    window.create(sf::VideoMode(1920, 1080, 32), "Test");
    background.setSize({1920, 600});
    background.setFillColor(sf::Color::Green);
    fontSetting_text.setFont(Fonts::getFont(OPENSANSBOLD));
    fontSetting_text.setString("Font Setting");
    fontSetting_text.setCharacterSize(20);
    fontSetting_text.setPosition(900, 600);
    backgroundColor_text.setFont(Fonts::getFont(OPENSANSBOLD));
    backgroundColor_text.setString("Background Color");
    backgroundColor_text.setCharacterSize(20);
    backgroundColor_text.setPosition(1660, 600);
    fontNames = OPENSANSBOLD;
    displayText.setFont(Fonts::getFont(fontNames));
    displayText.setString("Test");
    displayText.setCharacterSize(INITIAL_FONT_SIZE);
    displayText.setPosition({INITIAL_X_AXIS,INITIAL_Y_AXIS});
    displayText_shadow.setFont(Fonts::getFont(fontNames));
    displayText_shadow.setString(displayText.getString());
    displayText_shadow.setCharacterSize(displayText.getCharacterSize());
    displayText_shadow.setPosition(INITIAL_X_AXIS, INITIAL_Y_AXIS);
    displayText_shadow.setStyle(sf::Text::Italic);
    text_x_axis.setLabelString("Text X-Axis");
    text_y_axis.setLabelString("Text Y-Axis");
    text_opacity.setLabelString("Text Opacity");
    shadow_x_axis.setLabelString("Shadow X-Axis");
    shadow_y_axis.setLabelString("Shadow Y-Axis");
    shadow_opacity.setLabelString("Shadow Opacity");
    font_size.setLabelString("Font Size");
    shadow_skew.setLabelString("Shadow Skew");
    background_opacity.setLabelString("Background Opacity");
    text_x_axis.setPosition({300,650});
    text_y_axis.setPosition({300, 700});
    text_opacity.setPosition({300, 750});
    shadow_x_axis.setPosition({300, 800});
    shadow_y_axis.setPosition({300, 850});
    shadow_opacity.setPosition({300, 900});
    font_size.setPosition({300, 950});
    shadow_skew.setPosition({1100, 900});
    background_opacity.setPosition({1100, 950});
    text_x_axis.setMaxKnobScale(500);
    text_x_axis.setInitialValue(250);
    text_y_axis.setMaxKnobScale(200);
    text_y_axis.setInitialValue(100);
    text_opacity.setMaxKnobScale(255);
    background_opacity.setMaxKnobScale(255);
    font_size.setMaxKnobScale(300);
    font_size.setInitialValue(INITIAL_FONT_SIZE);
    shadow_x_axis.setMaxKnobScale(500);
    shadow_x_axis.setInitialValue(250);
    shadow_y_axis.setMaxKnobScale(300);
    shadow_y_axis.setInitialValue(150);
    shadow_opacity.setMaxKnobScale(255);
    shadow_opacity.setInitialValue(100);
    shadow_skew.setMaxKnobScale(200);
    shadow_skew.setInitialValue(30);
    logoText.setPosition({900,730});
    logoText.setBoxSize({400,50});
    logoText.setLabel("Logo Text");
    logoText.setLabelSize(50);
    fontMenu.setBoxSize({400,50});
    fontMenu.setPosition({900,630});
    fontMenu.setTopString("Open Sans Bold");
    fontMenu.addItemList("Open Sans Bold");
    fontMenu.addItemList("Arial");
    fontMenu.addItemList("StamperCmUp");
    fontMenu.addItemList("BraggaTitulDcFr");
    fontMenu.addItemList("AntiquaSh-Italic");
    addMenuBar();
    textColorMenu.setBoxSize({200,40});
    textColorMenu.setPosition({1350,630});
    backgroundColorMenu.setBoxSize({200, 40});
    backgroundColorMenu.setPosition({1700, 630});
    backgroundColorMenu.setDefault(sf::Color::Black);
}

LogoMaker::~LogoMaker() {

}

void LogoMaker::run() {
    while(window.isOpen()) {
        processInput();
        update();
        render();
    }
}

void LogoMaker::processInput() {
    sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window.close();
        logoText.addEventHandler(window, event);
        fontMenu.addEventHandler(window, event);
        menuBar.addEventHandler(window, event);
        textColorMenu.addEventHandler(window, event);
        backgroundColorMenu.addEventHandler(window, event);
    }

    //Prevent command execute more than one time.
    if (command != "None" && !isCommandExecute){
        executeCommand();
        std::cout << command << std::endl; ////Test output
    }
    if (command == "None"){
        isCommandExecute = false;
    }



    text_x_axis.addEventHandler(window, event);
    text_y_axis.addEventHandler(window, event);
    text_opacity.addEventHandler(window, event);
    shadow_x_axis.addEventHandler(window, event);
    shadow_y_axis.addEventHandler(window, event);
    shadow_opacity.addEventHandler(window, event);
    font_size.addEventHandler(window, event);
    shadow_skew.addEventHandler(window, event);
    background_opacity.addEventHandler(window, event);

}

void LogoMaker::update() {
    displayText.setFillColor(textColor);
    displayText.setPosition({INITIAL_X_AXIS + 2*text_x_axis.getKnobScale(), INITIAL_Y_AXIS + 2*text_y_axis.getKnobScale()});
    displayText.setFillColor(sf::Color(displayText.getFillColor().r,displayText.getFillColor().g,displayText.getFillColor().b,255 - text_opacity.getKnobScale()));
    displayText_shadow.setPosition({INITIAL_X_AXIS + 2*shadow_x_axis.getKnobScale(), INITIAL_Y_AXIS + 2*shadow_y_axis.getKnobScale()});
    displayText_shadow.setFillColor(sf::Color(displayText.getFillColor().r,displayText.getFillColor().g,displayText.getFillColor().b,255 - shadow_opacity.getKnobScale()));
    background.setFillColor(backgroundColor);
    background.setFillColor(sf::Color(background.getFillColor().r, background.getFillColor().g, background.getFillColor().b, 255 - background_opacity.getKnobScale()));
    displayText.setCharacterSize( font_size.getKnobScale());
    displayText_shadow.setCharacterSize(displayText.getCharacterSize());
    displayText_shadow.setScale({1, static_cast<float>(shadow_skew.getKnobScale()) / 100});
    displayText.setString(logoText.getString());
    displayText_shadow.setString(displayText.getString());
    updateFont(fontMenu.getCurrentSelection());
    command = menuBar.getEnableItemString();
    textColor = textColorMenu.getMainColor();
    backgroundColor = backgroundColorMenu.getMainColor();
    text_x_axis.update();
    text_y_axis.update();
    text_opacity.update();
    shadow_x_axis.update();
    shadow_y_axis.update();
    shadow_opacity.update();
    font_size.update();
    shadow_skew.update();
    background_opacity.update();
    logoText.update();
    fontMenu.update();
    menuBar.update();
    textColorMenu.update();
    backgroundColorMenu.update();
}

void LogoMaker::render() {
    window.clear(sf::Color{0,0,0});
    window.draw(background);
    window.draw(fontSetting_text);
    window.draw(backgroundColor_text);
    window.draw(displayText_shadow);
    window.draw(displayText);
    window.draw(text_x_axis);
    window.draw(text_y_axis);
    window.draw(text_opacity);
    window.draw(shadow_x_axis);
    window.draw(shadow_y_axis);
    window.draw(shadow_opacity);
    window.draw(font_size);
    window.draw(shadow_skew);
    window.draw(background_opacity);
    window.draw(logoText);
    window.draw(fontMenu);
    window.draw(menuBar);
    window.draw(textColorMenu);
    window.draw(backgroundColorMenu);
    window.display();
}

void LogoMaker::addMenuBar() {
    Menu menu1, menu2, menu3;
    menu1.addItemList("New Project");
    menu1.addItemList("Open Project");
    menu1.addItemList("Save Project");
    menu1.addItemList("Quit");
    menu1.setListBoxSize(MENUBARSIZE);

    menu2.addItemList("Undo");
    menu2.addItemList("Redo");
    menu2.setListBoxSize(MENUBARSIZE);

    menu3.addItemList("Export Image");
    menu3.setListBoxSize(MENUBARSIZE);

    menu1.setTopString("File");
    menu2.setTopString("Edit");
    menu3.setTopString("Render");
    menu1.setTopBoxSize(MENUBARSIZE);
    menu2.setTopBoxSize(MENUBARSIZE);
    menu3.setTopBoxSize(MENUBARSIZE);

    menuBar.addMenuBar(menu1);
    menuBar.addMenuBar(menu2);
    menuBar.addMenuBar(menu3);
}

bool LogoMaker::updateFont(const std::string& font) {
    if (font == "Open Sans Bold"){
        fontNames = OPENSANSBOLD;
    } else if (font == "Arial"){
        fontNames = ARIAL;
    } else if (font == "StamperCmUp"){
        fontNames = STAMPERCMUP;
    } else if (font == "BraggaTitulDcFr"){
        fontNames = BRAGGATITULDCFR;
    } else if (font == "AntiquaSh-Italic"){
        fontNames = ANTIQUASH_ITALIC;
    }
    displayText.setFont(Fonts::getFont(fontNames));
    displayText_shadow.setFont(Fonts::getFont(fontNames));
    return false;
}

void LogoMaker::executeCommand() {
    if (command != "None"){
        if (command == "New Project"){
            newProject();
        } else if (command == "Open Project"){
            openProject();
        } else if (command == "Save Project"){
            saveProject();
        } else if (command == "Quit"){
            exit(99);
        } else if (command == "Undo"){
            if (History::historyAmount() > 0){
                History::topHistory().component->applySnapshot(History::topHistory().snapshot);
                History::popHistory();
                std::cout << History::historyAmount() << std::endl;
            }
        } else if (command == "Redo"){
            //nothing
        } else if (command == "Export Image"){
            exportImage();
        }
    }
    isCommandExecute = true;
}

void LogoMaker::exportImage() {
    sf::RenderTexture texture;
    texture.create(background.getSize().x, background.getSize().y);
    texture.draw(background);
    texture.draw(displayText);
    texture.draw(displayText_shadow);
    texture.display();
    if (texture.getTexture().copyToImage().saveToFile("images/image.png"))
    {
        std::cout << "screenshot saved to " << "images/image.png" << std::endl;
    }
}

void LogoMaker::newProject() {
    textColor = sf::Color::White;
    backgroundColor = sf::Color::Black;

    textColorMenu.setDefault(sf::Color::White);
    backgroundColorMenu.setDefault(sf::Color::Black);
    textColorMenu.getMainColor();
    backgroundColorMenu.getMainColor();

    fontMenu.setTopString("Open Sans Bold");
    fontNames = OPENSANSBOLD;
    text_x_axis.setInitialValue(250);
    text_y_axis.setInitialValue(100);
    font_size.setInitialValue(INITIAL_FONT_SIZE);
    shadow_x_axis.setInitialValue(250);
    shadow_y_axis.setInitialValue(150);
    shadow_opacity.setInitialValue(100);
    shadow_skew.setInitialValue(30);
    background_opacity.setInitialValue(0);
    text_opacity.setInitialValue(0);

    logoText.setString("");
}

void LogoMaker::openProject() {
    sf::RenderWindow fileWindow;
    Item button_cancel, button_open;
    button_open.setString("Open");
    button_cancel.setString("Cancel");
    button_open.setBoxSize({200,50});
    button_cancel.setBoxSize({200,50});
    button_open.setPosition({300, 500});
    button_cancel.setPosition({550, 500});
    FileTree fileTree;
    createFileTree(fileTree, "files/");

    std::string selectedFileName;

    fileWindow.create(sf::VideoMode(800, 600, 32), "File Window");
    while (fileWindow.isOpen())
    {
        sf::Event event;
        while (fileWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                fileWindow.close();
            }
            button_cancel.addEventHandler(fileWindow, event);
            button_open.addEventHandler(fileWindow, event);
            fileTree.addEventHandler(fileWindow, event);
            if (button_cancel.checkState(States::ENABLE)){
                fileWindow.close();
            }


            //Here should get the directory from filetree
            if (button_open.checkState(States::ENABLE)){
                button_open.disableState(States::ENABLE);
                button_open.enableState(States::DISABLED);
                openFile("files/MyLogo.txt");
                fileWindow.close();
            }
        }
        fileWindow.clear();

        fileTree.update();
        button_cancel.update();
        button_open.update();

        fileWindow.draw(button_cancel);
        fileWindow.draw(button_open);
        fileWindow.draw(fileTree);

        fileWindow.display();
    }

}

void LogoMaker::saveProject(){
    std::string temp = displayText.getString();
    std::ofstream myLogo;
    myLogo.open("files/MyLogo.txt");
    myLogo << temp;
    myLogo.close();
}


std::vector<std::string> LogoMaker::getDirectory(const char *from) {
    DIR *dr;
    struct dirent *dent;
    dr = opendir(from); //files directory
    std::vector<std::string> files;
    if (dr) {
        while ((dent = readdir(dr)) != NULL) {
            files.push_back(dent->d_name) ;
        }
        closedir(dr); //close all directory
    }

    //erase the first two "."
    files.erase(files.begin(),files.begin()+2);

    return files;
}

void LogoMaker::createFileTree(FileTree& fileTree, const std::string& directory) {
    std::string directoryName = directory;
    directoryName.pop_back();
    directoryName = directoryName.substr(directoryName.find_last_of("/\\")+1);
    fileTree.push("0",directoryName);

    //temp = files/
    const char *temp = directory.data();

    for (int i = 0; i < getDirectory(temp).size(); ++i) {
        fileTree.push(directoryName, getDirectory(temp)[i]);
    }


    for (int i = 0; i < getDirectory(temp).size(); ++i) {
        if (getDirectory(temp)[i].find('.') == std::string::npos){
//            std::cout << getDirectory(temp)[i] << " ::: " << directory << std::endl;
            createSubFileTree(fileTree, getDirectory(temp)[i], directory);
        }
    }
}

void LogoMaker::createSubFileTree(FileTree &fileTree, const std::string &subDirectory, const std::string &directory) {
    //subDirectory= newfolder, newfloder (2)
    //directory = files/
    //directory + subDirectory + "/"=  files/newfolder/ = temp1 (string)
    //temp1 (string) = temp2 (const char*)

    std::string temp1 = directory + subDirectory + "/";
    const char *temp2 = temp1.data();

    for (int i = 0; i < getDirectory(temp2).size(); ++i) {
        fileTree.push(subDirectory, getDirectory(temp2)[i]);
    }

    for (int i = 0; i < getDirectory(temp2).size(); ++i) {
        if (getDirectory(temp2)[i].find('.') == std::string::npos){
//            std::cout << "Here::: "<< getDirectory(temp2)[i] << " ::: " << directory << std::endl;
            createSubFileTree(fileTree, getDirectory(temp2)[i], temp1);
        }
    }
    //subDirectory= gmcx
    //directory = files/
    //directory + subDirectory + "/"=  files/newfolder/ = temp1 (string)
    //temp1 (string) = temp2 (const char*)
}

void LogoMaker::openFile(std::string directory) {
    std::ifstream file(directory);
    std::string string;
    if (file.is_open()){
        while (std::getline(file,string)){
            std::cout << string << std::endl;
            logoText.setString(string);
            logoText.enableState(States::ENABLE);
            logoText.update();
            logoText.disableState(States::ENABLE);
        }
        file.close();
    } else
        std::cout << "Open File Error";
}
