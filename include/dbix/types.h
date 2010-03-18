
#ifndef _DBIX_TYPES_H_
#define _DBIX_TYPES_H_

#include <string>
#include <map>
#include <sparrow/coat/uptr.h>
#include <dbix/types/text.h>
#include <dbix/types/integer.h>
#include <dbix/types/number.h>
#include <dbix/types/boolean.h>

namespace dbix {

class is
{
 public:
  static dbix::types::text& text();
  static dbix::types::integer& integer();
  static dbix::types::number& number();
  static dbix::types::boolean& boolean();
};

class type_container
{
  typedef sparrow::coat::uptr<dbix::types::text> text_ptr;
  typedef sparrow::coat::uptr<dbix::types::integer> integer_ptr;
  typedef sparrow::coat::uptr<dbix::types::number> number_ptr;
  typedef sparrow::coat::uptr<dbix::types::boolean> boolean_ptr;

 public:
  type_container();
  virtual ~type_container();
  dbix::types::text& text(const std::string& s = "default");
  dbix::types::integer& integer(const std::string& s = "default");
  dbix::types::number& number(const std::string& s = "default");
  dbix::types::boolean& boolean(const std::string& s = "default");
 private:
  std::map<std::string,text_ptr> text_variants;
  std::map<std::string,integer_ptr> integer_variants;
  std::map<std::string,number_ptr> number_variants;
  std::map<std::string,boolean_ptr> boolean_variants;
};

}

#endif


