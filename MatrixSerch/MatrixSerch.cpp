// MatrixSerch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <array>


std::vector< std::vector <int>> matrixSearch(int(***matrix), int i, int m, int n, int searchingFor) //требуемая функция, получает массив в виде указателя на указетель указателя
{
    std::vector<std::vector<int>> result;
    for (int x = 0; x < i; x++)
    {
        for (int y = 0; y < m; y++)
        {
            for (int z = 0; z < n; z++)
            {
                if (matrix[x][y][z] == searchingFor)
                {
                    std::vector<int> newPoint = { x, y, z };
                    result.push_back(newPoint);
                }
            }
        }
    }
    return result;
}

template <size_t rows, size_t cols, size_t heigth>
std::vector< std::vector <int>> matrixSearch(int(&matrix)[rows][cols][heigth], int searchingFor) //перегрузка функции, которая упрощает работу с ней
{
    std::vector<std::vector<int>> result;
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            for (int z = 0; z < heigth; z++)
            {
                if (matrix[x][y][z] == searchingFor)
                {
                    std::vector<int> newPoint = { x, y, z };
                    result.push_back(newPoint);
                }
            }
        }
    }
    return result;
}

template <size_t rows, size_t cols, size_t heigth>
int*** Create3DPointer(int(&array)[rows][cols][heigth])
{
    int*** pointerToB = new int** [rows];
    for (int i = 0; i < rows; i++)
    {
        pointerToB[i] = new int* [cols];
        for (int j = 0; j < cols; j++)
        {
            pointerToB[i][j] = array[i][j];
        }
    }
    return pointerToB;
}
int main()
{
    int b[2][2][2] = { { {1,3}, {3,4} }, { {3,6}, {7,3} } }; //объявление массива
    int x = 2;
    int y = 2;
    int z = 2;
    int sF = 3; //искомое число
    int*** pointerToB = Create3DPointer(b); //преобразование массива в указатель
    std::vector< std::vector <int>> found = matrixSearch(pointerToB, x, y, z, sF);
    std::vector< std::vector <int>> alsoFound = matrixSearch(b, sF); //для перегрузки не требуется преобразовывать матрицу в указатель
    std::cout << "First function result:" << std::endl;
    for (auto i : found) {
        for (auto j : i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "Override function result:" << std::endl;
    for (auto i : alsoFound) {
        for (auto j : i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }
}






