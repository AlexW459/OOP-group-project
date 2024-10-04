#ifndef TREE_H
#define TREE_H

#include <vector>
#include <opencv2/core.hpp>
#include <iostream>
#include "Branch.h"

using namespace std;

class Tree{
    public:
        Tree(float initialWater, float initialNutrients, Branch* trunk);
        ~Tree();

        //Adds water and nutrients
        float addWater(float litres);
        float addNutrients(float kilograms);

        //Adds branches to the list
        void addBranches(vector<Branch*> newBranches);

        //Increases the size of branches and possibly adds new branches
        void grow(float &waterConsumed, float &nutrientsConsumed, 
        vector<float> &widthIncreases, vector<float> &lengthIncreases, vector<Branch*> &branchesGrown);

        //Changes the dimensions of the branhes
        void modifyBranches(vector<float> widthIncreases, vector<float> lengthIncreases);

        //Finds the position of a branch with a given index in the branch list
        int findBranch(int index);

        void draw(Mat* img);
    private:
        vector<Branch*> branchList;

        int maxIndex;
        float waterLevel;
        float maxWater;
        float nutrientLevel;
        float maxNutrients;
};

#endif