
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
      protected:
	int new_id();
      };
  }
}

#endif

