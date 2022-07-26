#include "gen_keys.h"
#include <iostream>

bool gen_keys::checkPrime(uint64_t value) {
    if (value % 2 == 0)
        return false;
    uint64_t s = sqrt(value) + 1;
    for (uint64_t i = 3; i< s; i+=2)
        if (value % i == 0)
            return false;
    return true;
}

uint64_t gen_keys::nPrime(uint64_t n) {
    uint64_t count = 0, a = 72345679;
    while (count != n) {
        a+=2;
        if (checkPrime(a))
            count++;
    }
    return a;
}

void gen_keys::newKey_1args() {
    key public_key, private_key;
    srand(time(NULL));
    int n_p = (rand() % 9999);
    int n_q = (rand() % 9999) + 1;
    std::cout << "Начата генерация ключей, это может занять некоторое время...\n";
    uint64_t p = nPrime(n_p);
    std::cout << "Первая часть ключа получена, p = "<<p<<"\n";
    uint64_t q = nPrime(n_q);
    std::cout << "Вторая часть ключа получена, q = " << q << "\n";
    big_int n = p * q;
    big_int fi = (p - 1) * (q - 1);
    big_int e = 2;
    std::cout << "\tn = "<< n <<"\n\tфи = "<<fi<<"\n\t";
    while (gcd(e, fi) != 1) {
        e++;
    }
    big_int k = 1;
    while (((k * fi) + 1) % e != 0) {
        k++;
    }
    big_int d = ((k * fi) + 1) / e;
    private_key.e = d.to_long_long();
    public_key.e = e.to_long_long();
    private_key.n = n.to_long_long();
    public_key.n = n.to_long_long();
    std::cout << "e = " << e << "\n\td = " << d << "\n\tk = " << k<<"\n";
    public_key.is_private = false;
    private_key.is_private = true;
    C_File public_key_("public.key", 1);
    C_File private_key_("private.key", 1);
    private_key_.setKey(private_key);
    public_key_.setKey(public_key);
    std::cout << "Ключи готовы!\n";
}

void gen_keys::newKey_2args(std::string argv) {
    key public_key, private_key;
    srand(std::stol(argv));
    int n_p = (rand() % 1000000);
    int n_q = (rand() % 1000000);
    std::cout << "Начата генерация ключей, это может занять некоторое время...\n";
    uint64_t p = nPrime(n_p);
    std::cout << "Первая часть ключа получена, p = " << p << "\n";
    uint64_t q = nPrime(n_q);
    std::cout << "Вторая часть ключа получена, q = " << q << "\n";
    //std::cout << p << " " << n_p << "\n";
    //std::cout << q << " " << n_q << "\n";
    big_int n = p * q;
    big_int fi = (p - 1) * (q - 1);
    big_int e = 2;
    std::cout << "\tn = " << n << "\n\tфи = " << fi << "\n\t";
    while (gcd(e, fi) != 1) {
       // std::cout << gcd(e, fi) << "\n";
        e++;
    }
    big_int k = 1;
    while (((k * fi) + 1) % e != 0) {
        k++;
    }
    big_int d = ((k * fi) + 1) / e;
    private_key.e = d.to_long_long();
    public_key.e = e.to_long_long();
    private_key.n = n.to_long_long();
    public_key.n = n.to_long_long();
    std::cout << "e = " << e << "\n\td = " << d << "\n\tk = " << k << "\n";
    public_key.is_private = false;
    private_key.is_private = true;
    C_File public_key_("public.key", 1);
    C_File private_key_("private.key", 1);
    private_key_.setKey(private_key);
    public_key_.setKey(public_key);
    std::cout << "Ключи готовы!\n";
}

void gen_keys::newKey_3args(char* argv[]) {
    key public_key, private_key;
    int n_p = std::stol(argv[2]);
    int n_q = std::stol(argv[3]);
    //std::cout << "Начата генерация ключей, это может занять некоторое время...\n";
    uint64_t p = n_p;
    std::cout << "Первая часть ключа получена, p = " << p << "\n";
    uint64_t q = n_q;
    std::cout << "Вторая часть ключа получена, q = " << q << "\n";
    //std::cout << p << " " << n_p << "\n";
   // std::cout << q << " " << n_q << "\n";
    big_int n = p * q;
    big_int fi = (p - 1) * (q - 1);
    big_int e = 2;
    std::cout << "\tn = " << n << "\n\tфи = " << fi << "\n\t";
    while (gcd(e, fi) != 1) {
        //std::cout << gcd(e, fi) << "\n";
        e++;
    }
    big_int k = 1;
    while (((k * fi) + 1) % e != 0) {
        k++;
    }
    big_int d = ((k * fi) + 1) / e;
    private_key.e = d.to_long_long();
    public_key.e = e.to_long_long();
    private_key.n = n.to_long_long();
    public_key.n = n.to_long_long();
    std::cout << "e = " << e << "\n\td = " << d << "\n\tk = " << k << "\n";
    public_key.is_private = false;
    private_key.is_private = true;
    C_File public_key_("public.key", 1);
    C_File private_key_("private.key", 1);
    private_key_.setKey(private_key);
    public_key_.setKey(public_key);
    std::cout << "Ключи готовы!\n";
}