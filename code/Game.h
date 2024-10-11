#ifndef GAME_H
#define GAME_H

#include "Tree.h"
#include "Timeline.h"
#include "Player.h"

class Game {
    public:
        Game();

        ~Game();

        void handleInputs(){

        }

        void drawScreen(){
            
        }

    private:
        Tree* gameTree;
        Player* gamePlayer;
        Timeline* gameTimeline;

};


#endif