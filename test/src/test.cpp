
#include <catch.hpp>

#include <any-of.hpp>
#include <config.hpp>

TEST_CASE("ntt-kv tes") {
  SECTION("any of") {
    using namespace ntt::kv::test;
    REQUIRE((AnyOf<int, int, float, char>()));
    REQUIRE(Not(AnyOf<int, float, char, void>()));
    REQUIRE(Not(AnyOf<int, char>()));
    REQUIRE((AnyOf<int, int>()));
    REQUIRE(Not(AnyOf<int, char>()));
    REQUIRE(Not(AnyOf<int>()));
  }
}