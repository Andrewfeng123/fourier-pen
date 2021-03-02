/*
 *
 * */

#pragma once

#include "globals.h"
#include <utility>
#include <array>

void initGraphics();

extern unsigned int pointShaderProg;
extern unsigned int pointVAO;
extern unsigned int pointVBO; 
void drawPoint(Coord point);

inline void drawCircle(Coord centre, float radius);

extern unsigned int lineVAO;
extern unsigned int lineVBO;
void drawLine(Line line);

extern void beginCurve();
extern std::array<Coord, 5000> pointSamples;
extern bool curveBegan;
extern int numPoints;
extern void endCurve();