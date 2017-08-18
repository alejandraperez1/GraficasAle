/*********************************************************
Materia: Gráficas Computacionales
Fecha: 16 de agosto del 201
Autor: A0133993 Alejandra Maria Perez Aleman
*********************************************************/

#include<iostream>

//1. Calcular el perimetro de un rectangulo.
int PerimetroRectangulo(int baseP, int alturaP) {
	int perimetro = 2 * baseP + 2 * alturaP;
	return perimetro;
}

//2. Calcular el área de un triángulo.
float AreaTriangulo(float baseA, float alturaA) {
	float area = (baseA*alturaA) / 2;
	return area;
}

//3. Encontrar el número mayor en un set de tres números enteros. El programa debe regresar el mayor de los tres números enviados a la función. 
int Mayor(int numero1, int numero2, int numero3) {
	if (numero1 > numero2) {
		if (numero1 > numero3) {
			return numero1;
		}
		else {
			return numero3;
		}
	}
	else {
		if (numero2 > numero3) {
			return numero2;
		}
		else {
			return numero3;
		}
	}
}

//4. Encontrar el número menor en un set de 3 números enteros. El programa debe regresar el menor de los tres números enviados a la función.
int Menor(int numero1, int numero2, int numero3) {
	if (numero1 > numero2) {
		if (numero2 > numero3) {
			return numero3;
		}
		else {
			return numero2;
		}
	}
	else {
		if (numero1 > numero3) {
			return numero3;
		}
		else {
			return numero1;
		}
	}
}

//5.Imprimir en consola una fila con n estrellas (*). Para este ejercicio, tienen que mostrar información al usuario y no regresar un valor.
void FilaEstrellas(int n)
{
	for (int e = 0; e < n; e++) {
		std::cout << "*";
	}
}

//6. Imprimir en consola una matriz nxn de estrellas(*).
void MatrizEstrellas(int n) {
	for (int e = 0; e < n; e++) {
		std::cout << "*";

		for (int m = 1; m < n; m++) {
			std::cout << "*";

		}
		std::cout << "\n";
	}
}

//7. Imprimir en consola una pirámide con n estrellas (*).
void PiramideEstrellas(int n) {
	for (int e = 0; e <= n; e++) {
		std::cout << "\n";

		for (int p = 0; p < e; p++) {
			std::cout << "*";

		}
	}
}

//8. Imprimir en consola una flecha creada con estrellas (*) en donde la punta tiene n estrellas, asumiendo que n es mayor a 1.
void FlechaEstrellas(int n) {
	for (int e = 0; e <= n; e++) {
		std::cout << "\n";
		for (int p = 0; p < e; p++) {
			std::cout << "*";
		}
	}
	for (int f = (n - 1); f >= 0; f--) {
		std::cout << "\n";
		for (int q = 1; q <= f; q++) {
			std::cout << "*";
		}

	}
}

//9. Calcular y mostrar los primeros n elementos de la sucesión de Fibonacci
void Fibonacci(int n) {
	int x = 0;
	int y = 1;
	int z = 1;
	for (int f = 1; f <= n; f++) {
		std::cout << z << " ";
		z = x + y;
		x = y;
		y = z;
	}
}

//10. Calcular si un número es primo o no. 
bool EsPrimo(int numero) {
	int c = 0;
	for (int i = 1; i <= numero; i++) {
		if ((numero % i) == 0) {
			c++;
		}
		else {
			c == c;
		}
	}
	if (c == 2) {
		std::cout << true;
		return "true";
	}
	else {
		std::cout << false;
		return "false";
	}
}

int main() {
	int p = PerimetroRectangulo(5, 3);
	std::cout << "El perimetro del rectangulo es " << p << std::endl;
	std::cin.get();
	float a = AreaTriangulo(5.0f, 3.0f);
	std::cout << "El area del triangulo es " << a << std::endl;
	std::cin.get();
	int mayor = Mayor(5, 9, 1);
	std::cout << "El numero mayor es " << mayor << std::endl;
	std::cin.get();
	int menor = Menor(5, 9, 1);
	std::cout << "El numero menor es " << menor << std::endl;
	std::cin.get();
	FilaEstrellas(5);
	std::cout << " " << std::endl;
	std::cin.get();
	MatrizEstrellas(4);
	std::cin.get();
	PiramideEstrellas(6);
	std::cin.get();
	FlechaEstrellas(3);
	std::cin.get();
	Fibonacci(9);
	std::cout << " " << std::endl;
	std::cin.get();
	EsPrimo(79);
	std::cout << " " << std::endl;
	std::cin.get();
	EsPrimo(52);
	std::cin.get();
	return 0;
}