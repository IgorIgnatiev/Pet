// Pet.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"C_Cat.h"
#include"C_Dog.h"
#include"C_Parrot.h"

int main()
{
    C_Cat cat(4, "Barsik", "No");
    C_Dog dog(8, "Rex", "Labrador");
    C_Parrot parrot(3, "Kesha", "Wavy", true);
    std::cout << cat << "\n" << dog << "\n" << parrot << "\n";
}
