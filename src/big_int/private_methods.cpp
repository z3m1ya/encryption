#include "big_int.h"

//Проверка строки на правильность числа
bool big_int::_is_valid_number(const std::string& str) {
	for (unsigned long long i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

//Удаление ведущих нулей
void big_int::_remove_leading_zeros() {
	while (_value.size() > 1 && _value.back() == 0) {
		_value.pop_back();
	}
	if (_value.size() == 1 && _value.back() == 0)
		_sign = true;
}

//Сдвиг вправо 
void big_int::_shift_right() {
	if (this->_value.size() == 0) {
		this->_value.push_back(0);
		return;
	}
	this->_value.push_back(this->_value[this->_value.size() - 1]);

	for (unsigned long long i = this->_value.size() - 2; i > 0; --i) 
		this->_value[i] = this->_value[i - 1];
	this->_value[0] = 0;
}
