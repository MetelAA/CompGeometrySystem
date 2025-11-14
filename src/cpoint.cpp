#include "cpoint.h"

CPoint::CPoint(qreal x, qreal y) : QPointF(x, y) {}

CPoint CPoint::operator+(const CPoint &other) const
{
    return CPoint(this->x() + other.x(), this->y()+other.y());
}

CPoint CPoint::operator-(const CPoint &other) const
{
    return CPoint(this->x() - other.x(), this->y()-other.y());
}


qreal CPoint::operator*(const CPoint &other) const
{
    return (this->x()*other.y() - this->y()*other.x());
}


CPoint::OrientationTypes CPoint::orientation(const CPoint &a, const CPoint &b, const CPoint &c)
{
    CPoint ab = a - b;
    CPoint ac = a - c;
    qreal scalarComposition = ab * ac;
    if(scalarComposition <= 1e-7){
        return OrientationTypes::collinear;
    }else if(scalarComposition > 0){
        return OrientationTypes::left;
    }
    return OrientationTypes::right;
}
