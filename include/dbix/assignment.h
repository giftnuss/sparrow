

#ifndef _DBIX_ASSIGNMENT_H_
#define _DBIX_ASSIGNMENT_H_

#include <stdexcept>
#include <dbix/column.h>
#include <dbix/value.h>

namespace dbix {

  class record;

class assignment
{
 private:
  friend class column;
  void set_record(record* r) { rec = r; }
  void set_value(dbix::value* v) { val = v; }
  void set_type(dbix::types::type* t) { typ = t; }
 public:
  template <typename T>
    dbix::record& is(T) throw (std::invalid_argument);
 private:
  record* rec;
  dbix::types::type* typ;
  dbix::value* val;
};

template <typename T>
dbix::record&
  assignment::is(T v) throw (std::invalid_argument)
{
  typ->valid_value(v,val);
  return *rec;
}

}

/*
 

  const types::type& columntype = col.type();
  columntype.validate_value(values.at(pos),val);

  return *this;

*/

#endif

