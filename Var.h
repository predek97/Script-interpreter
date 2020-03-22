//
// Created by predek on 03.05.17.
//

#ifndef INC_2_1_VARIABLE_H
#define INC_2_1_VARIABLE_H
#include <iostream>

class Var {
public:
    Var();
    Var(int value);

    int getValue() const;

    void setValue(int value);

    bool getIsNil() const;

    void setIsNil(bool isNil);
    friend std::ostream& operator<<(std::ostream& stream, const Var& var)
    {
        if(var.getIsNil())
            stream << "Nul";
        else
            stream << var.getValue();
        return stream;
    }
private:
    int value;
    bool isNil;
};


#endif //INC_2_1_VARIABLE_H
