#include <iostream>
#include "Main.h"

void Title()
{
	int type;
	std::cout << "\t\t[======================================]\n";
	std::cout << "\t\t\tPascal Triangle Calculator\n";
	std::cout << "\t\t[======================================]\n";

	std::cout << "\nWelcome to the Pascal Triangle Calculator, what type of calculation you want to try ?\n";
	std::cout << "\n1: Normal\n2: Recursive\n";
}

long long int Factorial(long long int n)
{
	if (n == 1 || n == 0) return 1;
	return n * Factorial(n - 1);
}

void NormalCalculator(int number, int** matrix)
{
	for (int n = 0; n <= number; n++)
	{
		std::cout << "n: " << n << "  ";

		//std::cout << *matrix[n] << " ";

		for (int k = 0; k <= n; k++)
		{
			matrix[n][k] = Factorial((long long int)n) / (Factorial((long long int)k) * Factorial((long long int)n - (long long int)k)); //this method needs the n and k to start on 0
			//matrix[n][k] = matrix[n - 1][k - 1] + matrix[n - 1][k];  //this method needs the n and k to start on 1

			std::cout << matrix[n][k] << " ";
		}

		//std::cout << *matrix[n] << " ";
		std::cout << std::endl;
	}
}

int RecursiveCalculator(int n, int k, int** matrix)
{
	if (n == 0 || k == 0 || n == k || (n == 1 && k == 1)) return 1;	
	return matrix[n][k] = RecursiveCalculator(n - 1, k - 1, matrix) + RecursiveCalculator(n - 1, k, matrix);
}

void RecursiveDisplay(int size, int** matrix) 
{
	for (int n = 0; n <= size; n++)
	{
		std::cout << "n: " << n << "  ";

		for (int k = 0; k <= n; k++)
		{
			matrix[n][k] = RecursiveCalculator(n, k, matrix);
			std::cout << matrix[n][k] << " ";
		}

		std::cout << std::endl;
	}
}


int main()
{
	int type, size;

	Title();

	std::cout << "\nEnter the number of the type you want to use: ";
	std::cin >> type;

	std::cout << "\nEnter the size of the triangle you want to calculate: ";
	std::cin >> size;

	//Create the matrix
	int** matrix = new int* [size];

	//Initialize the matrix in all positions with value 1
	for (int i = 0; i <= size; i++)
	{
		matrix[i] = new int[size];

		for (int j = 0; j <= size; j++)
		{
			matrix[i][j] = 1, 1;
		}
	}

	if (type == 1)
	{
		std::cout << "\nNormal calculation with size " << size << " is: \n";
		NormalCalculator(size, matrix);
	}
	else if (type == 2)
	{
		std::cout << "\nRecursive calculation with size " << size << " is: \n";
		RecursiveDisplay(size, matrix);
	}
	else
		std::cout << "\nSorry, the type is not a valid input\n\n";
}