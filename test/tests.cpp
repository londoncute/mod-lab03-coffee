// Copyright 2025 Olenev Dmitri

#include <gtest/gtest.h>
#include "../include/Automata.h"

TEST(AutomataTest, InitialState) {
  Automata a;
  EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, TurnOn) {
  Automata a;
  a.on();
  EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, AddCoin) {
  Automata a;
  a.on();
  a.coin(50);
  EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, GetMenu) {
  Automata a;
  const auto& menu = a.getMenu();
  ASSERT_FALSE(menu.empty());
  EXPECT_EQ(menu[0], "Чай");
}

TEST(AutomataTest, CheckFunds) {
  Automata a;
  a.on();
  a.coin(40);
  EXPECT_TRUE(a.check(3));  // Молоко стоит 40
  EXPECT_FALSE(a.check(1)); // Кофе стоит 50
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
