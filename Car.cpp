// Car.cpp
#include "Car.h"
#include <iostream>
#include <cmath>

Car::Car() : gear(GearType::PARK), speed(0.0), destinationSet(false) {
    currentLocation = {0.0, 0.0};
    destination = {0.0, 0.0};
}

void Car::accelerate(double acceleration) {
    if (acceleration < 0) return;
    if (gear == GearType::DRIVE || gear == GearType::REVERSE) {
        speed += acceleration;
    }
}

void Car::brake(double brakeForce) {
    if (brakeForce < 0) return;
    speed -= brakeForce;
    if (speed < 0) speed = 0;
}

void Car::shiftGear(GearType newGear) {
    gear = newGear;
}

GearType Car::getGearState() const { return gear; }

double Car::getSpeed() const { return speed; }

Location Car::getLocation() const { return currentLocation; }

Location Car::getDestination() const { return destination; }

void Car::setDestination(double lat, double lon) {
    destination = {lat, lon};
    destinationSet = true;
}

double Car::calculateDistance() const {
    const double R = 6371.0; // Radius of Earth in km
    double lat1 = currentLocation.latitude * M_PI / 180.0;
    double lon1 = currentLocation.longitude * M_PI / 180.0;
    double lat2 = destination.latitude * M_PI / 180.0;
    double lon2 = destination.longitude * M_PI / 180.0;

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c;
}

void Car::drive(double timeInHours) {
    if (!destinationSet || speed <= 0 || gear == GearType::PARK) return;

    double distance = speed * timeInHours;
    double totalDistance = calculateDistance();

    if (distance >= totalDistance) {
        currentLocation = destination;
    } else {
     
        double ratio = distance / totalDistance;
        currentLocation.latitude += (destination.latitude - currentLocation.latitude) * ratio;
        currentLocation.longitude += (destination.longitude - currentLocation.longitude) * ratio;
    }
}

double Car::timeToDestination() const {
    if (speed == 0 || !destinationSet) return -1.0;
    return calculateDistance() / speed;
}

bool Car::hasArrived() const {
    const double epsilon = 1e-6;
    return std::abs(currentLocation.latitude - destination.latitude) < epsilon &&
           std::abs(currentLocation.longitude - destination.longitude) < epsilon;
}

void Car::printStatus() const {
    std::cout << "Gear: " << static_cast<int>(gear)
              << ", Speed: " << speed << " km/h"
              << ", Location: (" << currentLocation.latitude << ", " << currentLocation.longitude << ")\n";
}
