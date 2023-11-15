#include "Status.h"
#include "Utils.h"
#include <cstring>
#include <iostream>
namespace sdds {


	Status::Status(const char* newDesc) : desc(nullptr), statusCode(0) {
        if (newDesc) {
            ut.alocpy(desc, newDesc);
        }
	}
    // Copy constructor
    Status::Status(const Status& other) : desc(nullptr), statusCode(other.statusCode) {
        if (other.desc) {
            ut.alocpy(desc, other.desc);
        }
    }


    Status::~Status() {
        clear();
    }


    // Operator Overloads

    Status& Status::operator=(int code)
    {
        statusCode = code;
        return *this;
    }

    Status& Status::operator=(const char* newDesc)
    {
        ut.alocpy(desc, newDesc);
        return *this;
    }

    // Type Conversion Overloads

    Status::operator int() const
    {
        return statusCode;
    }

    Status::operator const char* () const
    {
        return desc;
    }

    Status::operator bool() const
    {
        return !desc;
    }

    Status& Status::clear()
    {
        if (desc) {
            delete[] desc;
            desc = nullptr;
        }
        statusCode = 0;
        return *this;
    }


    std::ostream& operator<<(std::ostream& ostr, const Status& st)
    {
        if (!st) {
            if (st.statusCode) {
                ostr << "ERR#" << st.statusCode << ": " << st.desc;
            }
            else {
                ostr << st.desc;
            }
        }
        return ostr;
    }

}