#pragma once
struct Vector3
{
    double x, y, z;
};

Vector3 add(Vector3 a, Vector3 b);
Vector3 scale(Vector3 v, double scalar);