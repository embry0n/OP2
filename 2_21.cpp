//Найти ромб наибольшей площади с вершинами в заданном множестве точек на плоскости.

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Point {
    double x;
    double y;
};

// Функция для вычисления площади ромба
double calculateArea(const Point& p1, const Point& p2, const Point& p3) {
    return std::abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

// Функция для проверки, являются ли точки вершинами ромба
bool isDiamond(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    double centerX = (p1.x + p2.x + p3.x + p4.x) / 4.0;
    double centerY = (p1.y + p2.y + p3.y + p4.y) / 4.0;

    double dist1 = std::sqrt(std::pow(p1.x - centerX, 2) + std::pow(p1.y - centerY, 2));
    double dist2 = std::sqrt(std::pow(p2.x - centerX, 2) + std::pow(p2.y - centerY, 2));
    double dist3 = std::sqrt(std::pow(p3.x - centerX, 2) + std::pow(p3.y - centerY, 2));
    double dist4 = std::sqrt(std::pow(p4.x - centerX, 2) + std::pow(p4.y - centerY, 2));

    return (dist1 == dist2 && dist1 == dist3 && dist1 == dist4);
}

// Функция для поиска ромба с наибольшей площадью
void findLargestDiamond(const std::vector<Point>& points) {
    int n = points.size();
    double maxArea = 0.0;
    Point p1, p2, p3, p4; // Вершины ромба с наибольшей площадью

    for (int i = 0; i < n - 3; ++i) {
        for (int j = i + 1; j < n - 2; ++j) {
            for (int k = j + 1; k < n - 1; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    // Проверяем, являются ли точки вершинами ромба
                    if (isDiamond(points[i], points[j], points[k], points[l])) {
                        // Вычисляем площадь ромба
                        double area = calculateArea(points[i], points[j], points[k]) +
                            calculateArea(points[j], points[k], points[l]);

                        // Обновляем максимальную площадь и вершины ромба
                        if (area > maxArea) {
                            maxArea = area;
                            p1 = points[i];
                            p2 = points[j];
                            p3 = points[k];
                            p4 = points[l];
                        }
                    }
                }
            }
        }
    }

    // Выводим результаты
    if (maxArea > 0.0) {
        std::cout << "Ромб с наибольшей площадью найден:\n";
        std::cout << "Вершина 1: (" << p1.x << ", " << p1.y << ")\n";
        std::cout << "Вершина 2: (" << p2.x << ", " << p2.y << ")\n";
        std::cout << "Вершина 3: (" << p3.x << ", " << p3.y << ")\n";
        std::cout << "Вершина 4: (" << p4.x << ", " << p4.y << ")\n";
        std::cout << "Площадь: " << maxArea << "\n";
    }
    else {
        std::cout << "Ромб с наибольшей площадью не найден.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int numPoints;
    std::cout << "Введите количество точек: ";
    std::cin >> numPoints;

    std::vector<Point> points(numPoints);

    std::cout << "Введите координаты точек (x и y):\n";
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Точка " << i + 1 << ":\n";
        std::cout << "x: ";
        std::cin >> points[i].x;
        std::cout << "y: ";
        std::cin >> points[i].y;
    }

    findLargestDiamond(points);

    return 0;
}


