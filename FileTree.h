//
// Created by astraeven on 2022/4/28.
//

#ifndef SFML_TEMPLATE_FILETREE_H
#define SFML_TEMPLATE_FILETREE_H
#include "GUI_Components.h"
#include "FileNode.h"

class FileTree : public GUI_Components
{
private:
    //the root node of the tree
    FileNode* root = nullptr;

    std::string selectedString;
    std::vector<std::string> fileDirectory;
//    std::string fileDirectory_string;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, std::string parent, std::string item);

    //traverses the tree ad adds the evenhandlers for each of the nodes
    void traverse_event(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    void traverse_update(FileNode* &root);
    sf::Vector2f initPosition = {0, 0};
    void printTree(FileNode* &root);
//    std::string getSelectedString(FileNode* root);
    void getSelectedPath(FileNode* &root);

    void updateSelectedString(FileNode* &root);

public:
    //constructors
    FileTree();

    //this is the public version of push
    void push(std::string parent, std::string item);

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //does nothing now
    virtual void applySnapshot(const Snapshot& snapshot);

    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot& getSnapshot();
    //does nothing now
    virtual sf::FloatRect getGlobalBounds();

    void printTree();
//    std::string getSelectedString();
    std::vector<std::string> getSelectedPath();
};


#endif //SFML_TEMPLATE_FILETREE_H
