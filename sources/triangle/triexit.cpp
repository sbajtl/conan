#include <stdexcept>

#ifdef __cplusplus
extern "C"
{
#endif

void triexit(int code)
{
    throw std::runtime_error("Internal error in triangle");
}

#ifdef __cplusplus
}
#endif
