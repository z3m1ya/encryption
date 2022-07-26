#include "big_int.h"

//������ ������� ����
void add_leading_zeroes(std::vector<unsigned long>& num, const unsigned long long& count) {
	num.insert(num.cbegin(), count, 0);
}

//������ ���� � �����
void add_trailing_zeroes(std::vector<unsigned long>& num, const unsigned long long& count) {
	num.insert(num.cend(), count, 0);
}

//���������� ����� �������
big_int gcd(const big_int& a, const big_int& b) {
	return b != 0 ? gcd(b, a % b) : a;
}

//���������� ����� ��������
big_int lcm(const big_int& a, const big_int& b) {
	return a / gcd(a, b) * b;
}

//�������� �������� ����� a � b
void swap(big_int& a, big_int& b) {
	big_int temp(a);
	a = b;
	b = temp;
}

//������
big_int abs(const big_int& num) {
	return num < 0 ? -num : num;
}

//���������
big_int fact(const big_int& value) {
	if (value == 0)
		return 1;
	else
		return value * fact(value - 1);
}

//���������� � ������� ������
big_int pow2(const unsigned long long exp) {
	return pow(2, exp);
}

//���������� � ������� �������
big_int pow10(const unsigned long long exp) {
	return pow(10, exp);
}

//�������
big_int sqr(const big_int& num) {
	return num*num;
}

//������
big_int sqrt(const big_int& num) {
	big_int l, r = num, result, m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (m * m <= num)
		{
			result = m;
			l = m + 1;
		}
		else
			r = m - 1;
	}
	return result;
}

//���������� � �������
big_int pow(const big_int& num, const unsigned long long& exp) {
	big_int temp(num), result(1);
	big_int temp_exp(exp);
	while (temp_exp != 0) {
		if (temp_exp.odd()) 
			result *= temp;
		temp *= temp;
		temp_exp /= 2;
	}
	return result;
}

//���������� � ������� �� ������
big_int pows(const big_int& num, const big_int& exp, const big_int& m) {
	if (exp == 0)
		return 1;
	if (exp % 2 == 0) {
		big_int temp = pows(num, exp / 2, m);
		return temp * temp % m;
	}
	return pows(num, exp - 1, m) * num % m;
}

//���������� � ������� �� ������
big_int pows(const big_int& num, const long long& exp, const long long& m) {
	if (exp == 0)
		return 1;
	if (exp % 2 == 0) {
		big_int temp = pows(num, exp / 2, m);
		return temp * temp % m;
	}
	return pows(num, exp - 1, m) * num % m;
}

//��������� �����
big_int random(unsigned long long max) {
	big_int temp;
	temp._value[0] = rand() % max;
	return temp;
}

//C�������� �����
big_int random(std::string str) {
	big_int temp(str);
	big_int temp2; int i = 0;
	while (temp > 0) {
		if (temp >= big_int::_BASE) {
			temp /= big_int::_BASE;
			temp2._value.push_back(rand() % big_int::_BASE);
			i++;
		}
		else {
			temp2._value[i] = rand() % temp.to_long_long();
			temp = 0;
		}
		//std::cout << temp2 << "\n";
	}
	return temp2;
}
