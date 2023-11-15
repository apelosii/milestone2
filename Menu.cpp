#include "Menu.h"

namespace sdds {

	Menu::Menu(const char* newMenuContent) {
		if (newMenuContent == nullptr || strlen(newMenuContent) == 0) {
			MenuContent = nullptr;
			numOpts = 0;
		}
		else {
			numOpts = 0;
			size_t len = strlen(newMenuContent) + 1;
			MenuContent = new char[len];
			memcpy(MenuContent, newMenuContent, len);

			for (int i = 0; MenuContent[i] != '\0'; i++) {
				if (MenuContent[i] == '\t') {
					numOpts += 1;
				}
				else if (MenuContent[i+1] == '\0') {
					numOpts += 1; // Add one more time because content is missing one \t
				}
			}

			if (numOpts > 15) {
				delete[] MenuContent;
				MenuContent = nullptr; // Too many options, render the menu invalid
				numOpts = 0;
			}
		}
	}

	Menu::~Menu() {
		delete[] MenuContent;
		MenuContent = nullptr;
	}

	void Menu::print() const{
		unsigned int count = 1;
		int i = 0;
			do {
			while (MenuContent[i] != '\0') {
				if (MenuContent[i] == '\t') {
					std::cout << '\n';
					count++;
					std::cout << count << "- ";
				}
				else {
					if (i == 0) {
						std::cout << count << "- ";
					}
					std::cout << MenuContent[i];
				}
				i += 1;
			}
		} while (count < numOpts);
		std::cout << "\n---------------------------------" << std::endl;
		std::cout << "0- Exit" << std::endl;
	}

	unsigned int Menu::run() const {
		if (MenuContent != nullptr) {
			print();
			// Data Entry
			std::cout << "> ";
			bool ok = true;
			unsigned int choice;
			while (ok) {
				std::cin >> choice;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Invalid Integer, retry: ";
				}
				else if(choice < 1 || choice > numOpts) {
					if (choice == 0) {
						return choice;
					}
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Value out of range [0<=val<=" << numOpts << "]: ";
				}
				else {
					ok = false;
				}
			}
			return choice;
		}
		else {
			std::cout << "Invalid Menu!" << std::endl;
			return 0;
		}
	}
}
