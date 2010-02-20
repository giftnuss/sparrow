
#ifndef _SPARROW_TAP_MORE_1_
#define _SPARROW_TAP_MORE_1_

#include <sparrow/tap_base.h>

namespace sparrow {

template <typename C,typename A>
class tap_more_1  : public tap_base< tap_more_1<C,A> >
{
  public:
  void init();
  void simple_object_test();
  using tap_suite::ok;
};

}

#endif

