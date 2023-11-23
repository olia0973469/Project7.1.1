// Lab_7_1.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 0
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int i0, int i1);
void Change(int** a, int row1, int row2, int colCount, int j);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 9;
	int High = 61;
	int rowCount = 7;
	int colCount = 6;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	Sort(a, rowCount, colCount, 0, 0);
	Print(a, rowCount, colCount, 0, 0);

	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k, 0, 0);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(a, rowCount, colCount, 0, 0);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, i, j + 1);
		}
		else
		{
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
		}
	}
}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void Sort(int** a, const int rowCount, const int colCount, int i0, int i1)
{
	if (i0 < rowCount - 1)
	{
		if (i1 < rowCount - i0 - 1)
		{
			if ((a[i1][0] < a[i1 + 1][0])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] > a[i1 + 1][1])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] == a[i1 + 1][1] &&
					a[i1][2] > a[i1 + 1][2]))
			{
				Change(a, i1, i1 + 1, colCount, 0);
			}
			Sort(a, rowCount, colCount, i0, i1 + 1);
		}
		else
		{
			Sort(a, rowCount, colCount, i0 + 1, 0);
		}

	}
}
	void Change(int** a, int row1, int row2, const int colCount, int j)
{

		if (j < colCount)
		{
			int tmp = a[row1][j];
			a[row1][j] = a[row2][j];
			a[row2][j] = tmp;
			Change(a, row1, row2, colCount, j + 1);
		}
}
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			if (!(a[i][j] % 2 != 0 && i + j % 7 == 0))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
			Calc(a, rowCount, colCount, S, k, i, j + 1);
		}
		else
		{
			Calc(a, rowCount, colCount, S, k, i + 1, 0);
		}
	}
}
