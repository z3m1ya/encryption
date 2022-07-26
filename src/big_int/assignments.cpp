#include "big_int.h"

//Присваивание бигинта
big_int& big_int::operator=(const big_int& value) {
    _value = value._value;
    _sign = value._sign;
    return *this;
}

//Присваивание целого числа
big_int& big_int::operator=(const long long& value) {
    big_int temp(value);
    _value = temp._value;
    _sign = temp._sign;
    return *this;
}

//Присваивание строки
big_int& big_int::operator=(const std::string& value) {
    big_int temp(value);
    _value = temp._value;
    _sign = temp._sign;
    return *this;
}