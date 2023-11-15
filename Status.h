#ifndef SDDS_STATUS_H_
#define SDDS_STATUS_H_

#include <ostream>
namespace sdds {

	class Status {
	private:
		char* desc;
		int statusCode;
	public:

		Status(const char* desc = nullptr);
		Status(const Status& other);
		~Status();

		Status& operator=(int code);
		Status& operator=(const char* newDesc);
		friend std::ostream& operator<<(std::ostream& ostr, const Status& st);
		operator int() const;
		operator const char* () const;
		operator bool() const;

		Status& clear();

	};


}

#endif