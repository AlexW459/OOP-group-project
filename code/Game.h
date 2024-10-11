#ifndef GAME_H
#define GAME_H

#include "Tree.h"
#include "Timeline.h"
#include "Clickable.h"
#include "Player.h"

enum GameState{
    MAIN_MENU,
    IN_GAME,
    PRUNING_ACTION
};

class Game {
    public:
        Game(int windowWidth, int windowHeight);

        ~Game();

        void mouseClicked();

        void drawScreen();

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