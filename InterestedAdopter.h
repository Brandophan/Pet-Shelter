#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

class InterestedAdopter
{
public: 
	InterestedAdopter(); //class constructor 
	InterestedAdopter(std::string n, std::string p);
	std::string get_name() const; //assessors 
	std::string get_number() const; 
	void print_info();
private: 
	std::string name; 
	std::string number;
};