#include "FertilisingAction.h"

//Water added to the tree is equal to the fertiliser added to the tree
FertilisingAction::FertilisingAction(Player* currentPlayer, Tree* currentTree, float kilogramsToAdd) :
    WateringAction(currentPlayer, currentTree, kilogramsToAdd), nutrientsAdded(kilogramsToAdd){};

void FertilisingAction::performAction(){
    nutrientsAbsorbed = treeToModify->addNutrients(nutrientsAdded);;
    //Adds accompanying water to the tree
    WateringAction::performAction();
};

void FertilisingAction::reverseAction(){
    playerToModify->addFertiliser(nutrientsAbsorbed);
    WateringAction::reverseAction();
};

void FertilisingAction::printData(){
    cout << "Fertilising action object" << endl;
    cout << "Nutrients added: " << nutrientsAdded << endl;
    cout << "Nutrients absorbed: " << nutrientsAbsorbed << endl;
}
