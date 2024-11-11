#ifndef HW2_IMPL_H
#define HW2_IMPL_H

#include "hw2.h"

// Constructor
template <typename T>
Heap<T>::Heap(bool isMinHeap) : minHeap(isMinHeap) {}

// Insertar elemento
template <typename T>
void Heap<T>::insert(T const& element) {
    heap.push_back(element);  // Agregar al final del vector
    size_t index = heap.size() - 1;

    // Reajustar hacia arriba
    while (index > 0) {
        size_t parent = (index - 1) / 2;
        if ((minHeap && heap[index] < heap[parent]) || (!minHeap && heap[index] > heap[parent])) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Extraer elemento superior
template <typename T>
T Heap<T>::extractTop() {
    if (heap.empty()) return T{};  // Retorna un valor por defecto si el heap está vacío
    T top = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    size_t index = 0;
    while (index < heap.size()) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t swapIndex = index;

        if (left < heap.size() && ((minHeap && heap[left] < heap[swapIndex]) || (!minHeap && heap[left] > heap[swapIndex]))) {
            swapIndex = left;
        }

        if (right < heap.size() && ((minHeap && heap[right] < heap[swapIndex]) || (!minHeap && heap[right] > heap[swapIndex]))) {
            swapIndex = right;
        }

        if (swapIndex == index) break;

        std::swap(heap[index], heap[swapIndex]);
        index = swapIndex;
    }
    return top;
}

// Obtener elemento superior sin eliminarlo
template <typename T>
T Heap<T>::peek() const {
    return heap.empty() ? T{} : heap[0];
}

// Obtener el tamaño del heap
template <typename T>
size_t Heap<T>::size() const {
    return heap.size();
}

// Verificar si el heap está vacío
template <typename T>
bool Heap<T>::isEmpty() const {
    return heap.empty();
}

// Vaciar el heap
template <typename T>
void Heap<T>::clear() {
    heap.clear();
}

#endif
