
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <string>
#include <dbix/value.h>
#include <dbix/types/number.h>

using namespace std;
using namespace dbix;
using namespace dbix::types;

number::number()
  : type()
{

}

number::number(const number& o)
{
  identity = new_id();
}

number::~number()
{

}

int
number::new_id()
{
  static int id = 0;
  return ++id;
}


void
number::valid_value(const string& s, value* v)
{
  const char* nptr = s.c_str();
  char** endptr = NULL;
  long int i = strtol(nptr, endptr, 0);
  if(i) {
    if(errno == ERANGE) {
      if(i == -HUGE_VAL) {
	throw new invalid_argument(
          "Number value '" + s + "' is less than allowed minimum  value.");
      }
      if(i == HUGE_VAL) {
	throw new invalid_argument(
          "Number value '" + s + "' is bigger than allowed max value.");
      }
    }
  }
  else if(nptr == *endptr) {
    throw new invalid_argument("String contains no valid number.");
  }
  if(v) v->is(i);
}


