#include <iostream>
#include "Set.h"

using namespace std;

int main() {
	Set s1, s2;

	cout << "�� �������� �Է� (������ �� ������ ��)" << endl;

	cin >> s1 >> s2;
	cout << "�������� : " << (s1 | s2) << endl;
	cout << "�������� : " << (s1 & s2) << endl;
	return 0;
}