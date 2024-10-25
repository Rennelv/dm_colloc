# dmiti_colloc
## Коллоквиум ДМиТИ

[Задания](https://docs.google.com/document/d/1Dv_6AIhxg_3ezu6VMcEnMpyfRzgym9l8PmE4ULGfjgM/edit?tab=t.0)

###Дедлайны:

### 27.10.2024:
+ Мария - N7, N10
+ Александра - Z1, Z2
+ Алиса - N2, Q1
+ Михаил - N3
+ Асия - Z4, Z5, Q2, Q4
+ Евгений - N4, N5, N6, N8, N9
+ Данил - Z3, P4, P6

### 30.10.2024:
* Мария - Z6
* Александра - P12
* Алиса - Z8, Q7, Q8
* Михаил - Z9
* Асия - Z7
* Евгений - N11, N12, N13, N14
* Данил - P5

### 02.11.2024:
* Мария - Q5, P1
* Александра - Q6, P2
* Алиса - 
* Михаил - 
* Асия - Z10
* Евгений - P7
* Данил - P3

### 04.11.2024:
* Мария - 
* Александра - 
* Алиса - P9, P11
* Михаил - P8, P10, P13
* Асия - 
* Евгений - 
* Данил - Q1


### Инструкция по использованию репозитория
Для работы с репозиторием необходимо:
1. Склонировать репозиторий
2. Установить cmake(sudo apt install cmake)
3. Запустить /scripts/build sh(в терминале пропишите команду sh scripts/build.sh). После этого код скомпилируется
4. Для создания пулл-реквеста выполните следующие команды
+ git checkout main
+ git pull
+ git checkout -b <название_ветки> // название ветки такое же как название модуля из таблицы
+ git commit -m "название_коммита"
+ git push
5. Не забыть на гитхабе открыть пулл-реквест


### Правила написания программ
Пример готового модуля уже находится в репозиторие.
Для каждого числового множества существует свой класс, а именно N - LongNatural, Z - LongInteger, Q - LongRational, P - Polynomial.

При реализации модуля:
- сигнатура функции должна находится в include/<буква_множества>/функция.hpp
- в сигнатурах используем #ifndef
- тело функции находится в src/<буква_множества>/функция.cpp
- тесты(максимально вдумчиво придумываем их) находятся в tests/<буква_множества>/test_функция.hpp
- код форматировать .clang-format из репозитория
- названия переменных в camelCase
- работа с числами проиходит в формате uint-8_t
- прописывать комментарии. В сигнатурном файле указать Фамилию, группу, что принимает, делает и возвращает функция. Пытайтесь комментировать каджую строчку, но чтобы было читаемо. В местах с большой вложенностью лучше не комментировать каждую строку, а выделить отдельный блок для комментария.

Пример сигнатурного файла include/N/ADD_NN_N.hpp: 
```
#ifndef ADD_NN_N_HPP
#define ADD_NN_N_HPP

#include "N/LongNatural.hpp"

/*
    Выполнил Журавлев Дмитрий 3381

    Функция ADD_NN_N принимает два числа и возвращает их сумму.
    Принимает:
        a - первое число
        b - второе число
    Возвращает:
        LongNatural - сумма чисел
*/

LongNatural ADD_NN_N(const LongNatural& a, const LongNatural& b);

#endif  // ADD_NN_N_HPP
```
Пример тела функции src/N/ADD_NN_N.cpp:
```
#include "N/ADD_NN_N.hpp"

#include <algorithm>  // для std::reverse
#include <cstddef>

#include "N/COM_NN_D.hpp"
#include "N/LongNatural.hpp"

LongNatural ADD_NN_N(const LongNatural& a, const LongNatural& b) {
    std::vector<uint8_t> aArr = a.getArr();  // получаем массивы цифр числа а
    std::vector<uint8_t> bArr = b.getArr();  // получаем массивы цифр числа b

    // если число а меньше числа b, то меняем их местами
    if (COM_NN_D(a, b) == 1) {
        aArr = b.getArr();
        bArr = a.getArr();
    }

    std::vector<uint8_t> resultArr;      // массив для результата
    resultArr.reserve(aArr.size() + 1);  // резервируем место для результата

    uint8_t carry = 0;  // перенос
    size_t aLen = aArr.size();
    size_t bLen = bArr.size();

    for (size_t i = 0; i < aLen; i++) {
        size_t aIdx = aLen - i - 1;        // индекс для числа а с конца
        uint8_t sum = aArr[aIdx] + carry;  // складываем цифру числа а и перенос

        if (i < bLen) {
            size_t bIdx = bLen - i - 1;  // индекс для числа b с конца
            sum += bArr[bIdx];           // если есть соответсвующая цифра числа b, то прибавляем ее
        }

        carry = sum / 10;               // вычисляем перенос
        resultArr.push_back(sum % 10);  // добавляем остаток от деления на 10 в результат
    }

    if (carry != 0) {
        resultArr.push_back(carry);  // если есть перенос, то добавляем его в результат
    }

    std::reverse(resultArr.begin(), resultArr.end());  // переворачиваем массив

    return LongNatural(resultArr);  // возвращаем результат
}
```
