#include <gtest/gtest.h>
#include "../ex03/incl/Character.hpp"
#include "../ex03/incl/Floor.hpp"
#include "../ex03/incl/MateriaSource.hpp"
#include "../ex03/incl/Ice.hpp"
#include "../ex03/incl/Cure.hpp"

TEST(CharacterTest, TestCharacterCreation) {
    Character* character = new Character("Test Character");
    ASSERT_EQ(character->getName(), "Test Character");
    delete character;
}

TEST(CharacterTest, TestEquipMateria) {
    Character* character = new Character("Test Character");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    character->equip(ice);
    character->equip(cure);
    EXPECT_EQ(character->getMateria(0), "ice");
    EXPECT_EQ(character->getMateria(1), "cure");
    EXPECT_EQ(character->getMateria(2), "");

    delete character;
    Floor::getInstance().clearMaterias();
}

TEST(CharacterTest, TestUnequipMateria) {
    Character* character = new Character("Test Character");
    AMateria* ice = new Ice();

    character->equip(ice);
    character->unequip(0);
    EXPECT_EQ(character->getMateria(0), "");

    delete character;
    Floor::getInstance().clearMaterias();
}

TEST(CharacterTest, TestUseMateria) {
    Character* character = new Character("Test Character");
    Character* target = new Character("Target Character");
    AMateria* ice = new Ice();

    character->equip(ice);
    character->use(0, *target);

    delete character;
    delete target;
    Floor::getInstance().clearMaterias();
}

TEST(MateriaSourceTest, TestLearnMateria) {
    MateriaSource* source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    EXPECT_NE(source->createMateria("ice"), nullptr);
    EXPECT_NE(source->createMateria("cure"), nullptr);
    EXPECT_EQ(source->createMateria("unknown"), nullptr);

    delete source;
}

TEST(MateriaSourceTest, TestCreateMateria) {
    MateriaSource* source = new MateriaSource();
    AMateria* ice = new Ice();

    source->learnMateria(ice);
    AMateria* newIce = source->createMateria("ice");
    EXPECT_NE(newIce, nullptr);
    EXPECT_EQ(newIce->getType(), "ice");
    delete newIce;
    delete source;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
