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

void Automata::off() {
  if (state == WAIT) {
    state = OFF;
    std::cout << "Автомат выключен." << std::endl;
  }
}

void Automata::coin(int amount) {
  if (state == WAIT || state == ACCEPT) {
    cash += amount;
    state = ACCEPT;
    std::cout << "Внесено: " << amount << " руб. Текущий баланс: "
              << cash << " руб." << std::endl;
  }
}

const std::vector<std::string>& Automata::getMenu() const {
  return menu;
}

STATES Automata::getState() const {
  return state;
}

void Automata::choice(int drink) {
  if (state == ACCEPT && drink >= 0 && drink < menu.size()) {
    if (check(drink)) {
      state = CHECK;
      cook(drink);
    } else {
      std::cout << "Недостаточно средств!" << std::endl;
    }
  }
}

bool Automata::check(int drink) const {
  return cash >= prices[drink];
}

void Automata::cancel() {
  if (state == ACCEPT || state == CHECK) {
    std::cout << "Операция отменена. Возврат: " << cash << " руб." << std::endl;
    cash = 0;
    state = WAIT;
  }
}

void Automata::cook(int drink) {
  if (state == CHECK) {
    state = COOK;
    std::cout << "Готовим " << menu[drink] << "..." << std::endl;
    cash -= prices[drink];
    finish();
  }
}

void Automata::finish() {
  state = WAIT;
  std::cout << "Напиток готов. Заберите его." << std::endl;
  if (cash > 0) {
    std::cout << "Сдача: " << cash << " руб." << std::endl;
    cash = 0;
  }
}
