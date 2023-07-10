#include <iostream>

#include "doubly_linked_list.hpp"

using namespace std;
using namespace alds;

auto main() -> int {
  DoublyLinkedList<int> list;

  list.PushBack(1);
  list.PushBack(2);
  list.PushBack(3);

  cout << list << endl;
}