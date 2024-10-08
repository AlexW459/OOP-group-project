#include "GrowingAction.h"

GrowingAction::GrowingAction(Tree* currentTree) : treeToModify(currentTree) {};

void GrowingAction::performAction() {
    //Grows the tree and stores the changes in the corrresponding variables
    treeToModify->grow(waterConsumed, nutrientsConsumed, 
    branchWidthIncreases, branchLengthIncreases, newBranchIndices);
};

void GrowingAction::reverseAction() {
    //Removes additional branches
    treeToModify->removeBranches(newBranchIndices);
    //Resizes branches
    treeToModify->modifyBranches(branchWidthIncreases, branchLengthIncreases);
    //Returns water and nutrients to the tree
    treeToModify->addWater(waterConsumed);
    treeToModify->addNutrients(nutrientsConsumed);
    
}