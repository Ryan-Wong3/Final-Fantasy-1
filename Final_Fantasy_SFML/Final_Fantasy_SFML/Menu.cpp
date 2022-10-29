//
// Created by Ryan Wong on 4/17/2022.
//

#include "Menu.h"

Menu::Menu(float width, float height):windowSizeX(width), windowSizeY(height) {

    setUpMenu(width, height);

}

Menu::~Menu() {
    //delete this;
}

void Menu::setUpMenu(float width, float height){

    if(!font.loadFromFile("Fonts/Final-Fantasy.ttf")){

    }

    ///Set the menu in position
    //top Rectangle Piece
    textSquareTopLeft.loadFromFile("Sprites/Menu Sprites/Battle Board Upper.png");
    spriteSquareTopLeft.setTexture(textSquareTopLeft);
    spriteSquareTopLeft.setPosition(width * .05f, 30);

    //Bottom left square
    textSquareEnemyName.loadFromFile("Sprites/Menu Sprites/battle enemy name.png");
    spriteSquareEnemyName.setTexture(textSquareEnemyName);
    spriteSquareEnemyName.setPosition(spriteSquareTopLeft.getGlobalBounds().left , spriteSquareTopLeft.getGlobalBounds().top + spriteSquareTopLeft.getGlobalBounds().height + 3);

    //Battle option
    textBattleOptions.loadFromFile("Sprites/Menu Sprites/battle option.png");
    spriteBattleOptions.setTexture(textBattleOptions);
    spriteBattleOptions.setPosition(spriteSquareEnemyName.getGlobalBounds().left + spriteSquareEnemyName.getGlobalBounds().width + 5, spriteSquareEnemyName.getGlobalBounds().top);

    //hero name square
    textHeroNames.loadFromFile("Sprites/Menu Sprites/Hero Names.png");
    spriteHeroNames.setTexture(textHeroNames);
    spriteHeroNames.setPosition(spriteSquareTopLeft.getGlobalBounds().left + spriteSquareTopLeft.getGlobalBounds().width + 2, (spriteBattleOptions.getGlobalBounds().top + spriteBattleOptions.getGlobalBounds().height) - spriteHeroNames.getGlobalBounds().height);

    ///Forest background
    textForestLeft.loadFromFile("Sprites/Menu Sprites/NES - Final Fantasy - Battle Backgrounds.png");
    spriteForestLeft.setTexture(textForestLeft);
    spriteForestLeft.setPosition(spriteSquareTopLeft.getGlobalBounds().left + 35, spriteSquareTopLeft.getGlobalBounds().top + 30);
    spriteForestLeft.setScale(3.8, 3);
    textForestRight.loadFromFile("Sprites/Menu Sprites/NES - Final Fantasy - Battle Backgrounds.png");
    spriteForestRight.setTexture(textForestRight);
    spriteForestRight.setPosition(spriteHeroNames.getPosition().x - (spriteHeroNames.getPosition().x * .275f), spriteSquareTopLeft.getGlobalBounds().top + 30);
    spriteForestRight.setScale(1.7f,3);

    ///Borders
    menu[0].setFont(font);
    //menu[0].setFillColor(sf::Color::Red);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("FIGHT");
    menu[0].setPosition(sf::Vector2f(spriteBattleOptions.getPosition().x + (spriteBattleOptions.getGlobalBounds().width * .2), spriteBattleOptions.getGlobalBounds().top + (spriteBattleOptions.getGlobalBounds().height) * .17f )); // / (MAX_NUMBER_OF_ITEMS + 1) * 1) );
    menu[0].setCharacterSize(28);

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("MAGIC");
    menu[1].setPosition(sf::Vector2f(menu[0].getPosition().x, menu[0].getPosition().y + (height * .065f)));  //(MAX_NUMBER_OF_ITEMS + 1) * 2));
    menu[1].setCharacterSize(28);

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("ITEM");
    menu[2].setPosition(sf::Vector2f(menu[0].getPosition().x, menu[1].getPosition().y + (height * .065f))); //(MAX_NUMBER_OF_ITEMS + 1) * 3));
    menu[2].setCharacterSize(28);

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("RUN");
    menu[3].setPosition(sf::Vector2f(menu[0].getPosition().x,menu[2].getPosition().y + (height * .065f))); //(MAX_NUMBER_OF_ITEMS + 1) * 4));
    menu[3].setCharacterSize(28);

    selectedItemIndex = 0;

    ///Cursor
    texture.loadFromFile("Sprites/Menu Sprites/cursor1.png");
    cursor.setTexture(texture);
    //std::cout << "Global left " << menu->getGlobalBounds().left << std::endl;
    //std::cout << "Global top " << menu->getGlobalBounds().top;
    //cursor.setPosition(menu[selectedItemIndex].getGlobalBounds().left, menu[selectedItemIndex].getGlobalBounds().top);
    cursor.setPosition(menu[selectedItemIndex].getPosition().x - (width *.07f), menu[selectedItemIndex].getPosition().y - (height * .015f));
    cursor.setScale(1.5f, 1.5f);
}

void Menu::draw(sf::RenderWindow &window) {

    window.draw(spriteSquareTopLeft);
    window.draw(spriteSquareEnemyName);
    window.draw(spriteHeroNames);
    window.draw(spriteBattleOptions);
    window.draw(spriteForestLeft);
    window.draw(spriteForestRight);

    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i ++){

        window.draw(menu[i]);
        window.draw(cursor);
    }


}

void Menu::MoveUp() {

    if(selectedItemIndex - 1 >= 0){

        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        cursor.setPosition(menu[0].getPosition().x - (windowSizeX *.07f), menu[selectedItemIndex ].getPosition().y - (windowSizeY * .015f));
        //menu[selectedItemIndex].setColor(sf::Color::Red);
        menu[selectedItemIndex].setColor(sf::Color::White);
    }
}

void Menu::MoveDown() {

    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){

        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        cursor.setPosition(menu[0].getPosition().x - (windowSizeX *.07f), menu[selectedItemIndex ].getPosition().y - (windowSizeY * .015f));
        //menu[selectedItemIndex].setColor(sf::Color::Red);
        menu[selectedItemIndex].setColor(sf::Color::White);
    }
}

void Menu::setCursorPosition(float x, float y){
    cursor.setPosition(x, y);
}

sf::Vector2u Menu::getHeroSpriteNamePos(){

    return sf::Vector2u(spriteHeroNames.getPosition().x, spriteHeroNames.getPosition().y);
}

float Menu::getHeroSpriteHeight(){
    return spriteHeroNames.getGlobalBounds().height;
}

sf::Vector2u Menu::getEnemySpriteNamePos(){
    return sf::Vector2u(spriteSquareEnemyName.getPosition().x, spriteSquareEnemyName.getPosition().y);
}


sf::Sprite Menu::getCursor(){
    return cursor;
}

sf::Vector2u Menu::getCursorPosition(){
    return sf::Vector2u(cursor.getPosition().x, cursor.getPosition().y);
}
void Menu::savingCursorPos(float x, float y){

    savedCursorPos.x = x;
    savedCursorPos.y = y;
}

sf::Vector2u Menu::getSavedCursorPos(){
    return sf::Vector2u(savedCursorPos.x, savedCursorPos.y);
}