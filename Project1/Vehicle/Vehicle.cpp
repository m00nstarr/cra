#include "Refuel.cpp"

class Vehicle {
public:
	Vehicle(int maxFuel) {
		fuelOperator = new FuelOperator(maxFuel);
	}

	// this is not a car's responsibility.
	void ReFuel() {
		fuelOperator->ReFuel();
	}

	int GetMaxFuel() {
		return fuelOperator->GetMaxFuel();
	}

	int GetRemainingFuel() {
		return fuelOperator->GetRemainingFuel();
	}

	void SetRemainingFuel(int remaining_fuel) {
		fuelOperator->SetRemainingFuel(remaining_fuel);
	}

	void Accelerate() {
		fuelOperator->SetRemainingFuel(fuelOperator->GetRemainingFuel() - 1);
	}

private:
	FuelOperator* fuelOperator;
};