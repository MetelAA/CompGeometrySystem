#ifndef GENERATIONTYPE_H
#define GENERATIONTYPE_H

enum class GenerationType{
    StarPolygon, ConvexPolygon, NonConvexPolygon
};

inline GenerationType generationTypeFromString(const QString& str) {
    static QHash<QString, GenerationType> mapping = {
        {"star polygon", GenerationType::StarPolygon},
        {"convex polygon", GenerationType::ConvexPolygon},
        {"non-convex polygon", GenerationType::NonConvexPolygon}
    };


    return mapping.value(str, GenerationType::ConvexPolygon); // значение по умолчанию
}

#endif // GENERATIONTYPE_H
