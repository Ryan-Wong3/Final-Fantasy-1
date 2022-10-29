//
// Created by Ryan Wong on 4/30/2022.
//

#include "TurnSystem.h"

TurnSystem::TurnSystem(){

}

TurnSystem::~TurnSystem(){

    for(int i = 0; i < herosTurn.size(); i++){
        herosTurn.pop();
    }

}
void TurnSystem::setUpHerosTurns(std::vector<Characters*> character){

    for(int i = 0; i < character.size(); i++){
        herosTurn.push(character[i]);
    }
}

void TurnSystem::pushCharInLine(Characters *character) {
    herosTurn.push(character);
}

void TurnSystem::popFrontChar() {
    herosTurn.pop();
}

Characters* TurnSystem::currentTurn() {
    return herosTurn.front();
}

void TurnSystem::setNextHeroTurn(){

    Characters *temp = herosTurn.front();
    herosTurn.pop();
    herosTurn.push(temp);
}
void TurnSystem::removeFromBattle(Characters *deadChar){

    for(int i = 0; i < herosTurn.size(); i++){
        if(herosTurn.front() != deadChar){
            setNextHeroTurn();
        }
        else{
            std::cout << "Died: " << herosTurn.front()->charInfo.getNameStr() << std::endl;
            herosTurn.pop();
            //std::cout << "Turn after death: " << herosTurn.front()->charInfo.getNameStr() << std::endl;
            break;
        }
    }
}

bool TurnSystem::empty(){
    return herosTurn.empty();
}