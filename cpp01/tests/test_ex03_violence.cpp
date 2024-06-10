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

TEST(violenceTest, HumanAName) {
  Weapon weapon("");
  HumanA alice("Alice", weapon);

  EXPECT_EQ("Alice", alice.getName());
}

TEST(violenceTest, HumanAAttack) {
  std::setlocale(LC_ALL, "pt_BR.UTF-8");
  Weapon weapon("Zweihänder");
  HumanA alice("Alice", weapon);

  testing::internal::CaptureStdout();
  alice.attack();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Alice attacks with their Zweihänder!\n");
}

TEST(violenceTest, HumanASetWeapon) {
  Weapon knife("Knife");
  Weapon submachine("Submachine gun");
  HumanA alice("Allie", knife);

  testing::internal::CaptureStdout();
  alice.setWeapon(submachine);
  std::string output = testing::internal::GetCapturedStdout();  
  EXPECT_EQ(output, "Allie puts down Knife.\nAllie picks up Submachine gun.\n");
}

TEST(violenceTest, HumanBName) {
  HumanB bob("Bob");

  EXPECT_EQ("Bob", bob.getName());
}

TEST(violenceTest, HumanBAttack) {
  std::setlocale(LC_ALL, "pt_BR.UTF-8");
  Weapon weapon("Épée");
  HumanB bob("Bob", weapon);

  testing::internal::CaptureStdout();
  bob.attack();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Bob attacks with their Épée!\n");
  bob.unsetWeapon();
  testing::internal::CaptureStdout();
  bob.attack();
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Bob attacks with their *bare hands*!\n");
}

TEST(violenceTest, HumanBSetWeapon) {
  HumanB bob("Robert");

  testing::internal::CaptureStdout();
  bob.unsetWeapon();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Robert is already unarmed!\n");
  Weapon dagger("Dagger");
  testing::internal::CaptureStdout();
  bob.setWeapon(dagger);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Robert picks up Dagger.\n");
  Weapon shotgun("Shotgun");
  testing::internal::CaptureStdout();
  bob.setWeapon(shotgun);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Robert puts down Dagger.\nRobert picks up Shotgun.\n");
}
