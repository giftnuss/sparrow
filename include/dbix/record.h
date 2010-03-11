

#ifndef _DBIX_RECORD_H_
#define _DBIX_RECORD_H_

#include <string>
#include <vector>
#include <dbix/table.h>
#include <dbix/value.h>

namespace dbix {

class record
{
 private:
  friend class dbix::table;
  record(const dbix::table&);
 public:
  template <typename T>
    record& with(const std::string&, T);
 private:
  const dbix::table* tableptr;
  std::vector<dbix::value> values;
};


template <typename T> 
record&
  record::with(const std::string& key,T val)
{
  values.at(tableptr->column_pos(key)).is(val);
  return *this;
}

}

#endif

