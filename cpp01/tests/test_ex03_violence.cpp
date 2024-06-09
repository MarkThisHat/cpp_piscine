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
