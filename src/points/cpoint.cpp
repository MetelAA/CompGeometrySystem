#include "cpoint.h"

CPoint::CPoint(qreal x, qreal y) : QPointF(x, y) {}

CPoint::CPoint(const QPointF &point) : QPointF(point.x(), point.y()){}

CPoint CPoint::operator+(const CPoint &other) const
{
    return CPoint(this->x() + other.x(), this->y()+other.y());
}

CPoint CPoint::operator-(const CPoint &other) const
{
    return CPoint(this->x() - other.x(), this->y()-other.y());
}


qreal CPoint::pseudoScalarMult(const CPoint &other) const
{
    return (this->x()*other.y() - this->y()*other.x());
}

bool CPoint::isPointInTriangle(const CPoint &p, const CPoint &a, const CPoint &b, const CPoint &c)
{
    CPoint::OrientationTypes o1 = orientation(a, b, p);
    CPoint::OrientationTypes o2 = orientation(b, c, p);
    CPoint::OrientationTypes o3 = orientation(c, a, p);

    // Если все ориентации одинаковые (все Left или все Right) - точка внутри
    return (o1 == o2 && o2 == o3);
}



CPoint::OrientationTypes CPoint::orientation(const CPoint &a, const CPoint &b, const CPoint &c)
{
    CPoint ab = b - a;
    CPoint ac = c - a;
    qreal scalarComposition = ab.pseudoScalarMult(ac);
    if (qAbs(scalarComposition) <= 1e-9) {
        return OrientationTypes::collinear;
    } else if (scalarComposition > 0) {
        return OrientationTypes::left;
    }
    return OrientationTypes::right;
}
