#include <iostream>

struct Point {
    float x,y;
    bool operator==(const Point& other) {
        return x == other.x && y ==other.y;
    }
};

struct Circle {
    Point center;
    float radius;
    bool operator==(const Circle& other) {
        return center == other.center && radius == other.radius;
    }
};

enum RelativePosition {NO_COMMON_POINTS, TOUCHING, INTERSECTING, SAME};

float distanceBetween(const Point&p1, const Point&p2) {
    return sqrt(pow(p2.x - p1.x, 2)+ pow(p2.y - p1.y,2));
}

RelativePosition findRelativePosition(const Circle*c1, const Circle* c2) {
    float distanceBetweenC1andC2 = distanceBetween(c1->center, c2->center);
    if(c1 == c2)
        return SAME;
    if((c1->radius + c2->radius) == distanceBetweenC1andC2)
        return TOUCHING;
    if(distanceBetweenC1andC2> c1->radius +  c2->radius)
        return NO_COMMON_POINTS;
    if(abs(c1->radius -  c2->radius) < distanceBetweenC1andC2 && distanceBetweenC1andC2 < c1->radius +  c2->radius)
        return INTERSECTING;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
