#pragma once
#include<ostream>
class C_Pet
{
protected:
	short age;
	const char* name;
public:
	C_Pet()
	{
		this->age = 0;
		this->name = nullptr;
	}
	C_Pet(short age, const char* name)
	{
		this->age = age;
		this->name = name;
	}
	friend std::ostream& operator<<(std::ostream& out, const C_Pet& obj)
	{
		out << "Age: " << obj.age << "\nName: " << obj.name << "\n";
		return out;
	}
};