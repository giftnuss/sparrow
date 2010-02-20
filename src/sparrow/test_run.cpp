
#include <sparrow/tap_suite.h>
#include <sparrow/test_run.h>

using namespace sparrow;

test_run::test_run(tap_suite *s)
   : suite(s)
{
   suite->init();
}

test_run::~test_run()
{
   delete suite;
}

void test_run::plan()
{
   std::cout << std::endl << "1.." << suite->test_count() << std::endl;      
}

int test_run::run()
{
   suite->test_run();
   return 0;
}

