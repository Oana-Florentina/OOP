#pragma warning(disable : 4996)
#include "Sort.h"
#include <iostream>


void main() {

	Sort s1(15, 0, 99);	//ctor 1
	std::cout << "First array has this element at index 6: " << s1.GetElementFromIndex(6) << std::endl;
	s1.Print();
	std::cout << std::endl;


	Sort s2({ 10,20,30,4,2,55 });	//ctor 2
	std::cout << "Second array is: "; 
	s2.Print(); 
	std::cout << std::endl;


	int existing_vector[10] = { 10,3,66,5,90,3,77,92,1,9 };
	Sort s3(existing_vector, 10);	//ctor 3
	std::cout << "Third array has " << s3.GetElementsCount() << " elements." << std::endl;
	s3.Print();
	std::cout << std::endl;


	Sort s4(8, 11, 36, 2, 55, 75, 34, 22, 7);	//ctor 4
	std::cout << "Fourth array: "; s4.Print();
	std::cout << std::endl;


	char c[] = "21,23,55,64,38,86,34,10,0,3,6";
	Sort s5(c);		//ctor 5
	std::cout << "Fifth array is: "; s5.Print();
	std::cout << std::endl;


	Sort s6(5, 100, 200);
	s6.Merge(s2);
	std::cout << "Sixth array is: ";
	s6.Print();
}