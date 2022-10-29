//
// Created by Ryan Wong on 4/16/2022.
//

#include "Player.h"

Player::Player(SpriteName name, int rows, int cols, sf::Vector2u boundary)
: Animation(name, rows,cols, boundary){

    //sprite = Animation
}

//Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed)
//: animation(texture, imageCount, switchTime) {
//
//    this->speed = speed;
//    row = 0;
//    faceRight = true;
//
//    body.setSize(sf::Vector2f(100.0f, 150.0f));
//    body.setPosition(206.f, 206.f);
//    body.setTexture(texture);
//
//}

Player::~Player() {

}

void Player::update(float deltaTime) {

    sf::Vector2f movement(0.f, 0.f);

    /*
    std::cout << speed * deltaTime << std::endl;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speed * deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speed * deltaTime;

    if(movement.x == 0.f){
        row = 0;
    }
    else{
        row = 1;

        if(movement.x >= 0){
            faceRight = false;
        }
        else{
            faceRight = true;


        }
    }
    animation.update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
     */
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

        enableState(FORWARD);
        disableState(DOWNWARD);
        disableState(UPWARD);
        disableState(BACKWARD);

        movement.x += (speed * deltaTime) * 60;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){

        std::cout << "Left pressed " << deltaTime  <<  std::endl;

        enableState(BACKWARD);
        disableState(FORWARD);
        disableState(DOWNWARD);
        disableState(UPWARD);

        //Multiply 60 to get to expected speed
        movement.x -= (speed * deltaTime) * 60;
        //move((-speed * deltaTime), 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

        enableState(UPWARD);
        disableState(FORWARD);
        disableState(DOWNWARD);
        disableState(FORWARD);

        movement.y -= (speed * deltaTime) * 60;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

        enableState(DOWNWARD);
        disableState(UPWARD);
        disableState(DOWNWARD);
        disableState(FORWARD);

        movement.y += (speed * deltaTime) * 60;
    }
    else{
        disableState(DOWNWARD);
        disableState(UPWARD);
        disableState(DOWNWARD);
        disableState(FORWARD);
    }

    //body.move(movement);

}

/*
void Player::Draw(sf::RenderWindow &window) {
    window.draw(body);
}
*/

void Player::draw(sf::RenderTarget &window, sf::RenderStates states)const{

    //window.draw(body);
}