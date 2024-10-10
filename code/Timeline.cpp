#include "Timeline.h"

Timeline::Timeline(){};

Timeline::~Timeline(){
    for (int i = 0; i < listOfActions.size(); i++){
        //Deallocates the memory storing each action in he timeline
        delete listOfActions[i];
    }
}

void Timeline::performAction(Action* actionToPerform){
    //Adds the action to the list
    listOfActions.push_back(actionToPerform);
    //Performs the action immediately
    actionToPerform->performAction();
}

void Timeline::reverseAction(){
    //Reverses the last action that was taken
    listOfActions.back()->reverseAction();
    //Deallocates the memory
    delete listOfActions.back();
    //Deletes the pointer from the vector
    listOfActions.pop_back();
}

