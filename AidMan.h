#ifndef SDDS_AIDMAN_H_
#define SDDS_AIDMAN_H_
#include "Menu.h"
namespace sdds {

	class AidMan {

	private:

		char* filename;
		Menu mainMenu;

		unsigned int menu();

	public:

		AidMan(const char* newFilename = nullptr);
		~AidMan();
		void run();
	};



}

#endif