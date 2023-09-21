#ifndef QUEUE_HPP
#define QUEUE_HPP

// Circular Queue
// By: Lucas Correia de Araujo
//
// Exercice 12 from Oriented Object Programming C++ course by UFPR
//
// C++ implementation of a circular queue. 
// The queue has a maximum size of MAX_QUEUE. The default value is 10. 
// The queue is implemented using a static array and is circular, so 
// the first element is not always in the position 0. 
// The tam variable stores the number of elements in the queue and the 
// first and last variables store the index of the first and last element
// in the queue, respectively. 
//
// The queue has the following methods:
//  - enqueue: inserts an element in the queue. Returns true if the element was
//             inserted and false otherwise.
//  - dequeue: removes an element from the queue. Returns true if the element was
//             removed and false otherwise.
//  - isEmpty: returns true if the queue is empty and false otherwise.
//  - isFull: returns true if the queue is full and false otherwise.
//  - print: prints the queue.

#include <unistd.h>
#include <iostream>

template <typename T = int, ssize_t MAX_QUEUE = 10>
class Queue {
   public:
    Queue() : tam{-1}, first{0}, last{-1} {
        static_assert(
            MAX_QUEUE >= 1,
            "Compilation Error. Queue size should be greater than zero");
    }
    ~Queue() {}

    bool enqueue(const T value) {
        if (this->isFull()) return false;
        ssize_t index = this->last + 1;
        if (index >= MAX_QUEUE) index = 0;
        this->queue[index] = value;
        this->tam++;
        this->last = index;
        return true;
    }

    bool dequeue(T* const ret) {
        if (!this->isEmpty()) {
            *ret = this->queue[this->first];
            this->tam--;
            this->first++;
            if (this->first >= MAX_QUEUE) this->first = 0;
            return true;
        }
        return false;
    }

    bool isEmpty() const {
        if (this->tam < 0) return true;
        return false;
    }

    bool isFull() const {
        if (this->tam >= MAX_QUEUE - 1) return true;
        return false;
    }

    void print() const {
        std::cout << "Queue: ";
        if (this->isEmpty()) {
            std::cout << "Empty\n";
            return;
        }
        
        if (this->first <= this->last) { // No wrap around
            for (int i = this->first; i <= this->last; ++i) {
                std::cout << this->queue[i] << " ";
            }
        } else { // Wrap around
            for (int i = this->first; i < MAX_QUEUE; ++i) {
                std::cout << this->queue[i] << " ";
            }
            for (int i = 0; i <= this->last; ++i) {
                std::cout << this->queue[i] << " ";
            }
        }
        std::cout << "\n";
    }

   private:
    T queue[MAX_QUEUE];
    ssize_t tam, first, last;
};

#endif
