#include <iostream>

class Player {
private:
    int waterSupply;       // Amount of water the player has
    int fertilizerSupply;  // Amount of fertilizer the player has

public:
    useWater(int amount);
    useFertilizer(int amount);
    Player(int water, int fertilizer) : waterSupply(water), fertilizerSupply(fertilizer) {}
    // Getters for current supplies
    int getWaterSupply() const { return waterSupply; }
    int getFertilizerSupply() const { return fertilizerSupply; }
};