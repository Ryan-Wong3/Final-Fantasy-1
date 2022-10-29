//
// Created by Ryan Wong on 4/17/2022.
//

#include "Battle.h"

Battle::Battle(sf::Vector2u windowSize)
:windowSizeX(windowSize.x), windowSizeY(windowSize.y), menu(windowSize.x, windowSize.y){

    ///SET UP 4 HERO'S
    setUpHeros();

    ///Enemies
    setUpEnemies();

    turns.setUpHerosTurns(heros);


    moveForward(turns.currentTurn());
}

Battle::~Battle(){
    std::cout << "Battle desturctor" << std::endl;
    /*
    for(int i = 0; i < heros.size(); i++){
        std::cout << i << std::endl;
        delete heros[i];
    }
    for(int i = 0; i < enemies.size(); i++){
        delete enemies[i];
    }

     */
    std::cout << "Battle end desturctor" << std::endl;
    //
    //
    // delete this;

}

void Battle::setUpHeros(){

    float y = windowSizeY * .18f;
    float yNamePos = menu.getHeroSpriteNamePos().y + windowSizeY * .07f;

    for(int i = 0; i < 4; i++){

        //Values will need to be changed if screen size is to be adjusted(future improvement)
        heros.emplace_back(new Characters(listOfNames[i]));
        heros[i]->setPosition(windowSizeX * .670f, y);
        heros[i]->setScale(3.8, 3.8);
        y += 95;

        //set the position of the name
        heros[i]->setDisplayNamePos(menu.getHeroSpriteNamePos().x +(windowSizeX * .04f) , yNamePos);

        //setPos of Hp
        heros[i]->setHpTextPos(menu.getHeroSpriteNamePos().x+ (windowSizeX * .04f), heros[i]->getDisplayNamePos().y + (windowSizeY * .07f));
        heros[i]->setCurrentHpPos(menu.getHeroSpriteNamePos().x+ (windowSizeX * .04f) + (windowSizeX * .06f), heros[i]->getDisplayNamePos().y + (windowSizeY * .1f));

        yNamePos += menu.getHeroSpriteHeight()/4.2f;
    }
}

void Battle::setUpEnemies() {

    int randomNum = rand() % 3;
    float xPos = windowSizeX * .08f;
    float yPos = windowSizeY;
    float tempYPos;

    //0 = RED_IMP
    if(randomNum == 0){
        spawnAmount = 5 + (rand() % 2) ;
        yPos *= .18f;
        tempYPos = yPos;
    }
    //1 = gr_IMP
    else if(randomNum == 1){
        spawnAmount = 1 + ((rand() % 4));
        yPos = windowSizeY * .3f;
        tempYPos = yPos;
    }
    //2 = wolf
    else if(randomNum == 2){
        spawnAmount = 3 + (rand() % 6);
        yPos *= .19f;
        tempYPos = yPos;
    }

    //Create by amountSpawn amount of times
    for(int i = 0; i < spawnAmount; i++){

        enemies.emplace_back(new Characters(enemiesList[randomNum]));
        enemies[i]->setPosition(xPos, yPos);
        enemies[i]->setScale(3.8, 3.8);
        yPos += windowSizeY * .15f;

        if(yPos >= menu.getEnemySpriteNamePos().y){
            yPos = tempYPos;
            xPos += (windowSizeX * .15f);
            enemies[i]->setPosition(xPos, yPos);
            yPos += windowSizeY * .15f;
        }
        enemies[i]->setDisplayNamePos(menu.getEnemySpriteNamePos().x + (windowSizeX * .06f), menu.getEnemySpriteNamePos().y + (windowSizeY * .06f));
        //enemies[i]->setCurrentHpPos(enemies[i]->getPosition().x - 5, enemies[i]->getPosition().y - 5);
    }

    //test hp


    //Enemy name position

}

void Battle::fight(){

    //check if enemies are alive
    if(!enemies.empty() && !isGameOver){
        menu.savingCursorPos(menu.getCursorPosition().x, menu.getCursorPosition().y);
        inBattleOptions = true;
        inFightOpt = true;
        menu.setCursorPosition(enemies.front()->getPosition().x - (windowSizeX * .06f), enemies.front()->getPosition().y + (windowSizeY * .009f));
    }
    else{
        isGameOver = true;
    }
}

//occurs after all 4 party members select action
void Battle::playAction(){

    if(!isGameOver){
        std::cout << "Play action" << std::endl;
        //timer used for possible animation
        //sf::Clock delay;
        //sf::Time timer;
        //timer += delay.getElapsedTime();

        //Hero turn
        for(int i = 0; i < aliveHeros; i++){

            if(!enemies.empty()){

                moveForward(turns.currentTurn());
                attackTarget();

                //check if enemies are supposed to die
                deleteDeadEnemy();

                moveBackward(turns.currentTurn());
                turns.setNextHeroTurn();
            }
        }


        //enemy turn
        if(!enemies.empty()){
            playEnemyAction();
        }
        else{
            isGameOver = true;
        }

    }

}

