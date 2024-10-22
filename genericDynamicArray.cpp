#include <iostream>

template <typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int size;

    // Function to resize the array when needed
    void resize(int new_capacity) {
        T* temp = new T[new_capacity];  // Allocate new array with increased capacity
        
        // Copy old data to the new array
        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
        
        // Delete old array and assign new array
        delete[] data;
        data = temp;
        capacity = new_capacity;
    }

public:
    // Constructor
    DynamicArray() {
        size = 0;
        capacity = 2;
        data = new T[capacity];     // Allocate initial memory
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;  // Free allocated memory
    }

    // Function to add elements
    void add(T value) {
        if (size == capacity) {
            resize(capacity * 2);  // Double the capacity when full
        }
        data[size++] = value;      // Add the new element and increment size
    }

    // Function to get an element at a specific index
    T get(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        std::cerr << "Index out of bounds!" << std::endl;
        throw std::out_of_range("Index out of bounds!");
    }

    // Function to remove the last element
    void remove() {
        if (size > 0) {
            size--;  // Simply decrease the size; the data remains in memory
        }
    }

    // Function to get the size of the array
    int getSize() const {
        return size;
    }

    // Function to get the capacity of the array
    int getCapacity() const {
        return capacity;
    }

    // Overloading the [] operator (non-const version): allows modification
    T& operator[](int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        std::cerr << "Index out of bounds!" << std::endl;
        throw std::out_of_range("Index out of bounds!");
    }

    // Overloading the [] operator (const version): ensures element cannot be modified
    const T& operator[](int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        std::cerr << "Index out of bounds!" << std::endl;
        throw std::out_of_range("Index out of bounds!");
    }
};

int main() {
    // Non-const usage
    DynamicArray<int> arr;
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    // Accessing and modifying elements using non-const operator
    for (int i = 0; i < arr.getSize(); i++) {
        std::cout << "Element at index " << i << ": " << arr[i] << std::endl;
    }

    arr[1] = 25;  // Modify an element
    std::cout << "After modification, element at index 1: " << arr[1] << std::endl;

    return 0;
}
