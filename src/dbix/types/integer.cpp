
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <string>
#include <stdexcept>
#include <dbix/value.h>
#include <dbix/types/integer.h>

using namespace std;
using namespace dbix;
using namespace dbix::types;

integer::integer()
  : type()
{

}

integer::integer(const integer& o)
{
  identity = new_id();
}

integer::~integer()
{

}

int
integer::new_id()
{
  static int id = 0;
  return ++id;
}

void
integer::valid_value(const string& s, value* v)
{
  const char* nptr = s.c_str();
  char** endptr = NULL;
  long int i = strtol(nptr, endptr, 0);
  if(i) {
    if(errno == ERANGE) {
      if(i == LONG_MIN) {
	throw new invalid_argument(
          "Integer value '" + s + "' is less than allowed minimum  value.");
      }
      if(i == LONG_MAX) {
	throw new invalid_argument(
          "Integer value '" + s + "' is bigger than allowed max value.");
      }
    }
  }
  else if(nptr == *endptr) {
    throw new invalid_argument("String contains no valid integer.");
  }
  if(v) v->is(i);
}
