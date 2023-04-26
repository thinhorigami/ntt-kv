
#pragma once

namespace ntt::kv::syntax
{
  
  template <bool _value>
  struct Constbool
  {
    static inline constexpr bool Value = _value;
  };

  template <typename ... Ts>
  struct TAnyOf
  {};

  template <typename T, typename TMatch, typename ... Ts>
  struct TAnyOf<T, TMatch, Ts ...> : Constbool<std::is_same_v<T, TMatch>>
  {
    
  };

  template <typename T>
  struct TAnyOf<T> : Constbool<false>
  {
    
  };
  
  template <typename T, typename ... Ts>
  static inline constexpr bool any_of = TAnyOf<T, Ts ...>::Value;

  template <typename T, typename ... Ts>
  auto AnyOf() -> bool
  {
    if constexpr (any_of<T, Ts ...>) {
      return true;
    }
    return any_of<T, Ts ...>;
  }
} // namespace ntt::kv::syntax
