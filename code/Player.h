#include <iostream>

class Player {
private:
    int waterSupply;       // Amount of water the player has
    int fertilizerSupply;  // Amount of fertilizer the player has

public:
    bool useWater(int amount);
    bool useFertilizer(int amount);
    Player(int water, int fertilizer) : waterSupply(water), fertilizerSupply(fertilizer) {}
    // Getters for current supplies
    int getWaterSupply() { return waterSupply; }
    int getFertilizerSupply() { return fertilizerSupply; }
};