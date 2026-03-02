#include <app/run.hpp>
#include <GreeterLib/GreeterLib.hpp>
#include <iostream>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

int run_app(int argc, char* argv[]) {
  // Create a logger that writes to "app_log.txt"
    spdlog::info(get_greeting()); 

  auto file_logger{
    spdlog::basic_logger_mt("app_logger", "app_log.txt")
  };
  spdlog::set_default_logger(file_logger);

  spdlog::info("App starting up");

  Greeter my_greeter;
  std::cout << my_greeter.greet();

  // Flush logs to ensure they're written
  spdlog::shutdown();

  return 0;
}