#include "big_int.h"

//Операции сравнений между бигинтами

bool big_int::operator==(const big_int& value) const {
    if (_sign != value._sign) 
        return false;

    if (_value.size() != value._value.size()) 
        return false;

    for (unsigned long long i = 0; i < _value.size(); ++i) 
        if (_value[i] != value._value[i]) return false;

    return true;
}

bool big_int::operator!=(const big_int& value) const {
    return !(*this == value);
}

bool big_int::operator<(const big_int& value) const {
    if (*this == value) return false;
    if (!_sign) {
        if (value._sign)
            return ((-value) < (-*this));
        else 
            return true;
    }
    else if (!value._sign) 
        return false;
    else {
        if (_value.size() != value._value.size()) {
            return _value.size() < value._value.size();
        }
        else {
            for (long long i = _value.size() - 1; i >= 0; --i) {
                if (_value[i] != value._value[i]) 
                    return _value[i] < value._value[i];
            }
            return false;
        }
    }
}

bool big_int::operator>(const big_int& value) const {
    return !((*this < value) || (*this == value));
}

bool big_int::operator<=(const big_int& value) const {
    return (*this < value) || (*this == value);
}

bool big_int::operator>=(const big_int& value) const {
    return !(*this < value);
}

//Операции сравнений между целами числами и бигинтами

bool big_int::operator==(const long long& value) const {
    return *this == big_int(value);
}

bool operator==(const long long& a, const big_int& b) {
    return big_int(a) == b;
}

bool big_int::operator!=(const long long& value) const {
    return !(*this == big_int(value));
}

bool operator!=(const long long& a, const big_int& b) {
    return big_int(a) != b;
}

bool big_int::operator<(const long long& value) const {
    return *this < big_int(value);
}

bool operator<(const long long& a, const big_int& b) {
    return big_int(a) < b;
}

bool big_int::operator>(const long long& value) const {
    return *this > big_int(value);
}

bool operator>(const long long& a, const big_int& b) {
    return big_int(a) > b;
}

bool big_int::operator<=(const long long& value) const {
    return !(*this > big_int(value));
}

bool operator<=(const long long& a, const big_int& b) {
    return big_int(a) <= b;
}

bool big_int::operator>=(const long long& value) const {
    return !(*this < big_int(value));
}

bool operator>=(const long long& a, const big_int& b) {
    return big_int(a) >= b;
}

//Операции сравнений с строками и бигинтами

bool big_int::operator==(const std::string& value) const {
    return *this == big_int(value);
}

bool operator==(const std::string& a, const big_int& b) {
    return big_int(a) == b;
}

bool big_int::operator!=(const std::string& value) const {
    return !(*this == big_int(value));
}

bool operator!=(const std::string& a, const big_int& b) {
    return big_int(a) != b;
}

bool big_int::operator<(const std::string& value) const {
    return *this < big_int(value);
}

bool operator<(const std::string& a, const big_int& b) {
    return big_int(a) < b;
}

bool big_int::operator>(const std::string& value) const {
    return *this > big_int(value);
}

bool operator>(const std::string& a, const big_int& b) {
    return big_int(a) > b;
}

bool big_int::operator<=(const std::string& value) const {
    return !(*this > big_int(value));
}

bool operator<=(const std::string& a, const big_int& b) {
    return big_int(a) <= b;
}

bool big_int::operator>=(const std::string& value) const {
    return !(*this < big_int(value));
}

bool operator>=(const std::string& a, const big_int& b) {
    return big_int(a) >= b;
}