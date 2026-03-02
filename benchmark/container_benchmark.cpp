#include <benchmark/benchmark.h>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

// --- 1. Тестируем std::vector ---
static void BM_VectorFind(benchmark::State& state) {
    int size = state.range(0); // Получаем текущий размер (N)
    
    // Подготовка данных (не входит в замер времени)
    std::vector<int> v(size);
    std::iota(v.begin(), v.end(), 0); // Заполняем числами: 0, 1, 2, ...
    int target = size - 1;            // Ищем самый последний элемент

    // Цикл измерения
    for (auto _ : state) {
        auto it = std::find(v.begin(), v.end(), target);
        benchmark::DoNotOptimize(it); // Не даем компилятору удалить поиск
    }
    
    // Сообщаем библиотеке, чему равно N для расчета сложности
    state.SetComplexityN(state.range(0));
    state.SetBytesProcessed(
      static_cast<int64_t>(state.iterations()) * state.range(0)
  );
}
// Регистрируем: от 1024 до 65536 элементов, ожидаем сложность O(N)
BENCHMARK(BM_VectorFind)->RangeMultiplier(2)->Range(1<<10, 1<<16)->Complexity(benchmark::oN);


// --- 2. Тестируем std::list ---
static void BM_ListFind(benchmark::State& state) {
    int size = state.range(0);
    
    // Подготовка данных
    std::list<int> l(size);
    std::iota(l.begin(), l.end(), 0);
    int target = size - 1;

    // Цикл измерения
    for (auto _ : state) {
        auto it = std::find(l.begin(), l.end(), target);
        benchmark::DoNotOptimize(it);
    }
    
    state.SetComplexityN(state.range(0));
    state.SetBytesProcessed(
      static_cast<int64_t>(state.iterations()) * state.range(0)
  );
}
BENCHMARK(BM_ListFind)->RangeMultiplier(2)->Range(1<<10, 1<<16)->Complexity(benchmark::oN);

// Точка входа
BENCHMARK_MAIN();