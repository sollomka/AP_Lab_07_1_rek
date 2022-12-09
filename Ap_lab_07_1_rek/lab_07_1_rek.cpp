#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

void Create(int** R, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j);
void Print(int** R, const int rowCount, const int colCount, int i, int j);
void Sort(int** R, const int rowCount, const int colCount, int i0, int i1);
void Change(int** R, const int row1, const int row2, const int colCount, int j);
void Calc(int** R, const int rowCount, const int colCount, int i, int j, int& S, int& k);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int Low = -8;
	int High = 42;

	int rowCount = 8;
	int colCount = 7;

	int** R = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		R[i] = new int[colCount];

	Create(R, rowCount, colCount, Low, High, 0, 0);
	Print(R, rowCount, colCount, 0, 0);

	Sort(R, rowCount, colCount, 1, 0);
	Print(R, rowCount, colCount, 0, 0);

	int S = 0;
	int k = 0;

	Calc(R, rowCount, colCount, 0, 0, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;

	Print(R, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] R[i];
	delete[] R;
	return 0;
}

void Create(int** R, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	R[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(R, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(R, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** R, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << R[i][j];
	if (j < colCount - 1)
		Print(R, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(R, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void Sort(int** R, const int rowCount, const int colCount, int i0, int i1)
{
	if ((R[i1][0] < R[i1 + 1][0])
		||
		(R[i1][0] == R[i1 + 1][0] &&

			R[i1][1] < R[i1 + 1][1])
		||
		(R[i1][0] == R[i1 + 1][0] &&
			R[i1][1] == R[i1 + 1][1] &&
			R[i1][3] > R[i1 + 1][3]))
		Change(R, i1, i1 + 1, colCount, 0);

	if (i1 < rowCount - i0 - 1)
		Sort(R, rowCount, colCount, i0, i1 + 1);
	if (i0 < rowCount - 1)
		Sort(R, rowCount, colCount, i0 + 1, 0);
}

void Change(int** R, const int row1, const int row2, const int colCount, int j)
{
	int tmp = R[row1][j];
	R[row1][j] = R[row2][j];
	R[row2][j] = tmp;

	if (j < colCount - 1)
		Change(R, row1, row2, colCount, j + 1);

}

void Calc(int** R, const int rowCount, const int colCount, int i, int j, int& S, int& k)
{
	if (R[i][j] > 0 || (i % 2 != 0 && j % 2 != 0))
	{
		S += R[i][j];
		k++;
		R[i][j] = 0;
	}

	if (j < colCount - 1)
		Calc(R, rowCount, colCount, i, j + 1, S, k);

	if (i < rowCount - 1)
		Calc(R, rowCount, colCount, i + 1, 0, S, k);
}