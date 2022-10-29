//
// Created by Ryan Wong on 5/2/2022.
//

#include "World.h"

World::World(sf::Vector2u windowS)
:windowSize(windowS.x, windowS.y){

}

void World::loadWorldCorneria() {

    texture.loadFromFile("Sprites/World/Corneria.png");
    world.setTexture(texture);
    world.setScale(windowSize.x * 0.00448f,windowSize.y * 0.0049f);
    //set Size


}

void World::draw(sf::RenderTarget &window, sf::RenderStates states) const{

    window.draw(world);
}