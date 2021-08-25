#pragma once
#include"C_Pet.h"
class C_Dog :
	public C_Pet
{
private:
	const char* _breed;
public:
	C_Dog() : C_Pet()
	{
		this->_breed = nullptr;
	}
	C_Dog(short age, const char* name, const char* breed)
	{
		this->age = age;
		this->name = name;
		this->_breed = breed;
	}
	explicit operator C_Pet()
	{
		return C_Pet(this->age, this->name);
	}
	friend std::ostream& operator<<(std::ostream& out, const C_Dog& obj)
	{
		out << "Dog\n" << (C_Pet)obj << "Breed: " << obj._breed << "\n";
		return out;
	}
};