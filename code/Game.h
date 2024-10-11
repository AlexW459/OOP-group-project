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
// Print out what you want to do and give each option and ask for a prompt and do a Cin to detect what they have done
        }

        void drawScreen(){
            
        }

    private:
        Tree* gameTree;
        Player* gamePlayer;
        Timeline* gameTimeline;

};


#endif