//
// Created by Ryan Wong on 4/16/2022.
//

#include "Animation.h"

Animation::Animation() {


}

Animation::Animation(SpriteName name, int rows, int cols, sf::Vector2u boundary)
: rows(rows), cols(cols){

    setBoundary(boundary);
    init(name);
    sprite.setScale(scaleX, scaleY);
    totalTime = 0;
}

void Animation::init(SpriteName name) {

    //set the texture of the sprite which is spreadsheet
    sprite.setTexture(Sprite::getImage(name));

    //set the size of the single sprite width and height
    textRect.width = sprite.getGlobalBounds().width / cols;
    textRect.height = sprite.getGlobalBounds().height / rows;

    //sets the box to the top of the spreadsheet
    textRect.top = 0;
    textRect.left = 0;

    sprite.setTextureRect(textRect);
    sprite.setOrigin(textRect.width/2, textRect.height/2);
}


void Animation::animate(float deltaTime) {

    totalTime += deltaTime;

    if(totalTime >= switchTime){

        totalTime -= switchTime;

        //textRect.top = 0;
        if(getState(BACKWARD)){
           //std::cout << "Backwards " << std::endl;
            textRect.left = 0;
        }
        else if(getState(FORWARD)){
            //std::cout << "Forward" << std::endl;
            textRect.left = textRect.width;

        }
        else if(getState(DOWNWARD)){
            //std::cout << "down state pressed inside" << std::endl;
            textRect.left = textRect.width * 2;
        }
        else if(getState(UPWARD)){
            textRect.left = textRect.width*3;
        }

        textRect.top += textRect.height;

        if(textRect.top >= textRect.height * 2){

            //std::cout << "Restart" << std::endl;
            textRect.top = 0;
        }
    }

    sprite.setTextureRect(textRect);
}

void Animation::move(float x, float y){

    sprite.move(x, y);
}

sf::FloatRect Animation::getGlobalBounds() const {

    return sprite.getGlobalBounds();
}

void Animation::setPosition(float x, float y) {

    sprite.setPosition(x, y);
}

const sf::Vector2u &Animation::getBoundary() {

    return boundary;
}

void Animation::setBoundary(const sf::Vector2u &boundary) {

    Animation::boundary = boundary;
}


void Animation::setUserControl(const UserControlEnum &userControls){

    Animation::userControl = userControls;
}


void Animation::eventHandler(sf::RenderWindow &window, float deltaTime){

    sf::Vector2f movement(0.f, 0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        enableState(FORWARD);
        disableState(DOWNWARD);
        disableState(UPWARD);
        disableState(BACKWARD);

        movement.x += (speed * deltaTime) * 60;
        animate(deltaTime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        enableState(BACKWARD);
        disableState(FORWARD);
        disableState(DOWNWARD);
        disableState(UPWARD);

        //Multiply 60 to get to expected speed
        movement.x -= (speed * deltaTime) * 60;
        //move((-speed * deltaTime), 0);
        animate(deltaTime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        enableState(UPWARD);
        disableState(FORWARD);
        disableState(DOWNWARD);
        disableState(BACKWARD);
        movement.y -= (speed * deltaTime) * 60;
        animate(deltaTime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        enableState(DOWNWARD);
        disableState(UPWARD);
        disableState(BACKWARD);
        disableState(FORWARD);
        movement.y += (speed * deltaTime) * 60;
        animate(deltaTime);
    }

    sprite.move(movement);
}

void Animation::incStepCounter(){
    stepCounter++;
}

int Animation::getStepCounter(){
    std::cout << stepCounter << std::endl;
    return stepCounter;
}
void Animation::resetStepCounter(){
    stepCounter = 0;
}

void Animation::swapToWarriorWorld(){
    sprite.setTexture(Sprite::getImage(WARRIOR_WORLD));
}
void Animation::swapToMonkWorld(){
    sprite.setTexture(Sprite::getImage(MONK_WORLD));
}
void Animation::swapToBlackMageWorld(){
    sprite.setTexture(Sprite::getImage(BLACK_MAGE_WORLD));
}
void Animation::swapToWhiteMageWorld(){
    sprite.setTexture(Sprite::getImage(WHITE_MAGE_WORLD));
}

void Animation::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(sprite);
}

