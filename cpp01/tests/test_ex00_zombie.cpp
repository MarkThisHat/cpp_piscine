#include <gtest/gtest.h>
#include "../ex00/Zombie.hpp"

TEST(ZombieTest, Announce) {
	Zombie zombie("Foo");
	testing::internal::CaptureStdout();
	zombie.announce();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Foo: BraiiiiiiinnnzzzZ...\n");
}

TEST(ZombieTest, NewZombie) {
	Zombie* zombie = newZombie("Bar");
	testing::internal::CaptureStdout();
	zombie->announce();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Bar: BraiiiiiiinnnzzzZ...\n");
	delete zombie;
}

TEST(ZombieTest, RandomChump) {
	testing::internal::CaptureStdout();
	randomChump("Baz");
	std::string output = testing::internal::GetCapturedStdout();
	std::size_t pos = output.find("\n");
    std::string announcement = output.substr(0, pos + 1);
    EXPECT_EQ(announcement, "Baz: BraiiiiiiinnnzzzZ...\n");
}
