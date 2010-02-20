
#include <sparrow/tap_suite.h>

using namespace sparrow;

tap_suite::~tap_suite()
{

}

void
tap_suite::ok(bool b, const std::string& s)
{
  std::cout << (b ? "ok" : "not ok");
  if(s.length()) {
    std::cout << " -- " << s;
  }
  std::cout << std::endl;
}
