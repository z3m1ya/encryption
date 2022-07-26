#pragma once

#include <vector>
#include <iostream>
#include <string>


class big_int{

public:
	static const unsigned long long _BASE = 4294967296; //Система счисления (2^32)

	bool _sign;							//Знак
	std::vector<unsigned long> _value;	//Значение

	//private_methods.cpp
	//Служебные методы:

	bool _is_valid_number(const std::string&);
	void _remove_leading_zeros();
	void _shift_right();


	//constructors.cpp
	//Конструкторы:

	big_int();
	big_int(const big_int&);
	big_int(const std::string&);
	big_int(const long long&);

	//assignments.cpp
	//Присваивание:

	big_int& operator=(const big_int&);
	big_int& operator=(const long long&);
	big_int& operator=(const std::string&);

	//relationals.cpp
	//Оперции сравнения:

	bool operator==(const big_int&) const;
	bool operator!=(const big_int&) const;
	bool operator<(const big_int&) const;
	bool operator>(const big_int&) const;
	bool operator<=(const big_int&) const;
	bool operator>=(const big_int&) const;

	bool operator==(const long long&) const;
	bool operator!=(const long long&) const;
	bool operator<(const long long&) const;
	bool operator>(const long long&) const;
	bool operator<=(const long long&) const;
	bool operator>=(const long long&) const;

	bool operator==(const std::string&) const;
	bool operator!=(const std::string&) const;
	bool operator<(const std::string&) const;
	bool operator>(const std::string&) const;
	bool operator<=(const std::string&) const;
	bool operator>=(const std::string&) const;

	//unary_arithmetic.cpp
	//Унарные операции:

	const big_int operator+() const;
	const big_int operator-() const;
	
	//binary_arithmetic.cpp
	//Бинарные операции:

	big_int operator+(const big_int&) const;
	big_int operator-(const big_int&) const;
	big_int operator*(const big_int&) const;
	big_int operator/(const big_int&) const;
	big_int operator%(const big_int&) const;

	big_int operator+(const long long&) const;
	big_int operator-(const long long&) const;
	big_int operator*(const long long&) const;
	big_int operator/(const long long&) const;
	big_int operator%(const long long&) const;

	big_int operator+(const std::string&) const;
	big_int operator-(const std::string&) const;
	big_int operator*(const std::string&) const;
	big_int operator/(const std::string&) const;
	big_int operator%(const std::string&) const;

	//arithmetic_assignments.cpp
	//Операции с присваиванием:

	big_int& operator+=(const big_int&);
	big_int& operator-=(const big_int&);
	big_int& operator*=(const big_int&);
	big_int& operator/=(const big_int&);
	big_int& operator%=(const big_int&);

	big_int& operator+=(const long long&);
	big_int& operator-=(const long long&);
	big_int& operator*=(const long long&);
	big_int& operator/=(const long long&);
	big_int& operator%=(const long long&);

	big_int& operator+=(const std::string&);
	big_int& operator-=(const std::string&);
	big_int& operator*=(const std::string&);
	big_int& operator/=(const std::string&);
	big_int& operator%=(const std::string&);

	//increment_decrement.cpp
	//Инкримент и дискримент:

	big_int& operator++();		// ++i
	big_int& operator--();		// --i
	big_int operator++(int);	// i++
	big_int operator--(int);	// i--

	//streams.cpp
	//Потоки:

	friend std::istream& operator>>(std::istream&, big_int&);
	friend std::ostream& operator<<(std::ostream&, const big_int&);
	
	//public_methods.cpp
	//Публинчные методы:

	bool prime() const;
	bool sign() const;
	bool odd() const;
	bool even() const;
	unsigned long long size() const;

	std::string to_string() const;
	int to_int() const;
	long to_long() const;
	long long to_long_long() const;

	big_int abs() const;
	big_int sqr() const;
	big_int sqrt() const;
	big_int pow(const unsigned long long&) const;
	big_int pows(const unsigned long long&, const unsigned long long&) const;
};

//function.cpp
//Функции:

void add_leading_zeroes(std::vector<unsigned long>&, const unsigned long long&);
void add_trailing_zeroes(std::vector<unsigned long>&, const unsigned long long&);

big_int gcd(const big_int&, const big_int&);
big_int lcm(const big_int&, const big_int&);

void swap(big_int&, big_int&);
big_int abs(const big_int&);
big_int fact(const big_int&);  
big_int pow2(const unsigned long long);
big_int pow10(const unsigned long long);
big_int sqr(const big_int&);
big_int sqrt(const big_int&);
big_int pow(const big_int&, const unsigned long long&);
big_int pows(const big_int&, const big_int&, const big_int&);
big_int pows(const big_int&, const long long&, const long long&);
big_int random(unsigned long long);
big_int random(std::string);