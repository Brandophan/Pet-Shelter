#include "Cats.h"
std::string Cats::getFurColor()
{
	return this->fur_color; 
}
bool Cats::getLazy()
{
	return this->is_lazy; 
}
std::string Cats::GetAnimalType()
{
	return "Cat";
}
void Cats::displayInventory()
{
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "ID: " << getId() << std::endl;
	std::cout << "Breed: " << getBreed() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Days in shelter: " << getDaysInShelter() << std::endl;
	std::cout << "Fur Color: " << getFurColor() << std::endl;
	if (getLazy())
	{
		std::cout << "Is lazy: yes" << std::endl;
	}
	else
	{
		std::cout << "Is lazy: no"  << std::endl;
	}
}
int Cats::differentGroom()
{
	int interval = 3;
	return getDaysInShelter() / interval;
}
void Cats::getGrooming()
{
	std::cout << std::endl;
	int groomingInterval = 3;
	std::cout << " Pet Name:" << getName() << "(" << GetAnimalType() << ")" << std::endl;
	std::cout << getName() << " has been in the shelter for " << getDaysInShelter() << " days." << std::endl;
	std::cout << getName() << " has been groomed " << differentGroom() << " times." << std::endl;
	int daysSinceLastGrooming = getDaysInShelter() % groomingInterval;
	int daysUntilNextGrooming = groomingInterval - daysSinceLastGrooming;
	int nextGroomingDate = getDaysInShelter() + daysUntilNextGrooming;
	std::cout << " The next grooming for " << getName() << " is in " << daysUntilNextGrooming << " days, on day " << nextGroomingDate << "." << std::endl;
}
std::string Cats::GetAnimalCharacteristics()
{
	std::string output = getFurColor() + ", "; 
	if (getLazy())
	{
		output += "true"; 
	}
	else
	{
		output += "false";
	}
	return output; 
}

