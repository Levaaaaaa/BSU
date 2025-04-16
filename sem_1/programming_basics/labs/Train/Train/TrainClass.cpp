#include "TrainClass.h"

TRAIN::TRAIN() {
	destination = "";
	numberOfTrain = -1;
	isExpress = false;
}
TRAIN::TRAIN(std::string _destination, int _numberOfTrain, bool _isExpress)
{
	destination = _destination;
	numberOfTrain = _numberOfTrain;
	isExpress = _isExpress;

	//std::cout << "Constructor of initialization\n";
}

TRAIN::TRAIN(const TRAIN& oldTrain)
{
	destination = oldTrain.destination;
	numberOfTrain = oldTrain.numberOfTrain;
	isExpress = oldTrain.isExpress;

	//std::cout << "Copy constructor\n";
}

/*
void TRAIN::TrainsHeadingToTheDestination(std::vector<TRAIN> trains, std::string _destination)
{
	for (size_t i = 0; i < trains.size(); i++)
	{
		if (trains[i].destination.compare(_destination)) {
			std::cout << "\n";
			std::cout << trains[i].trainToString();
			std::cout << "\n";
		}
	}
}*/

std::vector<TRAIN> TRAIN::CreateVectorOfTrainsToDestination(std::vector<TRAIN> trains, std::string _destination)
{
	std::vector<TRAIN> result;

	for (size_t i = 0; i < trains.size(); i++)
	{
		if (!trains[i].destination.compare(_destination)) {
			result.push_back(trains[i]);
		}
	}

	return result;
}

std::vector<TRAIN> TRAIN::CreateVectorOfExpress(std::vector<TRAIN> trains, std::string _destanation)
{
	std::vector<TRAIN> result;
	std::vector<TRAIN> trainsSoughtForDestination = CreateVectorOfTrainsToDestination(trains, _destanation);

	for (size_t i = 0; i < trainsSoughtForDestination.size(); i++)
	{
		if (trainsSoughtForDestination[i].isExpress) {
			result.push_back(trainsSoughtForDestination[i]);
		}
	}

	return result;
}

std::string TRAIN::trainToString() const {
	std::string number;

	std::ostringstream oss;
	oss << numberOfTrain;
	number = oss.str();

	std::string _isExpress = isExpress ? "yes" : "no";
	/*
	std::string result = "\n\tThe destination: " + destination + "\n\tThe number of train: " + number + 
						"\n\tIs the train express: " + _isExpress + "\n";
	*/
	std::string result = "\n\tThe train number " + number + "\n\tis running to " + destination +
		"\n\tIs the train express: " + _isExpress + "\n";


	return result;
}

void TRAIN::printTrains(std::vector<TRAIN> trains)
{
	for (size_t i = 0; i < trains.size(); i++)
	{
		std::cout << "\n";
		std::cout << trains[i].trainToString();
		std::cout << "\n";
	}
}

void TRAIN::printVectorOfTrainsToDestination(std::vector<TRAIN> trains, std::string _destination)
{
	std::vector<TRAIN> result = CreateVectorOfTrainsToDestination(trains, _destination);

	if (result.size() != 0) {
		std::vector<TRAIN> result = CreateVectorOfTrainsToDestination(trains, _destination);

		std::cout << "\nTo " << _destination << " go the next trains:\n";
		printTrains(result);
	}
	else {
		std::cout << "\nTo " << _destination << " no trains running\n";
	}
}
void TRAIN::printVectorOfExpress(std::vector<TRAIN> trains, std::string _destination)
{
	std::vector<TRAIN> result = CreateVectorOfExpress(trains, _destination);

	if (result.size() != 0) {
		std::cout << "\nTo " << _destination << " go the next expresses:\n";
		printTrains(result);
	}
	else {
		std::cout << "\nTo " << _destination << " no expresses running\n";
	}
}