#include "big_int.h"

//������� ����
const big_int big_int::operator+() const {
	return big_int(*this);
}

//������� �����
const big_int big_int::operator-() const {
	big_int temp(*this);
	temp._sign = !temp._sign;
	return temp;
}
