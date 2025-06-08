// Copyright 2025 Olenev Dmitri

#include "../include/Automata.h"
#include <iostream>
#include <string>
#include <vector>

Automata::Automata() : cash(0), state(OFF) {
  menu = {"Чай", "Кофе", "Капучино", "Молоко"};
  prices = {30, 50, 70, 40};
}

void Automata::on() {
  if (state == OFF) {
    state = WAIT;
    std::cout << "Автомат включен." << std::endl;
  }
}

// ... (остальные методы остаются без изменений, но с переносом длинных строк)

void Automata::coin(int amount) {
  if (state == WAIT || state == ACCEPT) {
    cash += amount;
    state = ACCEPT;
    std::cout << "Внесено: " << amount << " руб. Текущий баланс: "
              << cash << " руб." << std::endl;
  }
}
