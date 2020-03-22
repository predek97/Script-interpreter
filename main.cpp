//#include <iostream>
#include <cstring>
#include "Variable.h"
#include "Stack.h"
#include "defines.h"

using namespace std;

char* charToCString(char a){
    char* temp = new char[2];
    temp[0] = a;
    temp[1] = '\0';
    return temp;
}

bool isOperator(char* a){
    for(int i = 0; i < number_of_operators; i++)
        if(!strcmp(a, operators[i].representation))
            return true;
    return false;
}

const Operator* getOperator(char* a){
    for(int i = 0; i < number_of_operators; i++)
        if(!strcmp(a, operators[i].representation))
            return &(operators[i]);
    return nullptr;
}
bool isNumber(char* a){
    for(int i = 0; i < 10; i++){
        if(!strcmp(a, numbers[i]))
            return true;
    }
    return false;
}
char* convertToRPN(const char* a){
    Stack stos;
    char* output = new char[2*strlen(a)+1]();
    for(int i = 0; a[i] != '\0'; i++){
        char* temp = charToCString(a[i]);
        if(isOperator(temp)){
            while(stos.first() && getOperator(stos.last()->getKey()) &&
                  (getOperator(stos.last()->getKey())->right_associative ||
                   getOperator(stos.last()->getKey())->priority <= getOperator(temp)->priority) )
            {
                strcat(output, stos.pop()->getKey());
                strcat(output, " ");
            }
            stos.push(temp);
        }
        else if(a[i] == '(')
            stos.push(temp);
        else if(a[i] == ')'){
            while(stos.last()->getKey()[0] != '('){
                strcat(output, stos.pop()->getKey());
                strcat(output, " ");
            }
            stos.pop();
        }
        else {
            strcat(output, temp);
            char* temp = charToCString(a[i+1]);
            if( isOperator(temp) || a[i+1] == '\0' || a[i+1] == '(' || a[i+1] == ')')
                strcat(output, " ");
            delete temp;
        }
        delete temp;
    }
    while(stos.first()){
        strcat(output, stos.pop()->getKey());
        strcat(output, " ");
    }
    return output;
}
int calculateRPN(char* a){
    Stack stos;
    for(int i = 0; a[i] != '\0'; i++){
        if(a[i] != ' '){
            char* temp = charToCString(a[i]);
            if(isOperator(temp)){
                Variable a = Variable(atoi(stos.pop()->getKey()));
                Variable b = Variable(atoi(stos.pop()->getKey()));
                stos.push(b.parse(temp, a).toCString());
            }
            else{
                char* tmp1 = new char[strlen(a)]();
                int start = i;
                do{
                    tmp1[i-start] = a[i];
                    i++;
                }while(a[i] != ' ' && a[i] != '\0');
                stos.push(tmp1);
                delete tmp1;
            }
            delete temp;
        }
    }
    return atoi(stos.pop()->getKey());
}
int main() {
    char* a = new char[instruction_length]();
    cin >> a;
    cout << convertToRPN(a) << endl;
    cout << a << endl;
    cout << calculateRPN(convertToRPN(a));
    /*int length = stos.length();
    char* e = new char[length];
    for(int i = 0; i < length; i++){
        e[i] = *stos.pop()->getKey();
    }
    cout << e;
    //cout << stos.first()->getKey() << endl;
    //cout << stos << endl;
    //cin >> a;
    //cout << a << endl;
    Variable b(10), c(5), d;
    //cout << b.parse('+', c) << endl << b << endl << b.parse('+', d);
    /*while(true){
       cin >>  a;
        for(int i = 0; a[i] != '\0'; i++){
            cout << b.parse(a[i],c) << endl;
        }
    }*/
    /*cout << "c = " << c << " b = " << b << " ";
    cout << "c + b = " << c+b << " ";
    d = c = b;
    cout << c << endl;*/
    return 0;
}