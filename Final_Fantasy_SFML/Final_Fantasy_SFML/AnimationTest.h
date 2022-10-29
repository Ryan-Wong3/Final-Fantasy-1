//
// Created by Ryan Wong on 4/16/2022.
//

#ifndef MAIN_CPP_ANIMATIONTEST_H
#define MAIN_CPP_ANIMATIONTEST_H

#include <SFML/Graphics.hpp>
#include <iostream>

class AnimationTest {

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;


public:
    AnimationTest(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
    ~AnimationTest();

    void update(int row, float deltaTime, bool faceRight);

public:
    sf::IntRect uvRect;

};


#endif //MAIN_CPP_ANIMATIONTEST_H
