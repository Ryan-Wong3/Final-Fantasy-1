//
// Created by Ryan Wong on 4/16/2022.
//

#include "States.h"

States::States() {

    for(int i = 0; i < LAST_STATE; i++){

        states[StatesEnum(i)] = false;
    }
}

bool States::getState(StatesEnum state) const {

    return states.at(state);
}

void States::disableState(StatesEnum state) {

    states[state] = false;
}

void States::enableState(StatesEnum state) {

    states[state] = true;
}

void States::toggleState(StatesEnum state) {

    states[state] = !states[state];
}
