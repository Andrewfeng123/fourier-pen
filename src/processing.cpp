/* @author Yvonne
 *
 * */
#include "processing.h"

#include <cmath>
#include <iostream>
#include <vector>

#include "globals.h"
#include "graphics.h"
//#include "samples.h"

std::ostream &operator<<(std::ostream &os, const struct Coord &coord);

Coord_list_t sampleSVG() {
    return {};
}

alpha_list_t DTFS(const Coord_list_t &coords, const int numCircles) {
    if (numCircles <= 0) {
        std::cerr << "Error in DTFS: numCircles not positive." << std::endl;
        return {};
    }
    if (coords.size() == 0) {
        std::cerr << "Error in DTFS: empty coord list." << std::endl;
        return {};
    }

    const int N = (int)coords.size();  // num of points
    const int K = (numCircles <= N) ? numCircles : N;
    if (numCircles > coords.size()) {  ///////////// output something to the user?
        std::cout << "Not enough points for that many circles!" << std::endl;
    }
    const float omega = 2 * M_PI / N;
    alpha_list_t alpha(K);
    for (int k = 0; k < K; k++) {
        alpha[k] = std::make_pair(0.0f, 0.0f);
        for (int n = 0; n < N; n++) {
            alpha[k].first += coords[n].x * cosf(-omega * k * n) - coords[n].y * sinf(-omega * k * n);
            alpha[k].second += coords[n].y * cosf(-omega * k * n) + coords[n].x * sinf(-omega * k * n);
        }
        alpha[k].first /= N;
        alpha[k].second /= N;
        //if (k%12==0) std::cout << "start: " << alpha[k].first <<  " " << alpha[k].second << std::endl;
    }

    return alpha;
}

inline float magnitude(float x, float y) {
    return sqrtf(x * x + y * y);
}
inline float phase(float x, float y) {
    return atan2f(y, x);
}

void drawFrame(const alpha_list_t &alphas, const int time) {
    const float speed = 100.0f;  //////////// fix this later
    // draw a circle
    struct Coord centre;
    for (int k = 0; k < alphas.size(); k++) {
        auto mag = magnitude(alphas[k].first, alphas[k].second);
        auto phi = phase(alphas[k].first, alphas[k].second);
        drawCircle(centre, mag);
        drawLine({centre, {centre.x + mag * cosf(phi + k * time / speed), centre.y + mag * sinf(phi + k * time / speed)}});
        centre = {
            centre.x + mag * cosf(phi + k * time / speed), centre.y + mag * sinf(phi + k * time / speed)};
    }
}

// Temporary testing method
/*
int main() {
    auto params = DTFS(square_wave, 200);

    // print coord list
    for (auto e : params)
    {
        std::cout << e.first << " + i*" << e.second << std::endl;
    }
    return 0;
}
*/

// for debugging
std::ostream &operator<<(std::ostream &os, const struct Coord &coord) {
    os << "(" << coord.x << "," << coord.y << ')';
    return os;
}