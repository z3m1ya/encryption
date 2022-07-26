#include "big_int.h"

//++i
big_int& big_int::operator++() {
    *this += 1;
    return *this;
}

//--i
big_int& big_int::operator--() {
    *this -= 1;
    return *this;
}

//i++
big_int big_int::operator++(int) {
    big_int temp = *this;
    *this += 1;
    return temp;
}

//i--
big_int big_int::operator--(int) {
    big_int temp = *this;
    *this -= 1;
    return temp;
}
