//
// Created by predek on 22.03.17.
//

#include "Stack.h"

Stack::Stack(){
    list = nullptr;
}

Element* Stack::pop() {
    if(!list) return nullptr;
    Element* temp = last();
    if(temp->previous)
        temp->previous->next = nullptr;
    else
        list = nullptr;
    temp->previous = nullptr;
    return temp;
}

int Stack::push(Element* element) {
    Element *temp = last();
    if(temp == nullptr)
        list = element;
    else{
        temp->next = element;
        element->previous = temp;
    }
    return 0;
}

char* Stack::push(char* key) {
    Element *new_elem = new Element(key);
    if(list)
    {
        new_elem->previous = last();
        new_elem->previous->next = new_elem;
    }
    else list = new_elem;
    return 0;
}
int Stack::length() const {
    if(list)
    {
        Element* temp = this->list;
        int length = 1;
        while(temp->next)
        {
            temp = temp->next;
            length++;
        }
        return length;
    }
    else return 0;
}

Element* Stack::last() const {
    if(!list) return nullptr;
    Element* temp = this->list;
    while(temp->next)
        temp = temp->next;
    return temp;
}

Element* Stack::first() {
    return list;
}

ostream& operator<<(ostream& os, const Stack& s)
{
    os << s.length();
    if(s.list)
    {
        Element* temp = s.last();
        while(temp->previous)
        {
            os << ' ' << *temp;
            temp = temp->previous;
        }
        os << ' ' << *temp;
    }
    return os;
}