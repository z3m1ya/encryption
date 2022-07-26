#include "big_int.h"

//Операции только с бигинтами:

big_int big_int::operator+(const big_int& summand) const {
	if (!_sign) {
		if (!summand._sign)
			return -(-*this + (-summand));
		else 
			return summand - (-*this);
	}
	else if (!summand._sign) 
		return *this - (-summand);
	bool carry = false;
	big_int sum(*this);
	for (unsigned long long i = 0; i < std::max(sum._value.size(), summand._value.size()) || carry != 0; ++i) {
		long long temp = (i < sum._value.size() ? sum._value[i] : 0);
		if (i >= _value.size())
			sum._value.push_back(0);
		temp += carry + (i < summand._value.size() ? summand._value[i] : 0);
		carry = temp >= big_int::_BASE;
		if (carry)
			temp -= big_int::_BASE;
		sum._value[i] = temp;
	}
	return sum;
}

big_int big_int::operator-(const big_int& subtracted) const {
	if (!subtracted._sign)
		return *this + (-subtracted);
	else if (!_sign) 
		return -(-*this + subtracted);
	else if (*this < subtracted)
		return -(subtracted - *this);
	else {
		big_int difference(*this);
		unsigned long long carry = 0;
		for (unsigned long long i = 0; i < subtracted._value.size() || carry != 0; ++i) {
			long long temp = _value[i] - (carry + (i < subtracted._value.size() ? subtracted._value[i] : 0));
			carry = temp < 0;
			if (carry != 0)
				temp += big_int::_BASE;
			difference._value[i] = temp;
		}
		difference._remove_leading_zeros();
		return difference;
	}
}

big_int big_int::operator*(const big_int& multiplier) const {
	big_int result, product(*this);
	result._value.resize(product._value.size() + multiplier._value.size());
	for (unsigned long long i = 0; i < product._value.size(); ++i) {
		unsigned long long carry = 0;
		for (unsigned long long j = 0; j < multiplier._value.size() || carry != 0; ++j) {
			long long cur = result._value[i + j] +
				product._value[i] * 1LL * (j < multiplier._value.size() ? multiplier._value[j] : 0) + carry;
			result._value[i + j] = static_cast<unsigned long>(cur % big_int::_BASE);
			carry = static_cast<unsigned long long>(cur / big_int::_BASE);
		}
	}
	result._sign = product._sign == multiplier._sign;
	result._remove_leading_zeros();
	return result;
}
/* {
	if (*this == 0 or right == 0)
		return big_int(0);
	if (*this == 1)
		return multiplier;
	if (right == 1)
		return *this;

	big_int result;

	if (abs(*this) < _BASE || abs(right) < _BASE)
		result = _value[0] * right._value[0];
	else {
		big_int left(*this);
		std::vector<unsigned long> larger, smaller;
		if (left._value.size() > right._value.size()) {
			larger = left._value;
			smaller = right._value;
		}
		else {
			larger = right._value;
			smaller = left._value;
		}
		add_leading_zeroes(smaller, larger.size() - smaller.size());
		unsigned long long half_length = larger.size() / 2;
		auto half_length_ceil = (unsigned long long) ceil(larger.size() / 2.0);
		big_int a_high, a_low;
		a_high._value = { &larger[0], &larger[half_length]};
		a_low._value = { &larger[half_length], &larger[larger.size()-1]};
		big_int b_high, b_low;
		b_high._value = { &smaller[0], &smaller[half_length] };
		b_low._value = { &smaller[half_length], &smaller[smaller.size()-1]};

		a_high._remove_leading_zeros();
		a_low._remove_leading_zeros();
		b_high._remove_leading_zeros();
		b_low._remove_leading_zeros();

		big_int result_high, result_mid, result_low;
		result_high = a_high * b_high;
		result_low = a_low * b_low;
		result_mid = (a_high + a_low) * (b_high + b_low) - result_high - result_low;

		add_trailing_zeroes(result_high._value, 2 * half_length_ceil);
		add_trailing_zeroes(result_mid._value, half_length_ceil);
		result_high._remove_leading_zeros();
		result_mid._remove_leading_zeros();
		result_low._remove_leading_zeros();

		result = result_high + result_mid + result_low;
	}
	result._remove_leading_zeros();

	if (this->_sign == right._sign)
		result._sign = true;
	else
		result._sign = false;

	return result;
} */

