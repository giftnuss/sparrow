
#ifndef _DBIX_TYPES_TYPE_H_
#define _DBIX_TYPES_TYPE_H_

namespace dbix {
  namespace types {

class type
{
 public:
  type();
  virtual ~type() = 0;
  int id() { return identity; }
 protected:
  int identity; 
};

  }
}

#endif
