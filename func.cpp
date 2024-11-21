#include "func.h"


int getValue() {
    int value;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer: ";
    }
    return value;
}

int** createArray(int**& arr, int n) {
    arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    return arr;
}

int* createArray2(int* arr, int n) {
    arr = new int [n];
    for (int i = 0; i < n; i++)
        arr[i] = 0;
    return arr;
}

bool* createArray2(bool* arr, int n) {
    arr = new bool[n];
    for (int i = 0; i < n; i++)
        arr[i] = false;
    return arr;
}

int minDistance(int dist[], bool sptSet[], int len) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < len; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[], int cabelChoice, int len, int src) {
    std::cout << "ћинимальное расстоние и цена  прокладки кабел€ до каждой вершины:\n";
    for (int i = 0; i < len; i++) {
        if (dist[i] == 0 && i == src)
            std::cout << "¬ершина " << i << ": точка откладывани€" << std::endl;       
        else
            std::cout << "¬ершина " << i << ": " << dist[i] << "  " << dist[i] * cabelChoice << std::endl;
    }
}

void dijkstra(int** graph, int src, int cabelChoice, int len) {
    int* dist = nullptr; // ћассив дл€ хранени€ рассто€ний от исходной вершины до остальных вершин
    bool* sptSet = nullptr; // ћассив дл€ отметки посещенных вершин
    dist = createArray2(dist, len); // —оздаем массив дл€ хранени€ рассто€ний
    sptSet = createArray2(sptSet, len); // —оздаем массив дл€ хранени€ состо€ни€ посещени€ вершин

    // »нициализаци€ массивов
    for (int i = 0; i < len; i++) {
        dist[i] = INT_MAX; // Ќачальное рассто€ние до всех вершин - бесконечность
        sptSet[i] = false; // Ќачальное состо€ние вершины - не посещена
    }

    dist[src] = 0; // –ассто€ние от исходной вершины до самой себ€ равно 0

    // ÷икл по всем вершинам графа
    for (int count = 0; count < len; count++) {
        int u = minDistance(dist, sptSet, len); // Ќаходим вершину с минимальным рассто€нием из непосещенных
        sptSet[u] = true; // ѕомечаем вершину как посещенную

        // ќбновление рассто€ний до смежных вершин через вершину u
        for (int v = 0; v < len; v++) {
            // ѕровер€ем, не посещена ли вершина v, есть ли между u и v ребро, 
            // не равно ли рассто€ние до u бесконечности, и не короче ли новый путь
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v]; // ќбновл€ем рассто€ние до вершины v
            }
        }
    }

    printSolution(dist, cabelChoice, len, src); // ¬ыводим результаты
}



void printAdjacencyMatrix(int** graph, int len) {
    int maxValue = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < V; j++) {
            maxValue = std::max(maxValue, graph[i][j]);
        }
    }
    std::cout << "     ";
    for (int i = 0; i < len; i++) {
        std::cout << std::setw(3) << i << " ";
    }
    std::cout << std::endl;
    std::cout << "    ";
    for (int i = 0; i < len; i++) {
        std::cout << "----";
    }
    std::cout << std::endl;
    for (int i = 0; i < len; i++) {
        std::cout << std::setw(3) << i << "| ";
        for (int j = 0; j < len; j++) {
            std::cout << std::setw(3) << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
    std::cout << std::endl;
}