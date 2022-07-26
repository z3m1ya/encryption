#include "C_File.h"

C_File::C_File(const std::string path, int mode)
{
	name = path;
	input_f.open(path, std::ios::in | std::ios::binary);
	std::string temp;
	if (mode == 1)
		output_f.open(name, std::ios::out | std::ifstream::binary);
	if (mode == 2)
		is_key_ = true;
	else
		is_key_ = false;
	point_f = 0;
	//std::cout << name;
}

C_File::C_File(const std::string path)
{
	name = path;
	input_f.open(path, std::ios::in | std::ios::binary);
	if (name[0] == '#')
		output_f.open(name, std::ios::out | std::ifstream::binary);
	point_f = 0;

}

void C_File::setKey(key key_)
{
	output_f << "key\n";
	output_f << key_.e << '\n';
	output_f << key_.n << '\n';
	output_f << key_.is_private;
}

char C_File::getByte()
{
	char temp_char;
	temp_char = input_f.get();
	//input_f >> temp_char;
	point_f++;
	return temp_char;
}

void C_File::pushByte(unsigned char& symbol)
{
	output_f << symbol;
}


key C_File::getKey()
{
	key temp;
	std::string str;
	getline(input_f, str, '\n');
	getline(input_f, str, '\n');
	temp.e = stoll(str);
	getline(input_f, str, '\n');
	temp.n = stoll(str);
	getline(input_f, str, '\n');
	temp.is_private = stoi(str);
	return temp;
}

bool C_File::end() const { return input_f.eof(); }

bool C_File::is_key()
{
	std::string temp;
	input_f >> temp;
	if (temp == "key")
		return true;
	else
		return false;
}

bool C_File::is_file()
{
	if (input_f)
		return true;
	return false;
}


unsigned long long C_File::size()
{
	int temp_size = 0;
	input_f.seekg(0, std::ios::end);
	temp_size = input_f.tellg();
	input_f.seekp(point_f * sizeof(char));
	return temp_size;
}

unsigned long long C_File::point() const { return point_f; }