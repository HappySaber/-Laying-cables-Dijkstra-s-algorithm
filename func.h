#pragma once

#include <iostream>
#include <climits>
#include <cstdlib>
#include <iomanip>

#define V 9

//���� ������� � �� ���������
enum Wares { rubber = 100, polyethylene = 200, pvh = 300 };

#define V 9

//�-��� ��� ����������� ����� ������������� ��������
int getValue();
//�������� ���������� ������������� �������
int** createArray(int**& arr, int n);
//�������� ����������� ������������� �������
int* createArray2(int* arr, int n);
//�������� ����������� ������������� ������� � ����������� ����������
bool* createArray2(bool* arr, int n);
// ������� ��� ���������� ������� � ����������� �����������
int minDistance(int dist[], bool sptSet[], int len);
//����� ����������� �� �����
void printSolution(int dist[], int cabelChoice, int len, int src);
//�������� ��������, ������� ��������� ����������� �������� �� �����
void dijkstra(int** graph, int src, int cabelChoice, int len);
//����� ����� � ���� ������� ���������
void printAdjacencyMatrix(int** graph, int len);