#ifndef PRUNING_ACTION_H
#define PRUNING_ACTION_H

#include "Action.h"
#include "Tree.h"

class PruningAction : public Action{
    public:
        PruningAction(Tree* currentTree, int branchIndex);

        void performAction();
        void reverseAction();

    private:
        int index;
        vector<Branch*> branchesRemoved;

        Tree* treeToModify;

};


#endif