//
// Created by Ryan Wong on 4/29/2022.
//

#include "CharacterInfo.h"
CharacterInfo::CharacterInfo(SpriteName name){

    font.loadFromFile("Fonts/Final-Fantasy.ttf");
    displayName.setFont(font);

    this->name = name;

    //stats provided from https://finalfantasy.fandom.com/wiki/Final_Fantasy_stats#cite_note-2
    if(name == SpriteName::WARRIOR_BATTLE){
        nameStr = "War";
        displayName.setString("War");
        //hp = 1;
        hp= 35;
        mp = 0;
        str = 10;
        intel = 1;
        acc = 18;
        def = 0;
    }
    else if(name == SpriteName::MONK_BATTLE){
        displayName.setString("Monk");
        nameStr = "Monk";
        //hp = 1;
        hp = 33;
        mp = 0;
        str = 12;
        intel = 1;
        acc = 13;
        def = 5;
    }
    else if(name == SpriteName::BLACK_MAGE_BATTLE){
        displayName.setString("Blck");
        nameStr = "Black";
        //hp = 1;
        hp = 25;
        mp = 10;
        str = 3;
        intel = 20;
        acc = 13;
        def = 0;
    }
    else if(name == SpriteName::WHITE_MAGE_BATTLE){
        displayName.setString("Whte");
        nameStr = "White";
        //hp = 1;
        hp = 33;
        mp = 10;
        str = 5;
        intel = 15;
        acc = 10;
        def = 0;
    }

    ///Enemies
    else if(name == SpriteName::RED_IMP){
        displayName.setString("IMP");
        hp = 8;
        mp = 0;
        str = 5;
        intel = 1;
        acc = 2;
        def = 4;

        exp = 2;
        gil = 6;
    }
    else if(name == SpriteName::Gr_IMP){
        displayName.setString("Gr IMP");
        hp = 16;
        mp = 0;
        str = 10;
        intel = 1;
        acc = 4;
        def = 6;

        exp = 13;
        gil = 18;
    }
    else if(name == SpriteName::WOLF){
        displayName.setString("WOLF");
        hp = 20;
        mp = 0;
        str = 10;
        intel = 1;
        acc = 5;
        def = 0;

        exp = 24;
        gil = 6;
    }


}


//void CharacterInfo::setName(SpriteName name){
//    this->name = name;
//}

SpriteName CharacterInfo::getName(){
    return name;
}

sf::Text CharacterInfo::getDisplayName(){
    return displayName;
}

sf::Vector2u CharacterInfo::getDisplayNamePos(){
    return sf::Vector2u(displayName.getPosition().x, displayName.getPosition().y);
}

void CharacterInfo::setDisplayNamePos(float x, float y){
    displayName.setPosition(x, y);
}

void CharacterInfo::setHp(int hp) {

    this->hp = hp;
}

int CharacterInfo::getHp() {
    return hp;
}

void CharacterInfo::setMp(int mp) {
    this->mp = mp;
}

int CharacterInfo::getMp() {
    return mp;
}

void CharacterInfo::setStr(int str) {
    this->str = str;
}

int CharacterInfo::getStr() {
    return str;
}

void CharacterInfo::setInt(int intel) {
    this->intel = intel;
}

int CharacterInfo::getIntel() {
    return intel;
}

void CharacterInfo::setAcc(int acc) {
    this->acc = acc;
}

int CharacterInfo::getAcc() {
    return acc;
}

void CharacterInfo::setDef(int def) {
    this->def = def;
}

int CharacterInfo::getDef() {
    return def;
}

std::string CharacterInfo::getNameStr(){
    return nameStr;
}