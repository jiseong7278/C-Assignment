#pragma once

using std::endl;
using std::cout;
using std::cin;

using std::ostream;
using std::istream;

class Set {
private :
	int size; // �迭�� ũ��
	int capacity; // �迭�� ����ִ� ���� ����
	int* arr; // �迭
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