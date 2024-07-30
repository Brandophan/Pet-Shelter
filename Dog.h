#pragma once
#include "Pets.h"

class Dog : public Pets
{

public: 
	Dog(std::string n, int id, std::string breed, int age, std::string active, bool walk) : Pets(n, id, breed, age), activity_level(active), needs_walk(walk) {};
	Dog(std::string n, int id, std::string breed, int age, int days, std::string active, bool walk) : Pets(n, id, breed, age, days), activity_level(active), needs_walk(walk) {};
	//accessors 
	std::string getActivity() const; 
	bool getNeedWalk() const; 
	virtual std::string GetAnimalType();
	virtual void displayInventory();
	int groom();
	virtual void getGrooming(); 
	virtual std::string GetAnimalCharacteristics();

private:
	std::string activity_level;
	bool needs_walk;
	
};
