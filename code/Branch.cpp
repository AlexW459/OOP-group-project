#include "Branch.h"

//Sets values to initial vaues specified in the constructor
Branch::Branch(int branchIndex, float initialAngle, float initialLength, 
float initialWidth, float initialXPos, float initialYPos): index(branchIndex) {
    Size size = Size(initialLength, initialWidth);

    //Finds the position of the centre of the branch based on the given position of the base of the branch
    float xPos = initialXPos+0.5*initialLength*cos(initialAngle);
    float yPos = initialYPos+0.5*initialLength*sin(initialAngle);

    Point centre = Point(xPos, initialYPos);

    branchRect = RotatedRect(centre, size, initialAngle);
}



float Branch::getAngle(){
    return branchRect.angle;
}

void Branch::getTipPos(float &xPosition, float &yPosition) {
    //Finds position of tip using trigonometry
    xPosition = branchRect.center.x+0.5*branchRect.size.height*cos(branchRect.angle);
    yPosition = branchRect.center.y+0.5*branchRect.size.height*sin(branchRect.angle);
}

int Branch::getIndex(){
    return index;
}

void Branch::addChild(int childIndex) {
    //Adds the new index onto the vector
    childIndices.push_back(childIndex);
}

bool Branch::removeChild(int childIndex){
    //Loops through every child of the branch
    for(int i = 0; i < childIndices.size(); i ++){
        //Checks if the current child is the one that is being removed
        if(childIndices[i] == childIndex){
            //Erases the element from the vector
            childIndices.erase(childIndices.begin() + i);
            //Exits function successfully
            return true;
        }
    }
    //Returns false if the child is not found
    return false;
}


vector<int> Branch::getChildren(){
    //Returns children
    return childIndices;
}

float Branch::getSize(){
    return branchRect.size.area();
}

void Branch::setPos(float newXPos, float newYPos){
    //Sets the centre of the branch based on the given coordinates, which are at the base of the branch
    branchRect.center.x = newXPos+0.5*branchRect.size.height*cos(branchRect.angle);
    branchRect.center.y = newYPos+0.5*branchRect.size.height*sin(branchRect.angle);
}

void Branch::grow(float areaIncrease, float &widthIncrease, float &lengthIncrease){
    //The change in length is equal to (n/age) times the change in width, 
    //so the branch initially grows longer and then later grows wider

    //Set n to an arbitrary value that can be adjusted during testing
    float n = 4;

    float width = branchRect.size.width;
    float length = branchRect.size.height;

    //formula for the increase in width derived using the quadratic formula
    widthIncrease = -width/2 - (length*age)/(2*n) + 
    sqrt((pow(width, 2))/4+(width*length*age)/(2*n)+(length*pow(age, 2))/(4*pow(n, 2)));

    lengthIncrease = (n/age)*widthIncrease;

    //Applies changes to variables
    branchRect.size.width += widthIncrease;
    branchRect.size.height += lengthIncrease;

    //Increments age by one
    age++;
}

void Branch::draw(Mat* img){
    Point2f vertices2f[4];

    //Gets points of rectangle
    branchRect.points(vertices2f);

    //Converts vertices to regular point objects from point2f objects
    vector<Point> vertices;
    for(int i = 0; i < 4; ++i){
        vertices.push_back(vertices2f[i]);
    }

    //Draws the branch to the image;
    fillConvexPoly(*img, vertices, (100, 100, 100));
}
