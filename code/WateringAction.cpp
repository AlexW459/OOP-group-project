#include "WateringAction.h"

WateringAction::WateringAction(Player* currentPlayer, Tree* currentTree, float litresToAdd) :
    waterAdded(litresToAdd), waterAbsorbed(0), playerToModify(currentPlayer), treeToModify(currentTree) {};

void WateringAction::performAction() {
    waterAbsorbed = treeToModify->addWater(waterAdded);
    playerToModify->useWater(waterAdded);
}

void WateringAction::reverseAction() {
    treeToModify->removeWater(waterAbsorbed);
    playerToModify->addWater(waterAdded);
}

void WateringAction::printData(){
    cout << "Watering Action object" << endl;
    cout << "Water Added: " << waterAdded << endl;
    cout << "Water absorbed: " << waterAbsorbed << endl;
}