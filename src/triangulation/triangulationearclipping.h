#ifndef TRIANGULATIONEARCLIPPING_H
#define TRIANGULATIONEARCLIPPING_H

#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "src/points/cpoint.h"

struct triangle{
    CPoint p1, p2, p3;
    triangle(CPoint p1, CPoint p2, CPoint p3): p1(p1), p2(p2), p3(p3) {}
};

class TriangulationEarClipping
{
public:
    TriangulationEarClipping();

    std::vector<triangle> EarClipping(std::vector<CPoint> polygon);


    // Утилиты для циклической навигации по std::list
    std::list<CPoint>::iterator getPrev(std::list<CPoint>::iterator it_curr, std::list<CPoint> &vertex);
    std::list<CPoint>::iterator getNext(std::list<CPoint>::iterator it_curr, std::list<CPoint> &vertex);

};

#endif // TRIANGULATIONEARCLIPPING_H
