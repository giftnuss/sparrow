
// has - eigenschaft
// with - wertzuweisung

#ifndef _ERM_H_
#define _ERM_H_

#include <dbix/types.h>
#include <dbix/table.h>

class erm {
 public:
  erm();
  dbix::table& entity();
  dbix::table& attribute();
  dbix::table& relationship_role();
 private:
  dbix::type_container tc;
  dbix::table entities;
  dbix::table attributes;
  dbix::table relationship_roles;
};

#endif

