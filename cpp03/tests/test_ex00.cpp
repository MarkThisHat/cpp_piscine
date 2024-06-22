#include <gtest/gtest.h>
#include "../ex00/ClapTrap.hpp"

TEST(ClapTrapTest, Constructor) {
    ClapTrap claptrap("CT-01");
    ASSERT_EQ(claptrap.getName(), "CT-01");
    ASSERT_EQ(claptrap.getHitPoints(), 10);
    ASSERT_EQ(claptrap.getEnergyPoints(), 10);
    ASSERT_EQ(claptrap.getAttackDamage(), 0);
}

TEST(ClapTrapTest, Attack) {
    ClapTrap claptrap("CT-01");
    claptrap.attack("Target-01");
    ASSERT_EQ(claptrap.getEnergyPoints(), 9);
}

TEST(ClapTrapTest, TakeDamage) {
    ClapTrap claptrap("CT-01");
    claptrap.takeDamage(5);
    ASSERT_EQ(claptrap.getHitPoints(), 5);
}

TEST(ClapTrapTest, BeRepaired) {
    ClapTrap claptrap("CT-01");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    ASSERT_EQ(claptrap.getHitPoints(), 8);
    ASSERT_EQ(claptrap.getEnergyPoints(), 9);
}

TEST(ClapTrapTest, EnergyDepletion) {
    ClapTrap claptrap("CT-01");
    for (int i = 0; i < 10; ++i) {
        claptrap.attack("Target-01");
    }
    ASSERT_EQ(claptrap.getEnergyPoints(), 0);
    claptrap.attack("Target-01");
    ASSERT_EQ(claptrap.getEnergyPoints(), 0);
}

TEST(ClapTrapTest, CopyConstructor) {
    ClapTrap claptrap1("CT-01");
    claptrap1.attack("Target-01");
    ClapTrap claptrap2(claptrap1);
    ASSERT_EQ(claptrap2.getName(), "CT-01");
    ASSERT_EQ(claptrap2.getHitPoints(), claptrap1.getHitPoints());
    ASSERT_EQ(claptrap2.getEnergyPoints(), claptrap1.getEnergyPoints());
    ASSERT_EQ(claptrap2.getAttackDamage(), claptrap1.getAttackDamage());
}

TEST(ClapTrapTest, AssignmentOperator) {
    ClapTrap claptrap1("CT-01");
    claptrap1.attack("Target-01");
    ClapTrap claptrap2("CT-02");
    claptrap2 = claptrap1;
    ASSERT_EQ(claptrap2.getName(), "CT-01");
    ASSERT_EQ(claptrap2.getHitPoints(), claptrap1.getHitPoints());
    ASSERT_EQ(claptrap2.getEnergyPoints(), claptrap1.getEnergyPoints());
    ASSERT_EQ(claptrap2.getAttackDamage(), claptrap1.getAttackDamage());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
