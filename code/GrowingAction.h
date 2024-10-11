#ifndef GROWING_ACTION_H
#define GROWING_ACTION_H

#include "Action.h"
#include "Tree.h"
#include "Player.h"

class GrowingAction : public Action : public Printable{
    public:
        GrowingAction(Tree* currentTree);

        void performAction();
        void reverseAction();
        void printdata();

    private:
        Tree* treeToModify;

        float waterConsumed;
        float nutrientsConsumed;

        //Stores the increases in width and height of each branch
        vector<float> branchWidthIncreases;
        vector<float> branchLengthIncreases;

        //Stores the indices of every new branch that was added
        vector<int> newBranchIndices;
};

#endif