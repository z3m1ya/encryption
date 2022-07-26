#pragma once

#include <vector>
#include <fstream>
#include "key.h"

class C_File {
private:
	unsigned long long point_f;
	std::fstream input_f;
	std::ofstream output_f;
	bool is_key_;

public:
	std::string name;

	C_File(const std::string, int);
	C_File(const std::string);

	char getByte();
	void pushByte(unsigned char&);

	void setKey(key);
	key getKey();

	bool end() const;
	bool is_key();
	bool is_file();
	//std::string getName("pub_key");
	//std::string getName("priv_key");
	//std::string getName("encrypting");

	unsigned long long size();
	unsigned long long point() const;
};

