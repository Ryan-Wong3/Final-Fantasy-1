//
// Created by Ryan Wong on 4/16/2022.
//

#include "Game.h"
#include "Player.h"
#include "Menu.h"
#include "Battle.h"

//in future store vector2u as a var to store size
Game::Game(sf::Vector2u windowS)
:windowSize(windowS.x, windowS.y), titleScreen(sf::Vector2u(1000, 850)), world(sf::Vector2u(1000, 850)){

    srand(time(NULL));

}

void Game::run() {


    sf::RenderWindow window({windowSize.x, windowSize.y, 32}, "Final Fantasy");
    window.setFramerateLimit(60);

    Animation warriorOfLights(WARRIOR_WORLD, 2, 4, {1000, 800});
    warriorOfLights.setPosition(window.getSize().x/2, window.getSize().y/2);

    float deltaTime = 0.0f;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;

        if(warriorOfLights.getStepCounter() == 50){
            std::cout << "Reached 50 " << std::endl;
            inWorld = false;
            inBattle = true;
            transitionBattle(window);
            warriorOfLights.resetStepCounter();
            std::cout << "Back in run funciton" << std::endl;
        }

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            switch(event.type){

                //event when a ey is pressed
                case sf::Event::KeyPressed:

                    switch(event.key.code){

                        ///counting steps to trigger battle
                        case sf::Keyboard::W:
                            if(inWorld){
                                warriorOfLights.incStepCounter();
                            }
                            break;

                        case sf::Keyboard::S:
                            if(inWorld) {
                                warriorOfLights.incStepCounter();
                            }
                            break;

                        case sf::Keyboard::A:
                            if(inWorld) {
                                warriorOfLights.incStepCounter();
                            }
                            break;
                        case sf::Keyboard::D:
                            if(inWorld) {
                                warriorOfLights.incStepCounter();
                            }
                            break;

                            ///swap player sprite
                        case::sf::Keyboard::Num1:
                            if(inWorld) {
                                warriorOfLights.swapToWarriorWorld();
                            }
                            break;

                        case::sf::Keyboard::Num2:
                            if(inWorld){
                                warriorOfLights.swapToMonkWorld();
                            }
                            break;
                        case::sf::Keyboard::Num3:
                            if(inWorld) {
                                warriorOfLights.swapToBlackMageWorld();
                            }
                            break;

                        case::sf::Keyboard::Num4:
                            if(inWorld) {
                                warriorOfLights.swapToWhiteMageWorld();
                            }
                            break;

                            ///transition from starting screen to World
                        case sf::Keyboard::Return:
                            if(inTitle) {
                                transitionTitleToWorld(window);
                            }
                            break;

                    }
            }

        }



        window.clear(sf::Color::Black);

        if(inTitle){
            window.draw(titleScreen);
        }
        else if(inWorld){

            warriorOfLights.eventHandler(window, deltaTime);
            window.draw(world);
            window.draw(warriorOfLights);
        }

        window.display();

    }
}

void Game::playTitleScreen(sf::RenderWindow &window){

    for(int i = 0; i < 13; i++){

        titleScreen.playTitleScrTransition();

        while(clock.getElapsedTime().asSeconds() < .15f){
            //delay until next sprite screen
        }

        window.clear(sf::Color::Black);
        window.draw(titleScreen);
        window.display();
        clock.restart();
    }
}


void Game::transitionBattle(sf::RenderWindow &window){

    Battle battle({windowSize.x, windowSize.y});

    while(inBattle) {

        sf::Event event;

        /*
        if(battle.gameOver()){
            inBattle = false;
            inWorld = true;
            break;
        }
        */

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            switch(event.type) {

                case sf::Event::KeyPressed:
                    switch (event.key.code) {


                        case sf::Keyboard::W:
                            if (!battle.getInBattleOptions()) {
                                battle.menu.MoveUp();
                            } else {
                                if (battle.inFight()) {
                                    battle.pointBeforeEnemy();
                                }
                            }
                            break;

                        case sf::Keyboard::S:
                            if (!battle.getInBattleOptions()) {
                                battle.menu.MoveDown();
                            } else {
                                if (battle.inFight()) {
                                    battle.pointNextEnemy();
                                }
                            }
                            break;

                            ///Battle Menu
                        case sf::Keyboard::Return:

                            if(battle.gameOver()){
                                inBattle = false;
                                inWorld = true;
                                break;
                            }

                            if (!battle.getInBattleOptions()) {

                                switch (battle.menu.GetPressedItem()) {
                                    case 0:
                                        battle.fight();
                                        break;

                                    case 1:
                                        std::cout << "MAGIC" << std::endl;

                                        break;
                                    case 2:
                                        std::cout << "ITEM" << std::endl;

                                        break;
                                    case 3:
                                        inBattle = false;
                                        inWorld = true;
                                        break;
                                }
                            }
                                //if in one of the selected options
                            else{
                                if (battle.inFight()) {
                                    battle.setAction(FIGHT);
                                }
                            }
                            break;



                        case sf::Keyboard::BackSpace:
                            //go back to default selection
                            if (battle.getInBattleOptions()) {
                                battle.returnBack();
                            }
                            break;
                    }

            }

        }
        window.clear(sf::Color::Black);
        battle.draw(window);
        window.display();
    }
    std::cout << "Out of battle end" << std::endl;
}



void Game::transitionTitleToWorld(sf::RenderWindow &window){

    playTitleScreen(window);
    inTitle = false;
    world.loadWorldCorneria();
    inWorld = true;
}

/*
//States (Not Used)
void Game::toggleTitleState(){
inTitle = !inTitle;
}
bool Game::getTitleState()const{
return inTitle;
}
void Game::toggleWorldState(){
inWorld = !inWorld;
}
bool Game::getWorldState()const{
return inWorld;
}
void Game::toggleBattleState(){
inBattle = !inBattle;
}
bool Game::getBattleState()const{
return inBattle;
}
*/
