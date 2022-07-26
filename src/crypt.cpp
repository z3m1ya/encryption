#include "crypt.h"

int crypt::findF(long long n) {
    big_int temp = 256;
    int f = 0;
    while ((temp < n )) {
        temp *= 256;
        f++;
    }
    return f;
}

void crypt::stringError(int error) {
    std::cout << "\nОшибка " << error << std::endl;
}

int crypt::cryptFile(std::string file_, std::string key_) {
    int error;
    C_File key_file(key_);
    if (!key_file.is_key()) {
        error = 3;
        stringError(error);
        std::cout << "Файл \"" << key_file.name << "\" не является ключoм\n";
        return error;
    }
    if (!key_file.is_file()) {
        error = 1;
        stringError(error);
        std::cout << "Ключ \"" << key_file.name << "\" не найден\n";
        return error;
    }
    key public_key = key_file.getKey();
    if (public_key.is_private) {
        error = 2;
        stringError(error);
        std::cout << "Ключ \"" << key_file.name << "\" не является открытым\n";
        return error;
    }
    big_int byte8 = 0;
    C_File a(file_), b("#" + std::string(file_) + '#');
    if (!a.is_file()) {
        error = 5;
        stringError(error);
        std::cout << "Файл \"" << a.name << "\" не найден\n";
        return error;
    }
    const int f = findF(public_key.n);
    std::cout << "\nИдёт шифрование файла \"" << a.name << "\"(" << a.size() << " байт) закрытым ключом \"" << key_file.name << "\" (размер буфера " << f << ")\n[";
    int r = a.size() / f >  20 ? (a.size() / f) / 20 : f;
    for (unsigned long long i = 0; i < a.size() / f; i++) {
        byte8 = 0;
        for (int j = 0; j < f; j++) {
            unsigned char t = a.getByte();
            //std::cout << int(t) << ") ";
            byte8 = (big_int(256).pow(j) * t) + byte8;
        }

        if (i % (r) == 0)
            std::cout << "#";

        byte8 = pows(byte8, public_key.e,public_key.n);

        for (int j = 0; j < f + 1; j++) {
            unsigned char temp = (byte8 % 256).to_int();
            b.pushByte(temp);
            //std::cout << a.point() << " " <<j<<" " << int(temp) << "\t";
            byte8 = byte8 / 256;
        }
    }
    for (int i = 0; i < a.size() % f; i++)
    {
        unsigned char t = a.getByte();
        b.pushByte(t);
    }
    std::cout << "]\n\nФайл успешно зашифрован!";
}

int crypt::decryptFile(std::string file_, std::string key_) {
    int error;
    C_File key_file(key_, 2);
    if (!key_file.is_key()) {
        error = 3;
        stringError(error);
        std::cout << "Файл \"" << key_file.name << "\" не является ключом\n";
        return error;
    }
    if (!key_file.is_file()) {
        error = 1;
        stringError(error);
        std::cout << "Ключ \"" << key_file.name << "\" не найден\n";
        return error;
    }
    key private_key = key_file.getKey();
    if (!private_key.is_private) {
        error = 2;
        stringError(error);
        std::cout << "Ключ \"" << key_file.name << "\" не является закрытым\n";
        return error;
    }
    big_int byte8 = 0;
    std::string file__ = file_;
    C_File a(file_, 0), b(file__.substr(1, file__.size() - 2), 1);
    //std::cout << file__.substr(1, file__.size() - 2);
    if (!a.is_file()) {
        error = 5;
        stringError(error);
        std::cout << "Файл \"" << a.name << "\" не найден\n";
        return error;
    }
    const int f = findF(private_key.n) + 1;
    std::cout << "\nИдёт расшифрование файла \"" << a.name << "\"(" << a.size() << " байт) закрытым ключом \"" << key_file.name << "\" (размер буфера "<< f <<")\n[";
    int r = a.size() > 20 * f ? a.size() / (20 * f) : f;
    for (unsigned long long i = 0; i < a.size() / f; i++) {
        byte8 = 0;
        for (int j = 0; j < f; j++) {
            unsigned char t = a.getByte();
            //std::cout << int(t) << ") ";
            byte8 = (big_int(256).pow(j) * t) + byte8;
        }

        if (i % (r) == 0)
            std::cout << "#";

        byte8 = pows(byte8, private_key.e, private_key.n);

        for (int j = 0; j < f - 1; j++) {
            unsigned char temp = (byte8 % 256).to_int();
            b.pushByte(temp);
            //std::cout << a.point() << " " <<j<<" " << int(temp) << "\t";
            byte8 = byte8 / 256;
        }
    }
    for (int i = 0; i < a.size() % f; i++)
    {
        unsigned char t = a.getByte();
        b.pushByte(t);
    }
    std::cout << "]\n\nФайл успешно расширован!";
    return 0;
}

void crypt::getKey_1args() {
    newKey_1args();
}

void crypt::getKey_2args(std::string argv) {
    void newKey_2args(std::string argv);
}

void crypt::getKey_3args(char* argv[]) {
    void newKey_3args(char* argv[]);
}