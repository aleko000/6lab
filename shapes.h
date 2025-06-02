#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

class Triangle {
protected:
    std::string id;
    double x, y;
    double sideA, sideB, sideC;

public:
    Triangle(const std::string& id, double x, double y, double a, double b, double c);
    virtual ~Triangle();

    std::string getId() const;
    double getX() const;
    double getY() const;

    virtual double getArea() const;
    virtual void Move(double dx, double dy);
    virtual void Display() const;
};

class Rectangle : public Triangle {
private:
    double width, height;

public:
    Rectangle(const std::string& id, double x, double y, double w, double h);
    double getArea() const override;
    void Display() const override;
};

class Factory {
private:
    std::vector<Triangle*> objects;

public:
    ~Factory();
    void CreateTriangle(const std::string& id, double x, double y, double a, double b, double c);
    void CreateRectangle(const std::string& id, double x, double y, double w, double h);
    void DeleteObject(const std::string& id);
    void DisplayAll() const;
    void MoveObject(const std::string& id, double dx, double dy);
    void CompareObjects(const std::string& id1, const std::string& id2);
};

#endif // SHAPES_H
