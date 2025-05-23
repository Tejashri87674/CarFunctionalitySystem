// Car.h
#ifndef CAR_H
#define CAR_H

enum class GearType {
    PARK,
    REVERSE,
    NEUTRAL,
    DRIVE
};

struct Location {
    double latitude;
    double longitude;
};

class Car {
private:
    GearType gear;
    double speed;
    Location currentLocation;
    Location destination;
    bool destinationSet;

public:
    Car();

    void accelerate(double acceleration);
    void brake(double brakeForce);
    void shiftGear(GearType newGear);
    
    GearType getGearState() const;
    double getSpeed() const;
    Location getLocation() const;
    Location getDestination() const;
    void setDestination(double lat, double lon);
    
    double calculateDistance() const;
    void drive(double timeInHours);
    double timeToDestination() const;
    bool hasArrived() const;

    void printStatus() const;
};

#endif // CAR_H
