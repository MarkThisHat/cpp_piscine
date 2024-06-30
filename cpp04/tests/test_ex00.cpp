#include <gtest/gtest.h>
#include "../ex00/incl/Animal.hpp"
#include "../ex00/incl/Cat.hpp"
#include "../ex00/incl/Dog.hpp"
#include "../ex00/incl/WrongAnimal.hpp"
#include "../ex00/incl/WrongCat.hpp"

TEST(AnimalTest, MakeSound) {
    Animal animal;
    testing::internal::CaptureStdout();
    animal.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\033[37mAnimal makes Animal-like noises\033[0m\n");
}

TEST(CatTest, MakeSound) {
    testing::internal::CaptureStdout();
    Animal* cat = new Cat();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\x1B[34mConstructor: \x1B[0m\x1B[33mYou are adopted by a new Cat!\x1B[0m\n");
    testing::internal::CaptureStdout();
    cat->makeSound();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\033[33mCat MEOWS\033[0m\n");
    delete cat;
}

TEST(DogTest, MakeSound) {
    testing::internal::CaptureStdout();
    Animal* dog = new Dog();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\x1B[34mConstructor: \x1B[0m\x1B[32mYou adopt a new Dog!\x1B[0m\n");
    testing::internal::CaptureStdout();
    dog->makeSound();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\033[32mDog BARKS\033[0m\n");
    delete dog;
}

TEST(WrongAnimalTest, MakeSound) {
    WrongAnimal* wrongAnimal = new WrongCat();
    testing::internal::CaptureStdout();
    wrongAnimal->makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\033[95mThe sounds this animal makes are just SO WRONG\033[0m\n");
    delete wrongAnimal;
}

TEST(WrongCatTest, MakeSound) {
    WrongCat wrongCat;
    testing::internal::CaptureStdout();
    wrongCat.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\033[93mThis cat meows wrongly\033[0m\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
