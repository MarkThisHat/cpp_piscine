#include <gtest/gtest.h>
#include "../ex02/FragTrap.hpp"

TEST(FragTrapTest, Constructor) {
    FragTrap frag("FT-42");

    EXPECT_EQ(frag.getName(), "FT-42");
    EXPECT_EQ(frag.getHitPoints(), 100);
    EXPECT_EQ(frag.getEnergyPoints(), 100);
    EXPECT_EQ(frag.getAttackDamage(), 30);
}

TEST(FragTrapTest, CopyConstructor) {
    FragTrap frag1("FT-42");
    FragTrap frag2(frag1);

    EXPECT_EQ(frag2.getName(), "FT-42");
    EXPECT_EQ(frag2.getHitPoints(), 100);
    EXPECT_EQ(frag2.getEnergyPoints(), 100);
    EXPECT_EQ(frag2.getAttackDamage(), 30);
}

TEST(FragTrapTest, AssignmentOperator) {
    FragTrap frag1("FT-42");
    FragTrap frag2("FT-43");

    frag2 = frag1;

    EXPECT_EQ(frag2.getName(), "FT-42");
    EXPECT_EQ(frag2.getHitPoints(), 100);
    EXPECT_EQ(frag2.getEnergyPoints(), 100);
    EXPECT_EQ(frag2.getAttackDamage(), 30);
}

TEST(FragTrapTest, HighFivesGuys) {
    FragTrap frag("FT-42");

    testing::internal::CaptureStdout();
    frag.highFivesGuys();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "FragTrap FT-42 is requesting a high five! High fives, folks!\n");
}

TEST(FragTrapTest, Attack) {
    FragTrap frag("FT-42");

    testing::internal::CaptureStdout();
    frag.attack("target");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "FragTrap FT-42 attacks target for [30] damage! (99) energy points left.\n");
}

TEST(FragTrapTest, TakeDamage) {
    FragTrap frag("FT-42");

    frag.takeDamage(20);
    EXPECT_EQ(frag.getHitPoints(), 80);
}

TEST(FragTrapTest, BeRepaired) {
    FragTrap frag("FT-42");

    frag.takeDamage(50);
    frag.beRepaired(30);
    EXPECT_EQ(frag.getHitPoints(), 80);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
