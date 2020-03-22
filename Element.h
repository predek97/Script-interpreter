//
// Created by predek on 22.03.17.
//

#ifndef INC_2_1_ELEMENT_H
#define INC_2_1_ELEMENT_H
#include <iostream>
using namespace std;

class Element {
public:
    Element(char* k);
    ~Element();
    char* getKey() const;
    void setKey(char* key);
    Element* next;
    Element* previous;
    friend ostream& operator<<(ostream& os, const Element& el);
private:
    char* key;
};


#endif //INC_2_1_ELEMENT_H
