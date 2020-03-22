//
// Created by predek on 22.03.17.
//

#ifndef INC_1_1_STACK_H
#define INC_1_1_STACK_H

#include "Element.h"

class Stack {
public:
    Element* list;
    Element* last() const;
    int length() const;
    Element* first();
    Element* pop();
    int push(Element* element);
    char* push(char* key);
    Stack();
    //Stack(int key);
    friend ostream& operator<<(ostream& os, const Stack& s);

};


#endif //INC_1_1_STACK_H
