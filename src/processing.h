/* @author Yvonne
 *
 * */
#pragma once

#include "globals.h"
#include <vector>

#define DEFAULT_NUM_CIRCLES 10
#define MAX_CIRCLES 100
#define MIN_CIRCLES 1

typedef std::vector<Coord> Coord_list_t;
typedef std::vector<std::pair<float, float>> alpha_list_t;

Coord_list_t sampleSVG();
alpha_list_t DTFS(const Coord_list_t& coords, const int numCircles = DEFAULT_NUM_CIRCLES);
void drawFrame(const alpha_list_t& alphas, const int time);
inline float mag(float x, float y);