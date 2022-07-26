#pragma once
#include "gen_keys.h"
#include "C_File.h"

class crypt : public gen_keys {
private:
    int findF(long long);

public:
    void stringError(int);
    int cryptFile(std::string, std::string); //зашифровка
    int decryptFile(std::string, std::string); //расшифровка

    //получение сгенерированных ключей
    void getKey_1args();
    void getKey_2args(std::string);
    void getKey_3args(char* argv[]);
};