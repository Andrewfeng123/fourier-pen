/* Globals */
#pragma once

#define MAX_X 1
#define MIN_X -1
#define MAX_Y 1
#define MIN_Y -1
#define M_PI 3.14159265358979323846f

// a coordinate
struct Coord
{
    float x = 0, y = 0;
};

struct Line {
    Coord p1, p2;
};