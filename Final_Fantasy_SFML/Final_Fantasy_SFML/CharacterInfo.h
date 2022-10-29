//
// Created by Ryan Wong on 4/29/2022.
//

#ifndef ANIMATION_H_CHARACTERINFO_H
#define ANIMATION_H_CHARACTERINFO_H

#include "SFML/Graphics.hpp"
#include "SpriteName.h"

//temp
#include <iostream>
#include <string>
class CharacterInfo {

private:
    SpriteName name;
    std::string nameStr;
    //Not all stat included from game
    //-----------
    //hp = Health points
    //mp = Magic Points
    //str = Strength
    //intel = intelligence
    //acc = accuracy
    //def = defence
    //exp = experience point
    //gil = (name of currency)
    //-----------
    int hp;
    int mp;
    int str;
    int intel;
    int acc;
    int def;

    float exp;
    int gil;

    sf::Font font;
    sf::Text displayName;


public:
    CharacterInfo(SpriteName name);

    //void setName(SpriteName name);
    SpriteName getName();
    sf::Text getDisplayName();
    sf::Vector2u getDisplayNamePos();
    void setDisplayNamePos(float x, float y);

    void setHp(int hp);
    int getHp();


    void setMp(int mp);
    int getMp();

    void setStr(int str);
    int getStr();

    void setInt(int intel);
    int getIntel();

    void setAcc(int acc);
    int getAcc();

    void setDef(int def);
    int getDef();

    std::string getNameStr();

};


#endif //ANIMATION_H_CHARACTERINFO_H
