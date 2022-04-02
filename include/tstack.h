// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename Type, int size>
class TStack {
 private:
  Type arr[100];
  int top;
 public:
  TStack() : top(-1) {}
  bool isEmpty() const {
    return top == -1;
  }
  bool isFull() const {
    return size == size - 1;
  }
  Type get() {
    return arr[top];
  }
  void pop() {
    if (top >= 0)
      top--;
    }
    void push(Type value) {
      if (top < size - 1)
        arr[++top] = value;
    }
};
#endif  // INCLUDE_TSTACK_H_
