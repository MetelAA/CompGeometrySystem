#include "randompointsset.h"
#include <QRandomGenerator>

RandomPointsSet::RandomPointsSet(int pCount, int width, int height) : pCount(pCount) {
    width = static_cast<int>(0.8 * width);
    height = static_cast<int>(0.8 * height);

    for(int i = 0; i < pCount; i++){
        qreal x = (QRandomGenerator::global()->generateDouble() * 2.0 - 1.0) * width / 2;
        qreal y = (QRandomGenerator::global()->generateDouble() * 2.0 - 1.0) * height / 2;
        points.push_back(CPoint(x, y));
    }
}

std::vector<CPoint> &RandomPointsSet::getPoints()
{
    return this->points;
}

int RandomPointsSet::getPCount()
{
    return this->pCount;
}
