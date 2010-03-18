
#ifndef _DBIX_TYPES_INTEGER_H_
#define _DBIX_TYPES_INTEGER_H_

#include <string>
#include <dbix/value.h>
#include <dbix/types/type.h>

namespace dbix {

  class is;

  namespace types {

    class integer : public type
      {
      private:
        integer();
      public:
        integer(const integer&);
	~integer();
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

