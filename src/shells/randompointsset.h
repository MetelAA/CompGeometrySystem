#ifndef RANDOMPOINTSSET_H
#define RANDOMPOINTSSET_H

#include "src/points/cpoint.h"

class RandomPointsSet
{
public:
    RandomPointsSet(int pCount, int width, int height);
    std::vector<CPoint>& getPoints();
    int getPCount();
protected:
    std::vector<CPoint> points;
    int pCount;
};

#endif // RANDOMPOINTSSET_H
