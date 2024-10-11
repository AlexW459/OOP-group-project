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
    
};

void GrowingAction::printData() {
    cout << "Growing action object" << endl;
    cout << "Water conumed: " << waterConsumed << endl;
    cout << "Nutrients consumed: " << nutrientsConsumed << endl;
    cout << "List of all branch width increments: " << endl;
    for (int i = 0; i < branchWidthIncreases.size(); i++){
        cout << branchWidthIncreases[i] << ", "; 
    } 
    cout << endl;
    
    cout << "List of all branch length incremtnes: " << endl;
    for (int i = 0; i < branchLengthIncreases.size(); i++){
        cout << branchLengthIncreases[i] << ", "; 
    } 
    cout << endl;

    cout << "List of all new branch indecies: " << endl;
    for (int i = 0; i < newBranchIndices.size(); i++){
        cout << newBranchIndices[i] << ", "; 
    } 
    cout << endl;
}

