// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int begin;
    int end;
    int count;

 public:
    TPQueue() : begin(0), end(0), count(0) {
        arr = new T[size];
    }
    ~TPQueue() {
        delete[] arr;
    }
    void push(const T& item) {
        if (count < size) {
            if (count == 0) {
                arr[end++] = item;
                count++;
            } else {
                int i = end - 1;
                bool pr = false;
                while (i >= begin && item.prior > arr[i].prior) {
                    arr[i + 1] = arr[i];
                    i--;
                    pr = true;
                }
                if (pr) {
                    arr[i + 1] = item;
                    end++;
                } else {
                    arr[--begin] = item;
                }
                count++;
            }
            if (end == size) end = 0;
        }
    }
    T pop() {
        T item = arr[begin++];
        count--;
        if (begin == size) begin = 0;
        return item;
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
