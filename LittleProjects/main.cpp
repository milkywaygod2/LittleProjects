#pragma once
#include "main.h"
int main() {
	int iInput;
	Cpokemon* pOmypoke = nullptr;

	cout << "Q.���ϴ� ���ϸ��� �����ϼ���.\n1.�̻��ؾ� 2.������ 3.��ī��" << endl << endl;
	cin >> iInput;

	switch(iInput) {
	case 1:
		pOmypoke = new Cpokemon0001�̻��ؾ�();
		break;
	case 2:
		pOmypoke = new Cpokemon0007������();
		break;
	case 3:
		pOmypoke = new Cpokemon0087��ī��();
		break;
	dafault:
		cout << "�� �� �����ϼ̽��ϴ�." << endl;
	}

	CplayGame Omygame(pOmypoke);
	while(true) {
		Omygame.printMenu();
		if(Omygame.isExit()) { cout << "�������� ��� �Ҹ�Ǿ� ���ϸ��� �׾����ϴ�." << endl << "������ �����մϴ�." << endl; return -1; }
	}
	return 0;
}
