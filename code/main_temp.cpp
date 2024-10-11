#include <iostream>
#include <filesystem>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

// things needed for clicking feature
#include "Game.h"
#include "Tree.h"
#include "Branch.h"
#include "Clickable.h" 

using namespace cv;
using namespace std;


// window interface
int main(void) {
    //Create instance of game class
    Game game(500, 800);

    while(game.isRunning()){
        
    }




    return 0;
}

