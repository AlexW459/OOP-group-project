#include "PruningAction.h"

PruningAction::PruningAction(Tree* currentTree, int branchIndex) : index(branchIndex), treeToModify(currentTree) {};

void PruningAction::performAction(){
    treeToModify->pruneBranch(index, branchesRemoved);
}

void PruningAction::reverseAction(){
    treeToModify->addBranches(branchesRemoved);
}