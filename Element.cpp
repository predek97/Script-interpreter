//
// Created by predek on 22.03.17.
//

#include "Element.h"
#include <cstring>
char* Element::getKey() const {
    return key;
}

void Element::setKey(char* key) {
    this->key = key;
}

Element::Element(char* key) {
    next = nullptr;
    previous = nullptr;
    this->key = new char[strlen(key)+1];
    strcpy ( this->key, key);
}

Element::~Element() {
    delete key;
}
ostream& operator<<(ostream& os, const Element& el) {
    os << el.key;
    return os;
}


