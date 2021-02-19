/* @author Yvonne
 *
 * */
#pragma once

#include "globals.h"
#include <vector>

#define DEFAULT_NUM_CIRCLES 10

typedef std::vector<Coord> Coord_list_t;
typedef std::vector<std::pair<float, float>> alpha_list_t;

Coord_list_t sampleSVG();
alpha_list_t DTFS(const Coord_list_t &coords, int numCircles = DEFAULT_NUM_CIRCLES);
void drawFrame(alpha_list_t alphas, int time);