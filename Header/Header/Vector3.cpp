#include "Vector3.h"


Vector3 add(Vector3 a, Vector3 b)
{
	Vector3 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;

	return result;
}

Vector3 scale(Vector3 a, double b)
{
	Vector3 result;
	result.x = (a.x) * b;
	result.y = (a.y) * b;
	result.z = (a.z) * b;

	return result;
}