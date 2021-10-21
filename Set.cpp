#include <iostream>
#include <string>
#include "Set.h"

Set::Set() {
	size = 4;
	capacity = 0;
	arr = new int[size];
}

Set::Set(const Set& set) : size(set.size), capacity(set.capacity) {
	arr = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = set.arr[i];
	}
}

Set::~Set() {
	delete[] arr;
}

void Set::resize() {
	int* temp_arr = new int[size * 2];
	for (int i = 0; i < size; i++) {
		temp_arr[i] = arr[i];
	}
	size *= 2;
	delete[] arr;
	arr = temp_arr;
}

void Set::removeDuplicatedElement() {
	for (int i = 0; i < capacity - 1; i++) {
		for (int j = i + 1; j < capacity; j++) {
			if (arr[i] == arr[j]) {
				cout << arr[j] << "는 중복원소이므로 제거" << endl;
				for (int k = j; k < capacity; k++) {
					arr[k] = arr[k + 1];
				}
				j--;
				capacity--;
			}
		}
	}
}

const Set Set::operator|(const Set& s) {
	Set resultSet;
	for (int i = 0; i < capacity; i++) {
		resultSet.arr[i] = arr[i];
		resultSet.capacity++;
		if (resultSet.size== resultSet.capacity) {
			resultSet.resize();
		}
	}
	for (int j = 0; j < s.capacity; j++) {
		for (int k = 0; k < capacity; k++) {
			if (s.arr[j] == arr[k])
				break;
			if (k == (capacity - 1)) {
				resultSet.arr[resultSet.capacity] = s.arr[j];
				resultSet.capacity++;
				if (resultSet.size == resultSet.capacity) {
					resultSet.resize();
				}
			}
		}
	}
	return Set(resultSet);
}

const Set Set::operator&(const Set& s) {
	Set resultSet;
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < s.capacity; j++) {
			if (arr[i] == s.arr[j]) {
				resultSet.arr[resultSet.capacity] = arr[i];
				resultSet.capacity++;
				if (resultSet.size == resultSet.capacity) {
					resultSet.resize();
				}
				break;
			}
		}
	}
	return Set(resultSet);
}

istream& operator>>(istream& inputStream, Set& s) {
	while (1) {
		int inputNum;
		inputStream >> inputNum;
		if (inputNum < 0)
			break;
		s.arr[s.capacity] = inputNum;
		s.capacity++;
		if (s.size == s.capacity) {
			s.resize();
		}
	}
	s.removeDuplicatedElement();
	return inputStream;
}

ostream& operator<<(ostream& outputStream, const Set s) {
	for (int i = 0; i < s.capacity; i++) {
		outputStream << s.arr[i] << " ";
	}
	return outputStream;
}