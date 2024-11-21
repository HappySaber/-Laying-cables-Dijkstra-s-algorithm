#include "func.h"

int main() {
    setlocale(LC_ALL, "Russian");
    bool fl = true;
    while (fl) {
        system("cls");
        int cabelChoice;
        bool flag = true;
        std::cout << std::endl << "Введите из какого материала хотите кабель?(резина-1, полиэтилен - 2, ПВХ - 3)" << std::endl;
        while (true) {
            cabelChoice = getValue();
            if (cabelChoice == 1) {
                cabelChoice = rubber;
                break;
            }
            else if (cabelChoice == 2) {
                cabelChoice = polyethylene;
                break;
            }
            else if (cabelChoice == 3) {
                cabelChoice = pvh;
                break;
            }
            else
                std::cout << "Введено неправильное значение, введите еще раз" << std::endl;

        }

        std::cout << "Хотите ввести граф вручную или использовать стандартный? 1 - Ввести вручную, 2 - Использовать стандартный" << std::endl;
        int choice;
        while (true) {
            choice = getValue();
            if (choice == 1 || choice == 2)
                break;
            std::cout << "Вы ввели неправильное значение, введите еще раз" << std::endl;
        }
        int points;
        int startPoint;
        int** graph = nullptr;
        switch (choice)
        {
        case 1:
            std::cout << "Введите количество значемых точек на местности: ";
            points = getValue();
            std::cout << "Теперь заполните граф" << std::endl;
            graph = createArray(graph, points);
            for (int i = 0; i < points - 1; i++) {
                for (int j = i; j < points; j++) {
                    if (i != j) {
                        std::cout << "Введите значение для " << i << "-" << j << ", " << j << "-" << i << std::endl;
                        graph[i][j] = graph[j][i] = getValue();
                    }
                }
            }

            std::cout << "Введите точку из которой вы хотите откладывать кабель: ";

            while (true) {
                startPoint = getValue();
                if (startPoint >= 0 && startPoint < points)
                    break;
                else
                    std::cout << "Введите значение повторно!" << std::endl;
            }
            std::cout << "Граф, использованный для расчета прокладки кабеля" << std::endl;
            printAdjacencyMatrix(graph, points);
            std::cout << "\n\n\n\n\n";
            dijkstra(graph, startPoint, cabelChoice, points);
            break;

        case 2:
            graph = createArray(graph, V);
            graph[0][1] = graph[1][0] = 4;
            graph[1][2] = graph[2][1] = 8;
            graph[0][7] = graph[7][0] = 8;
            graph[1][7] = graph[7][1] = 11;
            graph[2][3] = graph[3][2] = 7;
            graph[2][5] = graph[5][2] = 4;
            graph[2][8] = graph[8][2] = 2;
            graph[3][4] = graph[4][3] = 9;
            graph[3][5] = graph[5][3] = 14;
            graph[4][5] = graph[5][4] = 10;
            graph[5][6] = graph[6][5] = 2;
            graph[6][7] = graph[7][6] = 1;
            graph[6][8] = graph[8][6] = 6;
            graph[8][7] = graph[7][8] = 7;

            std::cout << "Граф, использованный для расчета прокладки кабеля" << std::endl;
            printAdjacencyMatrix(graph, V);
            std::cout << "\n\n\n\n\n";
            dijkstra(graph, 0, cabelChoice, V);

            break;
        }

        bool flag1 = true;
        int c;
        std::cout << "Хотите воспользоваться программой повторно? 1-ДА, 2-НЕТ" << std::endl;
        while (flag1) {
            c = getValue();
            if (c == 1 || c == 2) {
                if (c == 2) {
                    fl = false;
                    flag1 = false;
                }
                else
                    flag1 = false;
            }
            else {
                std::cout << "Неправильное значение, введите еще раз" << std::endl;
            }
        }
    }

    return 0;
}
