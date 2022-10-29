//
// Created by ryan_ on 4/27/2022.
//

#include "Characters.h"

Characters::Characters(SpriteName nameOfHero)
: charInfo(nameOfHero){

    font.loadFromFile("Fonts/Final-Fantasy.ttf");
    hpText.setFont(font);
    hpText.setString("HP");
    currentHp.setFont(font);
    currentHp.setString(std::to_string(charInfo.getHp()));

    sprite.setTexture(Sprite::getImage(nameOfHero));

    if((int)nameOfHero <= 7){
        textRect.width = sprite.getGlobalBounds().width/3;
        textRect.height = sprite.getGlobalBounds().height/2;
        textRect.left = 0;
        textRect.top = 0;
        sprite.setTextureRect(textRect);
        sprite.setScale(3, 3);
    }
    else{
        currentHp.setFillColor(sf::Color::Green);
    }

    //Attack = Weapon Attack + STR/2 (weapon attack not in build)
    attack = charInfo.getStr() / 2;

}

Characters::~Characters(){
    std::cout << "Character" << std::endl;
    //delete[] this;
}

bool Characters::isDead(){
    return dead;
}

void Characters::dies(){
    //set the hero sprite to the dead hero sprite
    dead = true;
    textRect.left = textRect.width * 2;
    textRect.top = textRect.height;
    sprite.setTextureRect(textRect);
}

void Characters::move(){
    //move the center of rect
    sprite.move(-1, 0);
}

void Characters::moveBack(){
    sprite.move(1, 0);
}

int Characters::getDamage(){
    //generate attack damage range
    //Damage = A...2A - D
    damage = (attack + (rand() % (attack*2)));
    std::cout << "Damage " << damage << std::endl;
    return damage;
}

void Characters::takeDamage(int damageTaken) {

    damageTaken -= charInfo.getDef();

    if(damageTaken <= 0){
        damageTaken = 1;
    }

    if((charInfo.getHp() - (damageTaken)) <= 0){
        charInfo.setHp(0);
        currentHp.setString("0");
    }
    else{
        charInfo.setHp(charInfo.getHp() - damageTaken);
        currentHp.setString(std::to_string(charInfo.getHp()));
    }
}

void Characters::setPosition(float x, float y) {

    sprite.setPosition(x, y);
}

sf::Vector2u Characters::getPosition(){
    return sf::Vector2u (sprite.getPosition().x, sprite.getPosition().y);
}

sf::FloatRect Characters::getGlobalBounds() {

    return sprite.getGlobalBounds();
}

void Characters::setScale(float x, float y){

    sprite.setScale(x, y);
}

sf::Text Characters::getDisplayName(){
    return charInfo.getDisplayName();
}

sf::Vector2u Characters::getDisplayNamePos(){

    return sf::Vector2u(charInfo.getDisplayNamePos());
}

void Characters::setDisplayNamePos(float x, float y){

    charInfo.setDisplayNamePos(x, y);
}

void Characters::setHpTextPos(float x, float y){
    hpText.setPosition(x, y);
}

void Characters::setCurrentHpPos(float x, float y){
    currentHp.setPosition(x, y);
}

sf::Text Characters::getHpText(){
    return hpText;
}

sf::Text Characters::getCurrentHp(){
    return currentHp;
}

ActionNames Characters::getAction(){
    return currentAction;
}

void  Characters::setAction(ActionNames action){
    currentAction = action;
}

void Characters::setTarget(Characters *enemy){
    targetedEnemy = enemy;
}

Characters* Characters::getTarget(){
    return targetedEnemy;
}




void Characters::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

void Characters::draw(sf::RenderTarget &window, sf::RenderStates states) const{

}


