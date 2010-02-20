
#include <sparrow/tap_more_1.h>

using namespace sparrow;

template <typename C,typename A>
void tap_more_1<C,A>::init()
{
  add(1,&tap_more_1<C,A>::simple_object_test);
}

template <typename C,typename A>
void tap_more_1<C,A>::simple_object_test()
{
  std::string msg = "object creation with empty argument";
  A a;
  try {
    C c(a);
    (*this).ok(true,msg);
  }
  catch(...) {
    ok(false,msg);
  }
}

