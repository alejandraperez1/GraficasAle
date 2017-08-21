/*********************************************************
Materia: Gráficas Computacionales
Fecha: 16 de agosto del 201
Autor: A0133993 Alejandra Maria Perez Aleman
*********************************************************/

#include<iostream>
#include "Circle.h"

int main()
{
	std::cout << "Hola, Mundo!" << std::endl;
	Circle killme(5);
	std::cout << killme.GetArea() << std::endl;
	std::cin.get();

	return 0;
}