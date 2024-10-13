#include "Game.h"

Game::Game(int windowWidth, int windowHeight) : gameRunning(true), currentState(IN_GAME){
    WINDOW_WIDTH = windowWidth;
    WINDOW_HEIGHT = windowHeight;
    
    gamePlayer = new Player(10, 5);

    //Creates tree with a default supply of 10L of water and 10kg of nutrients
    gameTree = new Tree(10, 10, new Branch(0, 0, 1, 50, 10,  WINDOW_WIDTH/ 2, WINDOW_HEIGHT));


    //Creates the image to display to the screen
    screenImg = new Mat(WINDOW_HEIGHT, WINDOW_WIDTH, CV_8UC3, CV_RGB(150, 150, 255));

    //Creates the timeline
    gameTimeline = new Timeline();

    int buttonWidth = 250;

    //Creates on-screen buttons
    Rect mainMenuButtonRect(WINDOW_WIDTH/2-100, WINDOW_HEIGHT/2-50, 200, 100);
    buttonList.push_back(new Clickable(mainMenuButtonRect, 1, "Play"));

    Rect instructionMenuButtonRect(WINDOW_WIDTH/2-100, WINDOW_HEIGHT/2+60, 200, 100);
    buttonList.push_back(new Clickable(instructionMenuButtonRect, 2, "Instructions"));

    Rect backButtonRect(10, 10, 200, 100);
    buttonList.push_back(new Clickable(backButtonRect, 3, "Back" ));

    Rect cancelPruningRect(10, WINDOW_HEIGHT-110, 200, 100);
    buttonList.push_back(new Clickable(cancelPruningRect, 4, "Cancel"));

    Rect waterTreeButtonRect(WINDOW_WIDTH-buttonWidth, 0, buttonWidth, 100);
    buttonList.push_back(new Clickable(waterTreeButtonRect, 5, "Water tree"));

    Rect fertiliseTreeRect(WINDOW_WIDTH-buttonWidth, 100, buttonWidth, 100);
    buttonList.push_back(new Clickable(fertiliseTreeRect, 6, "Fertilise tree"));

    Rect pruneBranchRect(WINDOW_WIDTH-buttonWidth, 200, buttonWidth, 100);
    buttonList.push_back(new Clickable(pruneBranchRect, 7, "Prune branch"));

    Rect growTreeRect(WINDOW_WIDTH-buttonWidth, 300, buttonWidth, 100);
    buttonList.push_back(new Clickable(growTreeRect, 8, "Grow tree"));

    Rect reverseActionRect(WINDOW_WIDTH-buttonWidth, 400, buttonWidth, 100);
    buttonList.push_back(new Clickable(reverseActionRect, 9, "Reverse action"));



    gameTimeline->performAction(new GrowingAction(gameTree));

    gameTimeline->performAction(new GrowingAction(gameTree));


    gameTimeline->reverseAction();

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
    //Clears what was previously on the screen
    *screenImg = CV_RGB(150, 150, 255);


    switch(currentState) {
    case MAIN_MENU:
        //Draws the play button
        buttonList[0]->draw(screenImg);
        //Draws the instruction menu button
        buttonList[1]->draw(screenImg);
        break;
    case INSTRUCTION_MENU:
        //Draws the back button
        buttonList[2]->draw(screenImg);

        //Explains the instructions
        putText(*screenImg, "Water and fertilise your tree so \n it grows big and tall. Prune branches that you want to remove,\nand reverse your previous actions if you make a mistake or don't like how the tree has grown.",
         Point(WINDOW_WIDTH/2-200, WINDOW_HEIGHT/2-100), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);

        break;
    case PRUNING_ACTION:
        //Draws the cancel pruning button
        buttonList[3]->draw(screenImg);

    case IN_GAME:
        //Draws the back button
        buttonList[2]->draw(screenImg);

        //Draws the action buttons
        for(int i = 4; i < buttonList.size(); i++){
            buttonList[i]->draw(screenImg);
        }


        //Draws the tree to the screen
        gameTree->draw(screenImg);

        break;
    }

    cv::imshow("Display window", *screenImg);
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