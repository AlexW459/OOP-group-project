#include <iostream>
#include <filesystem>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "Tree.h"
#include "Branch.h"

using namespace cv;
using namespace std;

int main()
{
    const int windowHeight = 400;
    const int windowWidth = 600;


    Mat img(windowHeight, windowWidth, CV_8UC3, CV_RGB(150, 150, 255));

    Tree tree(10, 10, new Branch(0, 0, 50, 10, windowWidth/2, windowHeight));

    for(int i = 0; i < 40; i++){
        float placeholder1, placeholder2;
        vector<float> placeholder3, placeholder4;
        vector<Branch*> placeholder5;

        tree.grow(placeholder1, placeholder2, placeholder3, placeholder4, placeholder5);

        tree.addWater(0.5);
        tree.addNutrients(0.5);
    }


    tree.draw(&img);
    cv::imshow("Display window", img);


    while(pollKey() != 27) {

    } // Wait for the user to press the escape key
    return 0;
}