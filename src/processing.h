/* @author Yvonne
 *
 * */
#pragma once

#include "globals.h"
#include <vector>

#define DEFAULT_NUM_CIRCLES 10
#define M_PI 3.14159265358979323846f

typedef std::vector<Coord> Coord_list_t;
typedef std::vector<std::pair<float, float>> alpha_list_t;

Coord_list_t sampleSVG();
alpha_list_t DTFS(const Coord_list_t &coords, int numCircles = DEFAULT_NUM_CIRCLES);
void drawFrame(alpha_list_t alphas, int time);