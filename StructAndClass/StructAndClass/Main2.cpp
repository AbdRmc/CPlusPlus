#include <iostream>


struct VehicleParameters
{
    double mass;
    double wheelbase;
    double maxEngineForce;
    double maxBrakeForce;
};

class VehicleModel
{
private:
	VehicleParameters parameters;
	double velocity;
	double distance;
	double netForce;

public:
	void update(double dt)
	{
		double acceleration = netForce / parameters.mass;
		distance += (velocity * dt  + 0.5 * acceleration * dt * dt);
		velocity += acceleration * dt;
	}
	double getVelocity() const
	{
		return velocity;
	}
	void initialize()
	{
		velocity = 0;
		distance = 0;
		netForce = 0;
	}
	void setParameters(double mass, double wheelbase)
	{
		parameters.mass = mass;
		parameters.wheelbase = wheelbase;
	}
	void setParameters2(const VehicleParameters& params)
	{
		parameters = params;
	}
	void accelerate(double accForce) 
	{
		netForce = accForce;
	}
	void brake(double brakeForce) 
	{
		netForce = -brakeForce;
	}
	double getDistance() const
	{
		return distance;
	}
};

int main()
{
	VehicleParameters opelAstra;
	opelAstra.mass = 1500.0;
	opelAstra.wheelbase = 2.7;
	opelAstra.maxEngineForce = 5000.0;
	opelAstra.maxBrakeForce = 8000.0;

	VehicleParameters fordTruck;
	fordTruck.mass = 15000.0;
	fordTruck.wheelbase = 4.5;
	fordTruck.maxEngineForce = 30000.0;
	fordTruck.maxBrakeForce = 50000.0;

	VehicleModel passangerCar;
	passangerCar.initialize();
	//vehicle.setParameters(opelAstra.mass,opelAstra.wheelbase);
	passangerCar.setParameters2(opelAstra);

	passangerCar.accelerate(opelAstra.maxEngineForce);
	passangerCar.update(0.8);

	std::cout << "[passanger car] velocity after 5 sec= " << passangerCar.getVelocity();
	std::cout << "  distance after 5 sec= "<< passangerCar.getDistance() << '\n';

	passangerCar.brake(opelAstra.maxBrakeForce);
	passangerCar.update(0.2);

	std::cout << "[passanger car] velocity after 5 sec= " << passangerCar.getVelocity();
	std::cout << "  distance after 5 sec= "<< passangerCar.getDistance() << '\n';

	VehicleModel truck;
	truck.initialize();
	//vehicle.setParameters(opelAstra.mass,opelAstra.wheelbase);
	truck.setParameters2(fordTruck);

	truck.accelerate(fordTruck.maxEngineForce);
	truck.update(0.8);

	std::cout << "[truck] velocity after 5 sec= " << truck.getVelocity();
	std::cout << "  distance after 5 sec= "<< truck.getDistance() << '\n';



	return 0;
}