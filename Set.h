#pragma once

using std::endl;
using std::cout;
using std::cin;

using std::ostream;
using std::istream;

class Set {
private :
	int size; // 배열의 크기
	int capacity; // 배열에 들어있는 원소 개수
	int* arr; // 배열
	void resize();

	void removeDuplicatedElement();

public :
	Set();
	Set(const Set& set);
	~Set();

	const Set operator|(const Set& s);
	const Set operator&(const Set& s);

	friend istream& operator>>(istream& inputStream, Set& s);
	friend ostream& operator<<(ostream& outputStream,const Set s);
};