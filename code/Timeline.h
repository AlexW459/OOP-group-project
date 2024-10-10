#ifndef TIMELINE_H
#define TIMELINE_H

#include <vector>
#include "Action.h"

using namespace std;

class Timeline{
    public:
        Timeline();
        ~Timeline();

        void performAction(Action* actionToPerform);
        void reverseAction();

    private:
        vector<Action*> listOfActions;
};

#endif