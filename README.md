# encryption version 1.2
Курсовая работа. Разработка библиотеки очень длинных чисел для реализации алгоритма асимметричного шифрования.

### Для использования необходимо запускать программу с аргументами командной строки:
`encryption <crypt/c/decrypt/d/key/k> [/?] <Путь к файлу> [Путь к открытому/закрытому ключу] [Зерно генерации ключа] [Простое число 1] [Простое число 2]`

`[/?]` - Вывод справки

`<crypt>` или `<c>` - Зашифровать

`<Путь к файлу>` - Путь или имя файла который нужно зашифровать
`[Путь к открытому ключу]` - Путь или имя открытого ключу, по умолчанию это "public.key"

Пример: `encryption crypt sercet.txt public_1.key`

`<decrypt>` или `<d>` - Расшифровать

`<Путь к файлу>` - Путь или имя файла который нужно расшифровать
`[Путь к закрытому ключу]` - Путь или имя открытого ключу, по умолчанию это "private.key"

Пример: `encryption decrypt #sercet.txt# private_1.key`

`<key>` или `<k>` - Сгенерировать пару ключей

`[Зерно генерации ключа]` - слово или строка на основе которой сгенерируется пара простых больших простых чисел
`[Простое число 1] [Простое число 2]` - Пара простых чисел на основе которых сгенерируются ключи.
Внимение!!! Если указать небольшие числа то шифр легко можно будет взломать, если указать непростые числа то шифрование не будет работать
