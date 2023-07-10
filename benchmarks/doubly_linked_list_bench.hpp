#include <benchmark/benchmark.h>

#include "doubly_linked_list.hpp"

inline auto BenchDLLBack(benchmark::State& state) {
  auto list = DoublyLinkedList<int>{};
  for (auto _ : state){
    for (auto i = 0; i < state.range(0); ++i) {
      list.PushBack(i);
    }

    for (auto i = 0; i < state.range(0); ++i) {
      list.PopBack();
    }
  }
}

inline auto BenchDLLFront(benchmark::State& state) {
  auto list = DoublyLinkedList<int>{};
  for (auto _ : state){
    for (auto i = 0; i < state.range(0); ++i) {
      list.PushFront(i);
    }

    for (auto i = 0; i < state.range(0); ++i) {
      list.PopFront();
    }
  }
}

BENCHMARK(BenchDLLBack)->Range(8, 8<<10);
BENCHMARK(BenchDLLFront)->Range(8, 8<<10);