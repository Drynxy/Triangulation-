#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

Point trilateration(Point p1, double r1, Point p2, double r2, Point p3, double r3) {
    double A = 2 * (p2.x - p1.x);
    double B = 2 * (p2.y - p1.y);
    double C = r1 * r1 - r2 * r2 - p1.x * p1.x + p2.x * p2.x - p1.y * p1.y + p2.y * p2.y;
    double D = 2 * (p3.x - p2.x);
    double E = 2 * (p3.y - p2.y);
    double F = r2 * r2 - r3 * r3 - p2.x * p2.x + p3.x * p3.x - p2.y * p2.y + p3.y * p3.y;

    double x = (C * E - F * B) / (E * A - B * D);
    double y = (C * D - A * F) / (B * D - A * E);

    return {x, y};
}

int main() {
    Point p1 = {0, 0};
    Point p2 = {4, 0};
    Point p3 = {0, 3};

    double r1 = 5;
    double r2 = 5;
    double r3 = 5;

    Point result = trilateration(p1, r1, p2, r2, p3, r3);

    std::cout << "La position estimée est : (" << result.x << ", " << result.y << ")" << std::endl;

    return 0;
}