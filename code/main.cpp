#include <iostream>
#include <filesystem>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

// things needed for clicking feature
#include "Tree.h"
#include "Branch.h"
#include "Clickable.h"  //include the Clickable header

using namespace cv;
using namespace std;


// window interface
int main() {
    //dimentions of window
    const int windowHeight = 400;
    const int windowWidth = 600;

    //displaying the window
    Mat img(windowHeight, windowWidth, CV_8UC3, CV_RGB(150, 150, 255));

    //displaying the thee
    Tree tree(10, 10, new Branch(0, 0, 1, 50, 10, windowWidth / 2, windowHeight));

    // Vectors for clickable feature
    vector<Clickable> clickables;

    //loop  for tree growth
    for (int i = 0; i < 30; i++) {
        float placeholder1, placeholder2;
        vector<float> placeholder3, placeholder4;
        vector<int> placeholder5;

        tree.grow(placeholder1, placeholder2, placeholder3, placeholder4, placeholder5);
        tree.addWater(i);
        tree.addNutrients(i);


        // updateing Clickables after tree growth:
        clickables.clear(); // Clear previous clickables

        // loop from 0 to the size of the tree
        for (int j = 0; j < 30; ++j) {
            Branch* branch = tree.branchList()[j]; // the list of all branches to find tip later
            float x, y;

            // find the position of the tip of the branch to click
            branch->getTipPos(x, y);

            // Adjust rectangle size 
            Rect branchRect(x - 5, y - 5, 10, 10);  // Make it a small square around the tip.
            clickables.push_back(Clickable(branchRect, j));  // Use branch index as ID. 
        }


        //draws the tree
        tree.draw(&img);

        // Draw clickables for visualization:
        for (const auto& clickable : clickables) {
            clickable.draw(img); //To visualize the clickable regions.

        // displays it
        imshow("Display window", img);


        //Mouse Callback 
        setMouseCallback("Display window", [](int event, int x, int y, int flags, void* userdata) {
            if (event == EVENT_LBUTTONDOWN) {
                vector<Clickable>* clickables = static_cast<vector<Clickable>*>(userdata);
                for (auto& clickable : *clickables) {
                    if (clickable.contains(Point2f(x, y))) {
                        clickable.setClicked(true);
                        clickable.executeCallback();
                        break;
                    }
                }
            }
            }, &clickables);

        while (pollKey() != 32) {} // Wait for spacebar
    }

    // Callback Setup NEEDS TO HAPPEN OUTSIDE GROWTH LOOP DO NOT MOVE
    for (auto& clickable : clickables) {
        // will get the call back id for action and execute it after growth
        clickable.setCallback([&](int id) {
            cout << "Clicked on branch: " << id << endl;
            // Add branch modification codeee
            // _ how to modify the tree based on the clicked branch ...

        });
    }

    return 0;
}
