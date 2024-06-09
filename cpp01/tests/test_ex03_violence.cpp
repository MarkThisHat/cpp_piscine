#include <gtest/gtest.h>
#include "../ex03/Weapon.hpp"

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
