
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

dbix::types::integer&
is::integer()
{
  static dbix::types::integer val;
  return val;
}

dbix::types::boolean&
is::boolean()
{
  static dbix::types::boolean val;
  return val;
}

dbix::types::number&
is::number()
{
  static dbix::types::number val;
  return val;
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
  map<string,text_ptr>::iterator iter = text_variants.find(key);

  if(iter == text_variants.end()) {
    pair<map<string,text_ptr>::iterator,bool> p;
    text_ptr* tp = new text_ptr(new dbix::types::text(is::text()));
    map<string,text_ptr>::value_type* v =
      new map<string,text_ptr>::value_type(key,*tp);
    p = text_variants.insert(*v);
    return *((*(p.first)).second);   
  }
  return *((*iter).second);
}

dbix::types::integer&
type_container::integer(const string& key)
{
  if(key == "default") {
    return is::integer();
  }
  map<string,integer_ptr>::iterator iter = integer_variants.find(key);

  if(iter == integer_variants.end()) {
    pair<map<string,integer_ptr>::iterator,bool> p;
    integer_ptr* tp = new integer_ptr(new dbix::types::integer(is::integer()));
    map<string,integer_ptr>::value_type* v =
      new map<string,integer_ptr>::value_type(key,*tp);
    p = integer_variants.insert(*v);
    return *((*(p.first)).second);   
  }
  return *((*iter).second);
}
dbix::types::boolean&
type_container::boolean(const string& key)
{
  if(key == "default") {
    return is::boolean();
  }
  map<string,boolean_ptr>::iterator iter = boolean_variants.find(key);

  if(iter == boolean_variants.end()) {
    pair<map<string,boolean_ptr>::iterator,bool> p;
    boolean_ptr* tp = new boolean_ptr(new dbix::types::boolean(is::boolean()));
    map<string,boolean_ptr>::value_type* v =
      new map<string,boolean_ptr>::value_type(key,*tp);
    p = boolean_variants.insert(*v);
    return *((*(p.first)).second);   
  }
  return *((*iter).second);
}

dbix::types::number&
type_container::number(const string& key)
{
  if(key == "default") {
    return is::number();
  }
  map<string,number_ptr>::iterator iter = number_variants.find(key);

  if(iter == number_variants.end()) {
    pair<map<string,number_ptr>::iterator,bool> p;
    number_ptr* tp = new number_ptr(new dbix::types::number(is::number()));
    map<string,number_ptr>::value_type* v =
      new map<string,number_ptr>::value_type(key,*tp);
    p = number_variants.insert(*v);
    return *((*(p.first)).second);   
  }
  return *((*iter).second);
}

