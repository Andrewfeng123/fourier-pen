/* @author Yvonne
 *
 * */
#include "processing.h"
#include "graphics.h"
#include "globals.h"

#include <vector>
#include <cmath>
#include <iostream>

std::ostream &operator<<(std::ostream &os, const struct Coord &coord);

/* DTFS examples */
std::vector<Coord> square = {{.x = 0.5, .y = 0.5}, {.x = 0.5, .y = -0.5}, {.x = -0.5, .y = 0.5}, {.x = -0.5, .y = -0.5}};

Coord_list_t sampleSVG()
{
    return {};
}

alpha_list_t DTFS(const Coord_list_t &coords, int numCircles)
{
    if (numCircles <= 0)
    {
        std::cerr << "Error in DTFS: numCircles not positive." << std::endl;
        return {};
    }
    if (coords.size() == 0)
    {
        std::cerr << "Error in DTFS: empty coord list." << std::endl;
        return {};
    }

    const int N = coords.size(); // num of points
    const int K = numCircles;
    const float omega = 2 * M_PI / N;
    alpha_list_t alpha(K);
    for (int k = 0; k < K; k++)
    {
        alpha[k] = std::make_pair(0.0f, 0.0f);
        for (int n = 0; n < N; n++)
        {
            alpha[k].first += coords[n].x * cos(-omega * k * n) - coords[n].y * sin(-omega * k * n);
            alpha[k].second += coords[n].y * cos(-omega * k * n) + coords[n].x * sin(-omega * k * n);
        }
        alpha[k].first /= N;
        alpha[k].second /= N;
    }

    return alpha;
}

void drawFrame(alpha_list_t alphas, int time)
{
    // draw a circle
    struct Coord centre;
    //drawCircle(centre, );
}

// Temporary testing method
int main()
{
    auto params = DTFS(square);
    // print coord list
    for (auto e : params)
    {
        std::cout << e.first << " + i*" << e.second << std::endl;
    }
    return 0;
}

// for debugging
std::ostream &operator<<(std::ostream &os, const struct Coord &coord)
{
    os << "(" << coord.x << "," << coord.y << ')';
    return os;
}