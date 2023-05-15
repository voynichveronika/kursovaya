#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	float matr[10][10];
	float treug[10][10];
	float svch[10], x[10], y[10];
	int n, m;
	float temp;

	f1:
		cout << "Введите размерность матрицы." << endl;

		cout << "Введите количество строк:" << endl;
		cin >> n;

		cout << "Введите количество столбцов:" << endl;
		cin >> m;

		if (n < 0 || m < 0)
		{
			cout << "Размерность матрицы не может быть отрицательной" << endl;
			cout << endl;
			goto f1;
		}

		if (n != m)
		{
			cout << "Матрица должна быть квадратной (кол-во строк = кол-во столбцов)" << endl;
			cout << endl;
			goto f1;
		}
		


	f2:
		cout << "Введите элементы матрицы " << n << "*" << n  << ":" << endl;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matr[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				treug[i][j] = 0;
			}
		}

		//вывод введенной матрицы
		cout << endl << "Матрица:" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << matr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;


		//проверка на симметричность
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matr[i][j] != matr[j][i])
				{
					cout << "Матрица не симметричная" << endl;
					goto f2;					
				}				
			}
		}
	

	cout << "Введите свободные члены матрицы " << n << "*" << n << ":" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> svch[i];
	}

	//вывод введенной матрицы со свободными членами
	cout << endl << "Матрица:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << svch[i];
		cout << endl;
	}
	cout << endl;
	

	for (int i = 0; i < n; i++)
	{
		temp = 0;
		for (int k = 0; k < i; k++)
		{
			temp = temp + treug[k][i] * treug[k][i];
		}

		treug[i][i] = sqrt(matr[i][i] - temp);

		for (int j = i; j < n; j++)
		{
			temp = 0;
			for (int k = 0; k < i; k++)
			{
				temp = temp + treug[k][i] * treug[k][j];
			}

			treug[i][j] = (matr[i][j] - temp) / treug[i][i];
		}
	}



	for (int i = 0; i < n; i++)
	{
		temp = 0;
		for (int k = 0; k < i; k++)
		{
			temp = temp + treug[k][i] * y[k];
		}

		y[i] = (svch[i] - temp) / treug[i][i];
	}




	// вывод треугольной матрицы
	cout << endl << "Треугольная матрица:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << treug[i][j] << " ";
		}
		cout << y[i];
		cout << endl;
	}
	cout << endl;



	for (int i = n - 1; i >= 0; i--)
	{
		temp = 0;
		for (int k = i + 1; k < n; k++)
		{
			temp = temp + treug[i][k] * x[k];
		}

		x[i] = (y[i] - temp) / treug[i][i];
	}

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "x" << i << " = " << x[i] << endl;
	}

}