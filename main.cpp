#include "shapes.h"
#include <iostream>

void ShowMenu() {
    std::cout << "\nМеню:" << std::endl;
    std::cout << "1. Создать треугольник" << std::endl;
    std::cout << "2. Создать прямоугольник" << std::endl;
    std::cout << "3. Удалить объект" << std::endl;
    std::cout << "4. Показать все объекты" << std::endl;
    std::cout << "5. Переместить объект" << std::endl;
    std::cout << "6. Сравнить два объекта" << std::endl;
    std::cout << "7. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

int main() {
    Factory factory;
    int choice;
    std::string id, id1, id2;
    double x, y, a, b, c, w, h, dx, dy;

    while (true) {
        ShowMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Введите ID треугольника: ";
                std::cin >> id;
                std::cout << "Введите координаты центра (x y): ";
                std::cin >> x >> y;
                std::cout << "Введите длины сторон (a b c): ";
                std::cin >> a >> b >> c;
                factory.CreateTriangle(id, x, y, a, b, c);
                break;
            case 2:
                std::cout << "Введите ID прямоугольника: ";
                std::cin >> id;
                std::cout << "Введите координаты центра (x y): ";
                std::cin >> x >> y;
                std::cout << "Введите ширину и высоту (w h): ";
                std::cin >> w >> h;
                factory.CreateRectangle(id, x, y, w, h);
                break;
            case 3:
                std::cout << "Введите ID объекта для удаления: ";
                std::cin >> id;
                factory.DeleteObject(id);
                break;
            case 4:
                factory.DisplayAll();
                break;
            case 5:
                std::cout << "Введите ID объекта для перемещения: ";
                std::cin >> id;
                std::cout << "Введите смещение (dx dy): ";
                std::cin >> dx >> dy;
                factory.MoveObject(id, dx, dy);
                break;
            case 6:
                std::cout << "Введите ID первого объекта: ";
                std::cin >> id1;
                std::cout << "Введите ID второго объекта: ";
                std::cin >> id2;
                factory.CompareObjects(id1, id2);
                break;
            case 7:
                std::cout << "Выход из программы." << std::endl;
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
                break;
        }
    }
}
