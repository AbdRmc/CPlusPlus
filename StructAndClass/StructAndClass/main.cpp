#include <iostream>

struct VehicleParameters
{
	double mass;
	double wheelbase;
};

class VehicleModel
{
private:
	VehicleParameters parameters;
    double velocity;
public:
	void update(double force, double dt)
	{
		double acceleration = force / parameters.mass;
        velocity += acceleration * dt;
	}
	double getVelocity() const
	{
		return velocity;
	}
	void initialize() 
	{
		velocity = 0;
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
};


int main()
{
	VehicleParameters opelAstra;
	opelAstra.mass = 1000.0;
	opelAstra.wheelbase = 5.0;

	VehicleModel vehicle;
	vehicle.initialize();
	//vehicle.setParameters(opelAstra.mass,opelAstra.wheelbase);
	vehicle.setParameters2(opelAstra);
	vehicle.update(500,0.1);

	std::cout << vehicle.getVelocity() << '\n';


	return 0;
}