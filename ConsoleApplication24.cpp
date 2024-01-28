
#include <iostream>
#include <string>
template <class T>
class Matrix
{
private:
    int col;
    int row;
    T** matrix;
public:
    Matrix(int cols, int rows) : col{ cols }, row{ rows }
    {
        matrix = new T*[cols];
        for (size_t i = 0; i < cols; i++)
        {
            matrix[i] = new T[rows];
        }
        srand(time(0));
    }
    void clear()
    {
        for (size_t i = 0; i < col; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    ~Matrix() { clear(); }
    void buildKeyboard()
    {
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                std::cin >> matrix[i][j];
            }
        }
    }
    void buildRandom()
    {
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                matrix[i][j] = rand() % 99 + 1;
            }
        }
    }
    void print()
    {
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator+(const Matrix& second)
    {
        Matrix result(col, row);
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                result.matrix[i][j] = matrix[i][j] + second.matrix[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& second)
    {
        Matrix result(col, row);
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                result.matrix[i][j] = matrix[i][j] - second.matrix[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix& second)
    {
        Matrix result(col, row);
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                result.matrix[i][j] = matrix[i][j] * second.matrix[i][j];
            }
        }
        return result;
    }
    Matrix operator/(const Matrix& second)
    {
        Matrix result(col, row);
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                result.matrix[i][j] = matrix[i][j] / second.matrix[i][j];
            }
        }
        return result;
    }
    T findMax()
    {
        T numMax = matrix[0][0];
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                if (matrix[i][j] > numMax)
                {
                    numMax = matrix[i][j];
                }
            }
        }
        return numMax;
    }
    T findMin()
    {
        T numMin = matrix[0][0];
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                if (matrix[i][j] < numMin)
                {
                    numMin = matrix[i][j];
                }
            }
        }
        return numMin;
    }
};


int main()
{
    Matrix<int> matrix1(3, 4);
    Matrix<int> matrix2(3, 4);
    std::cout << "Matrix 1:\n";
    matrix1.buildRandom();
    matrix1.print();
    std::cout << "------------";
    std::cout << std::endl;
    std::cout << "Matrix 2:\n";
    matrix2.buildRandom();
    matrix2.print();
    std::cout << "------------";
    std::cout << std::endl;
    std::cout << "Sum:\n";
    Matrix<int> sum = matrix1 + matrix2;
    sum.print();
    std::cout << "------------";
    std::cout << std::endl;
    std::cout << "Diff:\n";
    Matrix<int> diff = matrix1 - matrix2;
    diff.print();
    std::cout << "------------";
    std::cout << std::endl;
    std::cout << "Prod:\n";
    Matrix<int> prod = matrix1 * matrix2;
    prod.print();
    std::cout << "------------";
    std::cout << std::endl;
    std::cout << "Quot:\n";
    Matrix<int> quot = matrix1 / matrix2;
    quot.print();
    std::cout << "------------";
    std::cout << std::endl;
    std::cout << "Max number in Matrix 1:\n";
    std::cout << matrix1.findMax();
    std::cout << std::endl;
    std::cout << "Min number in Matrix 2:\n";
    std::cout << matrix2.findMin();
}
