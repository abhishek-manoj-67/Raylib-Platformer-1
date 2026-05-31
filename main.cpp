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

    while (WindowShouldClose() == false){
        // input
        Vec2 mouse = Vec2(GetMouseX(), GetMouseY());

        // update

        // render
        BeginDrawing();
            ClearBackground(BLACK);




        EndDrawing();
    }

    CloseWindow();
}