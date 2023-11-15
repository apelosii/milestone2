#include "Date.h"
#include "Utils.h"
#include <iostream>
	
namespace sdds {

	// Structors
	Date::Date(int year, int month, int day){
		Year = year;
		Month = month;
		Day = day;
		validate();
	}

	Date& Date::operator=(const Date& other) {
		Year = other.Year;
		Month = other.Month;
		Day = other.Day;
		Formatted = other.Formatted;
		State = other.State;
		return *this;
	}

	Date::Date() {
		ut.getSystemDate(&Year, &Month, &Day);
		Formatted = true;
	}

	bool Date::validate() {
		bool ok = true;
		int currYear;
		ut.getCurrYear(&currYear);
		if (Year < currYear || Year > maxYearValue) {
			State = "Invalid year in date";
			State = 1;
			ok = false;
		}
		else if (Month < 1 || Month > 12) {
			State = "Invalid month in date";
			State = 2;
			ok = false;
		}
		else if (Day < 1 || Day > ut.daysOfMon(Month, Year)) {
			State = "Invalid day in date";
			State = 3;
			ok = false;
		}
		else {
			State.clear();
		}
		return ok;
	}

	int Date::uniqueDateValue()
	{
		return (Year * 372 + Month * 31 + Day);
	}

	// Accessor
	const Status& Date::state() const{
		return State;
	}


	// Overloads
	bool Date::operator==(Date& other) {
		return (uniqueDateValue() == other.uniqueDateValue());
	}
	bool Date::operator!=(Date& other) {
		return (uniqueDateValue() != other.uniqueDateValue());
	}
	bool Date::operator<(Date& other) {
		return (uniqueDateValue() < other.uniqueDateValue());
	}
	bool Date::operator>(Date& other) {
		return (uniqueDateValue() > other.uniqueDateValue());
	}
	bool Date::operator<=(Date& other) {
		return (uniqueDateValue() <= other.uniqueDateValue());
	}
	bool Date::operator>=(Date& other) {
		return (uniqueDateValue() >= other.uniqueDateValue());
	}
	Date::operator bool() {
		return state();
	}

	// Modifier
	Date& Date::formatted(bool flag){
		Formatted = flag;
		return *this;
	}


	std::ostream& Date::write(std::ostream& ostr){
		if (Formatted == true) {
			//  YYYY/MM/DD
			ostr << Year << '/' << std::setw(2) << std::setfill('0') << Month << '/' << std::setw(2) << std::setfill('0') << Day;
		}else{
			ostr << (Year % 100) << std::setw(2) << std::setfill('0') << Month << std::setw(2) << std::setfill('0') << Day;
		}
		return ostr;
	}

	std::istream& Date::read(std::istream& istr){ 
		int inputDate;
		istr >> inputDate;
		if (istr.good()) {
			if (inputDate <= 9999) {
				Month = inputDate / 100;
				Day = inputDate % 100;
			}
			else if (inputDate >= 100000 && inputDate <= 999999) {
				Year = (inputDate / 10000) + 2000;
				Month = (inputDate / 100) % 100;
				Day = inputDate % 100;
			}
			else {
				std::cout << "Invalid date value";
				istr.setstate(std::ios::failbit);
			}

			if (!validate()) {
				istr.setstate(std::ios::failbit);
			}
		}
		else {
			std::cout << "Invalid date value";
			istr.setstate(std::ios::failbit);
		}
		return istr;
	}


	std::ostream& operator<<(std::ostream& ostr, Date& date) {
		return date.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Date& date) {
		return date.read(istr);
	}

}
