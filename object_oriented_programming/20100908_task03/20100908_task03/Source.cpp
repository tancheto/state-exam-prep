#include <iostream>
using namespace std;

class Computer {

private:

	bool isOn;
	short cpuNum;
	int ram;

public:

	static long count;

	Computer() {
		setIsOn(0);
		setRam(0);
		setCpuNum(0);

		count++;
	}

	Computer(const Computer& o) {
		setIsOn(o.isOn);
		setRam(o.ram);
		setCpuNum(o.cpuNum);
		
		count++;
	}

	Computer(const bool isOn, const short &cpuNum, const int &ram) {
		setIsOn(isOn);
		setRam(ram);
		setCpuNum(cpuNum);

		count++;
	}

	void setIsOn(const bool isOn) {
		this->isOn = isOn;
	}

	const bool getIsOn() {
		return this->isOn;
	}

	void setRam(const int& ram) {
		this->ram = ram;
	}

	const int& getRam() {
		return this->ram;
	}

	void setCpuNum(const short& cpuNum) {
		this->cpuNum = cpuNum;
	}

	const double& getCpuNum() {
		return this->cpuNum;
	}
};

long Computer::count = 0;

int main() {

	Computer myComputer1(true, 4, 16);
	Computer myComputer2;
	Computer myComputer3(myComputer1);

	cout << Computer::count << endl;

	return 0;
}