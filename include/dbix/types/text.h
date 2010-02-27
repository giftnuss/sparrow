
#ifndef _DBIX_TYPES_TEXT_H_
#define _DBIX_TYPES_TEXT_H_

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
      protected:
	int new_id();
      };
  }
}

#endif

