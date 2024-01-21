#pragma once
#include "main.h"
int main() {
	int iInput;
	Cpokemon* pOmypoke = nullptr;

	cout << "Q.원하는 포켓몬을 선택하세요.\n1.이상해씨 2.꼬북이 3.피카츄" << endl << endl;
	cin >> iInput;

	switch(iInput) {
	case 1:
		pOmypoke = new Cpokemon0001이상해씨();
		break;
	case 2:
		pOmypoke = new Cpokemon0007꼬북이();
		break;
	case 3:
		pOmypoke = new Cpokemon0087피카츄();
		break;
	dafault:
		cout << "잘 못 선택하셨습니다." << endl;
	}

	CplayGame Omygame(pOmypoke);
	while(true) {
		Omygame.printMenu();
		if(Omygame.isExit()) { cout << "에너지가 모두 소모되어 포켓몬이 죽었습니다." << endl << "게임을 종료합니다." << endl; return -1; }
	}
	return 0;
}
