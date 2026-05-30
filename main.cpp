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


    Polygon testShape({{100, 100}, {100, 200}, {200, 200}});
    Polygon testShape2({{400, 100}, {400, 200}, {500, 200}, {500, 100}});
    Vec2 testVector(100, 30);
    Vec2 testVector2(30, 100);

    
    while (WindowShouldClose() == false){
        // input
        Vec2 mouse = Vec2(GetMouseX(), GetMouseY());

        // update

        testShape.moveTo(mouse);

        
        testVector2 = mouse;

        Color color;
        color = testShape.collide(testShape2) ? YELLOW : GREEN;
        
        // render
        BeginDrawing();
            ClearBackground(BLACK);
            renderer.draw(testShape2, RED);
            renderer.draw(testShape, color);



        EndDrawing();
    }

    CloseWindow();
}