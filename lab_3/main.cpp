#include <iostream>
#include "include/triangle.h"
#include "include/square.h"
#include "include/octagon.h"
#include "include/FigureArray.h"

int main() {
    int numFigures = 0;
    int index = 0;
    char type;
    double totalArea = 0.0;

    std::cout << "Введите количество фигур" << std::endl;
    std::cin >> numFigures;

    // Array to track figure types
    char* figureTypes = new char[numFigures];
    Figure** figures = new Figure*[numFigures];

    while (index < numFigures) {
        std::cout << "Введите t-треугольник, s-квадрат, o-восьмиугольник" << std::endl;
        std::cin >> type;

        switch (type) {
            case 't': {
                Triangle* tri = new Triangle();
                std::cout << "Введите координаты треугольника (x1 y1 x2 y2 x3 y3): " << std::endl;
                std::cin >> *tri;
                figures[index] = tri;
                figureTypes[index] = 't';
                break;
            }
            case 's': {
                Square* sq = new Square();
                std::cout << "Введите координаты квадрата (x1 y1 x2 y2 x3 y3 x4 y4): " << std::endl;
                std::cin >> *sq;
                figures[index] = sq;
                figureTypes[index] = 's';
                break;
            }
            case 'o': {
                Octagon* oct = new Octagon();
                std::cout << "Введите координаты восьмиугольника (x1 y1 x2 y2 ... x8 y8): " << std::endl;
                std::cin >> *oct;
                figures[index] = oct;
                figureTypes[index] = 'o';
                break;
            }
            default:
                std::cout << "Неизвестный тип фигуры.\n";
                continue;
        }

        totalArea += figures[index]->getArea();
        std::cout << "Фигура добавлена с индексом " << index << std::endl;
        ++index;
    }

    char command;
    while (true) {
        std::cout << "Введите команду: a - общая площадь, r - удалить фигуру, c - центр фигуры, p - вывести фигуру, e - выйти\n";
        std::cin >> command;

        switch (command) {
            case 'a':
                std::cout << "Общая площадь: " << totalArea << std::endl;
                break;

            case 'r': {
                std::cout << "Введите индекс фигуры для удаления: ";
                int ind = 0;
                std::cin >> ind;

                if (ind >= 0 && ind < numFigures) {
                    totalArea -= figures[ind]->getArea();

                    // Properly delete the figure based on its type
                    switch (figureTypes[ind]) {
                        case 't':
                            delete static_cast<Triangle*>(figures[ind]);
                            break;
                        case 's':
                            delete static_cast<Square*>(figures[ind]);
                            break;
                        case 'o':
                            delete static_cast<Octagon*>(figures[ind]);
                            break;
                    }

                    // Shift remaining src and types
                    for (int i = ind; i < numFigures - 1; ++i) {
                        figures[i] = figures[i + 1];
                        figureTypes[i] = figureTypes[i + 1];
                    }

                    figures[numFigures - 1] = nullptr;
                    --numFigures;
                    std::cout << "Фигура удалена\n";
                } else {
                    std::cout << "Неверный индекс\n";
                }
                break;
            }

            case 'c': {
                std::cout << "Введите индекс фигуры: ";
                int ind = 0;
                std::cin >> ind;

                if (ind >= 0 && ind < numFigures) {
                    Point center = figures[ind]->getCenter();
                    std::cout << "Центр фигуры: " << center << std::endl;
                } else {
                    std::cout << "Неверный индекс\n";
                }
                break;
            }

            case 'p': {
                std::cout << "Введите индекс фигуры: ";
                int ind = 0;
                std::cin >> ind;

                if (ind >= 0 && ind < numFigures) {
                    // Output based on the stored figure type
                    switch (figureTypes[ind]) {
                        case 't':
                            std::cout << *static_cast<Triangle*>(figures[ind]) << std::endl;
                            break;
                        case 's':
                            std::cout << *static_cast<Square*>(figures[ind]) << std::endl;
                            break;
                        case 'o':
                            std::cout << *static_cast<Octagon*>(figures[ind]) << std::endl;
                            break;
                    }
                } else {
                    std::cout << "Неверный индекс\n";
                }
                break;
            }

            case 'e': {
                // Properly clean up memory based on figure types
                for (int i = 0; i < numFigures; ++i) {
                    switch (figureTypes[i]) {
                        case 't':
                            delete static_cast<Triangle*>(figures[i]);
                            break;
                        case 's':
                            delete static_cast<Square*>(figures[i]);
                            break;
                        case 'o':
                            delete static_cast<Octagon*>(figures[i]);
                            break;
                    }
                }
                delete[] figures;
                delete[] figureTypes;
                return 0;
            }

            default:
                std::cout << "Неизвестная команда\n";
        }
    }
}