void Battle::playEnemyAction(){

    int targetedHero;
    //targetedHero = selectAliveHero();
    //targetedHero = rand() % 4;

    for(int i = 0; i < enemies.size(); i++){

        if(!turns.empty()){
            targetedHero = selectAliveHero();
            heros[targetedHero]->takeDamage(enemies[i]->getDamage());
            std::cout << "Targeting hero: " <<  heros[targetedHero]->charInfo.getNameStr() << std::endl;


            //checking if hero is supposed to die
            if(heros[targetedHero]->charInfo.getHp() == 0 && !heros[targetedHero]->isDead()){
                //std::cout << "Hero's dying " << std::endl;

                //temporary manually move sprite to left to center dead sprite
                heros[targetedHero]->setPosition( windowSizeX * .64f, heros[targetedHero]->getPosition().y);

                heros[targetedHero]->dies();
                turns.removeFromBattle(heros[targetedHero]);
                aliveHeros--;
                //std::cout << "How many hero alive " << aliveHeros << std::endl;
            }
        }
    }

    //move the first alive hero forward
    if(!turns.empty()){
        moveForward(turns.currentTurn());
    }
    else{
        isGameOver = true;
    }


}

void Battle::attackTarget(){

    std::cout << "Name: " << turns.currentTurn()->charInfo.getNameStr() << std::endl;

    //if statement not working? (not nullptr after erasing?)
    if(turns.currentTurn()->getTarget() == nullptr){
        std::cout << "Null " << std::endl;
        enemies.front()->takeDamage(turns.currentTurn()->getDamage());
    }
    else{
        turns.currentTurn()->getTarget()->takeDamage(turns.currentTurn()->getDamage());
    }

    std::cout << "Health of current enemy " <<  turns.currentTurn()->getTarget()->charInfo.getHp() << std::endl;
}

void Battle::deleteDeadEnemy(){

    for(int i = 0; i < enemies.size(); i++){
        if(enemies[i]->charInfo.getHp() == 0){
            enemies.erase( enemies.begin() + i);
        }
    }
}

void Battle::moveForward(Characters *character) {

    sf::Clock tempClock;

    while(character->getPosition().x > (windowSizeX * .61f)){
        if(tempClock.getElapsedTime().asMilliseconds() > 10){
            character->move();
        }
    }
}

void Battle::moveBackward(Characters *character){
    sf::Clock tempClock;
    while(character->getPosition().x < (windowSizeX * .670f)){
        if(tempClock.getElapsedTime().asMilliseconds() > 10){
            character->moveBack();
        }
    }
}

///Battle States
bool Battle::inFight(){
    return inFightOpt;
}

bool Battle::inMagic(){
    return inFightOpt;
}

bool Battle::inItem(){
    return inItemOpt;
}

bool Battle::getInBattleOptions(){
    return inBattleOptions;
}

void Battle::returnBack(){
    resetCursor();
    inBattleOptions = false;
    inFightOpt = false;
    inMagicOpt = false;
    inItemOpt = false;
}

void Battle::pointNextEnemy(){
    if(( selectedEnemy + 1 < enemies.size())){
        selectedEnemy++;
        menu.setCursorPosition(enemies[selectedEnemy]->getPosition().x - (windowSizeX * .06f), enemies[selectedEnemy]->getPosition().y + (windowSizeY * .009f));
    }
}

void Battle::pointBeforeEnemy(){
    if( selectedEnemy - 1 >= 0){
        selectedEnemy--;
        menu.setCursorPosition(enemies[selectedEnemy]->getPosition().x - (windowSizeX * .06f), enemies[selectedEnemy]->getPosition().y + (windowSizeY * .009f));
    }
}

void Battle::setAction(ActionNames action){

    //set the current hero action's and target
    std::cout << "Current turn: " << turns.currentTurn()->charInfo.getNameStr() << std::endl;


    turns.currentTurn()->setAction(action);
    turns.currentTurn()->setTarget(enemies[selectedEnemy]);
    moveBackward(turns.currentTurn());


    playersTurn++;
    turns.setNextHeroTurn();

    std::cout << "Player turn: " << playersTurn << std::endl;
    if(playersTurn != aliveHeros){
        moveForward(turns.currentTurn());
    }
    else{
        playersTurn = 0;
        playAction();
    }
    resetCursor();
}

ActionNames Battle::getAction(){
    return turns.currentTurn()->getAction();
}

void Battle::resetCursor(){
    selectedEnemy = 0;
    menu.setCursorPosition(menu.getSavedCursorPos().x, menu.getSavedCursorPos().y);
    inBattleOptions = false;
    inFightOpt = false;
    inMagicOpt = false;
    inItemOpt = false;

}

int Battle::selectAliveHero(){

    int rngHeroSelected;
    rngHeroSelected = rand() % 4;

    while(heros[rngHeroSelected]->isDead()){
        rngHeroSelected = rand() % 4;
    }
    return rngHeroSelected;
}

void Battle::draw(sf::RenderWindow &window){

    menu.draw(window);

    ///Drawing each hero
    for(int i = 0; i < 4; i++){
        heros[i]->draw(window);
        window.draw(heros[i]->getDisplayName());
        window.draw(heros[i]->getHpText());
        window.draw(heros[i]->getCurrentHp());
    }

    ///Drawing Enemies
    if(!enemies.empty()){
        for(int i = 0; i < enemies.size(); i++){
            enemies[i]->draw(window);
            enemies[i]->getDisplayName();
            //window.draw(enemies[i]->getCurrentHp());
        }

        window.draw(enemies[0]->getDisplayName());
    }


    //draw cursor over other objects
    window.draw(menu.getCursor());
}

void Battle::draw(sf::RenderTarget &window, sf::RenderStates states)const{

}

bool Battle::gameOver(){
    return isGameOver;
}

void Battle::updateDeltaTime(){
    //time between each frame
    this->deltaTime = this->dtClock.getElapsedTime().asSeconds();
}