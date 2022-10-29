//
// Created by Ryan Wong on 4/16/2022.
//

#include "Sprite.h"

std::map<SpriteName, sf::Texture> Sprite::sprites;

std::string Sprite::getSpritePath(SpriteName name) {

    switch(name)
    {
        ///Hero's
        //Warrior
        case WARRIOR_WORLD: return "Sprites/Hero's/Warrior/final fantasy 1 warrior movement.png";
        case WARRIOR_BATTLE: return "Sprites/Hero's/Warrior/final fantasy 1 warrior combat.png";

        //MONK
        case MONK_WORLD: return "Sprites/Hero's/Monk/Monk World.png";
        case MONK_BATTLE: return "Sprites/Hero's/Monk/final fantasy 1 MONK_BATTLE.png";

        //Black Mage
        case BLACK_MAGE_WORLD: return "Sprites/Hero's/Black Mage/final fantasy 1 BlackMage World.png";
        case BLACK_MAGE_BATTLE: return "Sprites/Hero's/Black Mage/final fantasy 1 battle.png";

        //White Mage
        case WHITE_MAGE_WORLD: return "Sprites/Hero's/White Mage/White Mage World.png";
        case WHITE_MAGE_BATTLE: return "Sprites/Hero's/White Mage/final fantasy 1 White Mage Battle.png";

        //----------------------------------------------------
        ///Enemies

        //Red Imp
        case RED_IMP: return "Sprites/Enemies/Red Imp.png";

        //GR_IMP
        case Gr_IMP: return "Sprites/Enemies/gr IMP.png";

        //Wolf
        case WOLF: return "Sprites/Enemies/WOLF.png";

    }
    return std::string();
}

void Sprite::loadImage(SpriteName name) {

    sprites[name].loadFromFile(getSpritePath(name));
}

sf::Texture &Sprite::getImage(SpriteName name) {

    loadImage(name);
    return sprites[name];
}
