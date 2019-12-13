#include "Trit.h"

Tritset::reference::reference(Tritset* PTritset = NULL, size_t pos = 0) : _pos(pos), _PTritset(PTritset) {

	if (_pos > _PTritset->_capacity)
		_value = Unknown;
	else _value = _PTritset->get_value(pos);
}

Tritset::reference::~reference() // destroy the object
{
}

Tritset::reference & Tritset::reference::operator=(Trit val) {

	_PTritset->set_value(_pos, val);
	return *this;
}

Tritset::reference & Tritset::reference::operator=(const reference & Tritset) {

	this->_PTritset->set_value(_pos, Tritset._value);
	return *this;
}

bool Tritset::reference::operator!=(Trit val) {

	if (_value != val)
		return True;
	else return False;
}

bool Tritset::reference::operator!=(const reference & Trit) {

	if (this->_value != Trit._value)
		return True;
	else return False;
}

bool Tritset::reference::operator==(Trit val) {

	if (_value == val)
		return True;
	else return False;
}

bool Tritset::reference::operator==(const reference & Trit) {

	if (this->_value == Trit._value)
		return True;
	else return False;
}

Trit Tritset::reference::operator~() {

	switch (this->_value) {
	case True: return False;
	case False: return True;
	case Unknown: return Unknown;
	}
}

Trit Tritset::reference::operator&(Trit val) {

	switch (this->_value) {
	case True:
		switch (val) {
		case True: return True;
		case False: return False;
		case Unknown: return Unknown;
		}
	case False:
		switch (val) {
		case True: return False;
		case False: return False;
		case Unknown: return False;
		}
	case Unknown:
		switch (val) {
		case True: return Unknown;
		case False: return False;
		case Unknown: return Unknown;
		}
	}
}

Trit Tritset::reference::operator&(const reference & Trit) {

	switch (this->_value) {
	case True:
		switch (Trit._value) {
		case True: return True;
		case False: return False;
		case Unknown: return Unknown;
		}
	case False:
		switch (Trit._value) {
		case True: return False;
		case False: return False;
		case Unknown: return False;
		}
	case Unknown:
		switch (Trit._value) {
		case True: return Unknown;
		case False: return False;
		case Unknown: return Unknown;
		}
	}
}

Trit Tritset::reference::operator|(Trit val) {

	switch (this->_value) {
	case True:
		switch (val) {
		case True: return True;
		case False: return True;
		case Unknown: return True;
		}
	case False:
		switch (val) {
		case True: return True;
		case False: return False;
		case Unknown: return Unknown;
		}
	case Unknown:
		switch (val) {
		case True: return True;
		case False: return Unknown;
		case Unknown: return Unknown;
		}
	}
}

Trit Tritset::reference::operator|(const reference & Trit) {

	switch (this->_value) {
	case True:
		switch (Trit._value) {
		case True: return True;
		case False: return True;
		case Unknown: return True;
		}
	case False:
		switch (Trit._value) {
		case True: return True;
		case False: return False;
		case Unknown: return Unknown;
		}
	case Unknown:
		switch (Trit._value) {
		case True: return True;
		case False: return Unknown;
		case Unknown: return Unknown;
		}
	}
}

Trit Tritset::reference::get_value() {
	return this->_value;
}

size_t Tritset::reference::get_pos() {
	return this->_pos;
}

Tritset* Tritset::reference::get_pointer() {
	return this->_PTritset;
}