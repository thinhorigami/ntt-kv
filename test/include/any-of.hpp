
#include <ntt/kv/syntax/any-of.hpp>

namespace ntt::kv::test
{
  template <typename T, typename ... Ts> 
  auto AnyOf() -> bool
  {
    return syntax::AnyOf<T, Ts ...>();
  }
} // namespace ntt::kv::test
