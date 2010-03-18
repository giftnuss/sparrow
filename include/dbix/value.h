

#ifndef _DBIX_VALUE_H_
#define _DBIX_VALUE_H_

#include <string>

namespace dbix {

class value
{
 public:
  value();
  explicit value(const bool&);
  explicit value(const double&);
  explicit value(const int&);
  explicit value(const long int&);
  value(const std::string&);
  virtual ~value();
 public:
  value& is(const bool&);
  value& is(const double&);
  value& is(const long int&);
  value& is(const std::string&);
 public:
  double& to_double();
  int& to_int();
  std::string& to_string();
  bool is_null() const;
 private:
  void* data;
  void (value::*destruction)();
 private:
  void destroy();
  void destroy_double();
  void destroy_int();
  void destroy_string();
  void destroy_bool();
};

}

#endif
