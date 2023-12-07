#include <iostream>
#include <limits>
<<<<<<< HEAD
=======
#include <string>

#include <vector>

#include <iostream>

#include <algorithm> // std::shuffle
#include <chrono> 	 // std::chrono::system_clock
#include <random>	 // std::default_random_engine
>>>>>>> 77dcacbd8cd628484ab6909b98fc7126979ca2df

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

<<<<<<< HEAD
int main() {

	const size_t statistics_count = 1;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}
=======
class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
};

int main() {
	std::vector<int> values{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const size_t statistics_count = 11;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};

	double val = 0;
	std::cout << "values after random shuffle:" << std::endl;
	std::cout << values << std::endl;

	for (size_t i = 0; i < statistics_count; ++i) {
		statistics[i]->update(values[i]);
	}
	
>>>>>>> 77dcacbd8cd628484ab6909b98fc7126979ca2df

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

<<<<<<< HEAD
	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

=======
	if (std::cin.eof()) {
		for (size_t i = 0; i < statistics_count; ++i) {
			std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
		}
	}

	// Print results if any
	

>>>>>>> 77dcacbd8cd628484ab6909b98fc7126979ca2df
	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}