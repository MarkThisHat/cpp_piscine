#include <gtest/gtest.h>
#include "../ex01/Zombie.hpp"

TEST(HordeTest, ZeroZombie) {
	Zombie* horde = zombieHorde(0, "not a zombie");
	EXPECT_EQ(horde, nullptr);
}

TEST(HordeTest, NegativeZombies) {
	Zombie* horde = zombieHorde(-2, "even less zombies");
	EXPECT_EQ(horde, nullptr);
}

TEST(HordeTest, OneZombie) {
	Zombie* horde = zombieHorde(1, "Zombie");
	ASSERT_NE(horde, nullptr);
	EXPECT_NO_THROW(horde->announce());
	horde[0].~Zombie();
	operator delete[](horde);
}

TEST(HordeTest, ProperHorde) {
	Zombie* horde = zombieHorde(10, "Horde member");
	ASSERT_NE(horde, nullptr);
	for (int i = 0; i < 10; i++) {
		EXPECT_NO_THROW(horde[i].announce());
	}
	for (int i = 0; i < 10; i++) {
		horde[i].~Zombie();
	}
	operator delete[](horde);
}

TEST(HordeTest, Announcements) {
	Zombie* horde = zombieHorde(3, "Richard");
	for (int i = 0; i < 3; i++) {
		testing::internal::CaptureStdout();
		horde[i].announce();
		std::string output = testing::internal::GetCapturedStdout();
		EXPECT_EQ(output, "Richard: BraiiiiiiinnnzzzZ...\n");
	}
	for (int i = 0; i < 3; i++) {
		horde[i].~Zombie();
	}
	operator delete[](horde);
}
