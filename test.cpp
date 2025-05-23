#include <iostream>
#include <cassert>
#include "car.h"

void runTests() {
    std::cout << "Running tests...\n";

    // Test 1: Acceleration
    Car car;
    car.shiftGear(GearType::DRIVE);
    car.accelerate(50);
    assert(car.getSpeed() == 50);

    // Test 2: Braking
    car.brake(20);
    assert(car.getSpeed() == 30);

    // Test 3: Gear shift
    car.shiftGear(GearType::PARK);
    assert(car.getGearState() == GearType::PARK);

    // Test 4: Set and Get Destination
    car.setDestination(0.3, 0.3); 
    Location dest = car.getDestination();
    assert(dest.latitude == 0.3 && dest.longitude == 0.3);

    // Test 5: Drive and Arrival
    car.shiftGear(GearType::DRIVE);
    car.accelerate(100);  
    car.drive(1.0);       

    double distanceLeft = car.calculateDistance();
    std::cout << "Distance left: " << distanceLeft << " km\n";

    if (!car.hasArrived()) {
        std::cout << "Car has not yet arrived, driving more...\n";
        car.drive(1.0);  
    }

    assert(car.hasArrived());

    // Test 6: Time to destination
    car.setDestination(0.1, 0.1);
    car.accelerate(50);
    double timeToDest = car.timeToDestination();
    assert(timeToDest > 0);

    std::cout << "All tests passed successfully!\n";
}

int main() {
    runTests();
    return 0;
}
