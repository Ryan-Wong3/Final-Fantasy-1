//
// Created by Ryan Wong on 4/16/2022.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include "SFML/Graphics.hpp"
//#include "AnimationTest.h"
#include "Animation.h"

class Player:public Animation {

private:
    //sf::RectangleShape body;
    Animation animation;
    //AnimationTest animation;
    unsigned int row;
    float speed;
    bool faceRight;

public:
    Player(SpriteName name, int rows, int cols, sf::Vector2u boundary);
    //Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~Player();

    void update(float deltaTime);
    void Draw(sf::RenderWindow &);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states)const;
};


#endif //MAIN_CPP_PLAYER_H
