// Copyright 2025 Olenev Dmitri

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum STATES {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class Automata {
 private:
  int cash;
  std::vector<std::string> menu;
  std::vector<int> prices;
  STATES state;

 public:
  Automata();
  void on();
  void off();
  void coin(int amount);
  const std::vector<std::string>& getMenu() const;
  STATES getState() const;
  void choice(int drink);
  bool check(int drink) const;
  void cancel();
  void cook(int drink);
  void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
