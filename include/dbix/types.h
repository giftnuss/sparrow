
#ifndef _DBIX_TYPES_H_
#define _DBIX_TYPES_H_

#include <string>
#include <map>
#include <sparrow/coat/uptr.h>
#include <dbix/types/text.h>

namespace dbix {

  typedef sparrow::coat::uptr<dbix::types::text> text_ptr;

class is
{
 public:
  static dbix::types::text& text();
};

class type_container
{
 public:
  type_container();
  virtual ~type_container();
  dbix::types::text& text(const std::string& s = "default");
  dbix::types::text& integer(const std::string& s = "integer");
  dbix::types::text& boolean(const std::string& s = "boolean");
 private:
  std::map<std::string,text_ptr> text_variants;
};

}

#endif


