
#pragma once

#include <type_traits>
#include <string>
#include <ntt/kv/syntax/any-of.hpp>

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

  template <typename T>
  concept ReqTokenValue = requires {
    AnyOf<T, std::string, std::wstring>();
  };
  
  class Token
  {

  };

} // namespace ntt::kv::syntax
