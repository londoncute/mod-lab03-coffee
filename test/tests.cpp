// Copyright 2025 Olenev Dmitri

#include <gtest/gtest.h>
#include "../include/Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, TurnsOnCorrectly) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, AcceptsCoins) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, ReturnsCorrectMenu) {
    Automata a;
    const auto& menu = a.getMenu();
    ASSERT_EQ(menu.size(), 4);
    EXPECT_EQ(menu[0], "Чай");
    EXPECT_EQ(menu[1], "Кофе");
}

TEST(AutomataTest, ChecksBalanceCorrectly) {
    Automata a;
    a.on();
    a.coin(40);
    EXPECT_TRUE(a.check(3));  // Молоко стоит 40
    EXPECT_FALSE(a.check(1)); // Кофе стоит 50
}

TEST(AutomataTest, CancelsOperation) {
    Automata a;
    a.on();
    a.coin(100);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
