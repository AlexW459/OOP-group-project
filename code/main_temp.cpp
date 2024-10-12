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

    Game game = Game(800, 500);

    game.drawScreen();

    waitKey(0.3);

    return 0;
}

