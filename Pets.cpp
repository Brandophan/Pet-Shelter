#include "Pets.h"


//implemenations section
Pets::Pets()  //constructor with no parameters
{

	this->id = 0;
	this->days_in_shelter = 0;
	this->breed = "";
	this->name = "";
	this->age = 0;
	this->numPets++;
	this->adopter = new InterestedAdopter * [CLASS_ADOPT];
}
Pets::Pets(std::string n, int id, std::string breed, int age, int days) // constructor with paramenters
{

	this->name = n;
	this->id = id;
	this->breed = breed;
	this->age = age;
	this->days_in_shelter = days;
	this->adopter = new InterestedAdopter * [CLASS_ADOPT];
	this->numPets++;
}
Pets::Pets(std::string n, int id, std::string breed, int age) // constructor with parameters
{

	this->name = n;
	this->id = id;
	this->breed = breed;
	this->age = age;
	this->days_in_shelter = 0; 
	this->numPets++;
	this->adopter = new InterestedAdopter * [CLASS_ADOPT];
}
//assessor functions
std::string Pets::getName() const	// assessor
{
	return this->name;
}
std::string Pets::getBreed() const	// assessor
{
	return this->breed;
}
int Pets::getAge() const	//assessor
{
	return age;
}
int Pets::getId() const		//assessor
{
	return id;
}
int Pets::getDaysInShelter() const	//assesspr
{
	return this->days_in_shelter;
}
int Pets::getNumPets() const
{
	return numPets;
}
int Pets::get_Adopters() const
{
	return this->num_adopters;
}
std::string Pets::GetAnimalType()
{
	return "";
}
//mutator functions
void Pets::incrementDaysShelter() //mutator
{
	this->days_in_shelter++;
}
void Pets::setDaysInShelter(int days) // mutator
{
	this->days_in_shelter = days;
}
void Pets::resetDaysShelter() //mutator
{
	for (int i = 0; i < CLASS_PET; i++)
	{
		pets[i]->setDaysInShelter(0);
	}
}
void Pets::ResetNumPets() //mutator
{
	this->numPets = 0;
}
void Pets::displayInventory()
{
	if (getNumPets() == 0)
	{
		std::cout << "No Pets in the shelter." << std::endl;
		return;
	}
	else
	{
		// just use the getters i created to access the data members
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "ID: " << getId() << std::endl;
		std::cout << "Breed: " << getBreed() << std::endl;
		std::cout << "Age: " << getAge() << std::endl;
		std::cout << "Days in shelter: " << getDaysInShelter() << std::endl;
	}
}
void Pets::resetNumAdopters()
{
	this->num_adopters = 0;
}
void Pets::AddAdopter()
{
	std::string adopters;
	std::cout << "Are there any more adopters? (yes or no): ";
	std::cin >> adopters;
	if (adopters == "yes")
	{
		std::cin.ignore(100, '\n');
		std::string other_adopters;
		std::string phone_number;
		std::string name_adopt;
		std::cout << std::endl;
		std::cout << "For every pet added, there can be 3 suitable adopters" << std::endl;
		do {
			if (get_Adopters() >= CLASS_ADOPT)
			{

				std::cout << "Maximum number of adopters reached for this pet." << std::endl;
				break;
			}
			std::cout << "Please enter Phone Number and Name of the Interested Adopters" << std::endl;
			std::cout << "Name: ";
			std::getline(std::cin, name_adopt);
			std::cout << "Phone Number: ";
			std::getline(std::cin, phone_number);
			this->adopter[num_adopters] = new InterestedAdopter(name_adopt, phone_number);
			std::cout << "New Adopter added for the current pet." << std::endl;
			this->num_adopters++;
			if (get_Adopters() >= CLASS_ADOPT)
			{

				std::cout << "Maximum number of adopters reached for this pet." << std::endl;
				break;
			}
			std::cout << "Are there any more adopters? (yes or no): ";
			std::cin >> other_adopters;
			std::cin.ignore(100, '\n');
		} while (other_adopters == "yes");
	}
	
}
void Pets::AddSingleAdopter(InterestedAdopter* other_adopter)
{
	if (get_Adopters() >= CLASS_ADOPT)
	{
		std::cout << "Maximum number of adopters reached for this pet." << std::endl;
		return;
	}
	this->adopter[num_adopters] = other_adopter;
	this->num_adopters++;
}
void Pets::DisplayAdopters() 
{
	if (get_Adopters() == 0)
	{
		std::cout << "No Adopters availiable." << std::endl;
		return;
	}
	else if (get_Adopters() <= CLASS_ADOPT)
	{
		for (int i = 0; i < get_Adopters(); i++)
		{
			std::cout << "Adopter " << i + 1 << ": ";
			adopter[i]->print_info();
		}
	}
}
void Pets::getGrooming()
{
	std::cout << "This Pet needs grooming." << std::endl;
}

void Pets::removeAdopter()
{
	if (get_Adopters() == 0)
	{
		std::cout << "No adopters to remove." << std::endl; 
		return;
	}
	std::cout << "Removing Adopter with Name (" << adopter[0]->get_name() << "), with phone number: (" << adopter[0]->get_number() << ")"<<std::endl; 
	delete adopter[0]; 
	for (int i = 0; i < get_Adopters(); i++)
	{
		adopter[i] = adopter[i + 1]; 
	}
	adopter[get_Adopters() - 1] = nullptr; 
	this->num_adopters--; 
}
std::string Pets::GetAnimalCharacteristics()
{
	return ""; 
}
std::string Pets::output_adopters()
{
	std::string output;
	for (int i = 0; i < get_Adopters(); i++)
	{
		output += adopter[i]->get_name(); 
		output += ",";
		output+=adopter[i]->get_number();
		output += ",";
	}
	return output;
}






