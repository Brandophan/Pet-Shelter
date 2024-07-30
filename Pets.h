#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "InterestedAdopter.h"

const int CLASS_PET = 10;
const int CLASS_ADOPT = 3;
class Pets
{
public:
	// constructor with no parameters
	Pets();
	//constructor with parameters
	Pets(std::string n, int id, std::string breed, int age);
	Pets(std::string n, int id, std::string breed, int age, int days);

	void incrementDaysShelter(); // mutator
	void resetDaysShelter(); //mutator
	void setDaysInShelter(int days); // mutator
	void ResetNumPets();//mutator

	std::string getName() const;  // assessors
	std::string getBreed() const; // accessor
	int getAge() const;    // assesscor
	int getId() const;		// assessors
	int getDaysInShelter() const; // assessor
	int getNumPets() const; // assessor
	int get_Adopters() const;
	virtual std::string GetAnimalType();
	void resetNumAdopters();
	void AddSingleAdopter(InterestedAdopter* other_adopter);
	virtual void displayInventory(); 
	void AddAdopter();
	void DisplayAdopters();
	virtual void getGrooming();
	void removeAdopter();
	virtual std::string GetAnimalCharacteristics();
	std::string output_adopters();
private:
	Pets* pets[CLASS_PET];
	std::string name;
	std::string breed;
	int id;
	int days_in_shelter;
	int age;
	int numPets = 0;
	InterestedAdopter** adopter = nullptr;
	int num_adopters = 0;
};




