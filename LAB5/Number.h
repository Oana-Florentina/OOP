#pragma once

class Number {
	char* value;
	int base;

public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& n);
	Number(Number&& n);
	Number(int);
	~Number();

	void operator=(const Number& n1);
	void operator=(const char* newValue);
	void operator-();
	char& operator[](int index);

	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	friend Number operator*(const Number& n1, const Number& n2);
	friend Number operator/(const Number& n1, const Number& n2);
	friend Number operator+=(Number& n1, const Number& n2);
	friend Number operator-=(Number& n1, const Number& n2);
	
	Number& operator--();
	Number operator--(int value);

	Number operator|(const Number& n);

	bool operator>(const Number& n);
	bool operator<(const Number& n);
	bool operator>=(const Number& n);
	bool operator<=(const Number& n);
	bool operator==(const Number& n);
	bool operator!=(const Number& n);

	void SwitchBase(int newBase);
	void Print();
	char* GetCharValue();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};