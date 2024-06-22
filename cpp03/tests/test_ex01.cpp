#include <gtest/gtest.h>
#include "../ex01/ScavTrap.hpp"

TEST(ScavTrapTest, Constructor) {
    ScavTrap scavtrap("ST-01");
    ASSERT_EQ(scavtrap.getName(), "ST-01");
    ASSERT_EQ(scavtrap.getHitPoints(), 100);
    ASSERT_EQ(scavtrap.getEnergyPoints(), 50);
    ASSERT_EQ(scavtrap.getAttackDamage(), 20);
    ASSERT_FALSE(scavtrap.guardingStatus());
}

TEST(ScavTrapTest, CopyConstructor) {
    ScavTrap scavtrap1("ST-01");
    scavtrap1.guardGate();
    ScavTrap scavtrap2(scavtrap1);
    ASSERT_EQ(scavtrap2.getName(), "ST-01");
    ASSERT_EQ(scavtrap2.getHitPoints(), 100);
    ASSERT_EQ(scavtrap2.getEnergyPoints(), 50);
    ASSERT_EQ(scavtrap2.getAttackDamage(), 20);
    ASSERT_TRUE(scavtrap2.guardingStatus());
}

TEST(ScavTrapTest, AssignmentOperator) {
    ScavTrap scavtrap1("ST-01");
    scavtrap1.guardGate();
    ScavTrap scavtrap2("ST-02");
    scavtrap2 = scavtrap1;
    ASSERT_EQ(scavtrap2.getName(), "ST-01");
    ASSERT_EQ(scavtrap2.getHitPoints(), 100);
    ASSERT_EQ(scavtrap2.getEnergyPoints(), 50);
    ASSERT_EQ(scavtrap2.getAttackDamage(), 20);
    ASSERT_TRUE(scavtrap2.guardingStatus());
}

TEST(ScavTrapTest, GuardGate) {
    ScavTrap scavtrap("ST-01");
    scavtrap.guardGate();
    ASSERT_TRUE(scavtrap.guardingStatus());
    scavtrap.guardGate();
    ASSERT_FALSE(scavtrap.guardingStatus());
}

TEST(ScavTrapTest, InheritedAttack) {
    ScavTrap scavtrap("ST-01");
    scavtrap.attack("Target-01");
    ASSERT_EQ(scavtrap.getEnergyPoints(), 49);
}

TEST(ScavTrapTest, InheritedTakeDamage) {
    ScavTrap scavtrap("ST-01");
    scavtrap.takeDamage(50);
    ASSERT_EQ(scavtrap.getHitPoints(), 50);
}

TEST(ScavTrapTest, InheritedBeRepaired) {
    ScavTrap scavtrap("ST-01");
    scavtrap.takeDamage(50);
    scavtrap.beRepaired(30);
    ASSERT_EQ(scavtrap.getHitPoints(), 80);
    ASSERT_EQ(scavtrap.getEnergyPoints(), 49);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
