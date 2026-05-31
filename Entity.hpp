#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <raylib.h>

#include "Vector2D.hpp"
#include "Polygon.hpp"

class Entity {
public:

    Entity(Vec2 pos = Vec2(0,0), Vec2 size = Vec2(0,0)) : rect(Polygon({pos, pos + Vec2(0, 1) * size.dot(Vec2(0, 1)), pos + size, pos + Vec2(1, 0) * size.dot(Vec2(1, 0))})) {}

    void update();
    void renderBoundingBox(Color col = RED);

    Polygon rect;

protected:

private:

};
