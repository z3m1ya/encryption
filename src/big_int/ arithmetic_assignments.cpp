#include "big_int.h"

//Операции только с бигинтами:

big_int& big_int::operator+=(const big_int& summand) {
    *this = *this + summand;
    return *this;
}

big_int& big_int::operator-=(const big_int& subtracted) {
    *this = *this - subtracted;
    return *this;
}

big_int& big_int::operator*=(const big_int& multiplier) {
    *this = *this * multiplier;
    return *this;
}

big_int& big_int::operator/=(const big_int& divider) {
    *this = *this / divider;
    return *this;
}

big_int& big_int::operator%=(const big_int& divider) {
    *this = *this % divider;
    return *this;
}

//Операции с бигинтами и целыми числами:

big_int& big_int::operator+=(const long long& summand) {
    *this = *this + big_int(summand);
    return *this;
}

big_int& big_int::operator-=(const long long& subtracted) {
    *this = *this - big_int(subtracted);
    return *this;
}

big_int& big_int::operator*=(const long long& multiplier) {
    *this = *this * big_int(multiplier);
    return *this;
}

big_int& big_int::operator/=(const long long& divider) {
    *this = *this / big_int(divider);
    return *this;
}

big_int& big_int::operator%=(const long long& divider) {
    *this = *this % big_int(divider);
    return *this;
}

//Операции с бигинтами и строками:

big_int& big_int::operator+=(const std::string& value) {
    *this = *this + big_int(value);
    return *this;
}

big_int& big_int::operator-=(const std::string& value) {
    *this = *this - big_int(value);
    return *this;
}

big_int& big_int::operator*=(const std::string& value) {
    *this = *this * big_int(value);
    return *this;
}

big_int& big_int::operator/=(const std::string& value) {
    *this = *this / big_int(value);
    return *this;
}

big_int& big_int::operator%=(const std::string& value) {
    *this = *this % big_int(value);
    return *this;
}