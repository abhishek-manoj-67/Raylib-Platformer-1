#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <raylib.h>

#include "Polygon.hpp"
#include "Vector2D.hpp"

class Renderer {
public:
    Renderer() {}

    void draw(const Polygon& poly, const Color& color, bool hollow = false);
    void draw(const Vec2& end, const Color& color, const Vec2& start = ZERO_VECTOR);

protected:


private:


};
