#pragma once
#include"C_Pet.h"
class C_Parrot :
	public C_Pet
{
private:
	const char* _species;
	bool can_talk;
public:
	C_Parrot() : C_Pet()
	{
		this->_species = nullptr;
		this->can_talk = false;
	}
	C_Parrot(short age, const char* name, const char* breed, bool can)
	{
		this->age = age;
		this->name = name;
		this->_species = breed;
		this->can_talk = can;
	}
	explicit operator C_Pet()
	{
		return C_Pet(this->age, this->name);
	}
	friend std::ostream& operator<<(std::ostream& out, const C_Parrot& obj)
	{
		out << "Parrot\n" << (C_Pet)obj << "Species: " << obj._species << "\n";
		if (obj.can_talk == true)
		{
			out << "Can talk\n";
		}
		else
		{
			out << "Cannot talk\n";
		}
		return out;
	}
};