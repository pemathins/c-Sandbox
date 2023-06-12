#include <stdio.h>

// Define a base struct representing a shape
typedef struct {
    int d1;
    int d2;
    void (*draw)(d1);
    void (*draw)(d1,d2);
} Shape;

// Function to draw a shape
void drawShape(Shape* shape) {
    int d1;
    shape->draw(d1);
}

// Define derived structs for specific shapes
typedef struct {
    int width;
    int height;
    Shape base={width,height};
    
} Rectangle;

typedef struct {
    int radius;
    Shape base={radius,0};
    
} Circle;

// Draw function for rectangle
void drawRectangle(void) {
    printf("Drawing a rectangle.\n");
}

// Draw function for circle
void drawCircle(int radius) {
    printf("Drawing a circle. %f\n",2*3.57*radius*radius);
}

int main() {
    Rectangle rectangle = { { drawRectangle }, 4, 6 };
    Circle circle = { { drawCircle }, 5 };

    Shape* shape1 = (Shape*)&rectangle;
    Shape* shape2 = (Shape*)&circle;

    drawShape(shape1);
    drawShape(shape2);

    return 0;
}
