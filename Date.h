#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_

#include "Status.h"
#include <ostream>
#include <istream>
#include <iomanip>
namespace sdds {
	class Date {

	private:

		int Year;
		int Month;
		int Day;
		Status State;
		bool Formatted;

		bool validate();
		int uniqueDateValue();

	public:
		const int maxYearValue = 2030;
		// Structors
		Date(int year, int month, int day);
		Date& operator=(const Date& other);
		Date();

		// Accessor
		const Status& state() const;

		// Overloads
		bool operator==(Date& other);
		bool operator!=(Date& other);
		bool operator<(Date& other);
		bool operator>(Date& other);
		bool operator<=(Date& other);
		bool operator>=(Date& other);
		operator bool();

		Date& formatted(bool flag);

		std::ostream& write(std::ostream& ostr);
		std::istream& read(std::istream& istr);

		friend std::ostream& operator<<(std::ostream& ostr, Date& date);
		friend std::istream& operator>>(std::istream& istr, Date& date);

	};

}


#endif