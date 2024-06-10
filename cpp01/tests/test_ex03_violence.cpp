#include <gtest/gtest.h>
#include "../ex03/Weapon.hpp"
#include "../ex03/HumanA.hpp"
#include "../ex03/HumanB.hpp"

TEST(violenceTest, getType) {
  Weapon weapon("Cudgel");

  EXPECT_EQ(weapon.getType(), "Cudgel");
  EXPECT_NE(weapon.getType(), "Mace");
}

TEST(violenceTest, setType) {
  Weapon weapon("Sling");

  EXPECT_NE(weapon.getType(), "Mace");
  weapon.setType("Mace");
  EXPECT_EQ(weapon.getType(), "Mace");
}

TEST(violenceTest, setTypeBlank) {
  Weapon weapon("");

  EXPECT_NE(weapon.getType(), "");
  EXPECT_EQ(weapon.getType(), "Default");
  weapon.setType("Mace");
  EXPECT_NE(weapon.getType(), "Default");
  EXPECT_EQ(weapon.getType(), "Mace");
  weapon.setType("");
  EXPECT_NE(weapon.getType(), "");
  EXPECT_EQ(weapon.getType(), "Default");
}

TEST(violenceTest, HumanAAttack) {
  std::setlocale(LC_ALL, "pt_BR.UTF-8");
  Weapon weapon("Zweihänder");
  HumanA bob("Bob", weapon);

  testing::internal::CaptureStdout();
  bob.attack();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Bob attacks with their Zweihänder!\n");
}
