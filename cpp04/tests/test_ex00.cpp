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
    EXPECT_EQ(output, "Makes Animal noises\n");
}

TEST(CatTest, MakeSound) {
    testing::internal::CaptureStdout();
    Animal* cat = new Cat();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\033[33mYou are adopted by a new Cat!\033[0m\n");
    testing::internal::CaptureStdout();
    cat->makeSound();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\033[33mCat meows\033[0m\n");
    delete cat;
}

TEST(DogTest, MakeSound) {
    Dog dog;
    testing::internal::CaptureStdout();
    dog.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Dog barks\n");
}

TEST(WrongAnimalTest, MakeSound) {
    WrongAnimal wrongAnimal("Incorrect");
    testing::internal::CaptureStdout();
    wrongAnimal.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "WrongAnimal makes a sound\n");
}

TEST(WrongCatTest, MakeSound) {
    WrongCat wrongCat;
    testing::internal::CaptureStdout();
    wrongCat.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "This cat meows wrongly\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}