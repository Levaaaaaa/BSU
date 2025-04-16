#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class TRAIN {
private:
	std::string destination;
	int numberOfTrain;
	bool isExpress;

	std::vector<TRAIN> CreateVectorOfTrainsToDestination(std::vector<TRAIN>, std::string);
	std::vector<TRAIN> CreateVectorOfExpress(std::vector<TRAIN>, std::string);

public:

	TRAIN();
	TRAIN(std::string, int, bool _isExpress = false); //constructor of initialization
	TRAIN(const TRAIN&);	//constructor of copy

	std::string trainToString() const;

	//void TrainsHeadingToTheDestination(std::vector<TRAIN>, std::string);

	void printTrains(std::vector<TRAIN>);

	void printVectorOfTrainsToDestination(std::vector<TRAIN>, std::string);

	void printVectorOfExpress(std::vector<TRAIN>, std::string);

	std::string getDestination() { return destination; }
	void setDestination(std::string newDestination) { destination = newDestination; }

	int getNumerOfTrain() { return numberOfTrain; }
	void setDestination(int newNumerOfTrain) { numberOfTrain = newNumerOfTrain; }

	bool getIsExpress() { return isExpress; }
	void setIsExpress() { isExpress = !isExpress; }
};
