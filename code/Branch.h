#ifndef BRANCH_H
#define BRANCH_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <math.h> 

using namespace std;
using namespace cv;

class Branch{
    public:
        //Constructor
        Branch(int branchIndex, float initialAngle, float initialLength, float initialWidth, 
        float xPos, float yPos);

        float getAngle();

        //Sets parameters to the position of the tip of the branch
        void getTipPos(float &xPosition, float &yPosition);

        int getIndex();
        
        //Adds a new branch to the list of child indices
        void addChild(int index);
        //Removes child from list of indices
        bool removeChild(int index);

        //Returns the list of children
        vector<int> getChildren();
        
        //Returns the area of the branch (length*width)
        float getSize();

        void setPos(float newXPos, float newYPos);

        void grow(float areaIncrease);

        void draw(Mat* img);

    private:
        //Index of branch in tree
        int index;
        //Indices of all branches stemming from this branch
        vector<int> childIndices;

        //Rectanle representing the branch
        RotatedRect branchRect;

        //Number of times the branch has been allowed to grow
        int age;
};

#endif