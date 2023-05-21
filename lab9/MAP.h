#pragma once


template<class K, class V>
class Map {
	struct Element {
		K key;
		V value;
		int index;
	} *vector;

	int count;
	int size;

	

	void Resize() {//dublez sizeul
		if (size != 0) {
			Element* newvector = new Element[size * 2];
			size *= 2;

			for (int i = 0; i < count; i++)
				newvector[i] = vector[i];

			delete[] vector;
			//vector = nullptr;
			vector = newvector;
		}
		else {
			vector = new Element[1];
			size = 1;
			count = 0;
		}
	}

public:
	Map() {
		vector = new Element[1];
		size = 1;
		count = 0;
	}
	//~Map() {
		//delete[] vector;
	//}

	Element* begin() const { return &vector[0]; }

	Element* end() const { return &vector[count]; }

	V& operator[](K key) {
		for (int i = 0; i < count; i++)
			if (vector[i].key == key)
				return vector[i].value; 

		if (count == size) Resize();
		
		vector[count].key = key;
		vector[count].index = count;
		count++;
		return vector[count - 1].value;	
		
	}

	void Set(K key, V value) {

		for (int i = 0; i < count; i++)
			if (vector[i].key == key) { 
				vector[i].value = value; 
				return;
			}


		if (count == size) Resize();
		vector[count].key = key;
		vector[count].index = count;
		count++;
	}

	bool Get(const K& key, V& value) {
		for (int i = 0; i < count; i++)
			if (vector[i].key == key) {
				value = vector[i].value;
				return true;
			}
		return false;
	}

	int Count() {
		return count;
	}

	void Clear() {
		count = 0;
		size = 0;
		delete[] vector;
	}

	bool Delete(const K& key) {
		for (int i = 0; i < count; i++)
			if (vector[i].key == key) {
				for (int j = i; j < count - 1; j++) {
					vector[j] = vector[j + 1];
					vector[j].index = j;
				}
				count--;
				return true;
			}
		return false;
	}

	bool Includes(const Map<K, V>& map) {
		if (count < map.count) return false;

		bool inMap;
		for (int i = 0; i < map.count; i++) {
			inMap = false;
			for (int j = 0; j < count; j++)
				if (vector[j].key == map.vector[i].key) {
					inMap = true;
					break;
				}
			if (inMap == false)
				return false;
		}
		return true;
	}

	void Swap( Map<K, V>& m) {
		int mcount = m.count;
		int msize = m.size;
		Element* mvector = new Element[mcount];
		for (int i = 0; i < count; i++)
			mvector[i] = m.vector[i];

		while (this->size > m.size) m.Resize(); //m1 => m2
		for (int i = 0; i < this->count; i++)
			m.vector[i] = this->vector[i];
		m.size = this->size;			//e setat automat de resize
		m.count = this->count;


		while (this->size < msize) this->Resize();	//m2 => m1
		for (int i = 0; i < mcount; i++)
			this->vector[i] = mvector[i];
		this->size = msize;
		this->count = mcount;

	}

	void add(Map<K, V>& m) {//daca apar chei identice, rescriere
		for (int i = 0; i < m.count; i++)
			(*this)[i] = m.vector[i].value;
	}

	void Sort() {
		for (int i = 0; i < count; i++)
			for (int j = i + 1; j < count; j++) 
				if (vector[j].key < vector[i].key) {
					Element temp = vector[i];
					vector[i] = vector[j];
					vector[j] = temp;

					vector[j].index = i;
					vector[i].index = j;
				}
	}

};