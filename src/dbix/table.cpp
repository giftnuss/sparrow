
#include <dbix/table.h>
#include <dbix/record.h>

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
  if(has_column(c.name())) {
    throw invalid_argument(
      "Column name '" + c.name() + "' already known in table '" + name_ + "'.");
  }
  column_type cc(&c);
  columns.push_back(cc);
  map<string,int>::value_type* v =
    new map<string,int>::value_type(c.name(),columns.size()-1);

  pair<map<string,int>::iterator,bool> p = columnmap.insert(*v);
  return *this;
}

bool
table::has_column(const string& n) const
{
  map<string,int>::const_iterator iter = columnmap.find(n);
  return iter != columnmap.end();
}

column&
table::get_column(const string& n) throw (invalid_argument)
{
  try {
    return *(columns.at(columnmap.at(n)));
  }
  catch(out_of_range& e) {
    throw invalid_argument("Unknown column name '" + n + "' in table '" + name_ + "'.");
  }
}

column&
table::get_column(vector<column_type>::size_type s) throw (out_of_range)
{
  return *(columns.at(s));
}

column&
table::get_column(vector<column_type>::size_type s) const throw (out_of_range)
{
  return *(columns.at(s));
}

int
table::column_pos(const string& n) const throw (invalid_argument)
{
  try {
    return columnmap.at(n);
  }
  catch(out_of_range& e) {
    throw invalid_argument("Unknown column name '" + n + "' in table '" + name_ + "'.");
  }
}

vector<column_type>::size_type
table::column_count() const
{
  return columns.size();
}

record&
table::row()
{
  return *(new record(*this));
}

table&
table::insert(record& r)
{

  return *this;
}


