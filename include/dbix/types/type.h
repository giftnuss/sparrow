
#ifndef _DBIX_TYPES_TYPE_H_
#define _DBIX_TYPES_TYPE_H_

#include <dbix/value.h>

namespace dbix {
  namespace types {

    class type
    {
     public:
      type();
      virtual ~type() = 0;
      int id() { return identity; }
     public:
      virtual void valid_value(const std::string&, dbix::value* = NULL) = 0;
     protected:
      int identity;
    };

  }
}

#endif
