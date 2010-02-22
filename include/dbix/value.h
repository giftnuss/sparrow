

#ifndef _DBIX_VALUE_H_
#define _DBIX_VALUE_H_

#include <string>

namespace dbix {

class value
{
 private:
  value();
 public:
  value(const double&);
  value(const int&);
  value(const std::string&);
  virtual ~value();
 public:
  double& to_double();
  int& to_int();
  std::string& to_string();
 private:
  void* data;
  void (value::*destruction)();
 private:
  void destroy_double();
  void destroy_int();
  void destroy_string();
};

}

#endif
