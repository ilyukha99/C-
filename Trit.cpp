#include "Trit.h"

Tritset::Tritset(size_t trits_size) {

	size_t uints_size = trits_size / sizeof(uint) / 4;
	std::vector<uint> array(uints_size + 1, 0); // дополнительный бит на случай uints_size == 0
	this->_array = array;
	this->_size = trits_size;
	this->_capacity = (uints_size + 1) * sizeof(uint) * 4;

	Trit temp;
	for (size_t it = 0; it != this->_capacity; ++it) {
		(*this)[it] = Unknown;
		temp = (*this)[it];
	}
}

void Tritset::print_array() {

	size_t uints = this->_capacity / 4 / sizeof(uint);
	for (size_t it = 0; it != uints; ++it)
		std::cout << it << ") " << _array[it] << "\n";
	std::cout << "\n";
}

std::ostream & operator<<(std::ostream & out, Tritset & tr) {

	uint counter = 0, size = sizeof(uint) * 4;
	for (size_t it = 0; it != tr._capacity; ++it) {
		if (it % size && (tr[it] == False || tr[it] == True))
			out << "0" << tr[it] << "'";
		else if (tr[it] == False || tr[it] == True)
			out << "\n" << counter++ << ") " << "0" << tr[it] << "'";
		else if (it % size && tr[it] == Unknown)
			out << "10" << "'";
		else out << "\n" << counter++ << ") " << "10" << "'";
	}
	return out;
}

Tritset::reference Tritset::operator[](size_t pos) {
	return reference(this, pos);
}

Trit Tritset::operator[](size_t pos) const {
	return this->get_value(pos);
}

void Tritset::set_value(size_t pos, Trit value) {

	unsigned uint_size = sizeof(uint);
	bool* binary_decomposition = new bool[uint_size * 8];
	uint cur_uint = this->_array[pos / 4 / uint_size];
	size_t cur_pos = pos % (uint_size * 4);
	for (int it = uint_size * 8 - 1; it != -1; --it) {
		binary_decomposition[it] = cur_uint % 2;
		cur_uint /= 2;
	}

	if (value == False) {
		binary_decomposition[cur_pos * 2] = 0;
		binary_decomposition[cur_pos * 2 + 1] = 0;
	}

	else if (value == True) {
		binary_decomposition[cur_pos * 2] = 0;
		binary_decomposition[cur_pos * 2 + 1] = 1;
	}

	else {
		binary_decomposition[cur_pos * 2] = 1; 
		binary_decomposition[cur_pos * 2 + 1] = 0; 
	}

	uint res = 0;
	for (int it = 0; it != uint_size * 8; ++it)
		res = res * 2 + binary_decomposition[it];
	
	this->_array[pos / 4 / uint_size] = res;
}

size_t Tritset::size() const {
	return this->_size;
}

size_t Tritset::capacity() const {
	return this->_capacity;
}

Trit Tritset::get_value(size_t pos) const {

	unsigned uint_size = sizeof(uint);
	bool* binary_decomposition = new bool[uint_size * 8];
	uint cur_uint = this->_array[pos / 4 / uint_size];
	size_t cur_pos = pos % (uint_size * 4);
	for (int it = uint_size * 8 - 1; it != -1; --it) {
		binary_decomposition[it] = cur_uint % 2;
		cur_uint /= 2;
	}

	if (binary_decomposition[cur_pos * 2] == 0 && binary_decomposition[cur_pos * 2 + 1] == 0)
		return False;

	else if (binary_decomposition[cur_pos * 2] == 0 && binary_decomposition[cur_pos * 2 + 1] == 1)
		return True;

	else return Unknown;
}

void Tritset::trim(size_t lastIndex) {

	for (int it = _size - 1; it != lastIndex; --it)
		(*this)[it] = Unknown;
	_size = lastIndex + 1;
}

size_t Tritset::length() const {

	size_t length = 0;
	for (int it = 0; it != _size; ++it)
		if ((*this)[it] != Unknown) {
			length = it + 1;
		}
		return length;
}

Tritset operator|(const Tritset & tr1, const Tritset & tr2) {

	size_t min = (tr1.size() > tr2.size()) ? tr2.size() : tr1.size();
	size_t max = (tr1.size() < tr2.size()) ? tr2.size() : tr1.size();
	Tritset result(max);
	for (size_t it = 0; it != min; ++it)
		result[it] = tr1[it] | tr2[it];
	return result;
}

Tritset operator&(const Tritset & tr1, const Tritset & tr2) {

	size_t min = (tr1.size() > tr2.size()) ? tr2.size() : tr1.size();
	size_t max = (tr1.size() < tr2.size()) ? tr2.size() : tr1.size();
	Tritset result(max);
	for (size_t it = 0; it != min; ++it)
		result[it] = tr1[it] & tr2[it];
	return result;
}

void fill_Tritset(Tritset & tr, Trit value) {

	for (size_t it = 0; it != tr.size(); ++it)
		tr[it] = value;
}

void fill_Tritset_randomly(Tritset & tr) {
	
	for (size_t it = 0; it != tr.size(); ++it)
		tr[it] = (Trit)(rand() % 3);
}

void Tritset::operator&=(Tritset & tr2) {

	size_t min = (this->_size > tr2.size()) ? tr2.size() : this->_size;
	for (size_t it = 0; it != min; ++it)
		(*this)[it] = (*this)[it] & tr2[it];
}

void Tritset::operator|=(Tritset & tr2) {

	size_t min = (this->_size > tr2.size()) ? tr2.size() : this->_size;
	for (size_t it = 0; it != min; ++it)
		(*this)[it] = (*this)[it] | tr2[it];
}

Tritset operator~(const Tritset & tr1) {

	Tritset tr2(tr1.size());
	for (size_t it = 0; it != tr2.size(); ++it)
		tr2[it] = ~tr1[it];
	return tr2;
}

size_t Tritset::cardinality(Trit value) const {

	std::unordered_map <Trit, size_t> my_map;
	for (int it = 0; it != this->_size; ++it) {
		if ((*this)[it] == value)
			my_map[value]++;
	}

	auto iterator = my_map.begin();
	if (my_map.empty())
		return 0;

	else return iterator->second;
}

void Tritset::shrink() {

	_size = this->length();
	_array.resize(_size / 4 / sizeof(uint) + 1);
	_capacity = (_size / 4 / sizeof(uint) + 1) * 4 * sizeof(uint);
	
}

bool operator==(const Tritset & tr1, const Tritset & tr2) {

	for (int it = 0; it != tr1.capacity() && it != tr2.capacity(); ++it)
		if (tr1[it] != tr2[it])
			return False;
	if (tr1.size() == tr2.size())
		return True;
	return False;
}

bool operator!=(const Tritset & tr1, const Tritset & tr2) {

	for (int it = 0; it != tr1.capacity() && it != tr2.capacity(); ++it)
		if (tr1[it] != tr2[it])
			return True;
	if (tr1.size() == tr2.size())
		return False;
	return True;
}