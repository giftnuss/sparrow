
#include <utility>
#include <dbix/types.h>

using namespace std;
using namespace dbix;

dbix::types::text&
is::text()
{
  static dbix::types::text txt;
  return txt;
}

type_container::type_container()
{

}

type_container::~type_container()
{

}

dbix::types::text&
type_container::text(const string& key)
{
  if(key == "default") {
    return is::text();
  }
  map<string,text_ptr>::iterator
    iter = text_variants.find(key);

  if(iter == text_variants.end()) {
    pair<map<string,text_ptr>::iterator,bool> p;
    // destruction of v should not destroy object
    text_ptr* tp = new text_ptr(new dbix::types::text(is::text()));
    map<string,text_ptr>::value_type* v =
      new map<string,text_ptr>::value_type(key,*tp);
    p = text_variants.insert(*v);
    return *((*(p.first)).second);   
  }
  return *((*iter).second);
}


