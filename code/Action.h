#ifndef ACTION_H
#define ACTION_H


class Action {
    public:
        virtual void performAction() = 0;
        virtual void reverseAction() = 0;
};

#endif