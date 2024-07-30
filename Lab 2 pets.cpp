// Lab 1 Pets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Pets.h" 
#include "InterestedAdopter.h"
#include "Cats.h"
#include "Dog.h"

void greetUser();
bool shouldUseProgram();
bool hasCurrentInventory();
int getChoice();
int ReadFilePet(Pets* pet[], int count);
int getNewPet(Pets* ReadPet[], int ReadCount);
void display_the_Inventory(Pets* pets[], int count);
int resetInventory(Pets* pets[], int count);
void get_longest_pet(Pets* pet[], int num_pets);
void output_to_file(Pets* pets[], int count);
void groomInfo(Pets* pet[], int count);
bool stringToBool(std::string str);
int weeklyCheckup(Pets* pet[], int count);
int removeNullptr(Pets* pet[], int count);

const int MAX_PETS = 10;
int main()
{
	Pets* ReadPet[MAX_PETS];
	int ReadCount = 0;
	greetUser();
	if (!shouldUseProgram())  
	{
		return 0;
	}
	if (hasCurrentInventory()) 
	{
		ReadCount = ReadFilePet(ReadPet, ReadCount);
	}
	bool value = true;
	while (value)
	{
		int main_choice = getChoice();
		if (main_choice == 1)  
		{
			if (ReadCount >= MAX_PETS) 
			{
				std::cout << "The shelter has met its maximum capacity of pets" << std::endl;
			}
			else 
			{
				ReadCount = getNewPet(ReadPet, ReadCount);
			}
		}
		else if (main_choice == 2) 
		{
			display_the_Inventory(ReadPet, ReadCount);
		}
		else if (main_choice == 3) 
		{
			groomInfo(ReadPet, ReadCount);
		}
		else if (main_choice == 4) 
		{
			ReadCount = weeklyCheckup(ReadPet, ReadCount); 
			ReadCount = removeNullptr(ReadPet, ReadCount);
		}
		else if (main_choice == 5)
		{
			ReadCount = resetInventory(ReadPet, ReadCount);
		}
		else if (main_choice == 6)
		{
			get_longest_pet(ReadPet, ReadCount);
			output_to_file(ReadPet, ReadCount);
			value = false;
		}
		else 
		{
			std::cout << "Invalid choice. Please enter a number from 1 to 6." << std::endl;
		}
	}
	system("pause>0");
}


void greetUser() 
{
	std::cout << "Welcome to the pet shelter management program" << std::endl;
}

