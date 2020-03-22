//
// Created by predek on 22.03.17.
//

#ifndef INC_1_1_ELEMENT_H
#define INC_1_1_ELEMENT_H
#include <iostream>
using namespace std;

class Variable {
public:
    Variable(int k);
    Variable(int k, bool isNil);
    Variable();
    int getKey() const;
    void setKey(int key);
    bool getIsNil() const;
    void setIsNil(bool isNil);
    Variable parse(char* oper, Variable var);
    int toInt();
    char* toCString();
    friend std::ostream& operator<<(std::ostream& stream, const Variable& var)
    {
        if(var.getIsNil())
            stream << "Nul";
        else
            stream << var.getKey();
        return stream;
    }
    //operatory
    Variable operator- () {
        return Variable(-key, isNil);
    }
    Variable operator! () {
        return Variable(0, !isNil);
    }
    Variable& operator= (Variable& var) {
        key = var.key;
        isNil = var.isNil;
        return *this;
    }
    Variable operator+ (Variable& var) {
        return Variable(key + var.key, isNil || var.isNil);
    }
    Variable operator- (Variable& var) {
        return Variable(key - var.key, isNil || var.isNil);
    }
    Variable operator/ (Variable& var) {
        return Variable(key / var.key, isNil || var.isNil);
    }
    Variable operator* (Variable& var) {
        return Variable(key * var.key, isNil || var.isNil);
    }
    Variable operator% (Variable& var) {
        return Variable(key % var.key, isNil || var.isNil);
    }
private:
    int key;
    bool isNil;
};


#endif //INC_1_1_ELEMENT_H
