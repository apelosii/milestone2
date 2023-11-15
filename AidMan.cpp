#include "AidMan.h"
#include "Date.h"
namespace sdds {






	AidMan::AidMan(const char* newFilename) : filename(nullptr), mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"){
		filename = nullptr;
		if (newFilename != nullptr) {
			size_t len = strlen(newFilename) + 1;
			filename = new char[len];
			memcpy(filename, newFilename, len);
		}
	}

	AidMan::~AidMan(){
		delete[] filename;
		filename = nullptr;
	}

	unsigned int AidMan::menu(){
		//	Aid Management System Prototype
		//	Date : YYYY / MM / DD
		//	Data file : filename.csv
		//	---------------------------------
		std::cout << "Aid Management System" << std::endl;
		std::cout << Date().formatted(true) << std::endl;
		std::cout << "Data file: " << (filename != nullptr ? filename : "No file") << std::endl << std::endl;
		return mainMenu.run();
	}

	void AidMan::run(){
        unsigned int choice = 1;  // Initialize choice to a non-zero value

        while (choice != 0) {
            choice = menu();
            switch (choice) {
            case 0:
                std::cout << "Exiting Program!" << std::endl;
                break;
            case 1:
                std::cout << "\n****List Items****\n\n";
                break;
            case 2:
                std::cout << "\n****Add Item****\n\n";
                break;
            case 3:
                std::cout << "\n****Remove Item****\n\n";
                break;
            case 4:
                std::cout << "\n****Update Quantity****\n\n";
                break;
            case 5:
                std::cout << "\n****Sort****\n\n";
                break;
            case 6:
                std::cout << "\n****Ship Items****\n\n";
                break;
            case 7:
                std::cout << "\n****New/Open Aid Database****\n\n";
                break;
            }
        }
	}

}