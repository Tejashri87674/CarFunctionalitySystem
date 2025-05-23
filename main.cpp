#include "Car.h"
#include <iostream>

void showMenu() {
    std::cout << "\n=== Car Functionality Menu ===\n";
    std::cout << "1. Accelerate\n";
    std::cout << "2. Brake\n";
    std::cout << "3. Shift Gear\n";
    std::cout << "4. Set Destination\n";
    std::cout << "5. Drive\n";
    std::cout << "6. Show Status\n";
    std::cout << "7. Time to Destination\n";
    std::cout << "8. Check if Arrived\n";
    std::cout << "9. Exit\n";
    std::cout << "Choose an option (1-9): ";
}

GearType getGearFromInput() {
    std::cout << "Enter gear (0: PARK, 1: REVERSE, 2: NEUTRAL, 3: DRIVE): ";
    int gearInput;
    std::cin >> gearInput;
    switch (gearInput) {
        case 0: return GearType::PARK;
        case 1: return GearType::REVERSE;
        case 2: return GearType::NEUTRAL;
        case 3: return GearType::DRIVE;
        default: 
            std::cout << "Invalid gear. Defaulting to PARK.\n";
            return GearType::PARK;
    }
}

int main() {
    Car myCar;
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double acc;
                std::cout << "Enter acceleration (km/h): ";
                std::cin >> acc;
                myCar.accelerate(acc);
                break;
            }
            case 2: {
                double brake;
                std::cout << "Enter brake force (km/h): ";
                std::cin >> brake;
                myCar.brake(brake);
                break;
            }
            case 3: {
                myCar.shiftGear(getGearFromInput());
                break;
            }
            case 4: {
                double lat, lon;
                std::cout << "Enter destination latitude: ";
                std::cin >> lat;
                std::cout << "Enter destination longitude: ";
                std::cin >> lon;
                myCar.setDestination(lat, lon);
                break;
            }
            case 5: {
                double time;
                std::cout << "Enter drive time (in hours): ";
                std::cin >> time;
                myCar.drive(time);
                break;
            }
            case 6: {
                myCar.printStatus();
                break;
            }
            case 7: {
                double eta = myCar.timeToDestination();
                if (eta < 0)
                    std::cout << "Cannot calculate ETA. Check speed and destination.\n";
                else
                    std::cout << "Estimated Time to Destination: " << eta << " hours\n";
                break;
            }
            case 8: {
                if (myCar.hasArrived())
                    std::cout << "You have arrived at your destination!\n";
                else
                    std::cout << "Still traveling...\n";
                break;
            }
            case 9: {
                running = false;
                std::cout << "Exiting program.\n";
                break;
            }
            default: {
                std::cout << "Invalid option. Try again.\n";
            }
        }
    }

    return 0;
}
