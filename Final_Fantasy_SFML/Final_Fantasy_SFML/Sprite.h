//
// Created by Ryan Wong on 4/16/2022.
//

#ifndef MAIN_CPP_SPRITE_H
#define MAIN_CPP_SPRITE_H


#include <SFML/Graphics.hpp>
#include <map>
#include "SpriteName.h"

class Sprite {

private:
    static std::map<SpriteName,sf::Texture> sprites;
    static std::string getSpritePath(SpriteName name);
    static void loadImage(SpriteName name);

public:
    static sf::Texture& getImage(SpriteName name);
};


#endif //MAIN_CPP_SPRITE_H
