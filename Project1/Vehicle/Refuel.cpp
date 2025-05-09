class FuelOperator {
public:
	FuelOperator(int maxFuel) {
		max_fuel_ = maxFuel;
		remaining_fuel_ = maxFuel;
	}

	void ReFuel() {
		remaining_fuel_ = max_fuel_;
	}

	int GetMaxFuel() {
		return max_fuel_;
	}

	int GetRemainingFuel() {
		return remaining_fuel_;
	}

	void SetRemainingFuel(int remaining_fuel) {
		remaining_fuel_ = remaining_fuel;
	}

private:
	int max_fuel_;
	int remaining_fuel_;
};