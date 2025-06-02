#include "shapes.h"

Triangle::Triangle(const std::string& id, double x, double y, double a, double b, double c)
    : id(id), x(x), y(y), sideA(a), sideB(b), sideC(c) {}

Triangle::~Triangle() {}

std::string Triangle::getId() const { return id; }
double Triangle::getX() const { return x; }
double Triangle::getY() const { return y; }

double Triangle::getArea() const {
    double p = (sideA + sideB + sideC) / 2;
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

void Triangle::Move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Triangle::Display() const {
    std::cout << "Треугольник ID: " << id << std::endl;
    std::cout << "Координаты центра: (" << x << ", " << y << ")" << std::endl;
    std::cout << "Стороны: " << sideA << ", " << sideB << ", " << sideC << std::endl;
    std::cout << "Площадь: " << getArea() << std::endl;
}

Rectangle::Rectangle(const std::string& id, double x, double y, double w, double h)
    : Triangle(id, x, y, w, h, sqrt(w * w + h * h)), width(w), height(h) {}

double Rectangle::getArea() const {
    return width * height;
}

void Rectangle::Display() const {
    std::cout << "Прямоугольник ID: " << id << std::endl;
    std::cout << "Координаты центра: (" << x << ", " << y << ")" << std::endl;
    std::cout << "Ширина: " << width << ", Высота: " << height << std::endl;
    std::cout << "Площадь: " << getArea() << std::endl;
}

Factory::~Factory() {
    for (auto obj : objects) {
        delete obj;
    }
    objects.clear();
}

void Factory::CreateTriangle(const std::string& id, double x, double y, double a, double b, double c) {
    objects.push_back(new Triangle(id, x, y, a, b, c));
    std::cout << "Треугольник создан." << std::endl;
}

void Factory::CreateRectangle(const std::string& id, double x, double y, double w, double h) {
    objects.push_back(new Rectangle(id, x, y, w, h));
    std::cout << "Прямоугольник создан." << std::endl;
}

void Factory::DeleteObject(const std::string& id) {
    for (auto it = objects.begin(); it != objects.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            objects.erase(it);
            std::cout << "Объект с ID '" << id << "' удален." << std::endl;
            return;
        }
    }
    std::cout << "Объект с ID '" << id << "' не найден." << std::endl;
}

void Factory::DisplayAll() const {
    if (objects.empty()) {
        std::cout << "Нет объектов для отображения." << std::endl;
        return;
    }
    for (const auto obj : objects) {
        obj->Display();
        std::cout << "-------------------" << std::endl;
    }
}

void Factory::MoveObject(const std::string& id, double dx, double dy) {
    for (auto obj : objects) {
        if (obj->getId() == id) {
            obj->Move(dx, dy);
            std::cout << "Объект с ID '" << id << "' перемещен на (" << dx << ", " << dy << ")." << std::endl;
            return;
        }
    }
    std::cout << "Объект с ID '" << id << "' не найден." << std::endl;
}

void Factory::CompareObjects(const std::string& id1, const std::string& id2) {
    Triangle* obj1 = nullptr;
    Triangle* obj2 = nullptr;

    for (auto obj : objects) {
        if (obj->getId() == id1) obj1 = obj;
        if (obj->getId() == id2) obj2 = obj;
    }

    if (!obj1 || !obj2) {
        std::cout << "Один из объектов не найден." << std::endl;
        return;
    }

    double area1 = obj1->getArea();
    double area2 = obj2->getArea();

    std::cout << "Сравнение объектов:" << std::endl;
    std::cout << "Площадь объекта '" << id1 << "': " << area1 << std::endl;
    std::cout << "Площадь объекта '" << id2 << "': " << area2 << std::endl;

    if (area1 > area2) {
        std::cout << "Объект '" << id1 << "' больше." << std::endl;
    } else if (area1 < area2) {
        std::cout << "Объект '" << id2 << "' больше." << std::endl;
    } else {
        std::cout << "Объекты равны по площади." << std::endl;
    }
}
