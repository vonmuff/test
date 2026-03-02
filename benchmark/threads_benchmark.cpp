#include <benchmark/benchmark.h>
#include <vector>
#include <mutex>

// --- 1. Общие данные ---
// Это структура, которую будут делить между собой все потоки
struct SharedEnvironment {
    std::vector<int> data;
    std::mutex mtx;
};

// Глобальный указатель на нашу среду
SharedEnvironment* shared_env = nullptr;


// --- 2. Функция Подготовки (Setup) ---
// Запускается строго 1 раз перед стартом всех потоков конфигурации
static void DoSetup(const benchmark::State& state) {
    shared_env = new SharedEnvironment();
    
    // state.range(0) доступен даже здесь!
    int size = state.range(0); 
    shared_env->data.resize(size, 0); // Создаем массив нужного размера
}


// --- 3. Функция Очистки (Teardown) ---
// Запускается строго 1 раз, когда все потоки закончили работу
static void DoTeardown(const benchmark::State& state) {
    delete shared_env;
    shared_env = nullptr;
}


// --- 4. Сам тест (выполняется параллельно в N потоках) ---
static void BM_ThreadSafeWrite(benchmark::State& state) {
    // Если мы попросили ->Threads(4), то фреймворк запустит 
    // ЭТУ функцию одновременно в 4-х разных системных потоках.

    for (auto _ : state) {
        // Блокируем мьютекс. Если другой поток уже внутри, 
        // текущий поток будет ждать (тратить время)
        std::lock_guard<std::mutex> lock(shared_env->mtx);
        
        // Симулируем полезную работу — изменяем первый элемент
        shared_env->data[0] += 1;
        
        // Заставляем компилятор честно записать данные
        benchmark::DoNotOptimize(shared_env->data[0]);
    }
}


// --- 5. Регистрация ---
BENCHMARK(BM_ThreadSafeWrite)
    ->Arg(100000)            // Размер массива (передастся в Setup)
    ->Threads(1)           // Сценарий 1: Работаем в 1 поток (без ожиданий)
    ->Threads(2)           // Сценарий 2: Работаем в 2 потока (начнутся столкновения)
    ->Threads(4)           // Сценарий 3: Работаем в 4 потока (жесткая конкуренция)
    ->Threads(8)           // Сценарий 4: Работаем в 8 потоков (еще хуже)
    ->Setup(DoSetup)       // Привязываем нашу подготовку
    ->Teardown(DoTeardown);// Привязываем нашу очистку

BENCHMARK_MAIN();