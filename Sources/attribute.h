#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "main.h"

class Attribute {
public:
    enum class Type {
        RESOURCE,
        CHARACTERISTIC,
        RATING,
        SKILL,

        TOTAL
    };

    enum class ValueType {
//        MIN,
        CURRENT,
        MAX,

        TOTAL
    };

private:
    std::string mb_name {};
    Type mb_type {};

//    int mb_minValue {};
    int mb_curValue {};
    int mb_maxValue {};



public:
    Attribute();


    Type getType() const;
    string_view getName() const;
    void changeValue(ValueType valueType, int delta);
    int getValue(ValueType valueType) const;

};

#endif // ATTRIBUTE_H
