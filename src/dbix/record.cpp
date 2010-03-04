

#include <dbix/record.h>

using namespace std;
using namespace dbix;

record::record(const dbix::table& t)
  : tableptr(&t)
{}

record&
record::with(const string& key, int val)
{

  return *this;
}

record&
record::with(const string& key, double val)
{

  return *this;
}

record&
record::with(const string& key, string val)
{

  return *this;
}

