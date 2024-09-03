/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:36:39 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/03 14:04:49 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

void printBits(uintptr_t value, const std::string& description) {
  std::cout << description << " (raw bits): ";
  for (size_t i = 0; i < sizeof(uintptr_t) * 8; ++i) {
    std::cout << ((value >> (sizeof(uintptr_t) * 8 - 1 - i)) & 1);
    if ((i + 1) % 8 == 0 && i != (sizeof(uintptr_t) * 8 - 1)) {
      std::cout << " ";
    }
  }
  std::cout << "\n";
}

int main() {
  Data* character = new Data;
  character->name = "Fighter";
  character->strength = 16;
  character->dexterity = 14;
  character->constitution = 16;
  character->intelligence = 8;
  character->wisdom = 10;
  character->charisma = 8;
  character->moveSpeed = 9.144f;

  Data* restoredCharacter = NULL;
  std::cout << "Original character pointer address: " << character << "\n";
  std::cout << "Restored character pointer address: " << restoredCharacter << "\n";
  printBits(reinterpret_cast<uintptr_t>(character), "\nThe original pointer");

  uintptr_t raw = Serializer::serialize(character);
  printBits(raw, "A serialized pointer");

  restoredCharacter = Serializer::deserialize(raw);
  printBits(reinterpret_cast<uintptr_t>(restoredCharacter), "Deserialized pointer");

  if (restoredCharacter == character) {
    std::cout << "\nDeserialization successful: pointers match.\n";
  } else {
    std::cout << "\nDeserialization failed: pointers do not match.\n";
  }

  std::cout << "\n[Main] Restored character data:\n";
  std::cout << "Name: " << restoredCharacter->name << "\n";

  character->strength += 2;
  std::cout << "Restored Strength: " << restoredCharacter->strength << "\n";
  std::cout << "Original Strength: " << character->strength << std::endl;

  delete character;

  return 0;
}