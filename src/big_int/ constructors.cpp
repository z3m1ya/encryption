#include "big_int.h"

//Конструктор для null
big_int::big_int() : _sign(true) {
	_value.push_back(0);
}

//Конструктор копирования
big_int::big_int(const big_int& value) : _sign(value._sign) {
	_value = { value._value.begin(), value._value.end() };
}

//Конструктор для строк
big_int::big_int(const std::string& str) {
	big_int temp = 0, temp2 = 0, temp3 = 0;;
	if (str[0] == '+' || str[0] == '-') {
		_sign = str[0] == '+' ? true : false;
		std::string temp_str = str.substr(1);
		if (_is_valid_number(temp_str))
			for (unsigned long long i = 0; i < temp_str.length(); i++) {
				temp += big_int(10).pow(str.length() - i - 2) * int(temp_str[i] - '0');
			}
		else
			throw std::invalid_argument("Expected an integer, got \'" + str + "\'");
	}
	else {
		_sign = true;
		if (_is_valid_number(str))
			for (unsigned long long i = 0; i < str.length(); i++)
				temp += big_int(int(str[i] - '0')) * big_int(10).pow(str.length() - i - 1);
		else
			throw std::invalid_argument("Expected an integer, got \'" + str + "\'");
	}
	_value = temp._value;
}

//Конструктор для целых чисел
big_int::big_int(const long long& num) : _sign(num >= 0 ? true : false) {
	if (num >= _BASE) {
		_value.push_back(std::abs(num) % _BASE);
		_value.push_back(std::abs(num) / _BASE);
	}
	else
		_value.push_back(std::abs(num));
}