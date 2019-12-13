#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <ctime>
#include <bitset>

#define uint unsigned int

enum Trit { False = 0, True = 1, Unknown = 2 }; // F = 00, T = 01, U = 10

class Tritset {

	std::vector<uint> _array;
	size_t _size;
	size_t _capacity;

public:

	class reference {

		friend class Tritset;

	public:

		~reference();
		reference & operator=(Trit val);
		reference & operator=(const reference & Trit);
		operator Trit() const;

	private:

		reference(Tritset* PTritset, size_t pos); // construct from tritset reference and position
		size_t _pos; // position of the trit in Tritset
		Tritset* _PTritset; // pointer on the Tritset
		Trit _value; // value of an object

	};

	Tritset(size_t size);
	void set_value(size_t position, Trit value);
	Trit get_value(size_t pos) const;
	size_t capacity() const; // вернуть количество тритов, которых можно поместить по размеру
	size_t cardinality(Trit value) const; //вернуть количество F/U/T в тритсете
	void trim(size_t lastIndex); // забыть содержимое от lastIndex и дальше
	size_t length() const; // logical length - индекс последнего не Unknown трита +1
	size_t size() const; // вернуть количество тритов
	void print_array();
	friend std::ostream & operator<<(std::ostream & out, Tritset & tr);
	reference operator[](size_t pos);
	Trit operator[](size_t pos) const;
	void operator&=(Tritset & tr2);
	void operator|=(Tritset & tr2);
	void shrink();
};

bool operator==(const Tritset & tr1, const Tritset & tr2);
bool operator!=(const Tritset & tr1, const Tritset & tr2);
Tritset operator&(const Tritset & tr1, const Tritset & tr2);
Tritset operator|(const Tritset & tr1, const Tritset & tr2);
Tritset operator~(const Tritset & tr1);
Trit operator&(Trit left, Trit rigth);
Trit operator|(Trit left, Trit rigth);
Trit operator~(Trit tr);
void fill_Tritset(Tritset & tr, Trit value);
void fill_Tritset_randomly(Tritset & tr);