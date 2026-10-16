#include "Physics.h"
//#include "Vector3.h"

double calculateForce(double mass, double acceleration)
{
    return mass * acceleration;
}

Vector3 calculateAcceleration(Vector3 force, double mass)
{
    Vector3 result = scale(force,1/mass);
    return  result;
}

Vector3 updateVelocity(Vector3 velocity, Vector3 acceleration, double dt)
{
    Vector3 result = add(velocity, scale(acceleration, dt));
    return  result;
}