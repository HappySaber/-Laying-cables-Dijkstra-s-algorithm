#pragma once

#include <iostream>
#include <climits>
#include <cstdlib>
#include <iomanip>

#define V 9

//Виды кабелей и их стоимость
enum Wares { rubber = 100, polyethylene = 200, pvh = 300 };

#define V 9

//ф-ция для корректного ввода целочисленный значений
int getValue();
//Создание двумерного динамического массива
int** createArray(int**& arr, int n);
//Создание одномерного динамического массива
int* createArray2(int* arr, int n);
//Создание одномерного динамического массива с логическими значениями
bool* createArray2(bool* arr, int n);
// Функция для нахождения вершины с минимальным расстоянием
int minDistance(int dist[], bool sptSet[], int len);
//Вывод расстнояний до точек
void printSolution(int dist[], int cabelChoice, int len, int src);
//Алгоритм Дейкстры, который вычисляет минимальную дистнцию до точек
void dijkstra(int** graph, int src, int cabelChoice, int len);
//Вывод графа в виде матрицы смежности
void printAdjacencyMatrix(int** graph, int len);