#pragma once
#include <exception>
#include <iostream>


class excpOutOfBounds : public std::exception {
	virtual const char* what() const throw(){
		return "Indexul este inafara domeniului!";
	}
};
class excpNotEnoughSpace : public std::exception{
	virtual const char* what() const throw()	{
		return "Spatiu insuficient!";
	}
};



class Compare{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template <class T>
class ArrayIterator {
public:
	T** List;
	int Current;
	int Last;

	ArrayIterator() {
		Current = 0;
	}

	ArrayIterator& operator++() {
		Current++;
		return *this;
	}

	ArrayIterator& operator--() {
		Current--;
		return *this;
	}

	bool operator= (ArrayIterator<T>& it) {

	}

	bool operator!= (ArrayIterator<T>& it) {
		return Current != it.Last;
	}

	T* GetElement() {
		return List[Current];
	}

	T* operator* () {
		return GetElement();
	}


};

template<class T>

class Array{

	T** List; // lista cu pointeri la obiecte de tipul T*

	int size; // dimensiunea listei de pointeri

	int count; // cate elemente sunt in lista

	excpOutOfBounds excpOutOfBounds;
	excpNotEnoughSpace excpNotEnoughSpace;

public:

	Array(){ // Lista nu e alocata, Capacity si Size = 0
		count = size = 0;
		List = nullptr;
	}

	~Array() {
		
		for (int i = 0; i < size; i++)
			delete  List[i];
		delete[] List;
	} // destructor

	Array(int capacity){ // Lista e alocata cu 'capacity' elemente
		try {
			if (capacity < 0) throw excpOutOfBounds;
			List = new T * [capacity];
			for (int i = 0; i < capacity; i++)
				List[i] = new T;
			size = capacity;
			count = 0;
		}
		catch (std::exception e) {
			std::cout << "Exceptie: " << e.what() << std::endl;
		}
	}

	Array(const Array<T>& otherArray) { // constructor de copiere
		for (int i = 0; i < size; i++)		//pare mai mult un constructor de mutare
			delete  List[i];
		delete[] List;

		List = new T * [otherArray.size];
		for (int i = 0; i < otherArray.size; i++)
			List[i] = new T;

		for (int i = 0; i < otherArray.size; i++)
			*(List[i]) = *(otherArray.List[i]); 

		count = otherArray.count;
		size = otherArray.size;
	}



	T& operator[] (int index) { // arunca exceptie daca index este out of range
		try {
			if (index >= count || index < 0)
				throw excpOutOfBounds;
			return *(List[index]);
		}
		catch (std::exception& e){
			std::cout << "Exceptie: " << e.what() << std::endl;
		}
	}



	const Array<T>& operator+=(const T& newElem) { // adauga un element de tipul T la sfarsitul listei si returneaza this 
													//sfarstiul listei in termeni de ultimul element sau pe ultima pozitie?
		try {
			if (count == size)
				throw excpNotEnoughSpace;

			*(List[count]) = newElem;

			count++;

			return *this;
		}
		catch (std::exception& e) {
			std::cout << "Exceptie: " << e.what() << std::endl;
		}
	}
	const Array<T>& Insert(int index, const T& newElem) { // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptii
		try {
			if (index >= size || count+1>=size || index < 0)
				throw excpOutOfBounds;

			if(count>0)
				for (int i = count; i > index; i--)
					*(List[i]) = *(List[i - 1]);
				
			*(List[index]) = newElem;

			count++;

			return *this;
		}
		catch (std::exception& e) {
			std::cout << "Exceptie: " << e.what() << std::endl;
		}
	
	}
	const Array<T>& Insert(int index, const Array<T>& otherArray) { // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	
		try {
			if (index >= size || (index+otherArray.count>=size) || index < 0)
				throw excpOutOfBounds;

			if (count > 0)
				for (int i = count; i > index-1 ; i--)
					*(List[i + otherArray.count]) = *(List[i]);

			for (int i = index, othAIterator=0; i < index + otherArray.count; i++) {
				*(List[i]) = *(otherArray.List[othAIterator++]);
			}

			count += otherArray.count;
		}
		catch (std::exception& e) {
			std::cout << "Exceptie: " << e.what() << std::endl;
		}
	
	}


