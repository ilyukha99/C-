#include "Trit.h"

Tritset::reference::reference(Tritset* PTritset = NULL, size_t pos = 0) : _pos(pos), _PTritset(PTritset) {

}

Tritset::reference::~reference() // destroy the object
{
}

Tritset::reference & Tritset::reference::operator=(Trit val) {

	_PTritset->set_value(_pos, val);
	return *this;
}

Tritset::reference & Tritset::reference::operator=(const reference & ts) {

	this->_PTritset->set_value(_pos, (Trit)ts);
	return *this;
}

Trit operator~(Trit tr) {

	switch (tr) {
	case True: return False;
	case False: return True;
	default: return Unknown;
	}
}

Trit operator&(Trit left, Trit rigth) {

	switch (left) {
	case True:
		switch (rigth) {
		case True: return True;
		case False: return False;
		case Unknown: return Unknown;
		}
	case False:
		switch (rigth) {
		case True: return False;
		case False: return False;
		case Unknown: return False;
		}
	case Unknown:
		switch (rigth) {
		case True: return Unknown;
		case False: return False;
		case Unknown: return Unknown;
		}
	default: return Unknown;
	}
}

Trit operator|(Trit left, Trit rigth) {

	switch (left) {
	case True:
		switch (rigth) {
		case True: return True;
		case False: return True;
		case Unknown: return True;
		}
	case False:
		switch (rigth) {
		case True: return True;
		case False: return False;
		case Unknown: return Unknown;
		}
	case Unknown:
		switch (rigth) {
		case True: return True;
		case False: return Unknown;
		case Unknown: return Unknown;
		}
	default: return Unknown;
	}
}

Tritset::reference::operator Trit() const {
	return _PTritset->get_value(_pos);
}