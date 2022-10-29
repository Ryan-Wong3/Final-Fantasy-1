//
// Created by Ryan Wong on 4/17/2022.
//

#ifndef GAME_H_MENU_H
#define GAME_H_MENU_H

#include "SFML/Graphics.hpp"
#include <iostream>

//Defining the number of selection on screen
#define MAX_NUMBER_OF_ITEMS 4

class Menu {

private:
    float windowSizeX;
    float windowSizeY;

    ///Menu Background sprites
    sf::Texture textSquareTopLeft;
    sf::Sprite spriteSquareTopLeft;

    sf::Texture textSquareEnemyName;
    sf::Sprite spriteSquareEnemyName;

    sf::Texture textBattleOptions;
    sf::Sprite  spriteBattleOptions;

    sf::Texture textHeroNames;
    sf::Sprite spriteHeroNames;

    //Could set this in as another clas to be able to swap backgrounds
    sf::Texture textForestLeft;
    sf::Sprite spriteForestLeft;

    sf::Texture textForestRight;
    sf::Sprite spriteForestRight;


private:
    ///Menu Selection
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

    sf::Texture texture;
    sf::Sprite cursor;
    sf::Vector2u savedCursorPos;

    void setUpMenu(float width, float height);

public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem(){return selectedItemIndex;}



    sf::Vector2u getHeroSpriteNamePos();
    float getHeroSpriteHeight();

    sf::Vector2u getEnemySpriteNamePos();

    ///Cursor
    sf::Sprite getCursor();
    void setCursorPosition(float x, float y);
    sf::Vector2u getCursorPosition();
    void savingCursorPos(float x, float y);
    sf::Vector2u getSavedCursorPos();
};


#endif //GAME_H_MENU_H
