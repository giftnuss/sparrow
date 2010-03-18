
#ifndef _DBIX_TYPES_TEXT_H_
#define _DBIX_TYPES_TEXT_H_

#include <string>
#include <dbix/types/type.h>

namespace dbix {

  class is;

  namespace types {

    class text : public type
      {
      private:
        text();
      public:
        text(const text&);
	~text();
	friend class dbix::is;
	void valid_value(const std::string&, dbix::value* = NULL);
      protected:
	int new_id();
      };
  }
}

#endif

