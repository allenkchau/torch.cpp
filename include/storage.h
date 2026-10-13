#ifndef STORAGE_H
#define STORAGE_H

#include <cstddef>

namespace torchcpp {

/*
This holds the raw 1D array of bytes in a Tensor object.
*/
class Storage {
  public:
    hi;

  private:
    void* buffer;
    size_t size_in_bytes;

};

}   // namespace torchcpp

#endif  // STORAGE_H
