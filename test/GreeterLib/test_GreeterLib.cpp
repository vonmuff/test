#include <gtest/gtest.h>
#include "GreeterLib/GreeterLib.hpp"

TEST(GreeterAPITests, GetGreetingReturnsCorrectString) {
  Greeter my_greeter;
  const std::string expected{
    "Hello from the modular greeter library"
  };
  
  EXPECT_EQ(my_greeter.greet(), expected);
}