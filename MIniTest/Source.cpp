#include<iostream>
#include<time.h>
#include<vector>
namespace std {

	//function prototyping for enter data 
	void enterData(vector<vector<int> > firstMatrix, vector<vector<int> > secondMatrix, int rowFirst, int columnFirst, int rowSecond, int columnSecond);
	//function prototyping for multiplication function
	void multiplyMatrices(vector<vector<int> >firstMatrix, vector<vector<int> > secondMatrix, vector<vector<int> > mult, int rowFirst, int columnFirst, int rowSecond, int columnSecond);
	//function prototyping for display function
	void display(vector<vector<int> > mult, int rowFirst, int columnSecond);
	//function to initliaze matrix in which the values after multiplication are stored
	void INImat(int rowFirst, int columnSecond, vector<vector<int> > mult);

	int main()
	{
		vector<vector<int> > firstMatrix; vector<vector<int> > secondMatrix; vector<vector<int> > mult; int rowFirst, columnFirst, rowSecond, columnSecond;

		cout << "Enter rows and column for first matrix: ";
		cin >> rowFirst >> columnFirst;

		cout << "Enter rows and column for second matrix: ";
		cin >> rowSecond >> columnSecond;

		// If colum of first matrix in not equal to row of second matrix, asking user to enter the size of matrix again.
		while (columnFirst != rowSecond)
		{
			cout << "Error! column of first matrix not equal to row of second." << endl;
			cout << "Enter rows and column for first matrix: ";
			cin >> rowFirst >> columnFirst;
			cout << "Enter rows and column for second matrix: ";
			cin >> rowSecond >> columnSecond;
		}

		// Function to take matrices data
		enterData(firstMatrix, secondMatrix, rowFirst, columnFirst, rowSecond, columnSecond);
		//function to initlize matrix in which data will be stored after multipicartion.
		INImat(rowFirst, rowSecond, mult);

		// Function to multiply two matrices.
		multiplyMatrices(firstMatrix, secondMatrix, mult, rowFirst, columnFirst, rowSecond, columnSecond);

		// Function to display resultant matrix after multiplication.
		display(mult, rowFirst, columnSecond);

		return 0;
	}

	void enterData(vector<vector<int> >firstMatrix, vector<vector<int> > secondMatrix, int rowFirst, int columnFirst, int rowSecond, int columnSecond)
	{
		int i, j;
		srand(time(0));
		//cout << endl << "Enter elements of matrix 1:" << endl;
		for (i = 0; i < rowFirst; ++i)
		{
			for (j = 0; j < columnFirst; ++j)
			{
				cout << "Entering  elements in a Randomly" << endl;//<< i + 1 << j + 1 << ": ";
				//cin >> rand();
				firstMatrix[i][j] = rand();
			}
		}

		//cout << endl << "Enter elements of matrix 2:" << endl;
		for (i = 0; i < rowSecond; ++i)
		{
			for (j = 0; j < columnSecond; ++j)
			{
				cout << "Entering elements in b randomly" << endl;// << i + 1 << j + 1 << ": ";
				secondMatrix[i][j] = rand();
			}
		}
	}
	void INImat(int rowFirst, int columnSecond, vector<vector<int> > mult) {
		// Initializing elements of matrix mult to 0.

		for (int i = 0; i < rowFirst; ++i)
		{
			for (int j = 0; j < columnSecond; ++j)
			{
				mult[i][j] = 0;
			}
		}

	}

	void multiplyMatrices(vector<vector<int> > firstMatrix, vector<vector<int> > secondMatrix, vector<vector<int> > mult, int rowFirst, int columnFirst, int rowSecond, int columnSecond)
	{
		int i, j, k;



		// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
		for (i = 0; i < rowFirst; ++i)
		{
			for (j = 0; j < columnSecond; ++j)
			{
				for (k = 0; k < columnFirst; ++k)
				{
					mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
				}
			}
		}
	}

	void display(vector<vector<int> > mult, int rowFirst, int columnSecond)
	{
		int i, j;

		cout << "Output Matrix:" << endl;
		for (i = 0; i < rowFirst; ++i)
		{
			for (j = 0; j < columnSecond; ++j)
			{
				cout << mult[i][j] << " ";
				if (j == columnSecond - 1)
					cout << endl << endl;
			}
		}
	}
}