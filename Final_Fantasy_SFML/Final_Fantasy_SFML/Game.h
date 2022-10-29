//
// Created by Ryan Wong on 4/16/2022.
//

#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include "Animation.h"
#include "TitleScreen.h"
#include "SFML/Audio.hpp"
#include "World.h"

class Game {

private:
    sf::Vector2u windowSize;

    bool inTitle = true;
    bool inWorld = false;
    bool inBattle = false;

    sf::Clock clock;

    TitleScreen titleScreen;
    World world;
    void playTitleScreen(sf::RenderWindow &window);
    void transitionTitleToWorld(sf::RenderWindow &window);
    void transitionBattle(sf::RenderWindow &window);

    //Unsure
    void countingStep(sf::Keyboard button);

public:
    Game(sf::Vector2u windowS);
    void run();

    /*
    void toggleTitleState();
    bool getTitleState()const;
    void toggleWorldState();
    bool getWorldState()const;
    void toggleBattleState();
    bool getBattleState()const;
    */

};


#endif //MAIN_CPP_GAME_H
