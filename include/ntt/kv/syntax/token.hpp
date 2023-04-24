
#pragma once

#include <type_traits>
#include <string>

namespace ntt::kv::syntax
{
  enum class TokenType
  {
    NONE,
    EQUAL, // =
    STRING, // "
    DOT, // .
    COMMA, // ,
    TRUE, // true
    FALSE, ///false
    NUMBER, // 123 ...
  };

  template <typename T, typename TMatcxh, typename ... Ts>
  struct TAnyOf
  {
    /* ddo nothings */
    static inline constexpr bool Value = TAnyOf<TMatcxh, Ts ...>:: Value;
  };
  
  template <typename T, typename ... Ts>
  struct TAnyOf<T, T, Ts ...>
  {
    static inline constexpr bool Value = true;
  };

  template <typename T, typename TMatch>
  struct TAnyOf<T, TMatch>
  {
    static inline constexpr bool Value =false;
  };
  

  template <typename T>
  concept ReqTokenValue = requires {
    TAnyOf<T, std::string, std::wstring>::Value;
  };
  
  class Token
  {

  };

} // namespace ntt::kv::syntax
