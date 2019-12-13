//int new_uint = pow(2, uint_size), res = 0;
//for (int it = 0; it != uint_size; ++it) {
//	res += new_uint * binary_decomposition[it];
//	new_uint = new_uint / 2;
//}

//for (auto it = my_map.begin(); it != my_map.end(); ++it) {
//	if (it->first == True)
//		my_map[it->first]++;
//	else if (it->first == False)
//		my_map[False]++;
//	else my_map[Unknown]++;
//}

//void resize(size_t new_size);
//void Tritset::resize(size_t new_size) {
//
//	size_t new_uints = new_size / 4 / sizeof(uint);
//	if (new_size > _capacity) {
//		_size = new_size;
//		_array.resize(new_uints + 1, 0);
//		_capacity = new_size + 1;
//	}
//	else if (new_size > _size && new_size < _capacity) {
//		_size = new_size;
//	}
//	else _size = new_size;
//
//}

//void Tritset::print_tritset() {
//
//	uint cur_uint = 0;
//	unsigned uint_size = sizeof(uint);
//	size_t uints = this->_capacity / 4 / uint_size;
//	bool* binary_decomposition = new bool[uint_size * 8];
//	for (size_t it = 0; it != uints; ++it) {
//		cur_uint = this->_array[it];
//		for (unsigned i = uint_size * 8 - 1; i != -1; --i) {
//			binary_decomposition[i] = cur_uint % 2;
//			cur_uint /= 2;
//		}
//		std::cout << it << ") ";
//		for (unsigned i = 0; i != uint_size * 8; ++i) {
//			std::cout << binary_decomposition[i];
//			if (i % 2 && i != uint_size * 8 - 1)
//				std::cout << "'";
//		}
//		std::cout << "\n";
//	}
//	std::cout << "\n";
//}

//void Tritset::inverse() {
//
//	for (size_t it = 0; it != this->_size; ++it)
//		(*this)[it] = ~(*this)[it];
//}

//switch (tr[it]) {
//case True: if (it % size == 15)
//	out << ++counter << ") " << "01" << "\n";
//		   else out << "01" << "'";
//case False: if (it % size == 15)
//	out << ++counter << ") " << "00" << "\n";
//			else out << "00" << "'";
//case Unknown: if (it % size == 15)
//	out << ++counter << ") " << "10" << "\n";
//			  else out << "10" << "'";
//}

/*if (this->length() > _size) {
_array.resize(this->length());
_capacity = this->length();
}
else {
_array.resize(_size);
_capacity = _size;
}*/

//int main(){
//	Tritset set1(133);
//	fill_Tritset(set1, True);
//	std::cout << set1 << "\n";
//
//	Tritset set(51);
//	fill_Tritset_randomly(set);
//	std::cout << set << "\n";
//
//	Tritset set2(400);
//	set2 = set1 & set;
//
//	std::cout << set2 << "\n";
//
//	std::cout << set2.capacity() << "\n";
//
//	std::cout << set2.cardinality(Unknown) << "\n";
//
//	std::cout << set2.length() << "\n";
//
//	set2.shrink();
//	std::cout << set2 << "\n";
//
//	set2 = ~set2;
//	std::cout << set2 << "\n";
//
//	std::cout << (set1 == set2) << "\n";
//	std::cout << (set1 != set2) << "\n";
//	std::cout << (set1 == set1) << "\n";

//  return 0;
//}