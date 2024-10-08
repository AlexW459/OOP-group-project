#ifndef FERTILISING_ACTION_H
#define FERTILISING_ACTION_H

#include "WateringAction.h"
#include "Tree.h"
#include "Player.h"

class FertilisingAction : public WateringAction {
public:
    FertilisingAction(Player* currentPlayer, Tree* currentTree, float litresToAdd);
    
    void performAction();
    void reverseAction();

private:
    float nutrientsAdded;
    float nutrientsAbsorbed;
};

#endif