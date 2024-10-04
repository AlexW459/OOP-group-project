#ifndef WATERING_ACTION_H
#define WATERING_ACTION_H

#include "Action.h"
#include "Tree.h"
#include "Player.h"

class WateringAction : public Action {
public:
    WateringAction(Player &playerToModify, Tree &treeToModify, float litresToAdd);

    void performAction();
    void reverseAction();

private:
    float waterAdded;
    float waterAbsorbed;
};

#endif