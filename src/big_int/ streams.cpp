#include "big_int.h"

//Ввод
std::istream& operator>>(std::istream& in, big_int& value) {
    std::string input;
    in >> input;
    value = big_int(input);
    return in;
}

//Вывод
std::ostream& operator<<(std::ostream& out, const big_int& value) {
    out << value.to_string();
    return out;
}