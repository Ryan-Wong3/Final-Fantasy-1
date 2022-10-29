//
// Created by ryan_ on 4/27/2022.
//

#ifndef GAME_H_HERO_H
#define GAME_H_HERO_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "SpriteName.h"
#include "Sprite.h"
#include "CharacterInfo.h"
#include "ActionNames.h"
#include <ctime>

class Characters: sf::Drawable {

private:

    int attack;
    int damage;

    sf::Texture text;
    sf::Sprite sprite;
    sf::IntRect textRect;

    sf::Font font;
    sf::Text hpText;
    sf::Text currentHp;

    ActionNames currentAction;
    Characters *targetedEnemy;

    ///State
    bool dead = false;

public:
    Characters(SpriteName nameOfHero);
    ~Characters();
    CharacterInfo charInfo;

    ///Status
    bool isDead();
    void dies();

    ///Name
    sf::Text getDisplayName();
    sf::Vector2u getDisplayNamePos();
    void setDisplayNamePos(float x, float y);

    ///HP
    sf::Text getHpText();
    void setHpTextPos(float x, float y);
    sf::Text getCurrentHp();
    void setCurrentHpPos(float x, float y);

    ///Damage
    int getDamage();
    void takeDamage(int damageTaken);

    ///Positions
    void move();
    void moveBack();
    void setPosition(float x, float y);
    sf::Vector2u getPosition();
    sf::FloatRect getGlobalBounds();
    void setScale(float x, float y);

    ///Action
    ActionNames getAction();
    void setAction(ActionNames action);
    void setTarget(Characters *enemy);
    Characters* getTarget();


    ///Draw
    void draw(sf::RenderWindow &window);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states)const;
};


#endif //GAME_H_HERO_H
