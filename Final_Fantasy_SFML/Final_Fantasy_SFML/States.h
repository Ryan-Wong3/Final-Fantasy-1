//
// Created by Ryan Wong on 4/16/2022.
//

#ifndef MAIN_CPP_STATES_H
#define MAIN_CPP_STATES_H

#include "StatesEnum.h"
#include <map>

class States {

private:
    std::map<StatesEnum, bool>states;

public:
    States();

    bool getState(StatesEnum state)const;
    void disableState(StatesEnum state);
    void enableState(StatesEnum state);
    void toggleState(StatesEnum state);
};


#endif //MAIN_CPP_STATES_H
