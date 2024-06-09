#include <gtest/gtest.h>
#include <string>

void setupVariables(\
	std::string& brain, \
	std::string*& stringPTR, \
	std::string& stringREF\
	) {

	brain = "HI THIS IS BRAIN";
	stringPTR = &brain;
	stringREF = brain;
}

TEST(StringTest, AddressTest) {
	std::string		brain;
	std::string* 	stringPTR;
	std::string& 	stringREF = brain;

	setupVariables(brain, stringPTR, stringREF);


	std::cout << "Memory address of string: " << &brain << std::endl;
	EXPECT_EQ(&brain, stringPTR);
	std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
	EXPECT_EQ(&brain, &stringREF);
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
	EXPECT_EQ(stringPTR, &stringREF);
}

TEST(StringTest, ValueTest) {
	std::string		brain;
	std::string*	stringPTR;
	std::string&	stringREF = brain;

	setupVariables(brain, stringPTR, stringREF);

	std::cout << "Value of string: " << brain << std::endl;
	EXPECT_EQ("HI THIS IS BRAIN", brain);
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	EXPECT_EQ("HI THIS IS BRAIN", *stringPTR);
	std::cout << "Value referenced by stringREF: " << stringREF << std::endl;
	EXPECT_EQ("HI THIS IS BRAIN", stringREF);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
