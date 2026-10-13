#include "Physics.h"
#include "Vector3.h"
#include <iostream>

int main()
{
    double force = calculateForce(1000, 2);

    Vector3 vec1;
    Vector3 vec2;
    double scaleFactor;
    Vector3 result1;
    Vector3 result2;

    vec1.x = 10;
    vec1.y = 20;
    vec1.z = 30;
    vec2.x = 40;
    vec2.y = 50;
    vec2.z = 60;
    scaleFactor = 5;

    result1 = add(vec1,vec2);
    result2 = scale(vec1,scaleFactor);

    std::cout << "result1 X: " << result1.x << '\n';
    std::cout << "result1 Y: " << result1.y << '\n';
    std::cout << "result1 Z: " << result1.z << '\n';

    std::cout << "result2 X: " << result2.x << '\n';
    std::cout << "result2 Y: " << result2.y << '\n';
    std::cout << "result2 Z: " << result2.z << '\n';

}