bool shouldUseProgram()  
{
	std::string response;

	std::cout << "This program will allow you to keep track of the pets in the shelter" << std::endl;
	std::cout << "Would you like to use the program?" << std::endl;
	std::cout << "Please type (yes or no): ";
	std::cin >> response; 
	return response == "yes"; 
} 
bool hasCurrentInventory()
{
	std::string response;
	std::cout << "Is there current inventory?" << std::endl;
	std::cout << "Please enter (yes or no): ";
	std::cin >> response;
	return response == "yes";
}
int getChoice()
{
	std::cout << std::endl;
	std::cout << "What would you like to do" << std::endl;
	std::cout << "1. Add a new pet" << std::endl;
	std::cout << "2. Display current inventory" << std::endl;
	std::cout << "3. Grooming Information" << std::endl;
	std::cout << "4. Weekly Checkup" << std::endl;
	std::cout << "5. Clear the Inventory" << std::endl;
	std::cout << "6. Exit program" << std::endl;
	int choice = 0;
	std::cin >> choice;
	return choice; 
}
bool stringToBool(std::string str)
{
	if (str == "true" || str == "True" || str == "yes" || str == "Yes")
	{
		return true;
	}
	else if (str == "false" || str == "False" || str == "no" || str == "No")
	{
		return false;
	}
}
int ReadFilePet(Pets* pet[], int count)
{
	// Cat, Max, 1, Labrador Retriever, 3, 5, Bob, 123 - 456 - 7890, Jane, 234 - 567 - 8901, John, 345 - 678 - 9012
	std::string FileName;
	std::cout << "Please enter the file name: ";
	std::cin >> FileName;
	std::cin.ignore();
	std::ifstream InFile(FileName);
	if (InFile.fail())
	{
		std::cout << "Your not in the file" << std::endl;
		return count;
	}
	std::string line;
	while (getline(InFile, line) && count <= MAX_PETS)
	{
		std::string animal_type;
		std::string name;
		std::string breed;
		int age;
		int id;
		int days;
		std::string adopter_name1;
		std::string adopter_phone1;
		std::string adopter_name2;
		std::string adopter_phone2;
		std::string adopter_name3;
		std::string adopter_phone3;
		std::stringstream ss(line);
		std::string field;
		getline(ss, field, ','); 
		animal_type = field; 
		animal_type[0] = toupper(animal_type[0]);
		if (animal_type == "Cat")
		{
			//Cats(std::string n, int id, std::string breed, int age, int days, std::string fur, bool lazy) : Pets(n, id, breed, age, days), fur_color(fur), is_lazy(lazy)
			std::string fur_color; 
			std::string lazy_str; 
			bool is_lazy;
			getline(ss, field, ',');
			name = field;
			getline(ss, field, ',');
			id = std::stoi(field);
			getline(ss, field, ',');
			breed = field;
			getline(ss, field, ',');
			age = std::stoi(field);
			getline(ss, field, ',');
			days = std::stoi(field);
			getline(ss, field, ',');
			fur_color = field;
			getline(ss, field, ',');
			lazy_str = field;
			if (lazy_str == "true")
			{
				is_lazy = false;
			}
			else
			{
				is_lazy = true;
			}
			pet[count] = new Cats(name, id, breed, age, days, fur_color, is_lazy);
			getline(ss, field, ',');
			adopter_name1 = field;
			getline(ss, field, ',');
			adopter_phone1 = field;
			if (!adopter_name1.empty())
			{
				pet[count]->AddSingleAdopter(new InterestedAdopter(adopter_name1, adopter_phone1));
			}
			getline(ss, field, ',');
			adopter_name2 = field;
			getline(ss, field, ',');
			adopter_phone2 = field;
			if (!adopter_name2.empty())
			{
				pet[count]->AddSingleAdopter(new InterestedAdopter(adopter_name2, adopter_phone2));
			}
			getline(ss, field, ',');
			adopter_name3 = field;
			getline(ss, field, ',');
			adopter_phone3 = field;
			if (!adopter_name3.empty())
			{
				pet[count]->AddSingleAdopter(new InterestedAdopter(adopter_name3, adopter_phone3));
			}
			count++;
		}
		else if (animal_type == "Dog")
		{
			std::string active_level;
			std::string walk_str; 
			bool need_walk; 
			//Dog(std::string n, int id, std::string breed, int age, int days, std::string active, bool walk) : Pets(n, id, breed, age, days), activity_level(active), needs_walk(walk) {};
			getline(ss, field, ',');
			name = field;
			getline(ss, field, ',');
			id = std::stoi(field);
			getline(ss, field, ',');
			breed = field;
			getline(ss, field, ',');
			age = std::stoi(field);
			getline(ss, field, ',');
			days = std::stoi(field);
			getline(ss, field, ','); 
			active_level = field; 
			getline(ss, field, ',');
			walk_str = field; 
			if (walk_str == "yes")
			{
				need_walk = false;
			}
			else
			{
				need_walk = true;
			}
			pet[count] = new Dog(name, id, breed, age, days, active_level, need_walk);
			getline(ss, field, ',');
			adopter_name1 = field;
			getline(ss, field, ',');
			adopter_phone1 = field;
			if (!adopter_name1.empty())
			{
				pet[count]->AddSingleAdopter(new InterestedAdopter(adopter_name1, adopter_phone1));
			}
			getline(ss, field, ',');
			adopter_name2 = field;
			getline(ss, field, ',');
			adopter_phone2 = field;
			if (!adopter_name2.empty())
			{
				pet[count]->AddSingleAdopter(new InterestedAdopter(adopter_name2, adopter_phone2));
			}
			getline(ss, field, ',');
			adopter_name3 = field;
			getline(ss, field, ',');
			adopter_phone3 = field;
			if (!adopter_name3.empty())
			{
				pet[count]->AddSingleAdopter(new InterestedAdopter(adopter_name3, adopter_phone3));
			}
			count++;
		}
	}
	InFile.close();
	std::cout << "Read in " << count << " pets from " << FileName << std::endl;
	return count;
	
}
int getNewPet(Pets* ReadPet[], int ReadCount)
{
	std::string choice;
	std::cout << "Would you like to add a Cat or Dog? "; 
	std::cin >> choice; 
	choice[0] = toupper(choice[0]);
	if (choice == "Cat")
	{
		for (int i = 0; i < ReadCount; i++)
		{
			ReadPet[i]->incrementDaysShelter();
		}
		//Cats(std::string n, int id, std::string breed, int age, int days, std::string fur, bool lazy) : Pets(n, id, breed, age, days), fur_color(fur), is_lazy(lazy);
		std::string name;
		int id;
		std::string breed;
		int age;
		std::string fur_color;
		std::string input_str;
		bool is_lazy;
		int days_shelter;
		std::cout << "Enter the new Cats name: ";
		std::cin >> name;
		std::cout << "Enter the new Cats ID: ";
		std::cin >> id;
		std::cout << "Enter the new Cats breed: ";
		std::cin >> breed;
		std::cout << "Enter the new Cats age: ";
		std::cin >> age; 
		std::cout << "Days in Shelter: "; 
		std::cin >> days_shelter;
		std::cout << "Enter the new cats fur color: ";
		std::cin >> fur_color;
		std::cout << "Is the Cat lazy (yes or no): "; 
		std::cin >> input_str;
		is_lazy = stringToBool(input_str);
		ReadPet[ReadCount] = new Cats(name, id, breed, age, days_shelter,fur_color, is_lazy);
		std::cin.ignore(100, '\n');
		ReadPet[ReadCount]->AddAdopter();
		std::cout << "New pet added to the shelter." << std::endl << std::endl;
		ReadCount++;
	}
	else if (choice == "Dog")
	{ 
		for (int i = 0; i < ReadCount; i++)
		{
			ReadPet[i]->incrementDaysShelter();
		}
		//Dog(std::string n, int id, std::string breed, int age, int days, std::string active, bool walk) : Pets(n, id, breed, age, days), activity_level(active), needs_walk(walk) {};
		std::string name;
		int id;
		std::string breed;
		int age;
		std::string activity_level; 
		std::string input_str;
		bool walk; 
		int days_shelter;
		std::cout << "Enter the new Dogs name: ";
		std::cin >> name;
		std::cout << "Enter the new Dogs ID: ";
		std::cin >> id;
		std::cout << "Enter the new Dogs breed: ";
		std::cin >> breed;
		std::cout << "Enter the new Dogs age: ";
		std::cin >> age;
		std::cout << "Days in Shelter: ";
		std::cin >> days_shelter;
		std::cout << "What is the Dogs activity level? "; 
		std::cin >> activity_level; 
		std::cout << "Does the Dog need a walk (yes or no): "; 
		std::cin >> input_str; 
		walk = stringToBool(input_str);
		ReadPet[ReadCount] = new Dog(name, id, breed, age,days_shelter, activity_level, walk); 
		std::cin.ignore(100, '\n');
		ReadPet[ReadCount]->AddAdopter();
		std::cout << "New pet added to the shelter." << std::endl << std::endl;
		ReadCount++;
	}	

	return ReadCount++;
}


