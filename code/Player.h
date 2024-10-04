#include <iostream>

class Player {
private:
    int waterSupply;       // Amount of water the player has
    int fertilizerSupply;  // Amount of fertilizer the player has

public:
    // Constructor to initialize water and fertilizer supplies
    Player(int water, int fertilizer) : waterSupply(water), fertilizerSupply(fertilizer) {}

    // Method to use water, returns true if successful
    bool useWater(int amount) {
        if (waterSupply >= amount) {
            waterSupply -= amount;
            std::cout << "Used " << amount << " units of water. Remaining water: " << waterSupply << std::endl;
            return true;
        } else {
            std::cout << "Not enough water." << std::endl;
            return false;
        }
    }

    // Method to use fertilizer, returns true if successful
    bool useFertilizer(int amount) {
        if (fertilizerSupply >= amount) {
            fertilizerSupply -= amount;
            std::cout << "Used " << amount << " units of fertilizer. Remaining fertilizer: " << fertilizerSupply << std::endl;
            return true;
        } else {
            std::cout << "Not enough fertilizer." << std::endl;
            return false;
        }
    }

    // Getters for current supplies
    int getWaterSupply() const { return waterSupply; }
    int getFertilizerSupply() const { return fertilizerSupply; }
};