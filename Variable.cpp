//
// Created by predek on 22.03.17.
//

#include "Variable.h"

int Variable::getKey() const {
    return key;
}

void Variable::setKey(int key) {
    this->key = key;
}

Variable::Variable(int key) {
    isNil = false;
    this->key = key;
}

Variable::Variable(): key(0), isNil(true) {
}
bool Variable::getIsNil() const {
    return isNil;
}

void Variable::setIsNil(bool isNil) {
    this->isNil = isNil;
}

Variable::Variable(int k, bool isNil):key(k), isNil(isNil){

}

Variable Variable::parse(char* oper, Variable var) {
    switch(oper[0]){
        default: return *this;
        case '+': return (*this) + var;
        case '-': return (*this) - var;
        case '/': return (*this) / var;
        case '*': return (*this) * var;
        case '%': return (*this) % var;
        case '=': return *this = var;
    }
}

int Variable::toInt() {
    return 0;
}

char *Variable::toCString() {
    if(isNil)
        return "Nul";

    int temp = key;
    int len = 1;
    if(temp < 0)
        len++;
    for (len = 0; temp != 0; len++) {
        temp = temp / 10;
    }
    char* output = new char[len];
    sprintf(output, "%d", key);

    return output;
}




