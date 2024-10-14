#include <iostream>
#include "Player.h"
#include "Printable.h"
#include "Action.h"
#include "Tree.h"
#include "Branch.h"
#include "Timeline.h"
#include <vector>

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
    std::cout << "Player test complete" << std::endl;



    //Test using branch
    // Initialize a branch with specific parameters
    Branch branch(0, -1, 45.0, 100.0, 20.0, 50.0, 50.0);

    // Test index and parent index
    if (branch.getIndex() == 0) {
        std::cout << "Passed: Index is correct" << std::endl;
    } else {
        std::cout << "Failed: Index is incorrect" << std::endl;
    }

    if (branch.getParentIndex() == -1) {
        std::cout << "Passed: Parent index is correct" << std::endl;
    } else {
        std::cout << "Failed: Parent index is incorrect" << std::endl;
    }

    // Test angle
    if (branch.getAngle() == 45.0) {
        std::cout << "Passed: Angle is correct" << std::endl;
    } else {
        std::cout << "Failed: Angle is incorrect" << std::endl;
    }

    // Test size (width * length = 20 * 100 = 2000)
    if (branch.getSize() == 2000.0) {
        std::cout << "Passed: Size is correct" << std::endl;
    } else {
        std::cout << "Failed: Size is incorrect" << std::endl;
    }

    // Test position of the tip
    float tipX, tipY;
    branch.getTipPos(tipX, tipY);
    std::cout << "Tip position: (" << tipX << ", " << tipY << ")" << std::endl;

    // Indicate end of tests
    std::cout << "Branch test complete" << std::endl;




    //Test using timeline
    // Create a Timeline object
    Timeline timeline;

    // Perform the first action
    Action* action = nullptr;  // Placeholder, testing the framework with a null action
    timeline.performAction(action);
    std::cout << "Performed an action successfully." << std::endl;

    // Reverse the last action
    timeline.reverseAction();
    std::cout << "Reversed the last action successfully." << std::endl;

    // Print the timeline (should be empty now)
    timeline.printData();
}

