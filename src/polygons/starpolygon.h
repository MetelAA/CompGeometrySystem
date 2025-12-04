#ifndef STARPOLYGON_H
#define STARPOLYGON_H

#include "src/polygons/convexpolygon.h".h"

class StarPolygon : public ConvexPolygon {
public:
    StarPolygon(int pCount, int width, int height);
};

#endif // STARPOLYGON_H
