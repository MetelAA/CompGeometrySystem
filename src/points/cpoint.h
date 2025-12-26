#ifndef CPOINT_H
#define CPOINT_H

#include <QPointF>

class CPoint : public QPointF
{
public:
    enum class OrientationTypes{
        left, right, collinear
    };

    CPoint(qreal x, qreal y);
    CPoint(const QPointF& point);

    CPoint operator+(const CPoint& other) const;
    CPoint operator-(const CPoint& other) const;
    qreal pseudoScalarMult(const CPoint& other) const;
    static OrientationTypes orientation(const CPoint& a, const CPoint& b, const CPoint& c);
    static bool isPointInTriangle(const CPoint& p, const CPoint& a, const CPoint& b, const CPoint& c);
};



#endif // CPOINT_H
