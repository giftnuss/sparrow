
// has - eigenschaft
// with - wertzuweisung

#ifndef _ERM_H_
#define _ERM_H_

#include <dbix/types.h>
#include <dbix/table.h>
#include <dbix/record.h>

class erm {
 public:
  erm();
  dbix::table& entity() { return entities; };
  dbix::table& attribute() { return attributes; };
  dbix::table& relationship_role() { return relationship_roles; };
 private:
  dbix::type_container tc;
  dbix::table entities;
  dbix::table attributes;
  dbix::table relationship_roles;
};

#endif

