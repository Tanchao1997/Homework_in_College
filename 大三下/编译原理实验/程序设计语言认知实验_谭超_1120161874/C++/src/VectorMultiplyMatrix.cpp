// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
/*——inputMatrix函数实现从文件中读入大小未知的矩阵;
并将矩阵以二位数组的形式返回给调用的人，同时通过参数传递返回矩阵的行数、列数
——*/
int** inputMatrix(string fileName, int* matrixRow, int* matrixColumn)
{
	ifstream fin(fileName);
	int row, column;
	fin >> row;
	fin >> column;
	*matrixRow = row;
	*matrixColumn = column;
	//printf("%d %d\n", row, column);
	//动态申请相应大小的内存
	int** ss = new int*[row];
	for (int i = 0; i < row; i++)
		ss[i] = new int[column];

	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<column; j++)
		{
			fin >> ss[i][j];
		}
	}
	return ss;
}
/*——vectorMultiplyMatrix()函数计算向量和矩阵的乘法，并将结果存为一个ss[1][matrixColumn]大小的
二维数组返回，
——*/
int** vectorMultiplyMatrix(int** vector, int** matrix, int vectorColumn, int matrixColumn)
{
	int** ss = new int*;
	ss[0] = new int[matrixColumn];
	for (int i = 0; i < matrixColumn; i++)
		ss[0][i] = 0;

	for (int i = 0; i < matrixColumn; i++)
	{
		for (int j = 0; j < vectorColumn; j++)
			ss[0][i] += vector[0][j] * matrix[j][i];
	}
	return ss;
}
int main()
{
	clock_t startTime, endTime;
	
	int vectorRow = 0, vectorColumn = 0, matrixRow = 0, matrixColumn = 0;
	int** vector = inputMatrix("vector.txt", &vectorRow, &vectorColumn);
	int** matrix = inputMatrix("matrix.txt", &matrixRow, &matrixColumn);
	startTime = clock();
	int** resultVector = vectorMultiplyMatrix(vector, matrix, vectorColumn, matrixColumn);
	endTime = clock();
	/*printf("result:\n");
	for (int i = 0; i < matrixColumn; i++)
	printf("%d ", resultVector[0][i]);
	printf("\n");*/
	//——将结果写入result.txt文件中
	ofstream result("result.txt");
	result << 1 << ' ' << matrixColumn << '\n';
	for (int i = 0; i < matrixColumn; i++)
		result << resultVector[0][i] << ' ';
	result << '\n';
	//释放内存
	for (int i = 0; i < vectorRow; i++)
		delete[] vector[i];
	delete[] vector;
	for (int i = 0; i < matrixRow; i++)
		delete[] matrix[i];
	delete[] matrix;
	delete[] resultVector[0];
	delete[] resultVector;

	cout << "Running time:" << (double)(endTime - startTime) << "ms\n" << endl;
	system("pause");
	return 0;
}