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

    CPoint operator+(const CPoint& other) const;
    CPoint operator-(const CPoint& other) const;
    qreal operator*(const CPoint& other) const;
    static OrientationTypes orientation(const CPoint& a, const CPoint& b, const CPoint& c);
};



#endif // CPOINT_H
