//
// Created by Ryan Wong on 5/2/2022.
//

#ifndef ANIMATION_H_WORLD_H
#define ANIMATION_H_WORLD_H

#include "SFML/Graphics.hpp"

class World : public sf::Drawable{

private:
    sf::Texture texture;
    sf::Sprite world;

    sf::Vector2u windowSize;

public:
    World(sf::Vector2u);
    void loadWorldCorneria();

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //ANIMATION_H_WORLD_H
