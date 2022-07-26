#pragma once
#include "key.h"
#include "C_File.h"


//Генерация ключей

class gen_keys {
private:
    bool checkPrime(uint64_t);
    uint64_t nPrime(uint64_t);

public:
    void newKey_1args();
    void newKey_2args(std::string);
    void newKey_3args(char* argv[]);
};