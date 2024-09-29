#include "Tree.h"

//Maximum width of a branch before it will no longer sprout new branches
const float NEW_BRANCH_THRESHOLD = 5000;
//Required nutrients and water for a new branch to grow
const float NEW_BRANCH_REQUIREMENT = 3;

//Scales the amount that branches grow by with a given amount of food
const float BRANCH_GROWTH_AMOUNT = 300;

Tree::Tree(float initialWater, float initialNutrients, Branch* trunk): waterLevel(initialWater), 
nutrientLevel(initialNutrients), maxIndex(1) {
    //Adds the trunk as the first branch in the list
    branchList.push_back(trunk);

    //sets a seed for randomly generated numbers
    long int t = static_cast<long int> (time(NULL));
    srand(t);

}

Tree::~Tree(){
    //Deletes all of the branches
    for(int i = 0; i < branchList.size(); i++){
        delete branchList[i];
    }
}

float Tree::addWater(float litres){
    //Checks whether the tree has the capacity to absorb the given amount of water
    if(litres+waterLevel >= maxWater){
        //Finds the amount of water that was actually absorbed
        float waterAbsorbed = maxWater - waterLevel;

        //Sets the water level to the maximum value
        waterLevel = maxWater;
        
        //Returns the amount of water that was absorbed
        return waterAbsorbed;
    }else{
        //Add all of the water to the tree
        waterLevel += litres;
        //Return the amount that was absorbed
        return litres;
    }
}

float Tree::addNutrients(float kilograms){
    //Checks whether the tree has the capacity to absorb the given amount of nutrients
    if(kilograms+nutrientLevel >= maxNutrients){
        //Finds the amount of water that was actually absorbed
        float nutrientsAbsorbed = maxNutrients - nutrientLevel;

        //Sets the water level to the maximum value
        nutrientLevel = maxNutrients;
        
        //Returns the amount of water that was absorbed
        return nutrientsAbsorbed;
    }else{
        //Add all of the water to the tree
        nutrientLevel += kilograms;
        //Return the amount that was absorbed
        return kilograms;
    }
}

void Tree::addBranches(vector<Branch*> newBranches){
    //Adds the additional branches to the tree
    for(int i = 0; i < newBranches.size(); i++){
        branchList.push_back(newBranches[i]);
    }
}

void Tree::grow(float &waterConsumed, float &nutrientsConsumed, 
vector<float> &widthIncreases, vector<float> &lengthIncreases, vector<Branch*> &branchesGrown){

    //Finds the growth amount of each branch based on the amount of water and nutrients
    float growthAmount = min(waterLevel, nutrientLevel);
    float branchGrowthAmount = BRANCH_GROWTH_AMOUNT*growthAmount/branchList.size();


    waterLevel*=0.8;
    nutrientLevel*= 0.8;

    for(int i = 0; i < branchList.size(); i++){
        float widthGrowth;
        float lengthGrowth;

        //Grows the branch by the calculated amount
        branchList[i]->grow(branchGrowthAmount, widthGrowth, lengthGrowth);

        //Adds the growth amounts to the corresponding lists
        widthIncreases.push_back(widthGrowth);
        lengthIncreases.push_back(lengthGrowth);

        //Moves all of the child branches in accordance with the branch's growth
        //Gets children of current branch
        vector<int> childIndices = branchList[i]->getChildren();

        //Gets new position of the tip of the current branch
        float newTipX;
        float newTipY;
        branchList[i]->getTipPos(newTipX, newTipY);

        //Loops through all of the children
        for(int i = 0; i < childIndices.size(); i++){
            //Adjusts position of branches
            branchList[findBranch(childIndices[i])]->setPos(newTipX, newTipY);
        }


        //Adds a new branch if the tree has the required nutrients and water
        if(min(nutrientLevel, waterLevel) > NEW_BRANCH_REQUIREMENT && branchList[i]->getSize() < NEW_BRANCH_THRESHOLD){
            
            //Gets the angle of the current branch
            float currentBranchAngle = branchList[i]->getAngle();

            //Generates a random number between -45 and 45
            float newAngle = 90*((float)(rand()) /RAND_MAX-0.5);
            Branch* newBranch = new Branch(maxIndex, newAngle, 50, 10, newTipX, newTipY);
            branchList.push_back(newBranch);
            

            //Increments the highest index
            maxIndex++;
        }
    }

}

void Tree::modifyBranches(vector<float> widthIncreases, vector<float> lengthIncreases){
    //Checks that the modification is valid
    if(widthIncreases.size() != branchList.size() || lengthIncreases.size() != branchList.size()){
        cout << "Error in Tree.modifyBranches(), size of modifying arrays does not match the number of branches in the tree" << endl;
        return;
    }

    //Loops through each of the branches in the tree
    for(int i = 0; i < branchList.size(); i++){
        //Adjusts branch size
        branchList[i]->modifySize(widthIncreases[i], lengthIncreases[i]);

        //Moves child branches to account for the change in size of their parent

        //Gets children of current branch
        vector<int> childIndices = branchList[i]->getChildren();

        //Gets new position of the tip of the current branch
        float newTipX;
        float newTipY;
        branchList[i]->getTipPos(newTipX, newTipY);

        //Loops through all of the children
        for(int i = 0; i < childIndices.size(); i++){
            //Adjusts position of branches
            branchList[findBranch(childIndices[i])]->setPos(newTipX, newTipY);
        }

    }
}

int Tree::findBranch(int index){
    //Loops through the list of branches
    for(int i = 0; i < branchList.size(); i++){
        if(branchList[i]->getIndex() == index) return i;
    }

    cout << "Error in Tree.findBranch(), branch with that index not found" << endl;
    return 0;
}

void Tree::draw(Mat* img){
    //Loops through each of the branches in the tree
    for(int i = 0; i < branchList.size(); i++){
        branchList[i]->draw(img);
    }
}
