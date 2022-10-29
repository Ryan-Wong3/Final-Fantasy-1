//
// Created by Ryan Wong on 5/2/2022.
//

#ifndef ANIMATION_H_TITLESCREEN_H
#define ANIMATION_H_TITLESCREEN_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

class TitleScreen : public sf::Drawable{

private:
    sf::Texture titleSheet;
    sf::Sprite title;
    sf::IntRect textRect;

    sf::Vector2u windowSize;

    sf::Clock clock;

    sf::Font font;
    std::vector<sf::Text> text;
    std::string stringToDisplay[4] {"Ryan", "CS 003A", "CRN 37045", "SPRING 2022"};

    bool transition = false;

    void setUpText();
    void setUpTitleScreen();

public:
    TitleScreen(sf::Vector2u windowS);

    void playTitleScrTransition();

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

};


#endif //ANIMATION_H_TITLESCREEN_H
