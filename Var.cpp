//
// Created by predek on 03.05.17.
//

#include "Var.h"

int Var::getValue() const {
    return value;
}

void Var::setValue(int value) {
    Var::value = value;
}

bool Var::getIsNil() const {
    return isNil;
}

void Var::setIsNil(bool isNil) {
    Var::isNil = isNil;
}

Var::Var() {
    value = 0;
    isNil = true;
}

Var::Var(int value) {
    this->value = value;
    isNil = false;
}


