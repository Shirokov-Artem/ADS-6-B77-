// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <cstring>
#include <stdexcept>

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int begin, end, count;
    int next(int current) {
        return (current + 1) % size;
    }

    int prev(int current) {
        return (current - 1 + size) % size;
    }

 public:
    TPQueue(): begin(0), end(0), count(0), arr(new T[size]) {}

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& item) {
        if (count == size) {
            throw std::out_of_range("Queue is full");
        }

        if (count == 0) {
            arr[begin] = item;
            count++;
            return;
        }

        int i = end;
        while (i != begin && item.prior > arr[prev(i)].prior) {
            arr[i] = arr[prev(i)];
            i = prev(i);
        }

        arr[i] = item;
        end = next(end);
        count++;
    }

    T pop() {
        if (count == 0) {
            throw std::out_of_range("Queue is empty");
        }

        T item = arr[begin];
        begin = next(begin);
        count--;

        return item;
    }
};


#endif  // INCLUDE_TPQUEUE_H_
