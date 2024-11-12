# Коллоквиум ДМиТИ

[Задания](https://docs.google.com/document/d/1Dv_6AIhxg_3ezu6VMcEnMpyfRzgym9l8PmE4ULGfjgM/edit?tab=t.0)


Необходимые библиотеки для запуска программы:
- cmake v3.22 и выше
- libglfw3
- gtest для сборки тестов


 Сборка и запуск:
 ```
 - git clone https://github.com/Rennelv/dm_colloc
 - cd dm_colloc
 - cmake -DCMAKE_BUILD_TYPE=Release -B build
 - cmake --build build --parallel
 - ./build/bin/dm_math
 ```