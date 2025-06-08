// Copyright 2025 Olenev Dmitri

#include <iostream>
#include "../include/Automata.h"

int main() {
  Automata coffeeMachine;

  coffeeMachine.on();
  coffeeMachine.coin(100);
  std::cout << "Меню:" << std::endl;
  auto menu = coffeeMachine.getMenu();
  for (size_t i = 0; i < menu.size(); i++) {
    std::cout << i << ". " << menu[i] << std::endl;
  }
  coffeeMachine.choice(1);
  coffeeMachine.off();

  return 0;
}
