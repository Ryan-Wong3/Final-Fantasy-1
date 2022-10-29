//
// Created by Ryan Wong on 5/2/2022.
//

#include "TitleScreen.h"


TitleScreen::TitleScreen(sf::Vector2u windowS): windowSize(windowS.x, windowS.y){


    setUpTitleScreen();
    setUpText();

}

void TitleScreen::setUpTitleScreen(){

    titleSheet.loadFromFile("Sprites/Title Screen/Title.png");
    title.setTexture(titleSheet);

    textRect.width = title.getGlobalBounds().width / 4;
    textRect.height = title.getGlobalBounds().height / 4;

    textRect.left = 0;
    textRect.top = 0;

    title.setTextureRect(textRect);

    title.setScale(windowSize.x * .00391f, windowSize.y* .00446f);

}

void TitleScreen::setUpText(){

    float tempX = windowSize.x * .26f;
    float tempY = windowSize.y * .22f;

    float yPos = .16f;
    font.loadFromFile("Fonts/Final-Fantasy.ttf");
    for(int i = 0; i < 4; i++){
        sf::Text t;
        text.push_back(t);
        text[i].setFont(font);
        text[i].setString(stringToDisplay[i]);
        text[i].setPosition(windowSize.x * .18f, windowSize.y * yPos);
        yPos += .1f;

    }
}

void TitleScreen::playTitleScrTransition(){

    transition = true;
    if (textRect.left >= 256) {
        textRect.left = 0;
        textRect.top += textRect.height;
    } else {
        textRect.left += textRect.width;
    }

    clock.restart();
    title.setTextureRect(textRect);
}

void TitleScreen::draw(sf::RenderTarget &window, sf::RenderStates states) const{

    window.draw(title);

    if(!transition){
        for(int i = 0; i < text.size(); i++){
            window.draw(text[i]);
        }
    }

}