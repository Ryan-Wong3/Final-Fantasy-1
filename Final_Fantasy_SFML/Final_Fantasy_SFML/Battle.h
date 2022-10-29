//
// Created by Ryan Wong on 4/17/2022.
//

#ifndef GAME_H_BATTLE_H
#define GAME_H_BATTLE_H

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Characters.h"
#include <vector>
#include <stdlib.h>
#include <ctime>
#include "TurnSystem.h"

class Battle: public sf::Drawable{

private:
    sf::Clock dtClock;
    float deltaTime;

    TurnSystem turns;
    int playersTurn = 0;

    float windowSizeX;
    float windowSizeY ;

    bool isGameOver = false;

    bool inBattleOptions = false;
    bool inFightOpt = false;
    bool inMagicOpt = false;
    bool inItemOpt = false;
    int selectedEnemy = 0;

    ///Hero's
    int aliveHeros = 4;
    Characters listOfNames[4] = {WARRIOR_BATTLE, MONK_BATTLE, BLACK_MAGE_BATTLE, WHITE_MAGE_BATTLE};
    void setUpHeros();


    ///Enemies
    int spawnAmount = 0;
    void setUpEnemies();
    SpriteName enemiesList[3] = {RED_IMP, Gr_IMP, WOLF};
    int selectAliveHero();
    void deleteDeadEnemy();


    void findNextAliveHero();
    void attackTarget();
    void playAction();
    void playEnemyAction();


public:
    Battle(sf::Vector2u windowSize);
    ~Battle();

    std::vector<Characters*> heros;
    std::vector<Characters*> enemies;

    ///Battle Menu States
    bool battleStarted = false;
    bool getInBattleOptions();
    bool inFight();
    bool inMagic();
    bool inItem();

    void generateBattle();

    ///Menu Options
    Menu menu;
    void returnBack();
    void resetCursor();

    ///Fight
    void fight();
    void pointNextEnemy();
    void pointBeforeEnemy();


    ///Magic
    void magic();
    ///Item
    void item();
    ///Run
    void run();

    //Moving the hero during turns
    void moveForward(Characters *character);
    void moveBackward(Characters *characters);

    ///Actions
    ActionNames getAction();
    void setAction(ActionNames action);

    bool gameOver();

    ///Draw
    void draw(sf::RenderWindow &window);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states)const;

    void updateDeltaTime();


};


#endif //GAME_H_BATTLE_H
