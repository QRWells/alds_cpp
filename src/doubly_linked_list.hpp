// Doubly linked list implementation
// Multi-thread unsafe

#pragma once

#include <sstream>

namespace alds {
template <class T> struct Node {
public:
  Node(T data) : data_(data) {}

  void SetNext(Node<T> *next) { next_ = next; }
  void SetPrev(Node<T> *prev) { prev_ = prev; }

  auto GetNext() -> Node<T> * { return next_; }
  auto GetPrev() -> Node<T> * { return prev_; }

  auto GetData() -> T { return data_; }
  void SetData(T data) { data_ = data; }

private:
  alignas(sizeof(void *)) T data_;
  alignas(sizeof(void *)) Node<T> *next_{nullptr};
  alignas(sizeof(void *)) Node<T> *prev_{nullptr};
};

template <class T> class DoublyLinkedList {
public:
  DoublyLinkedList() = default;
  ~DoublyLinkedList() {
    auto current = head_;
    while (current) {
      auto next = current->GetNext();
      delete current;
      current = next;
    }
  }

  void PushBack(T const &data) {
    auto node = new Node<T>(data);
    if (!head_) {
      head_ = node;
      tail_ = node;
    } else {
      tail_->SetNext(node);
      node->SetPrev(tail_);
      tail_ = node;
    }
  }

  void PushFront(T const &data) {
    auto node = new Node<T>(data);
    if (!head_) {
      head_ = node;
      tail_ = node;
    } else {
      head_->SetPrev(node);
      node->SetNext(head_);
      head_ = node;
    }
  }

  void PopBack() {
    if (!head_) {
      return;
    }
    if (head_ == tail_) {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    } else {
      auto prev = tail_->GetPrev();
      delete tail_;
      tail_ = prev;
      tail_->SetNext(nullptr);
    }
  }

  void PopFront() {
    if (!head_) {
      return;
    }
    if (head_ == tail_) {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    } else {
      auto next = head_->GetNext();
      delete head_;
      head_ = next;
      head_->SetPrev(nullptr);
    }
  }

  void Clear() {
    auto current = head_;
    while (current) {
      auto next = current->GetNext();
      delete current;
      current = next;
    }
    head_ = nullptr;
    tail_ = nullptr;
  }

  auto GetHead() -> Node<T> * { return head_; }
  auto GetTail() -> Node<T> * { return tail_; }

  friend auto operator<<(std::ostream &os, DoublyLinkedList<T> const &list)
      -> std::ostream & {
    auto current = list.head_;
    std::stringstream ss;
    ss << "[";
    while (current) {
      ss << current->GetData();
      if (current->GetNext()) {
        ss << ", ";
      }
      current = current->GetNext();
    }
    ss << "]";
    return os << ss.str();
  }

  auto ToString() -> std::string {
    auto current = head_;
    std::stringstream ss;
    ss << "[";
    while (current) {
      ss << current->GetData();
      if (current->GetNext()) {
        ss << ", ";
      }
      current = current->GetNext();
    }
    ss << "]";
    return ss.str();
  }

private:
  Node<T> *head_{nullptr};
  Node<T> *tail_{nullptr};
};
} // namespace alds