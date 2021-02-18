/* @author Yvonne
 *
 * */
#pragma once

#include "globals.h"
#include <vector>

#define THICKNESS 1

typedef std::vector<Coord> Coord_list_t;

Coord_list_t sampleSVG();
std::vector<int> DTFS(const Coord_list_t &coords, int numCircles);
//void drawFrame(std::vector <int>);