#include <iostream>
#include "crypt.h"
#include "gen_keys.h"

void printHelp() {
    std::cout << "\nencryption version 1.2\n";
    std::cout << "\nИспользовние: encryption <crypt/c/decrypt/d/key/k> [/?] <Путь к файлу> [Путь к открытому/закрытому ключу] [Зерно генерации ключа] [Простое число 1] [Простое число 2]\n\n";
    std::cout << "\t[/?] - Вывод справки\n\n";
    std::cout << "\t<crypt> или <c> - Зашифровать\n\n";
    std::cout << "\t<Путь к файлу> - Путь или имя файла который нужно зашифровать\n";
    std::cout << "\t[Путь к открытому ключу] - Путь или имя открытого ключу, по умолчанию это \"public.key\"\n";
    std::cout << "\tПример: encryption crypt sercet.txt public_1.key\n\n";
    std::cout << "\t<decrypt> или <d> - Расшифровать\n\n";
    std::cout << "\t<Путь к файлу> - Путь или имя файла который нужно расшифровать\n";
    std::cout << "\t[Путь к закрытому ключу] - Путь или имя открытого ключу, по умолчанию это \"private.key\"\n";
    std::cout << "\tПример: encryption decrypt #sercet.txt# private_1.key\n\n";
    std::cout << "\t<key> или <k> - Сгенерировать пару ключей\n\n";
    std::cout << "\t[Зерно генерации ключа] - слово или строка на основе которой сгенерируется пара простых больших простых чисел\n";
    std::cout << "\t[Простое число 1] [Простое число 2] - Пара простых чисел на основе которых сгенерируются ключи. \n\tВнимение!!! Если указать небольшие числа то шифр легко можно будет взломать, если указать непростые числа то шифрование не будет работать\n\n";
    std::cout << "" << std::endl;
}

int main(int argc, char* argv[]) {
    crypt Crypt;
    gen_keys Gen_keys;
    setlocale(LC_ALL, "Russian");
    std::string defult_key = "public.key";
    std::string defult_private_key = "private.key";
    //std::cout << argv[1] << std::stol(argv[1]);
    if (argc > 1) {
        if (std::string(argv[1]) == "crypt" || std::string(argv[1]) == "c") {
            if (argc == 3)
                return Crypt.cryptFile(std::string(argv[2]), defult_key);
            else if (argc == 4)
                return Crypt.cryptFile(std::string(argv[2]), std::string(argv[3]));
            else
                printHelp();
        }
        else if (std::string(argv[1]) == "decrypt" || std::string(argv[1]) == "d") {
            if (argc == 3)
                return Crypt.decryptFile(std::string(argv[2]), defult_private_key);
            else if (argc == 4)
                return Crypt.decryptFile(std::string(argv[2]), std::string(argv[3]));
            else
                printHelp();
        }
        else if (std::string(argv[1]) == "key" || std::string(argv[1]) == "k") {
            if (argc == 2)
                Gen_keys.newKey_1args();
            else if (argc == 3)
                Gen_keys.newKey_2args(std::string(argv[2]));
            else if (argc == 4)
                Gen_keys.newKey_3args(argv);
            else
                printHelp();
        }
        else
            printHelp();
    }
    else
        printHelp();    
}
