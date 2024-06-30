#include <gtest/gtest.h>
#include "../ex01/incl/Dog.hpp"
#include "../ex01/incl/Cat.hpp"

TEST(BrainTest, SetAndGetIdea) {
    Brain brain;
    brain.setIdea("Idea 1", 0);
    EXPECT_EQ(brain.getIdea(0), "Idea 1");
    EXPECT_EQ(brain.getIdea(1), "This animal has no idea");
}

TEST(DogTest, SetAndGetBrainIdea) {
    Dog dog;
    dog.setBrainIdea("Chase the cat", 0);
    EXPECT_EQ(dog.getBrain().getIdea(0), "Chase the cat");

    Dog dog2 = dog;
    EXPECT_EQ(dog2.getBrain().getIdea(0), "Chase the cat");

    Dog dog3;
    dog3 = dog;
    EXPECT_EQ(dog3.getBrain().getIdea(0), "Chase the cat");

    dog2.setBrainIdea("Sleep all day", 0);
    EXPECT_EQ(dog.getBrain().getIdea(0), "Chase the cat");
    EXPECT_EQ(dog2.getBrain().getIdea(0), "Sleep all day");
}

TEST(CatTest, SetAndGetBrainIdea) {
    Cat cat;
    cat.setBrainIdea("Catch the mouse", 0);
    EXPECT_EQ(cat.getBrain()->getIdea(0), "Catch the mouse");

    Cat cat2 = cat;
    EXPECT_EQ(cat2.getBrain()->getIdea(0), "Catch the mouse");

    Cat cat3;
    cat3 = cat;
    EXPECT_EQ(cat3.getBrain()->getIdea(0), "Catch the mouse");

    cat2.setBrainIdea("Sleep all day", 0);
    EXPECT_EQ(cat.getBrain()->getIdea(0), "Catch the mouse");
    EXPECT_EQ(cat2.getBrain()->getIdea(0), "Sleep all day");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