	const Array<T>& Delete(int index) { // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
		try {
			if (index > count || index < 0)
				throw excpOutOfBounds;

			for (int i = index; i < count; i++)
				*(List[i]) = *(List[i + 1]);

			count--;

			return *this;
		}
		catch (std::exception& e) {
			std::cout << "Exceptie: " << e.what() << std::endl;
		}
	}


	bool operator=(const Array<T>& otherArray);



	void Sort() { // sorteaza folosind comparatia intre elementele din T
		for (int step = 0; step < count - 1; step++) {
			int min_idx = step;
			for (int i = step + 1; i < count; i++)
				if (*(List[i]) < *(List[min_idx]))
					min_idx = i;

			T newEl = *(List[min_idx]);
			*(List[min_idx]) = *(List[step]);
			*(List[step]) = newEl;
		}
		
	}
	void Sort(int(*compare)(const T&, const T&)) { // sorteaza folosind o functie de comparatie
		for (int step = 0; step < count - 1; step++) {
			int min_idx = step;
			for (int i = step + 1; i < count; i++)
				if (compare( * (List[i]), *(List[min_idx])))
					min_idx = i;

			T newEl = *(List[min_idx]);
			*(List[min_idx]) = *(List[step]);
			*(List[step]) = newEl;
		}
	}
	void Sort(Compare* comparator) { // sorteaza folosind un obiect de comparatie
		for (int step = 0; step < count - 1; step++) {
			int min_idx = step;
			for (int i = step + 1; i < count; i++)
				if (comparator->CompareElements(*(List[i]), *(List[min_idx])))
					min_idx = i;

			T newEl = *(List[min_idx]);
			*(List[min_idx]) = *(List[step]);
			*(List[step]) = newEl;
		}
	
	}


	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem) { // cauta un element folosind binary search in Array
		
		int l = 0;
		int r = count - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;

			if (*(List[m]) == elem)
				return m;

			if (*(List[m]) < elem)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {//  cauta un element folosind binary search si o functie de comparatie
		int l = 0;
		int r = count - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;

			if (compare(* (List[m]), elem)) == 1) // ==1 ar insemna ca sunt egale
				return m;

			if (compare( * (List[m]), elem) == 2) // ==2 ar insemna ca sunt mai mici
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	
	}
	int BinarySearch(const T& elem, Compare* comparator) { //  cauta un element folosind binary search si un comparator
		
		int l = 0;
		int r = count - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;

			if (comparator->CompareElements(*(List[m]), elem)) == 1) // ==1 ar insemna ca sunt egale
			return m;

			if (comparator->CompareElements(*(List[m]), elem) == 2) // ==2 ar insemna ca sunt mai mici
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;

	
	}


	int Find(const T& elem) { // cauta un element in Array
		for (int i = 0; i < count; i++)
			if (*(List[i]) == elem) return i;
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&)) { //  cauta un element folosind o functie de comparatie
		for (int i = 0; i < count; i++)
			if (compare(*(List[i]), elem) == 1) return i; //==1 inseamna ca sunt egale
		return -1;
	}
	int Find(const T& elem, Compare* comparator) {//  cauta un element folosind un comparator
		for (int i = 0; i < count; i++)
			if (comparator->CompareElements(*(List[i]), elem) == 1) return i; //==1 inseamna ca sunt egale
		return -1;
	
	}


	int GetSize(){
		return size;
	}

	int GetCount() {
		return count;
	}


	ArrayIterator<T> GetBeginIterator() {
		return begin();
	}
	ArrayIterator<T> GetEndIterator() {
		return end();
	}
	ArrayIterator<T> begin() {
		ArrayIterator<T> ar;
		ar.Last = Size;
		ar.List = List;
		return ar;
	}
	ArrayIterator<T> end() {
		ArrayIterator<T> ar;
		ar.Last = Size;
		ar.List = List;
		ar.Current = Size - 1;
		return ar;
	}
};