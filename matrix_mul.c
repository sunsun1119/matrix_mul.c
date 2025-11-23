#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500  // 矩陣大小，可依需求調整

// 生成隨機矩陣
void generateMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = rand() % 10;  // 隨機 0~9
}

// 矩陣乘法（標準高效能迴圈順序）
void multiplyMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE; k++) {
            int temp = a[i][k];
            for (int j = 0; j < SIZE; j++) {
                result[i][j] += temp * b[k][j];
            }
        }
    }
}

int main() {
    int matrixA[SIZE][SIZE] = {0};
    int matrixB[SIZE][SIZE] = {0};
    int result[SIZE][SIZE] = {0};

    srand(time(NULL));

    generateMatrix(matrixA);
    generateMatrix(matrixB);

    clock_t start = clock();
    multiplyMatrix(matrixA, matrixB, result);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("矩陣乘法完成！耗時: %f 秒\n", time_taken);

    // 選擇性印出結果矩陣，矩陣太大就不要印
    // printf("%d", result[0][0]);

    return 0;
}
