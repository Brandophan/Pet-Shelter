#include "Dog.h"
// assessors functions
std::string Dog::getActivity() const
{
	return this->activity_level; 
}
bool Dog::getNeedWalk() const
{
	return this->needs_walk; 
}
std::string Dog::GetAnimalType()
{
	return "Dog";
}
void Dog::displayInventory()
{
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "ID: " << getId() << std::endl;
	std::cout << "Breed: " << getBreed() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Days in shelter: " << getDaysInShelter() << std::endl;
	std::cout << "Activity Level: " << getActivity() << std::endl;
	if (getNeedWalk())
	{
		std::cout << "Needs a walk: true" << std::endl;
	}
	else {
		std::cout << "Needs a walk: false" << std::endl;
	}
}
int Dog::groom()
{
	int groomingInterval = 1;
	return getDaysInShelter() / groomingInterval;
}
void Dog::getGrooming()
{
	std::cout << std::endl;
	int groomingInterval = 1;
	std::cout << " Pet Name:"<< getName() << "(" << GetAnimalType() << ")" << std::endl;
	std::cout << getName()<< " has been in the shelter for " << getDaysInShelter() << " days."<<std::endl;
	std::cout << getName()<<" has been groomed " << groom() << " times." << std::endl; 
	int daysSinceLastGrooming = getDaysInShelter() % groomingInterval;
	int daysUntilNextGrooming = groomingInterval - daysSinceLastGrooming;
	int nextGroomingDate = getDaysInShelter() + daysUntilNextGrooming;
	std::cout << " The next grooming for " << getName()<< " is in " << daysUntilNextGrooming << " days, on day "<< nextGroomingDate << "." << std::endl;
}
std::string Dog::GetAnimalCharacteristics()
{
	std::string output = getActivity() + ", ";
	if (getNeedWalk())
	{
		output += "yes";
	}
	else {
		output += "no";
	}
	return output;
}


