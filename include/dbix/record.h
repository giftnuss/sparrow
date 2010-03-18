

#ifndef _DBIX_RECORD_H_
#define _DBIX_RECORD_H_

#include <string>
#include <vector>
#include <dbix/column.h>
#include <dbix/table.h>
#include <dbix/value.h>

namespace dbix {

class record
{
 private:
  friend class dbix::table;
  record(const dbix::table&);
 public:
  dbix::assignment& with(const std::string&);
 private:
  const dbix::table* tableptr;
  std::vector<dbix::value> values;
};

}

#endif

