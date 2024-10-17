#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

// Template class for Array
template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    // Default constructor: creates an empty array
    Array() : _data(NULL), _size(0) {
		std::cout << "Array of length " << _size << " constructed" << std::endl;
	}

    // Constructor with size parameter: creates an array of n elements
    Array(unsigned int n) : _data(new T[n]()), _size(n) {
		std::cout << "Array of length " << _size << " constructed" << std::endl;
		for (int i = 0; i < _size; i++) {
			std::cout << "Array[" << i << "] contains: " << _data[i] << std::endl;
		}
	}

    // Copy constructor
    Array(const Array& other) : _data(new T[other._size]), _size(other._size) {
		for (int i = 0; i < _size; i++) {
			_data[i] = other._data[i];
			std::cout << "Array[" << i << "] contains: " << _data[i] << std::endl;
		}
	}

	//copy assignment operator
	Array &operator=(Array const &other) {
		if (this != &other) {
			delete[] _data;
			_size = other._size;
			_data = new T[_size];
			for (int i = 0; i < _size; i++) {
				_data[i] = other._data[i];
				std::cout << "Array[" << i << "] contains: " << _data[i] << std::endl;
			}
		}
		return *this;
	}

    ~Array() {
        delete[] _data;
		std::cout << "Array destroyed" << std::endl;
    }


    // Subscript operator for accessing elements
    T& operator[](unsigned int i) {
        if (i >= _size) {
			throw std::out_of_range("Index out of bounds");
        }
        return _data[i];
    }

    // Const version of the subscript operator for accessing elements
    const T& operator[](unsigned int i) const {
        if (i >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[i];
    }

    // Returns the size of the array
    unsigned int size() const {
        return _size;
    }
};

#endif