#include <gtest/gtest.h>
#include "../ex03/DiamondTrap.hpp"

TEST(DiamondTrapTest, Initialization) {
    DiamondTrap dt("Diamond");

    EXPECT_EQ(dt.getName(), "Diamond");
    EXPECT_EQ(dt.ClapTrap::getName(), "Diamond_clap_name");
    EXPECT_EQ(dt.getHitPoints(), 100);
    EXPECT_EQ(dt.getEnergyPoints(), 50);
    EXPECT_EQ(dt.getAttackDamage(), 30);
}

TEST(DiamondTrapTest, AttackFunction) {
    DiamondTrap dt("Diamond");

    testing::internal::CaptureStdout();
    dt.attack("target");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Diamond_clap_name attacks target"), std::string::npos);
}

TEST(DiamondTrapTest, WhoAmIFunction) {
    DiamondTrap dt("Diamond");

    testing::internal::CaptureStdout();
    dt.whoAmI();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Who am I? I'm Diamond_clap_name but also: Diamond\n");
}

TEST(DiamondTrapTest, CopyConstructor) {
    DiamondTrap dt1("Diamond");
    DiamondTrap dt2(dt1);

    EXPECT_EQ(dt2.getName(), "Diamond");
    EXPECT_EQ(dt2.ClapTrap::getName(), "Diamond_clap_name");
    EXPECT_EQ(dt2.getHitPoints(), dt1.getHitPoints());
    EXPECT_EQ(dt2.getEnergyPoints(), dt1.getEnergyPoints());
    EXPECT_EQ(dt2.getAttackDamage(), dt1.getAttackDamage());
}

TEST(DiamondTrapTest, AssignmentOperator) {
    DiamondTrap dt1("Diamond");
    DiamondTrap dt2("Emerald");

    dt2 = dt1;

    EXPECT_EQ(dt2.getName(), "Diamond");
    EXPECT_EQ(dt2.ClapTrap::getName(), "Diamond_clap_name");
    EXPECT_EQ(dt2.getHitPoints(), dt1.getHitPoints());
    EXPECT_EQ(dt2.getEnergyPoints(), dt1.getEnergyPoints());
    EXPECT_EQ(dt2.getAttackDamage(), dt1.getAttackDamage());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
