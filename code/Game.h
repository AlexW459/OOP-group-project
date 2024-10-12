#ifndef GAME_H
#define GAME_H

#include "Printable.h"
#include "Timeline.h"
#include "Tree.h"
#include "Clickable.h"
#include "Player.h"

using namespace cv;

enum GameState{
    MAIN_MENU,
    INSTRUCTION_MENU,
    IN_GAME,
    PRUNING_ACTION
};

class Game : Printable{
    public:
        Game(int windowWidth, int windowHeight);

        ~Game();

        void mouseClicked();

        void drawScreen();

        void printData();

        bool isRunning();

    private:
        Mat* screenImg;

        Tree* gameTree;
        Player* gamePlayer;
        Timeline* gameTimeline;

        vector<Clickable*> buttonList;

        int WINDOW_WIDTH;
        int WINDOW_HEIGHT;

        bool gameRunning;

        GameState currentState;

};


#endif