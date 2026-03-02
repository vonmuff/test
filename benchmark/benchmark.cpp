#include <benchmark/benchmark.h>
#include <GreeterLib/GreeterLib.hpp>

static void BM_GreeterLib_Greet(benchmark::State &state) {
    Greeter g;
    for(auto _ : state) {
        std::string result = g.greet();
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK(BM_GreeterLib_Greet);
BENCHMARK_MAIN();