// Copyright 2025 Olenev Dmitri

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

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
  Automata();
  void on();
  void off();
  void coin(int amount);
  std::vector<std::string> getMenu();
  STATES getState();
  void choice(int drink);
  bool check(int drink);
  void cancel();
  void cook(int drink);
  void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
