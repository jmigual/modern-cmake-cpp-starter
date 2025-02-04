
#include <benchmark/benchmark.h>

#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <greeter/greeter.hpp>

#include "example.hpp"

static void GreeterBench(benchmark::State &state) {
    for (auto _ : state) {
        for (int i = 0; i < state.range(0); ++i) {
            Example::appGreeter("world");
        }
    }
}

static void GreeterBenchLib(benchmark::State &state) {
    for (auto _ : state) {
        for (int i = 0; i < state.range(0); ++i) {
            Greeter::greet("world");
        }
    }
}

constexpr const int kMinSize = 1024;
constexpr const int kMaxSize = 8 << 12;
constexpr const int kMultiplier = 8;

BENCHMARK(GreeterBench)->RangeMultiplier(kMultiplier)->Range(kMinSize, kMaxSize);
BENCHMARK(GreeterBenchLib)->RangeMultiplier(kMultiplier)->Range(kMinSize, kMaxSize);
BENCHMARK_MAIN();
