# Коллоквиум ДМиТИ

[Задания](https://docs.google.com/document/d/1Dv_6AIhxg_3ezu6VMcEnMpyfRzgym9l8PmE4ULGfjgM/edit?tab=t.0)\
[Документация](https://rennelv.github.io/dm_colloc/)

### Необходимые библиотеки для запуска программы:
- cmake v3.22 и выше
- libglfw3
- gtest для сборки тестов


### Сборка и запуск программы:
 ```
git clone https://github.com/Rennelv/dm_colloc
cd dm_colloc
cmake -DCMAKE_BUILD_TYPE=Release -B build
cmake --build build --parallel
./build/bin/dm_math
 ```

### Сборка и запуск тестов:
 ```
cmake -DCMAKE_BUILD_TYPE=Release -B build -DCOMPILE_TESTS=ON
cmake --build build --parallel
./build/bin/dm_tests
 ```

 ### Команда разработчиков:
:star2: Журавлев Дмитрий 3381 - архитектор

:star2: Гладилин Евгений 3381 - ответственный за управление качеством\

:star: Деревягина Александра 3381

:star: Киреева Асия 3381

:star: Кунакова Мария 3381

:star: Салдин Даниил 3381

:star: Уфимцева Алиса 3381

:star: Щеглов Михаил 3381