#include <iostream>

class Player {
private:
    int waterSupply;       // Amount of water the player has
    int fertilizerSupply;  // Amount of fertilizer the player has

public:
    Player(int water, int fertilizer) : waterSupply(water), fertilizerSupply(fertilizer) {};

    bool useWater(int amount);
    bool useFertilizer(int amount);

    // Getters for current supplies
    int getWaterSupply();
    int getFertilizerSupply();
};