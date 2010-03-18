
#ifndef _DBIX_TYPES_NUMBER_H_
#define _DBIX_TYPES_NUMBER_H_

#include <dbix/types/type.h>

namespace dbix {

  class is;

  namespace types {

    class number : public type
      {
      private:
        number();
      public:
        number(const number&);
	~number();
	friend class dbix::is;
      public:
	void valid_value(const std::string&, dbix::value* = NULL);
	void valid_value(bool, dbix::value* = NULL);
	void valid_value(int, dbix::value* = NULL);
	void valid_value(double, dbix::value* = NULL);
      protected:
	int new_id();
      };
  }
}

#endif

