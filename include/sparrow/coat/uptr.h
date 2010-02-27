

#ifndef _SPARROW_COAT_UPTR_
#define _SPARROW_COAT_UPTR_

#include <stdexcept>

namespace sparrow {
  namespace coat {

template<typename T>
class uptr
  {
  public:
    uptr();
    uptr(T*);
    uptr(const uptr<T>&);
    ~uptr();
    T* operator->() const;
    T& operator*() const;
    operator bool() const;
    void operator=(T*);
  private:
    T* ptr;
    int refcount;
  };

template<typename T>
  inline uptr<T>::uptr()
  : ptr(NULL)
  , refcount(0)
  {}

template<typename T>
  inline uptr<T>::uptr(T* p)
  : ptr(p)
  , refcount(1)
  {}

template<typename T>
  inline uptr<T>::uptr(const uptr<T>& c)
  : ptr(c.ptr)
  {
    //*(const_cast<T**>(&ptr)) = NULL;
    int* rptr = const_cast<int*>(&refcount);
    ++ *rptr;
  }

template<typename T>
  inline uptr<T>::~uptr()
  {
    --refcount;
    if(refcount == 0) delete ptr;
  }

template<typename T>
  inline T* uptr<T>::operator->() const
  {
    if(ptr) return ptr;
    throw std::runtime_error("uptr internal pointer is 0 in operator ->");
  }

template<typename T>
  inline T& uptr<T>::operator*() const
  {
    if(ptr) return *ptr;
    throw std::runtime_error("uptr internal pointer is 0 in operator *");
  }

template<typename T>
  inline uptr<T>::operator bool() const
  {
    return bool(ptr);
  }

template<typename T>
  inline void uptr<T>::operator=(T* p)
  {
    if(refcount) {
      throw std::runtime_error("operator = not allowed when valid pointer exists.");
    }
    ++refcount;
    ptr = p;
  }

  }
}

#endif

