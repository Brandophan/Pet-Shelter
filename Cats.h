#pragma once
#include "Pets.h"

class Cats : public Pets
{
public: 

	Cats(std::string n, int id, std::string breed, int age, std::string fur, bool lazy) : Pets(n, id, breed, age), fur_color(fur), is_lazy(lazy) {};
	Cats(std::string n, int id, std::string breed, int age, int days, std::string fur, bool lazy) : Pets(n, id, breed, age, days), fur_color(fur), is_lazy(lazy) {};
	//Assessors 
	std::string getFurColor(); 
	bool getLazy(); 
	virtual std::string GetAnimalType();
	virtual void displayInventory();
	virtual void getGrooming();
	int differentGroom(); 
	virtual std::string GetAnimalCharacteristics();
private:
	std::string fur_color; 
	bool is_lazy;
};
