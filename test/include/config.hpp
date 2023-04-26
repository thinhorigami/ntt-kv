
#pragma once

#include <type_traits>
#include <concepts>

namespace ntt::kv::test
{
  template <typename T> requires std::is_convertible_v<T, bool>
  auto Not(T _value) -> bool 
  {
    return {!_value};
  }
} // namespace ntt::kv::test
