#include "app/run.hpp"
#include <vector>

//void f(int); 
//void f(char*);

int main(int argc, char* argv[]) {
 // f(NULL); // calls f(int), not f(char*)
 
  return run_app(argc, argv);
}