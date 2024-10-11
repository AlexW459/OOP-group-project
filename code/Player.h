#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player {
private:
    float waterSupply;       // Amount of water the player has
    float fertilizerSupply;  // Amount of fertilizer the player has

public:
    // Constructor
    Player(int water, int fertilizer);

    // Methods for using resources
    bool useWater(int amount);
    bool useFertilizer(int amount);

    // New methods for adding resources
    void addWater(int amount);
    void addFertilizer(int amount);

    // Getters for current supplies
    int getWaterSupply();
    int getFertilizerSupply();
};

#endif
