#pragma once
#include <vector>
#include <string>

enum STATES {
    OFF,        // Автомат выключен
    WAIT,       // Ожидание внесения денег
    ACCEPT,     // Прием денег
    CHECK,      // Проверка суммы
    COOK        // Приготовление напитка
};

class Automata {
private:
    int cash;                   // Текущая сумма
    std::vector<std::string> menu;  // Меню напитков
    std::vector<int> prices;    // Цены напитков
    STATES state;               // Текущее состояние

public:
    Automata();                 // Конструктор
    void on();                  // Включение автомата
    void off();                 // Выключение автомата
    void coin(int amount);      // Внесение денег
    std::vector<std::string> getMenu(); // Получение меню
    STATES getState();          // Получение текущего состояния
    void choice(int drink);     // Выбор напитка
    bool check(int drink);      // Проверка суммы
    void cancel();              // Отмена операции
    void cook(int drink);       // Приготовление напитка
    void finish();              // Завершение обслуживания
};
