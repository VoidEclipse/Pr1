#include <iostream>
#include <stdlib.h>
#include <locale>
#include <iomanip>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment( lib, "winmm" )

using namespace std;

const int n = 3;
float a[n][n];
float num;
char h;

class matrix
{
public:
	matrix() {

	}
	int i, j, a[n][n];

	void input() {
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				cin >> a[i][j];
	}

	matrix output() {
		matrix result;
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				result.a[i][j] = a[i][j];
		return result;
	}

	

	void printMatrix() {
		for (i = 0; i<n; i++) {
			for (j = 0; j<n; j++)
				cout << a[i][j] << "\t";
			cout << endl;
		}
	}

	void per_num() {

		cout << "Введите число на которое хотите умножить матрицу A: ";
		cin >> num;
		for (i = 0; i<n; i++) {
			for (j = 0; j<n; j++) {

				a[i][j] *= num;

				cout << a[i][j] << " ";

			} cout << endl;

		}
	}


	matrix operator+ (matrix& m1) {
		matrix result1;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				result1.a[i][j] = a[i][j] + m1.a[i][j];
			}
		}
		return result1;
	}

	matrix operator- (matrix& m2) {
		matrix result2;

		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				result2.a[i][j] - m2.a[i][j];
		return result2;
	}


	matrix operator* (matrix& m4) {
		matrix result;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				result.a[i][j] = 0;
				for (int k = 0; k<n; k++) {
					result.a[i][j] += a[i][k] * m4.a[k][j];

				}
			}
		}
		return result;
	}



};

int main() {

	setlocale(LC_ALL, "Rus");

	matrix m7;
	cout << "Введите матрицу A: " << endl;

	matrix a;
	matrix q1;
	q1.input();


	cout << "Введите матрицу B: " << endl;

	matrix q2;
	q2.input();

	bool rightSelectMenu = false;
	do {

		cout << "Выберите оперцию: \n";
		cin >> h;
		switch (h)
		{
		case '+':
			a = q1 + q2;
			rightSelectMenu = true;
			break;

		case '-':
			a = q1 - q2;
			rightSelectMenu = true;
			break;

		case '*':
			a = q1*q2;
			rightSelectMenu = true;
			break;


		default: cout << "ОШИБКА! Неверная операция" << endl;
		}
	} while (!rightSelectMenu);

	cout << "Исходная матрица: " << endl;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cout << a.a[i][j] << " ";
		}
		cout << endl;
	}

	q1.per_num();

	

	system("pause");

	return 0;
}