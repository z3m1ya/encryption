#include "big_int.h"

//Проверка числа на простоту:
bool big_int::prime() const {
    if (*this % 2 == 0)
        return false;
    for (big_int i = 3; i < this->sqrt(); i += 2)
        if (*this % i == 0)
            return false;
    return true;
}

//Знак
bool big_int::sign() const {
    return _sign;
}

//Нечётность
bool big_int::odd() const {
    return this->_value[0] % 2;
}

//Чётность
bool big_int::even() const {
    return !this->odd();
}

//Размер
unsigned long long big_int::size() const {
    return _value.size();
}

//Конфертация в строку
std::string big_int::to_string() const {
    big_int temp(*this), temp_char;
    std::string str = "";
    temp._sign = true;
    do {
        temp_char = temp % 10;
        str = char(temp_char.to_int() + '0') + str;
        temp = temp / 10;
    } while (temp > 0);
    if (!_sign)
        str = "-" + str;
    return str;
}

//Конвертация в инт
int big_int::to_int() const {
    big_int temp(*this), temp_char;
    int i = 0, k = 0;
    do {
        temp_char = temp % 10;
        i += temp_char._value[0] * std::pow(10,k);
        temp /= 10;
        k++;
    } while (temp > 0);
    if (!_sign)
        i *= -1;
    return i;
}

//Конвертация в лонг
long big_int::to_long() const {
    big_int temp(*this), temp_char;
    long l = 0;
    int k = 0;
    do {
        temp_char = temp % 10;
        l += temp_char._value[0] * std::pow(10, k);
        temp /= 10;
        k++;
    } while (temp > 0);
    if (!_sign)
        l *= -1;
    return l;
}

//Конвертация в лонг лонг
long long big_int::to_long_long() const {
    big_int temp(*this), temp_char;
    long long l = 0;
    int k = 0;
    do {
        temp_char = temp % 10;
        l += temp_char._value[0] * std::pow(10,k);
        temp /= 10;
        k++;
    } while (temp > 0);
    if (!_sign)
        l *= -1;
    return l;
}

//Модуль
big_int big_int::abs() const {
    return this->_sign == true ? *this : -*this;
}

//Квадрат
big_int big_int::sqr() const {
    return *this * *this;
}

//Корень
big_int big_int::sqrt() const {
    big_int l, r = *this, result, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (m * m <= *this)
        {
            result = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return result;
}

//Возведение в степень
big_int big_int::pow(const unsigned long long& exp) const {
    big_int temp(*this), result(1);
    big_int temp_exp(exp);
    while (temp_exp != 0) {
        if (temp_exp.odd())
            result *= temp;
        temp *= temp;
        temp_exp /= 2;
    }
    return result;
}

//Возведение в степень по модулю
big_int big_int::pows(const unsigned long long& exp, const unsigned long long& m) const {
    if (exp == 0)
        return 1;
    if (exp % 2 == 0) {
        big_int temp = this->pows(exp / 2, m);
        return temp * temp % m;
    }
    return this->pows(exp - 1, m) * this->to_long_long() % m;
}
