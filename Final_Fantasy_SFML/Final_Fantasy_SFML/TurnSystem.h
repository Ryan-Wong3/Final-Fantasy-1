//
// Created by Ryan Wong on 4/30/2022.
//

#ifndef ANIMATION_H_TURNSYSTEM_H
#define ANIMATION_H_TURNSYSTEM_H

#include "Characters.h"
#include <vector>
#include <queue>

class TurnSystem {

private:
    std::queue<Characters*> herosTurn;

    void pushCharInLine(Characters *character);
    void popFrontChar();

public:
    TurnSystem();
    ~TurnSystem();

    void setUpHerosTurns(std::vector<Characters*> character);
    void setNextHeroTurn();

    Characters* currentTurn();
    void removeFromBattle(Characters *deadChar);

    bool empty();

};


#endif //ANIMATION_H_TURNSYSTEM_H
