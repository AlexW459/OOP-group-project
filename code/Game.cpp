#include "Game.h"

Game::Game(int windowWidth, int windowHeight) : gameRunning(true), currentState(MAIN_MENU){
    WINDOW_WIDTH = windowWidth;
    WINDOW_HEIGHT = windowHeight;
    
    gamePlayer = new Player(10, 5);

    //Creates tree with a default supply of 10L of water and 10kg of nutrients
    gameTree = new Tree(10, 10, new Branch(0, 0, 1, 50, 10,  WINDOW_WIDTH/ 2, WINDOW_HEIGHT));


    //Creates the image to display to the screen
    screenImg = new Mat(WINDOW_HEIGHT, WINDOW_WIDTH, CV_8UC3, CV_RGB(150, 150, 255));

    //Creates the timeline
    gameTimeline = new Timeline();


    //Creates on-screen buttons
    Rect mainMenuButtonRect(WINDOW_WIDTH/2-100, WINDOW_HEIGHT/2-50, 200, 100);
    buttonList.push_back(new Clickable(mainMenuButtonRect, 1, "Play"));

    Rect waterTreeButtonRect(WINDOW_WIDTH-100, 0, 200, 100);
    buttonList.push_back(new Clickable(mainMenuButtonRect, 2, "Water tree"));

    Rect fertiliseTreeRect(WINDOW_WIDTH-100, 100, 200, 100);
    buttonList.push_back(new Clickable(fertiliseTreeRect, 3, "Fertilise tree"));

    Rect pruneBranchRect(WINDOW_WIDTH-100, 200, 200, 100);
    buttonList.push_back(new Clickable(pruneBranchRect, 3, "Prune branch"));

    Rect growTreeRect(WINDOW_WIDTH-100, 300, 200, 100);
    buttonList.push_back(new Clickable(growTreeRect, 3, "Grow tree"));


    Rect reverseActionRect(WINDOW_WIDTH-100, 400, 200, 100);
    buttonList.push_back(new Clickable(reverseActionRect, 3, "Reverse action"));


}

Game::~Game(){
    //Loops through button list and frees memory
    for(int i = 0; i < buttonList.size(); i++){
        delete buttonList[i];
    }

    //Frees memory
    delete screenImg;
    delete gameTree;
    delete gamePlayer;
    delete gameTimeline;

}

void Game::drawScreen(){

    if(currentState == MAIN_MENU){
        //Draws the play button
        buttonList[0]->draw(screenImg);
    }else{
        //Draws the action buttons
        for(int i = 1; i < buttonList.size(); i++){
            buttonList[i]->draw(screenImg);
        }
        //Draws the tree to the screen
        gameTree->draw(screenImg);

    }

    imshow("Display window", *screenImg);
}


bool Game::isRunning() {
    return gameRunning;
}

void Game::printData(){
    cout << "Game object" << endl;
    gameTree->printData();
    gamePlayer->printData();
    gameTimeline->printData();

    cout << "Window width: " << WINDOW_WIDTH << endl;
    cout << "Window height: " << WINDOW_HEIGHT << endl;

    cout << "Game state: " << currentState << endl;
}