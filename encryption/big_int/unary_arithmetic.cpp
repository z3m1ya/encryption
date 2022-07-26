#include "big_int.h"

//”нарный плюс
const big_int big_int::operator+() const {
	return big_int(*this);
}

//”нарный минус
const big_int big_int::operator-() const {
	big_int temp(*this);
	temp._sign = !temp._sign;
	return temp;
}
