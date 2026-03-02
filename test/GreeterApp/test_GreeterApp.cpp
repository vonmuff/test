#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "app/run.hpp"
#include <fstream>
#include <string>

class AppLogTest : public testing::Test {
protected:
  const std::string log_filename{"app_log.txt"};

   void TearDown() override {
    // Очистить файл журнала после каждого теста
    std::remove(log_filename.c_str());
  }
};

TEST_F(AppLogTest, LogsStartupMessageToFile) {
  run_app(0, nullptr);

  std::ifstream log_file(log_filename);
  ASSERT_TRUE(log_file.is_open());

  std::string line;
  std::getline(log_file, line);

  // Use a matcher to check the format
  EXPECT_THAT(line, testing::HasSubstr(
    "App starting up"
  ));
}

// TEST_F(AppLogTest, AnotherTest) {
//   std::ifstream log_file(log_filename);
  
//   // ...don't create a log file
  
//   ASSERT_TRUE(log_file.is_open());
// }