#pragma once

#include <QuidditchUtilityStructs.hpp>

// Generic Ball Class
class Ball {
public:
    // Constructor with starting Location
    explicit Ball(Location startLocation);

    Location getLocation() const;
    void setLocation(Location newLocation);

    float getVelocity() const;    
    void setVelocity(float newVelocity);
    
    bool getPossession() const; 
    void setPossession(bool controlled);

    Location getTarget() const;
    void setTarget(Location location);

    // Add any additional ball-related properties and functions

private:
    Location location;
    float velocity = 0.0F;
    bool possession = false;
    Location targetLocation = {0,0};


    // Add any other ball-related properties
};