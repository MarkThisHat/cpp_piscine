#include <gtest/gtest.h>
#include "../ex02/incl/Dog.hpp"
#include "../ex02/incl/Cat.hpp"

TEST(AnimalTest, DogMakeSound) {
    Dog dog;
    EXPECT_NO_THROW(dog.makeSound());
}

TEST(AnimalTest, CatMakeSound) {
    Cat cat;
    EXPECT_NO_THROW(cat.makeSound());
}

TEST(AnimalTest, DogSetAndGetBrainIdea) {
    Dog dog;
    dog.setBrainIdea("Fetch the ball", 0);
    EXPECT_EQ(dog.getBrain().getIdea(0), "Fetch the ball");
}

TEST(AnimalTest, CatSetAndGetBrainIdea) {
    Cat cat;
    cat.setBrainIdea("Catch the mouse", 0);
    EXPECT_EQ(cat.getBrain().getIdea(0), "Catch the mouse");
}

TEST(AnimalTest, PolymorphicBehavior) {
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();

    dog->setBrainIdea("Guard the house", 0);
    cat->setBrainIdea("Sleep on the couch", 0);

    EXPECT_EQ(dog->getBrain().getIdea(0), "Guard the house");
    EXPECT_EQ(cat->getBrain().getIdea(0), "Sleep on the couch");

    delete dog;
    delete cat;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
