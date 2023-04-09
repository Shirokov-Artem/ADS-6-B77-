// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T arr[size];
    int begin,
        end;
    int count;

    int next(int current) {
        ++current;
        if (current == size)
            current = 0;
        return current;
    }

    int prev(int current) {
        --current;
        if (current == -1)
            current = size - 1;
        return current;
    }

    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

 public:
    TPQueue() :
        begin(0), end(0), count(0) {
    }

    void push(const T& item) {
        if (count == size)
            throw std::string("Queue overflow!");
        if (count == 0) {
            arr[end] = item;
            count++;
            return;
        }
        int cur = prev(end);
        while (arr[cur].prior >= item.prior) {
            arr[next(cur)] = arr[cur];
            if (cur == begin) {
                begin = next(begin);
                break;
            }
            cur = prev(cur);
        }
        arr[next(cur)] = item;
        end = next(end);
        count++;
    }

    T pop() {
        if (count == 0)
            throw std::string("Queue is empty!");
        T item = arr[begin];
        count--;
        begin = next(begin);
        return item;
    }

    T get() const {
        if (count == 0)
            throw std::string("Queue is empty!");
        return arr[begin];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == size;
    }
};

struct SYM {
  char ch;
  int prior;
};


#endif  // INCLUDE_TPQUEUE_H_
