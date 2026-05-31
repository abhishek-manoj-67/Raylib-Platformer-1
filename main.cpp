#include <iostream>
#include <raylib.h>
#include <vector>
#include <unordered_map>

#include "Vector2D.hpp"
#include "Polygon.hpp"
#include "Renderer.hpp"
#include "Utility.hpp"

// formula to find peak jump height (floor x's):
// vx-\frac{a}{2}x^{2}+\frac{a}{2}x

int main () {
    // setup
    const short SCREEN_WIDTH = 1358, SCREEN_HEIGHT = 764;
    const unsigned char FPS = 60;

    // boilerplate
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Window");
    SetExitKey(KEY_NULL);
    SetTargetFPS(FPS);

    // variables
    Renderer renderer;


    double radius = 1.0;
    short segs = 1200;

    std::vector<Vec2> points;

    for (int i = 0; i < segs; i++) {

        points.push_back(Vec2(i * radius, 0));

    }

    
    while (WindowShouldClose() == false){
        // input
        Vec2 mouse = Vec2(GetMouseX(), GetMouseY());

        points[0] = mouse;

        // update
        for (int i = 1; i < segs; i++) {

            Vec2 prev = points[i - 1];
            Vec2 current = points[i];

            Vec2 distance = current - prev;

            if (distance.magnitude() > radius) {

                distance = distance.normalize() * radius;
                points[i] = points[i - 1] + distance;

            }

        }

        // render
        BeginDrawing();
            ClearBackground(BLACK);

            for (int i = 1; i < segs; i++) {

                renderer.draw(points[i - 1], RED, points[i]);

            }

        EndDrawing();
    }

    CloseWindow();
}