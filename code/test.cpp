#include <iostream>
#include "Player.h"
#include "Printable.h"
#include "Action.h"
#include "Tree.h"
#include "Branch.h"
#include "Timeline.h"
int main() {
    // Test for Player

    // Initialize player with some water and fertilizer
    Player player(50.0, 30.0);

    // Test initial supplies
    std::cout << "Initial supplies:" << std::endl;
    player.printData();  // Should show 50 water, 30 fertilizer

    // Test using water (successful case)
    std::cout << "\nTest: Using 20 units of water." << std::endl;
    if (player.useWater(20.0)) {
        std::cout << "Water usage successful." << std::endl;
    } else {
        std::cout << "Water usage failed." << std::endl;
    }

    // Test adding water
    std::cout << "\nTest: Adding 30 units of water." << std::endl;
    player.addWater(30.0);
    player.printData();  // Should show updated water supply

    // Test using fertilizer (successful case)
    std::cout << "\nTest: Using 10 units of fertilizer." << std::endl;
    if (player.useFertiliser(10.0)) {
        std::cout << "Fertilizer usage successful." << std::endl;
    } else {
        std::cout << "Fertilizer usage failed." << std::endl;
    }

    // Test adding fertilizer
    std::cout << "\nTest: Adding 15 units of fertilizer." << std::endl;
    player.addFertiliser(15.0);
    player.printData();  // Should show updated fertilizer supply

    // Indicate end of test
    cout << "Player initialization test complete" << endl;



    //Test using branch
    // Initialize a branch with specific parameters
    Branch branch(0, -1, 45.0f, 100.0f, 20.0f, 50.0f, 50.0f);

    // Test index and parent index
    if (branch.getIndex() == 0) {
        cout << "Passed: Index is correct" << endl;
    } else {
        cout << "Failed: Index is incorrect" << endl;
    }

    if (branch.getParentIndex() == -1) {
        cout << "Passed: Parent index is correct" << endl;
    } else {
        cout << "Failed: Parent index is incorrect" << endl;
    }

    // Test angle
    if (branch.getAngle() == 45.0f) {
        cout << "Passed: Angle is correct" << endl;
    } else {
        cout << "Failed: Angle is incorrect" << endl;
    }

    // Test size (width * length = 20 * 100 = 2000)
    if (branch.getSize() == 2000.0f) {
        cout << "Passed: Size is correct" << endl;
    } else {
        cout << "Failed: Size is incorrect" << endl;
    }

    // Test position of the tip
    float tipX, tipY;
    branch.getTipPos(tipX, tipY);
    cout << "Tip position: (" << tipX << ", " << tipY << ")" << endl;

    // Indicate end of tests
    cout << "Branch initialization test complete" << endl;


    //Test using timeline
    
    

    return 0;
}






