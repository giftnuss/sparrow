
#include <dbix/value.h>

using namespace std;
using namespace dbix;

value::value()
  : data(NULL)
{
}

value::value(const bool& b)
{
  data = new bool(b);
  destruction = &value::destroy_bool;
}

value::value(const double& dbl)
{
  data = new double(dbl);
  destruction = &value::destroy_double;
}

value::value(const int& i)
{
  data = new long int(i);
  destruction = &value::destroy_int;
}

value::value(const long int& i)
{
  data = new long int(i);
  destruction = &value::destroy_int;
}

value::value(const char* str)
{
  data = new string(str);
  destruction = &value::destroy_string;
}

value::value(const string& str)
{
  data = new string(str);
  destruction = &value::destroy_string;
}

value::~value()
{
  destroy();
}

inline void
value::destroy()
{
  if(destruction) {
    (this->*destruction)();
  }
}

void
value::destroy_double()
{
  delete static_cast<double *>(data);
}

void
value::destroy_int()
{
  delete static_cast<long int *>(data);
}

void
value::destroy_string()
{
  delete static_cast<string *>(data);
}

void
value::destroy_bool()
{
  delete static_cast<bool *>(data);
}

value&
value::is(const bool& v)
{
  destroy();
  data = new bool(v);
  destruction = &value::destroy_bool;
  return *this;
}

value&
value::is(const long int& v)
{
  destroy();
  data = new long int(v);
  destruction = &value::destroy_int;
  return *this;
}

value&
value::is(const double& v)
{
  destroy();  
  data = new double(v);
  destruction = &value::destroy_double;
  return *this;
}

value&
value::is(const string& v)
{
  destroy();  
  data = new string(v);
  destruction = &value::destroy_string;
  return *this;
}

double&
value::to_double()
{
  return *(static_cast<double*>(data));
}

long int&
value::to_int()
{
  return *(static_cast<long int*>(data));
}

string&
value::to_string()
{
  return *(static_cast<string*>(data));
}

bool&
value::to_bool()
{
  return *(static_cast<bool*>(data));
}

bool
value::is_null() const
{
  return bool(data);
}

