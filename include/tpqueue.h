// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
 private:
    T arr[size];
    int begin, end;
    int count;

 public:
    TPQueue() : begin(0), end(0), count(0) {}

    void push(const T& item) {
        if (count < size) {
            if (count == 0) {
                arr[end] = item;
                end = (end + 1) % size;
                count++;
            } else {
                int i = end - 1;
                if (i < 0) {
                    i = size - 1;
                }

                while (i != begin - 1) {
                    if (item.prior > arr[i].prior) {
                        arr[(i + 1) % size] = arr[i];
                        i--;

                        if (i < 0) {
                            i = size - 1;
                        }
                    } else {
                        break;
                    }
                }

                arr[(i + 1) % size] = item;
                end = (end + 1) % size;
                count++;
            }
        }
    }

    T pop() {
        if (count > 0) {
            T item = arr[begin];
            begin = (begin + 1) % size;
            count--;
            return item;
        }
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == size;
    }
};


#endif  // INCLUDE_TPQUEUE_H_
