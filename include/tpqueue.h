// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* arr; // массив с данными
    int begin, // начало очереди
        end; // конец очереди
    int count; // счетчик элементов
    
 public:
    TPQueue(): begin(0), end(0), count(0) { 
        arr = new T[size]; 
    }
    
    ~TPQueue() {
        delete[] arr; 
    }
    
    bool isEmpty() const {
        return count == 0; 
    }
    
    bool isFull() const {
        return count == size; 
    }
    
    void push(const T& item) {
        if (count < size) {
            int cur = end;
            while (cur != begin && item.prior > arr[(cur - 1 + size) % size].prior) {
                arr[cur] = arr[(cur - 1 + size) % size];
                cur = (cur - 1 + size) % size;
            }
            arr[cur] = item;
            end = (end + 1) % size;
            count++;
        } else
            throw "Queue is full!";
    }
    
    T pop() {
        if (count > 0) {
            T item = arr[begin];
            begin = (begin + 1) % size;
            count--;
            return item;
        } else
            throw "Queue is empty!";
    }
};

struct SYM {
  char ch;
  int prior;
};


#endif  // INCLUDE_TPQUEUE_H_
