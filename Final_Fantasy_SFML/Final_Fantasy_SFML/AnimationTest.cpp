//
// Created by Ryan Wong on 4/16/2022.
//

#include "AnimationTest.h"

AnimationTest::AnimationTest(sf::Texture *texture, sf::Vector2u imageCount, float switchTime) {

    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

AnimationTest::~AnimationTest() {

}

void AnimationTest::update(int row, float deltaTime, bool faceRight) {

    currentImage.x = row;
    totalTime += deltaTime;

    if(totalTime >= switchTime){

        totalTime -= switchTime;
        currentImage.y++;

        if(currentImage.y >= imageCount.y){

            currentImage.y = 0;
        }
    }


    uvRect.top = currentImage.y * uvRect.height;

    if(faceRight){
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
    else{

        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
}
