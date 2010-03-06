

#ifndef _SPARROW_COAT_SPTR_H_
#define _SPARROW_COaT_SPTR_H_

namespace sparrow {
  namespace coat {

template<typename T>
class sptr
  {
  public:
    sptr(T *p) : ptr(p) { }
    sptr(const sptr<T> &c)
      : ptr(c.ptr)
      {
        sptr<T>* cc = const_cast<sptr<T>*>(&c);
        cc->ptr = NULL;
      }
    ~sptr() { if(ptr) delete ptr; };
    T* operator->() const
      {
        if(ptr) return ptr;
        throw std::runtime_error("sptr internal pointer is 0 in operator ->");
      }
    T& operator*() const
      {
        if(ptr) return *ptr;
        throw std::runtime_error("sptr internal pointer is 0 in operator *");
      }
    operator bool() const
      {
	return bool(ptr);
      }
  private:
    T* ptr;
  };

  }
}

#endif
