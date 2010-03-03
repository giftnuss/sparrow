

#include <dbix/table.h>

using namespace std;
using namespace dbix;

table::table(string n)
  : name_(n)
{}

table::~table()
{}

const string&
table::name() const
{
  return name_;
}

table&
table::has(column& c) throw (invalid_argument)
{
  map<string,column>::value_type* v =
    new map<string,column>::value_type(c.name(),c);

  pair<map<string,column>::iterator,bool> p = columns.insert(*v);
  if(!p.second) {
    throw invalid_argument(
      "Column name '" + c.name() + "' already known in table '" + name_ + "'.");
  }
  return *this;
}

bool
table::has_column(const string& n) const
{
  map<string,dbix::column>::const_iterator iter = columns.find(n);
  return iter != columns.end();
}

column&
table::get_column(const string& n) throw (invalid_argument)
{
  try {
    return columns.at(n);
  }
  catch(out_of_range& e) {
    throw invalid_argument("Unknown column name '" + n + "' in table '" + name_ + "'.");
  }
}






