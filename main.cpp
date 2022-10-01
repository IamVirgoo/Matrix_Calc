#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    private:
        /**
         * @description Обьявления полей класса
         * @params row_size - количество элементов в строке; <br/>
         *         column_size - количество элементов в колонке <br/>
         *         matrix - матрица
         * */
        int row_size, column_size;
        int** matrix;
        /**
         * @name createMatrix
         * @description Метод используется для инициализации поля матрицы
         * @return void
         * */
        void createMatrix() {
            matrix = new int*[row_size];
            for (int i = 0; i < row_size; i++) {
                matrix[i] = new int[column_size];
            }
        }
        /**
         * @name generateMatrix
         * @description Генерация элеементов матрицы с последующим его заполнением
         * @return void
         * */
        void generateMatrix() {
            for (int i = 0; i < row_size; i++) {
                for (int j = 0; j < column_size; j++) {
                    matrix[i][j] = rand() % 2;
                }
            }
        }
    public:
        /**
         * @description Конструктор класса
         * */
        Matrix(int row_size, int column_size) {
            this->row_size = row_size;
            this->column_size = column_size;

            createMatrix();
            generateMatrix();
        }
        /**
         * @name printPlace
         * @description Вывод матрицы в консоль
         * @return void
         * */
        void printPlace() {
            for (int row_index = 0; row_index < this->row_size; row_index++) {
                for (int column_index = 0; column_index < this->column_size; column_index++) {
                    cout.width(5);
                    cout << matrix[row_index][column_index] << ' ';
                }
                cout << '\n';
            }
        }
        /**
         * @description Инициализация оператора для присваивания значения одной матрицы другой
         * @return Matrix*
         * */
        Matrix* operator=(Matrix& secondMatrix) {
            auto resultMatrix = new Matrix(secondMatrix.row_size, secondMatrix.column_size);
            for (int row_index = 0; row_index < secondMatrix.row_size; row_index++) {
                for (int column_index = 0; column_index < secondMatrix.column_size; column_index++) {
                    resultMatrix->matrix[row_index][column_index] = secondMatrix.matrix[row_index][column_index];
                }
            }
            return resultMatrix;
        }
        /**
         * @description Инициализация оператора для коньюнкции двух матриц
         * @return Matrix*
         * */
        Matrix* operator*(Matrix& secondMatrix) {
            auto resultMatrix = new Matrix(secondMatrix.row_size, secondMatrix.column_size);
            for (int row_index = 0; row_index < secondMatrix.row_size; row_index++) {
                for (int column_index = 0; column_index < secondMatrix.column_size; column_index++) {
                    if (this->matrix[row_index][column_index] == 1 && secondMatrix.matrix[row_index][column_index] == 1)
                        resultMatrix->matrix[row_index][column_index] = 1;
                    else
                        resultMatrix->matrix[row_index][column_index] = 0;
                }
            }
            return resultMatrix;
        }
};

int main() {
    auto first_matrix = new Matrix(4, 4);
    auto second_matrix = new Matrix(4, 4);
    Matrix *result_matrix;
    cout << "====================FIRST MATRIX====================" << '\n' << '\n';
    first_matrix->printPlace();
    cout << '\n' << "===================SECOND MATRIX====================" << '\n' << '\n';
    second_matrix->printPlace();
    result_matrix = *first_matrix * *second_matrix;
    cout << '\n' << "===================RESULT MATRIX====================" << '\n' << '\n';
    result_matrix->printPlace();
    return 0;
}
