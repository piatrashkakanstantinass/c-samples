#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

void printPoint(Point p) {
    printf("(%g, %g)", p.x, p.y);
}

Point createPoint(double x, double y) {
    Point p = {x, y};
    return p;
}

double getDistance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(void) {
    printf("%g\n", getDistance(createPoint(2, -3), createPoint(-4, 5)));
    return 0;
}