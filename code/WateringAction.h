#ifndef WATERING_ACTION_H
#define WATERING_ACTION_H

#include "Action.h"
#include "Tree.h"
#include "Player.h"

class WateringAction : public Action {
public:
    WateringAction(Player* currentPlayer, Tree* currentTree, float litresToAdd);

    virtual void performAction();
    virtual void reverseAction();

protected:
    Player* playerToModify;
    Tree* treeToModify;

    float waterAdded;
    float waterAbsorbed;
};

#endif