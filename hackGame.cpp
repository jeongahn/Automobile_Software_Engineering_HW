#include <iostream>
#include <string>
#include <vector>

void showMenu();
void startGame();
void showInstructions();
void displayCANPackets();
bool checkGuess(const std::string& manufacturer, const std::string& model);

int main() {
  showMenu();
  return 0;
}

void showMenu() {
  int choice;
  do {
    std::cout << "=== CAN Protocol Hacking CTF Game ===\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Instructions\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        startGame();
        break;
      case 2:
        showInstructions();
        break;
      case 3:
        std::cout << "Exiting the game. Goodbye!\n";
        break;
      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 3);
}

void startGame() {
  std::cout << "문제: 자동차의 CAN과 통신해서 얻은 패킷들을 통해 어떤 "
               "자동차인지 알아내야한다!\n";
  displayCANPackets();

  std::string manufacturer, model;
  bool correct = false;

  while (!correct) {
    std::cout << "Enter the manufacturer: ";
    std::cin.ignore();
    std::getline(std::cin, manufacturer);
    std::cout << "Enter the model: ";
    std::getline(std::cin, model);

    if (checkGuess(manufacturer, model)) {
      std::cout << "Congratulations! You guessed correctly!\n";
      exit(0);
    } else {
      std::cout << "Fail, try again.\n";
    }
  }
}

void showInstructions() {
  std::cout << "=== Instructions ===\n";
  std::cout << "1. The goal is to guess the manufacturer and model of the car "
               "based on the provided CAN packets.\n";
  std::cout << "2. You will be provided with simulated CAN packets.\n";
  std::cout << "3. Analyze the packets and input the correct manufacturer and "
               "model.\n";
  std::cout << "4. Good luck!\n";
}

void displayCANPackets() {
  std::vector<std::string> canPackets = {
      "can0  7E0   [8]  03 22 F1 90 00 00 00 00",
      "can0  7E8   [8]  10 14 62 F1 90 57 44 44",
      "can0  7E0   [8]  30 00 00 00 00 00 00 00",
      "can0  7E8   [8]  21 48 46 35 47 42 35 42",
      "can0  7E8   [8]  22 41 32 37 30 38 36 36"};

  std::cout << "Simulated CAN Packets:\n";
  for (const auto& packet : canPackets) {
    std::cout << packet << "\n";
  }
}

bool checkGuess(const std::string& manufacturer, const std::string& model) {
  // Correct manufacturer and model
  const std::string correctManufacturer = "BMW";
  const std::string correctModel = "328i";

  return (manufacturer == correctManufacturer && model == correctModel);
}