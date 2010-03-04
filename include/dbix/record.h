

#ifndef _DBIX_RECORD_H_
#define _DBIX_RECORD_H_

#include <string>

namespace dbix {

  class table;

class record
{
 private:
  friend class dbix::table;
  record(const dbix::table&);
 public:
  record& with(const std::string&,int);
  record& with(const std::string&,double);
  record& with(const std::string&,std::string);
 private:
  const dbix::table* tableptr;
};

}

#endif

