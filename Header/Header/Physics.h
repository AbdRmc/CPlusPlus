//#pragma once
double calculateForce(double mass, double acceleration);

Vector3 calculateAcceleration(Vector3 force, double mass);

Vector3 updateVelocity(Vector3 velocity, Vector3 acceleration, double dt);