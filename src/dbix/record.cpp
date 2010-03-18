

#include <dbix/record.h>
#include <dbix/table.h>
#include <dbix/assignment.h>

using namespace std;
using namespace dbix;

record::record(const dbix::table& t)
  : tableptr(&t)
  , values()
{
  int cc = tableptr->column_count();
  values.reserve(cc);
  for(int i = 0; i < cc; ++i) {
    values.push_back(*(new value()));
  }
}

assignment&
record::with(const string& key)
{
  int pos = tableptr->column_pos(key);
  column& col = tableptr->get_column(pos);
  return col.assign_to(this);
}

