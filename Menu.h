#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include "Utils.h"
#include <cstring>
#include <iostream>
namespace sdds {

	class Menu {

	private:

		const unsigned int maxOpts = 15;
		unsigned int numOpts;
		char* MenuContent;

	public:

		Menu(const char* newMenuContent);
		~Menu();
		void print() const;
		unsigned int run() const;
		
	};



}

#endif