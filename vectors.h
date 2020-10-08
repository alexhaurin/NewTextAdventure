#pragma once
#include <vector>
#include <string>

template<typename T>
void print(T message) {
	std::cout << message << std::endl;
}

template<typename T>
void addVectorItem(std::vector<T>& vector, T item) {
	vector.push_back(item);
}

//Deletes item from vector using value
template<typename T>
void deleteVectorItem(std::vector<T>& vector, T item) {
	for (unsigned int i = 0; i < vector.size(); i++) {
		if (vector[i] == item) {
			vector.erase(0);
			break;
		}
	}
}

//Finds item in vector using value
template<typename T>
bool findVectorItem(std::vector<T>& vector, T item) {
	for (unsigned int i = 0; i < vector.size(); i++) {
		if (vector[i] == item) {
			return true;
		}
	}

	return false;
}

template<typename T>
void printVector(std::vector<T>& vector) {
	for (unsigned int i = 0; i < vector.size(); i++) {
		std::cout << vector[i] << ", ";
	}
}