void display_the_Inventory(Pets* pets[], int count)
{
	if (count == 0) 
	{
		std::cout << "The shelter has no pets at the moment." << std::endl << std::endl;
	}
	else 
	{
		std::cout << std::endl << std::endl;
		std::cout << "Current inventory" << std::endl;
		for (int i = 0; i < count; i++)
		{
			std::cout << std::endl;
			std::cout << "Pet #" << i + 1 << " (" << pets[i]->GetAnimalType() << ")" << std::endl;
			pets[i]->displayInventory();
			pets[i]->DisplayAdopters();
		}
	}
}
int resetInventory(Pets* pets[], int count)
{
	for (int i = 0; i < count; i++)
	{
		delete pets[i];
		pets[i] = nullptr; 
	}
	count = 0;
	std::cout << "Inventory has been reset." << std::endl;
	return count;
}
void get_longest_pet(Pets* pet[], int num_pets)
{
	if (num_pets == 0) 
	{
		std::cout << "No pets in the shelter. " << std::endl;

	}
	int longest_days = pet[0]->getDaysInShelter();
	int longest_index = 0;
	for (int i = 0; i < num_pets; i++)
	{
		if (pet[i]->getDaysInShelter() > longest_days)
		{
			longest_days = pet[i]->getDaysInShelter();
			longest_index = i;
		}
	}
	std::cout << std::endl;
	std::cout << "The following pet has been in the shelter the longest: " << std::endl;
	pet[longest_index]->displayInventory();
	pet[longest_index]->DisplayAdopters();
}
void output_to_file(Pets* pets[], int count)
{
	std::string choice;
	std::cout << "Would you like to output the current pets in the shelter to a new file? ";
	std::cin >> choice;
	if (choice == "yes")
	{
		std::ofstream output("output.txt");
		if (output.is_open() == true)
		{
			std::cout << "The File is open!" << std::endl;
			std::cout << "Thank you for using the Pet Shelter Program" << std::endl;
		}
		else
		{
			std::cout << "The File is not open" << std::endl;
		}
		for (int i = 0; i < count; i++)
		{
			output << pets[i]->GetAnimalType() << ", "<< pets[i]->getName() << ", " << pets[i]->getId() << ", " << pets[i]->getBreed() << ", " << pets[i]->getAge() << ", " << pets[i]->getDaysInShelter() << ", "<< pets[i]->GetAnimalCharacteristics() << ", " << pets[i]->output_adopters() << std::endl;
		}
	}
	else
	{
		std::cout << "Thank you for using the Pet Shelter Program" << std::endl;
	}
}
void groomInfo(Pets* pet[], int count)
{
	for (int i = 0; i < count; i++)
	{
		pet[i]->getGrooming();
	}
}
int weeklyCheckup(Pets* pet[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (pet[i]->getDaysInShelter() >= 15)
		{
			std::cout << std::endl;
			std::cout << "Pet " << i + 1 << ": (" << pet[i]->getName() << ") has been in the shelter for 15 days." << std::endl;
			std::cout << "The Pet (" << pet[i]->getName() << ") has been adopted." << std::endl;
			delete pet[i];
			pet[i] = nullptr;
		}
		else if (pet[i]->getDaysInShelter() == 10)
		{
			std::cout << std::endl;
			std::cout << "Pet " << i + 1 << ":(" << pet[i]->getName() << ") has been in the shelter for 10 days." << std::endl;
			std::cout << "Please contact the interested adopters." << std::endl;
			pet[i]->DisplayAdopters();
			std::cout << "Is there an interested adopter? ";
			std::string value;
			std::cin >> value;
			if (value == "yes")
			{
				pet[i]->removeAdopter();
				std::cout << "The Pet (" << pet[i]->getName() << ") has been adopted. " << std::endl;
				delete pet[i];
				pet[i] = nullptr;
			}
			std::cin.ignore(100, '\n');
		}
		else if (pet[i]->getDaysInShelter() % 7 == 0)
		{
			std::cout << std::endl;
			std::cout << "Pet " << i + 1 << ":(" << pet[i]->getName() << ") needs a checkup." << std::endl;
			std::cout << std::endl;
		}
		else if (pet[i]->getDaysInShelter() > 7 && pet[i]->getDaysInShelter() < 10)
		{
			std::cout << std::endl;
			std::cout << "Pet " << i + 1 << ":(" << pet[i]->getName() << ")" << " is " << 10 - pet[i]->getDaysInShelter() << " days from needing to contact an Interested Adopter." << std::endl;
			std::cout << std::endl;
		}
		else if (pet[i]->getDaysInShelter() > 10 && pet[i]->getDaysInShelter() < 15)
		{
			std::cout << std::endl;
			std::cout << "Pet " << i + 1 << ":(" << pet[i]->getName() << ") is " << 15 - pet[i]->getDaysInShelter() <<  " days from exceeding 15 days in the shelter. Should get ready for adoption." << std::endl;
			std::cout << std::endl;
		}
		else if (pet[i]->getDaysInShelter() < 7)
		{
			std::cout << std::endl;
			std::cout << "Pet " << i + 1 << ":(" << pet[i]->getName() << ")" << " is " << 7- pet[i]->getDaysInShelter() << " days from needing a checkup." << std::endl;
			std::cout << std::endl;
		}
	}
	return count;
}
int removeNullptr(Pets* pet[], int count)
{
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (pet[i] != nullptr) 
		{
			pet[index] = pet[i];
			index++;
		}
	}
	std::cout << std::endl;
	std::cout << "Number of pets remaning: " << index << std::endl; 
	return index;
}




