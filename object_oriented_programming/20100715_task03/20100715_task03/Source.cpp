#include <iostream>
using namespace std;

class PortableComputer {

private:

	bool isWirelessNetworkOn;
	int ram;
	double frequency;

public:

	static long count;

	PortableComputer() {
		setIsWirelessNetworkOn(0);
		setRam(0);
		setFrequency(0);
	}

	PortableComputer(const PortableComputer& o) {
		setIsWirelessNetworkOn(o.isWirelessNetworkOn);
		setRam(o.ram);
		setFrequency(o.frequency);

		if (this->isWirelessNetworkOn) {
			count++;
		}
	}

	PortableComputer(const bool& isWirelessNetworkOn, const	int& ram, const	double& frequency) {
		setIsWirelessNetworkOn(isWirelessNetworkOn);
		setRam(ram);
		setFrequency(frequency);

		if (this->isWirelessNetworkOn) {
			count++;
		}
	}

	void setIsWirelessNetworkOn(const bool isWirelessNetworkOn) {
		this->isWirelessNetworkOn = isWirelessNetworkOn;
	}

	const bool getIsWirelessNetworkOn() {
		return this->isWirelessNetworkOn;
	}

	void setRam(const int& ram) {
		this->ram = ram;
	}

	const int& getRam() {
		return this->ram;
	}

	void setFrequency(const double& frequency) {
		this->frequency = frequency;
	}

	const double& getFrequency() {
		return this->frequency;
	}
};

long PortableComputer::count = 0;

int main() {

	PortableComputer myComputer1(true, 16, 2.4);
	PortableComputer myComputer2;
	PortableComputer myComputer3(myComputer1);

	cout << PortableComputer::count << endl;

	return 0;
}