#include "Player.h"

// Constructor to initialize water and fertilizer supplies
Player::Player(int water, int fertilizer) : waterSupply(water), fertilizerSupply(fertilizer) {}

// Method to use water, returns true if successful
bool Player::useWater(int amount) {
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
bool Player::useFertilizer(int amount) {
    if (fertilizerSupply >= amount) {
        fertilizerSupply -= amount;
        std::cout << "Used " << amount << " units of fertilizer. Remaining fertilizer: " << fertilizerSupply << std::endl;
        return true;
    } else {
        std::cout << "Not enough fertilizer." << std::endl;
        return false;
    }
}

int Player::getWaterSupply() {
    return waterSupply; 
}

int Player::getFertilizerSupply() {
     return fertilizerSupply; 
}