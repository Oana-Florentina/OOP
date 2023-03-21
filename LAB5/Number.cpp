#include "Number.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS


Number::Number(const char* value, int base){
	this->base = base;
    this->value = new char[32]{ '\0' };
	strcpy(this->value, (char*)value);
}

Number::Number(const Number& n){
    base = n.base;
    value = new char[32]{ '\0' };
    memcpy(value, n.value, 32);
}

Number::Number(Number&& n){
    value = n.value;
    n.value = nullptr;
    base = n.base;
}

Number::Number(int x){
    base = 10;
    value = new char[32]{ '\0' };
    sprintf(value, "%d", x);    
}

Number::~Number(){
    delete[] value;
}


int getDecimalValue(char* str, int base){
    int decValue = 0;

    int strln = strlen(str);

    for (int i = strln - 1; i >= 0; i--)
        if (str[i] >= 'A' && str[i] < 'Z')
            decValue = decValue + (str[i] - 'A' + 10) * pow(base, (strln - 1 - i));
        else
            decValue = decValue + (str[i] - '0') * pow(base, (strln - 1 - i));

    return decValue;
}




void Number::operator=(const Number& n1){
    Number temp(n1.value, n1.base);
    temp.SwitchBase(base);

    base = temp.base;
    value = new char[32]{ '\0' };
    memcpy(value, temp.value, 32);
}

void Number::operator=(const char* newValue){
    value = new char[32]{ '\0' };
    memcpy(value, newValue, 32);
}

void Number::operator-(){
    int aux = atoi(value);
    aux = aux * (-1);
    _itoa(aux, value, base);
}

char& Number::operator[](int index){
    return value[index];
}


Number operator+(const Number& n1, const Number& n2) {
    int sum, baseToConvert;
    char str[32];

    Number a(n1.value, n1.base);
    Number b(n2.value, n2.base);

    a.SwitchBase(10);
    b.SwitchBase(10);

    sum = atoi(a.value) + atoi(b.value);
    sprintf(str, "%d", sum);

    baseToConvert = std::max(a.base, b.base);

    Number rez(str, 10);
    rez.SwitchBase(baseToConvert);

    return rez;
}

Number operator-(const Number& n1, const Number& n2) {
    int difference, baseToConvert;
    char str[32];

    Number a(n1.value, n1.base);
    Number b(n2.value, n2.base);

    a.SwitchBase(10);
    b.SwitchBase(10);

    difference = atoi(a.value) - atoi(b.value);
    sprintf(str, "%d", difference);

    baseToConvert = std::max(a.base, b.base);

    Number rez(str, 10);
    rez.SwitchBase(baseToConvert);

    return rez;
}

Number operator*(const Number& n1, const Number& n2){
    int product, baseToConvert;
    char str[32];

    Number a(n1.value, n1.base);
    Number b(n2.value, n2.base);

    a.SwitchBase(10);
    b.SwitchBase(10);

    product = atoi(a.value) * atoi(b.value);
    sprintf(str, "%d", product);

    baseToConvert = std::max(a.base, b.base);

    Number rez(str, 10);
    rez.SwitchBase(baseToConvert);

    return rez;
}

Number operator/(const Number& n1, const Number& n2){
    int division, baseToConvert;
    char str[32];

    Number a(n1.value, n1.base);
    Number b(n2.value, n2.base);

    a.SwitchBase(10);
    b.SwitchBase(10);

    division = atoi(a.value) / atoi(b.value);//int() ?
    sprintf(str, "%d", division);

    baseToConvert = std::max(a.base, b.base);

    Number rez(str, 10);
    rez.SwitchBase(baseToConvert);

    return rez;
}

Number operator+=(Number& n1, const Number& n2) {
    n1 = n1 + n2;
    return n1;
}

Number operator-=(Number& n1, const Number& n2) {
    n1 = n1 - n2;
    return n1;
}



Number& Number::operator--(){
    char* cutValue = new char[32]{ '\0' };

    for (int i = 0; i < strlen(value); i++)
        cutValue[i] = value[i + 1];

    strcpy(this->value, cutValue);

    return (*this);
}

Number Number::operator--(int value){
    char* cutValue = new char[32]{ '\0' };

    for (int i = 0; i < strlen(this->value)-1; i++)
        cutValue[i] = this->value[i];

    strcpy(this->value, cutValue);

    return (*this);
}

Number Number::operator|(const Number& n){
    char* newValue = new char[strlen(value) + strlen(n.value)]{ '\0' };

    Number a(n.value, n.base);
    a.SwitchBase(this->base);
        
    for (int i = 0; i < strlen(value); i++)
        newValue[i] = value[i];
    for (int i = 0; i < strlen(a.value); i++)
        newValue[i + strlen(value)] = a.value[i];
       
    Number newObj(newValue, this->base);

    return newObj;
}

bool Number::operator>(const Number& n){
    if(getDecimalValue(value, base) > getDecimalValue(n.value, n.base))
        return true;
    else 
        return false;
}

bool Number::operator<(const Number& n){
    if (getDecimalValue(value, base) < getDecimalValue(n.value, n.base))
        return true;
    else 
        return false;
}

bool Number::operator>=(const Number& n){
    if (getDecimalValue(value, base) >= getDecimalValue(n.value, n.base))
        return true;
    else 
        return false;
}

bool Number::operator<=(const Number& n){
    if (getDecimalValue(value, base) <= getDecimalValue(n.value, n.base))
        return true;
    else 
        return false;
}

bool Number::operator==(const Number& n){
    if (strcmp(value, n.value)==0)
        return true;
    else 
        return false;
}

bool Number::operator!=(const Number& n1){
    if (strcmp(value, n1.value) != 0)
        return true;
    else return false;
}



void Number::SwitchBase(int newBase){
    int decValue = getDecimalValue(value, base);

    char* newValue = new char[32]{'\0'};
    int i = 0;
    while (decValue > 0){
        int rem = decValue % newBase;
        decValue = decValue / newBase;
        char newChar = '0' + rem;

        if (newChar > '9')
            newChar = 'A' + (newChar - '9') - 1;

        newValue[i]=newChar;
        i++;
    }

    char* newValue2 = new char[32]{'\0'};
    int lengthOfNewValue = strlen(newValue);

    for(int i = 0; i < lengthOfNewValue; i++)
        newValue2[i] = newValue[lengthOfNewValue - 1 - i];
    
    strcpy(value, newValue2);
    base = newBase;
}

void Number::Print(){
    printf("%s\n",value);
}

char* Number::GetCharValue(){
    return value;
}

int Number::GetDigitsCount(){
    return strlen(value);

   /* int i = 0, count = 0;
    while (value[i] != '\0') {
        count++;
    }
    return count;
    */
}

int Number::GetBase(){
    return base;
}


