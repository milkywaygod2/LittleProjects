#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cpokemon {
	//포켓몬이 공통으로 갖는 각각의 고유한 값들
protected:
	int m_iEXP;
	int m_iLevel;
	int m_iEnergy;

	string mc_Sname;
	int mc_eat_iEnergy_recovery;
	int mc_sleep_iEnergy_recovery;
	int mc_hangout_iEnergy_recovery;
	int mc_hangout_iEXP_recovery;
	int mc_train_iEnergy_recovery;
	int mc_train_iEXP_recovery;
	int mc_levelup_iEXP_recovery;
	int mc_levelup_iEXP_thresh;

	//포켓몬이 공통으로 갖는 행위 및 기능들
public:
	bool eat() {
		cout << mc_Sname << "는 밥을 먹는다." << endl;
		m_iEnergy += mc_eat_iEnergy_recovery;
		levelup();
		return checkEnergy();
	}
	bool sleep() {
		cout << mc_Sname << "는 잠을 잔다." << endl;
		m_iEnergy += mc_sleep_iEnergy_recovery;
		levelup();
		return checkEnergy();
	}
	bool hangout() {
		cout << mc_Sname << "가 논다." << endl;
		m_iEnergy += mc_hangout_iEnergy_recovery;
		m_iEXP += mc_hangout_iEXP_recovery;
		levelup();
		return checkEnergy();
	}
	bool train() {
		cout << mc_Sname << "는 훈련했다." << endl;
		m_iEnergy += mc_train_iEnergy_recovery;
		m_iEXP += mc_train_iEXP_recovery;
		levelup();
		return checkEnergy();
	}
	void levelup() {
		if(m_iEXP >= mc_levelup_iEXP_thresh) {
			cout << mc_Sname << ", 레벨업!" << endl;
			m_iLevel++;
			m_iEXP -= mc_levelup_iEXP_thresh;
		}
	}

	bool checkEnergy() { if(m_iEnergy <= 0) { return true; } else { return false; } }
	void printInfo() {
		cout << "현재 " << mc_Sname << "의 정보" << endl;
		cout << "EXP = " << m_iEXP << endl;
		cout << "Energy = " << m_iEnergy << endl;
		cout << "Level = " << m_iLevel << endl << endl << endl;
	}
public:
	Cpokemon() {}
	~Cpokemon() {}
};

class Cpokemon0001이상해씨 : public Cpokemon {
private:
public:
	Cpokemon0001이상해씨() {
		m_iEXP = 20;
		m_iLevel = 0;
		m_iEnergy = 30;
		mc_Sname = "이상해씨";
		mc_eat_iEnergy_recovery = 5;
		mc_sleep_iEnergy_recovery = 20;
		mc_hangout_iEnergy_recovery = -10;
		mc_hangout_iEXP_recovery = 15;
		mc_train_iEnergy_recovery = -10;
		mc_train_iEXP_recovery = 20;
		mc_levelup_iEXP_recovery = -35;
		mc_levelup_iEXP_thresh = 35;

		cout << "이상해씨가 생성되었습니다." << endl;
		printInfo();
	}
	~Cpokemon0001이상해씨() {}
};

class Cpokemon0007꼬북이 : public Cpokemon {
private:
public:
	Cpokemon0007꼬북이() {
		m_iEXP = 40;
		m_iLevel = 0;
		m_iEnergy = 50;
		mc_Sname = "꼬북이";
		mc_eat_iEnergy_recovery = 15;
		mc_sleep_iEnergy_recovery = 10;
		mc_hangout_iEnergy_recovery = -30;
		mc_hangout_iEXP_recovery = 15;
		mc_train_iEnergy_recovery = -20;
		mc_train_iEXP_recovery = 30;
		mc_levelup_iEXP_recovery = -50;
		mc_levelup_iEXP_thresh = 50;

		cout << "꼬북이가 생성되었습니다." << endl;
		printInfo();
	}
	~Cpokemon0007꼬북이() {}
};

class Cpokemon0087피카츄 : public Cpokemon {
private:
public:
	Cpokemon0087피카츄() {
		m_iEXP = 30;
		m_iLevel = 0;
		m_iEnergy = 50;
		mc_Sname = "피카츄";
		mc_eat_iEnergy_recovery = 10;
		mc_sleep_iEnergy_recovery = 5;
		mc_hangout_iEnergy_recovery = -20;
		mc_hangout_iEXP_recovery = 5;
		mc_train_iEnergy_recovery = -15;
		mc_train_iEXP_recovery = 20;
		mc_levelup_iEXP_recovery = -40;
		mc_levelup_iEXP_thresh = 40;

		cout << "피카츄가 생성되었습니다." << endl;
		printInfo();
	}
	~Cpokemon0087피카츄() {}
};

class CplayGame {
private:
	Cpokemon* m_pPoke;
	int m_iMenu;
	bool m_bExit;

public:
	void printMenu() {
		cout << "Q.1밥 2잠 3놀기 4운동 5종료" << endl;
		cin >> m_iMenu;
		play();
	}
	void play() {
		switch(m_iMenu) {
		case 1:
			m_bExit = m_pPoke->eat();
			break;
		case 2:
			m_bExit = m_pPoke->sleep();
			break;
		case 3:
			m_bExit = m_pPoke->hangout();
			break;
		case 4:
			m_bExit = m_pPoke->train();
			break;
		case 5:
			m_bExit = true;
		} m_pPoke->printInfo();
	}

	Cpokemon* getPoke() { return m_pPoke; }
	void setPoke(Cpokemon* _pPoke) { this->m_pPoke = _pPoke; }

	int getMenu() { return m_iMenu; }
	void setMenu(int _menu) { this->m_iMenu = _menu; }

	bool isExit() { return m_bExit; }
	void setExit(bool _bExit) { this->m_bExit = _bExit; }

public:
	CplayGame(Cpokemon* _pPoke) { this->m_pPoke = _pPoke; }
	~CplayGame() {}

};