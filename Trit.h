#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <ctime>

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

		reference::~reference();
		reference & operator=(Trit val);
		reference & operator=(const reference & Trit);
		bool operator!=(Trit val);
		bool operator==(Trit val);
		Trit operator&(Trit val);
		Trit operator&(const reference & val);
		Trit operator|(Trit val);
		Trit operator|(const reference & val);
		Trit operator~();
		Trit get_value();
		size_t get_pos();
		Tritset* get_pointer();

	private:

		reference(Tritset* PTritset, size_t pos); // construct from tritset reference and position
		size_t _pos; // position of the trit in Tritset
		Tritset* _PTritset; // pointer on the Tritset
		Trit _value; // value of an object

	};

	Tritset(size_t size);
	void set_value(size_t position, Trit value);
	Trit get_value(size_t pos);
	size_t capacity() const; // вернуть количество тритов, которых можно поместить по размеру
	size_t cardinality(Trit value); //вернуть количество F/U/T в тритсете
	void trim(size_t lastIndex); // забыть содержимое от lastIndex и дальше
	size_t length(); // logical length - индекс последнего не Unknown трита +1
	size_t size() const; // вернуть количество тритов
	std::vector<uint> get_array();
	void print_array();
	void print_tritset();
	reference operator[](size_t pos);
	void inverse();
	void operator&=(Tritset & tr2);
	void operator|=(Tritset & tr2);
	void fill_Tritset(Trit value);
	void fill_Tritset_randomly();
	void shrink();
};

Tritset operator&(Tritset & tr1, Tritset & tr2);
Tritset operator|(Tritset & tr1, Tritset & tr2);
Tritset operator~(Tritset & tr1);