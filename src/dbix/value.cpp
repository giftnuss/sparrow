
#include <dbix/value.h>

using namespace std;
using namespace dbix;

value::value()
  : data(NULL)
{
}

value::value(const double& dbl)
{
  data = new double(dbl);
  destruction = &value::destroy_double;
}

value::value(const int& i)
{
  data = new int(i);
  destruction = &value::destroy_int;
}

value::value(const string& str)
{
  data = new string(str);
  destruction = &value::destroy_string;
}

value::~value()
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
  delete static_cast<int *>(data);
}

void
value::destroy_string()
{
  delete static_cast<string *>(data);
}

double&
value::to_double()
{
  return *(static_cast<double*>(data));
}

int&
value::to_int()
{
  return *(static_cast<int*>(data));
}

string&
value::to_string()
{
  return *(static_cast<string*>(data));
}


