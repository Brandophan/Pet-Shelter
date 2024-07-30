#include "InterestedAdopter.h"


InterestedAdopter::InterestedAdopter()
{
	this->name = "";
	this->number = ""; 
}
InterestedAdopter::InterestedAdopter(std::string n, std::string p)
{
	this->name = n; 
	this->number = p; 
}
std::string InterestedAdopter::get_name() const
{
	return this->name; 
}
std::string InterestedAdopter::get_number() const
{
	return this->number; 
}
void InterestedAdopter::print_info()
{
	std::cout << get_name() << "," << get_number() << std::endl;
}