#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "doubly_linked_list.hpp"

using namespace alds;

TEST_CASE("double linked list") {
  auto list = DoublyLinkedList<int>{};

  SUBCASE("push back") {
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);

    CHECK(list.ToString() == "[1, 2, 3]");
  }

  SUBCASE("push front") {
    list.PushFront(1);
    list.PushFront(2);
    list.PushFront(3);

    CHECK(list.ToString() == "[3, 2, 1]");
  }
}