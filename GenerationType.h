#ifndef GENERATIONTYPE_H
#define GENERATIONTYPE_H

enum class GenerationType{
    SimplePolygon, StarPolygon, ConvexPolygon, ConvexHull, Triangulation
};

inline GenerationType generationTypeFromString(const QString& str) {
    static QHash<QString, GenerationType> mapping = {
        {"simple polygon", GenerationType::SimplePolygon},
        {"star polygon", GenerationType::StarPolygon},
        {"convex polygon", GenerationType::ConvexPolygon},
        {"convex hull", GenerationType::ConvexHull},
        {"triangulation", GenerationType::Triangulation}
    };


    return mapping.value(str, GenerationType::SimplePolygon); // значение по умолчанию
}

#endif // GENERATIONTYPE_H
