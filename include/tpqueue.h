// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>
#include <stdexcept>

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int begin,
        end,
        count;

 public:
    TPQueue() :
        begin(0), end(0), count(0) {
        arr = new T[size + 1];
    }

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& item) {
        if (count >= size) {
            throw std::logic_error("Queue is full");
        } else if (count == 0) {
            arr[end] = item;
        } else {
            int i = end - 1;
            if (i < 0) i = size - 1;
            while (i >= begin && item.prior > arr[i].prior) {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = item;
            end++;
            if (end > size)
                end -= size + 1;
        }
        count++;
    }

    T pop() {
        if (count == 0) {
            throw std::logic_error("Queue is empty");
        }
        T item = arr[begin++];
        count--;
        if (begin > size)
            begin -= size + 1;
        return item;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == size;
    }
};



#endif  // INCLUDE_TPQUEUE_H_
