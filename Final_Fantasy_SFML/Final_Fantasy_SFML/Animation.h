//
// Created by Ryan Wong on 4/16/2022.
//

#ifndef MAIN_CPP_ANIMATION_H
#define MAIN_CPP_ANIMATION_H

#include <iostream>
#include "Sprite.h"
#include "States.h"
#include "UserControlEnum.h"
//Movement


class Animation: public sf::Drawable, public States{

private:
    float speed = 2.5;
    float scaleX = 3.5f, scaleY = 3.5f;
    sf::Vector2u boundary;

    sf::Sprite sprite;
    sf::IntRect textRect;
    sf::Clock clock;
    int rows, cols;

    float totalTime;
    float switchTime = 0.15f;

    //Private functions
    void init(SpriteName name);
    UserControlEnum userControl;

    //movement
    int stepCounter = 0;

public:
    Animation();
    Animation(SpriteName name, int rows, int cols, sf::Vector2u boundary);

    void animate(float deltaTime);
    void move(float x, float y);
    sf::FloatRect getGlobalBounds()const;
    void setPosition(float x, float y);

    const sf::Vector2u& getBoundary();
    void setBoundary(const sf::Vector2u &boundary);

    void setUserControl(const UserControlEnum &userControls);
    void eventHandler(sf::RenderWindow &window,  float deltaTime);

    void swapToWarriorWorld();
    void swapToMonkWorld();
    void swapToBlackMageWorld();
    void swapToWhiteMageWorld();

    void incStepCounter();
    int getStepCounter();
    void resetStepCounter();

    void Update(int rows, float delaTime);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states)const;

};


#endif //MAIN_CPP_ANIMATION_H