/*big_int big_int::operator/(const big_int& divider) const {
	if (divider == 0) 
		throw std::logic_error("Attempted division by zero");
	big_int b = divider;
	b._sign = true;
	big_int result, current, quotient(*this);
	result._value.resize(quotient._value.size());
	for (long long i = static_cast<long long>(quotient._value.size()) - 1; i >= 0; --i) {
		current._shift_right();
		current._value[0] = quotient._value[i];
		current._remove_leading_zeros();
		unsigned long long x = 0, l = 0, r = big_int::_BASE;
		while (l <= r) {
			int m = (l + r) / 2;
			big_int temp = b * m;
			if (temp <= current) {
				x = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		std::cout << 111 << " " << result._value[i];
		result._value[i] = x;
		current = current - b * x;
	}

	result._sign = quotient._sign == divider._sign;
	result._remove_leading_zeros();
	return result;
} */

big_int big_int::operator/(const big_int& right) const {
	big_int left = *this;
	if (right == 0) 
		throw std::logic_error("Attempted division by zero");
	big_int b = right;
	b._sign = true;
	big_int result, current;
	result._value.resize(left._value.size());
	for (unsigned long long i = (left._value.size()); i > 0; --i) {
		current._shift_right();
		current._value[0] = left._value[i - 1];
		current._remove_leading_zeros();
		unsigned long long l = 0, r = big_int::_BASE;
		unsigned long long x = 0;
		while (l <= r) {
			unsigned long long m = (l + r) / 2;
			big_int t = b * m;
			if (t <= current) {
				x = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		result._value[i - 1] = x;
		current = current - b * x;
	}
	result._sign = left._sign == right._sign;
	result._remove_leading_zeros();
	return result;
}

big_int big_int::operator%(const big_int& divider) const {
	big_int result = *this - (*this / divider) * divider;
	if (!result._sign) 
		result += divider;
	return result;
}

//Операции с целыми числами:

big_int big_int::operator+(const long long& addendum) const {
	return *this + big_int(addendum);
}

big_int operator+(const long long& a, const big_int& b) {
	return big_int(a) + b;
}

big_int big_int::operator-(const long long& subtrahend) const {
	return *this - big_int(subtrahend);
}

big_int operator-(const long long& a, const big_int& b) {
	return big_int(a) - b;
}

big_int big_int::operator*(const long long& multiplier) const {
	return *this * big_int(multiplier);
}

big_int operator*(const long long& a, const big_int& b) {
	return big_int(a) * b;
}

big_int big_int::operator/(const long long& divider) const {
	return *this / big_int(divider);
}

big_int operator/(const long long& a, const big_int& b) {
	return big_int(a) / b;
}

big_int big_int::operator%(const long long& divider) const {
	return *this % big_int(divider);
}

big_int operator%(const long long& a, const big_int& b) {
	return big_int(a) % b;
}

//Операции со строками:

big_int big_int::operator+(const std::string& value) const {
	return *this + big_int(value);
}

big_int operator+(const std::string& a, const big_int& b) {
	return big_int(a) + b;
}

big_int big_int::operator-(const std::string& value) const {
	return *this - big_int(value);
}

big_int operator-(const std::string& a, const big_int& b) {
	return big_int(a) - b;
}

big_int big_int::operator*(const std::string& value) const {
	return *this * big_int(value);
}

big_int operator*(const std::string& a, const big_int& b) {
	return big_int(a) * b;
}

big_int big_int::operator/(const std::string& value) const {
	return *this / big_int(value);
}

big_int operator/(const std::string& a, const big_int& b) {
	return big_int(a) / b;
}

big_int big_int::operator%(const std::string& value) const {
	return *this % big_int(value);
}

big_int operator%(const std::string& a, const big_int& b) {
	return big_int(a) % b;
}