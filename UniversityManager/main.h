#pragma once
/*
학사관리프로그램
user	기능
교직원	과목등록/과목취소/출력
교수	과목개설/과목수정/개설취소/출력
학생	수강신청/수강철회/출력

과목	과목코드
		과목명
		개설여부
		개설정보	수강인원
					강의일시	요일
								시간
					강의실		건물명
								호수
교직원	등록과목
		등록개수
		f등록
		f취소
		f등록과목출력

교수	교수명
		학과명
		개설과목목록
		개설과목개수
		f과목개설
		f개설취소
		f과목정보수정
		f개설과목출력

학생	학생명
		학과명
		수강신청목록
		수강신청개수
		f수강신청
		f신청취소
		f수강과목출력
*/

#include <iostream>
#include <string>

using namespace std;

class Cinfo_when {
private:
	char* m_cDay;
	int m_iTime[10];
public:
	void setDate(char* _d) {
		delete[] m_cDay;
		m_cDay = new char[strlen(_d) + 1];
		strcpy_s(m_cDay, strlen(_d), _d);
	}
	void* getTime() { return m_iTime; }
	void printWhen() {
		cout << "요일 : " << m_cDay << endl;
		cout << "시간 : ";
		int i = 0;
		while(m_iTime[i] != -1) {
			cout << m_iTime[i] << ",";
			i++;
		}
		cout << "교시" << endl;
	}
public:
	Cinfo_when(char* _d, int* _t, int _size) {
		int i;
		m_cDay = new char[strlen(_d) + 1];
		strcpy_s(m_cDay, strlen(_d), _d);
		for(i = 0; i < _size; i++)
			m_iTime[i] = _t[i];
		m_iTime[i] = -1;
	}
	~Cinfo_when() {
		cout << m_cDay << endl;
		delete[] m_cDay;
	}
};
class Cinfo_where {
private:
	char m_cBuildingname[20];
	int m_iRoomnum;
public:
	void setBuildingname(char* _building) { strcpy_s(m_cBuildingname, _building); }
	void setRoomnum(int _room) { m_iRoomnum = _room; }
	void printWhere() {
		cout << "건물명 : " << m_cBuildingname << endl;
		cout << "호수 : " << m_iRoomnum << endl;
	}
public:
	Cinfo_where(char* _building, int _room) {
		setBuildingname(_building);
		setRoomnum(_room);
	}
	~Cinfo_where() {}
};
class Csubject_info {
private:
	int m_iStudentnum;
public:
	Cinfo_when Owhen;
	Cinfo_where Owhere;
	void setStudentnum(int _student) { m_iStudentnum = _student; }
	void printInfo() {
		Owhen.printWhen(); Owhere.printWhere();
		cout << "인원수 : " << m_iStudentnum << endl;
	}
public:
	Csubject_info(char* _d, int* _t, int _size, char* _building, int _room, int _student) : Owhen(_d, _t, _size), Owhere(_building, _room) { m_iStudentnum = _student; }
	~Csubject_info() {}
};
class Csubject {
private:
	int m_iSubjectCode;
	char m_cSubjectName[20];
	Csubject_info* m_pOinfo;
	bool m_bFlag_subject;
public:
	void setSubjectCode(int _subjectCode) { this->m_iSubjectCode = m_iSubjectCode; }
	int getSubjectCode() { return m_iSubjectCode; }
	void setSubjectName(char* _subjectName) { strcpy_s(this->m_cSubjectName, _subjectName); }
	char* getSubjectName() { return m_cSubjectName; }

	void resetInfo() { delete m_pOinfo; m_pOinfo = nullptr; }
	Csubject_info* getInfo() { return m_pOinfo; }
	void setInfo() {
		char day[10], building[20];
		int t[10];
		int runT, room, studN, cardinal;

		cout << "강의요일을 입력하시오";
		cin >> day;
		cout << "시간단위를 입력하시오.";
		cin >> runT;
		cout << "강의교시를 입력하시오";
		for(cardinal = 0; cardinal < runT; cardinal++)
			cin >> t[cardinal];
		cout << "강의건물을 입력하시오";
		cin >> building;
		cout << "건물의 호수을 입력하시오";
		cin >> room;
		cout << "강의 정원을 입력하시오";
		cin >> studN;
		m_pOinfo = new Csubject_info(day, t, runT, building, room, studN);
		m_bFlag_subject = true;
	}

	void setFlag(bool _b) { m_bFlag_subject = _b; }
	bool getFlag() { return m_bFlag_subject; }

	void printSubject() { cout << "과목코드 : " << m_iSubjectCode << ", 과목명 : " << m_cSubjectName << endl; }
	void printInfo() { if(m_pOinfo != NULL) { m_pOinfo->printInfo(); } }

public:
	Csubject(int _subjectCode, char* _subjectName) {
		this->m_iSubjectCode = m_iSubjectCode;
		strcpy_s(this->m_cSubjectName, _subjectName);
		m_pOinfo = nullptr;
		m_bFlag_subject = false;
	}
	~Csubject() {
		cout << "m_pOinfo" << endl;
		if(m_bFlag_subject)
			delete m_pOinfo;
	}
};

class Cuser_staff {
private:
	Csubject* m_pOsubjectStaff[10];
	int m_iSubjectNum = 0;
public:
	void inputStaff(int _subjectCode, char* _subjectName) {
		int i; bool f = true;
		for(i = 0; i < m_iSubjectNum; i++) {
			if(m_pOsubjectStaff[i]->getSubjectCode() == _subjectCode || !strcmp(m_pOsubjectStaff[i]->getSubjectName(), _subjectName))
				f = false; cout << "이미 등록된 과목입니다." << endl;
		}
		if(f)
			m_pOsubjectStaff[m_iSubjectNum++] = new Csubject(_subjectCode, _subjectName);
	}
	void cancelStaff(int _subjectCode) {
		int i, j = -1;
		for(i = 0; i < m_iSubjectNum - 1; i++) {
			if(m_pOsubjectStaff[i]->getSubjectCode() == _subjectCode) {
				j = i;
				break;
			}
		}
		if(j != -1) {
			for(i = j; i < m_iSubjectNum - 1; i++) {
				m_pOsubjectStaff[i] = m_pOsubjectStaff[i + 1];
			}
			m_iSubjectNum--;
		} else {
			cout << "삭제할 과목코드가 없습니다." << endl;
		}
	}
	void printStaff() {
		int i;
		for(i = 0; i < m_iSubjectNum - 1; i++) {
			m_pOsubjectStaff[i]->printSubject();
		}
	}

	Csubject** getSubjectlist() { return m_pOsubjectStaff; }
	int getSubjectNum() { return m_iSubjectNum; }
public:
	Cuser_staff() {}
	~Cuser_staff() {
		int i;
		cout << "subject list" << endl;
		for(i = 0; i < m_iSubjectNum; i++)
			delete m_pOsubjectStaff[i];
	}
};
class Cuser_professor {
private:
	char m_cNameProf[10], m_cDepaProf[10];
	Csubject* m_pOsubjectProf[5];
	int cntProf = 0;
public:
	void openProf(Cuser_staff* _staff) {
		int iInputCode, i;
		bool f = false;
		Csubject** ppOsubjectStaff = _staff->getSubjectlist();
		_staff->printStaff();
		cout << "개설할 과목코드를 입력하세요.";
		cin >> iInputCode;

		for(i = 0; i < _staff->getSubjectNum(); i++) {
			if(iInputCode == ppOsubjectStaff[i]->getSubjectCode()) {
				if(!ppOsubjectStaff[i]->getFlag()) {
					ppOsubjectStaff[i]->setInfo();
					m_pOsubjectProf[cntProf] = ppOsubjectStaff[i];
					cntProf++;
				} else {
					cout << "이미 개설된 과목입니다." << endl;
				}
				f = true;
				break;
			}
		}
		if(!f) {
			cout << "없는 과목코드입니다." << endl;
		}
	}
	void cancelProf() {
		int iSubjectCode, i, j = -1;
		cout << "취소할 과목코드를 입력하세요." << endl;
		cin >> iSubjectCode;
		for(i = 0; i < cntProf; i++) {
			if(iSubjectCode == m_pOsubjectProf[i]->getSubjectCode()) {
				j = 1;
				m_pOsubjectProf[i]->setFlag(false);
				m_pOsubjectProf[i]->resetInfo();
				break;
			}
		}
	}
	void editProf() {
		int i, j = -1, iSubjectCode, inputAction, runT, room, studN;
		char day[10], building[20];
		int* time = NULL;
		cout << "수정할 과목의 코드를 입력하시오." << endl;
		cin >> iSubjectCode;
		for(i = 0; i < cntProf; i++) {
			if(iSubjectCode == m_pOsubjectProf[i]->getSubjectCode()) {
				//j=1;
				break;
			}
		}
		if(i == cntProf)
			cout << "해당과목이 없습니다." << endl;
		else {
			cout << "Q.할일을 고르시오. 1시간수정 2강의실수정 3수강인원수정" << endl;
			cin >> inputAction;
			switch(inputAction) {
			case 1:
				cout << "요일 : ";
				cin >> day;
				cout << "시간단위";
				cin >> runT;
				cout << "강의 교시";
				for(j = 0; j < runT; j++)
					cin >> time[j];
				time[j] = -1;
				m_pOsubjectProf[i]->getInfo()->Owhen.setDate(day);
				break;
			case 2:
				cout << "강의 건물을 입력하시오";
				cin >> building;
				cout << "강의 호수를 입력하시오";
				cin >> room;
				m_pOsubjectProf[i]->getInfo()->Owhere.setBuildingname(building);
				m_pOsubjectProf[i]->getInfo()->Owhere.setRoomnum(room);
				break;
			case 3:
				cout << "인원 수 : ";
				cin >> studN;
				m_pOsubjectProf[i]->getInfo()->setStudentnum(studN);
				break;
			default:
				cout << "잘 못 입력하셨습니다." << endl;
			}
		}
	}
	void printProf() {
		int i;
		cout << "교수명 : " << m_cNameProf << endl;
		cout << "학과 : " << m_cDepaProf << endl;
		for(i = 0; i < cntProf; i++) {
			m_pOsubjectProf[i]->printSubject();
			if(m_pOsubjectProf[i]->getFlag())
				m_pOsubjectProf[i]->getInfo()->printInfo();
		}
	}
public:
	Cuser_professor(char* _nameProf, char* _depaProf) {
		strcpy_s(m_cNameProf, _nameProf);
		strcpy_s(m_cDepaProf, _depaProf);
	}
	~Cuser_professor() {}
};
class Cuser_student {
private:
	char m_cNameStud[10], m_cDepaStud[20];
	Csubject* m_pOsubjectStud[5];
	int cntStud = 0;
public:
	void selectStud(Cuser_staff* _staff) {
		int i, iInputCode;
		bool f = false;
		Csubject** ppOsubjectStaff = _staff->getSubjectlist();

		for(i = 0; i < _staff->getSubjectNum(); i++) {
			if(ppOsubjectStaff[i]->getFlag()) {
				ppOsubjectStaff[i]->printSubject();
				ppOsubjectStaff[i]->printInfo();
			}
		}
		cout << "신청할 과목코드를 입력하시오.";
		cin >> iInputCode;
		for(i = 0; i < cntStud; i++) {
			if(cntStud == m_pOsubjectStud[i]->getSubjectCode()) {
				cout << "이미 신청한 과목입니다." << endl;
				return;
			}
		}
		for(i = 0; i < _staff->getSubjectNum(); i++) {
			if(iInputCode == ppOsubjectStaff[i]->getSubjectCode()) {
				m_pOsubjectStud[cntStud] = ppOsubjectStaff[i];
				cntStud++;
				f = true;
				break;
			}
		}
		if(!f)
			cout << "없는 과목코드입니다." << endl;
	}
	void cancelStud() {
		int iInputCode, i, j = -1;
		cout << "취소할 과목코드를 입력하시오" << endl;
		cin >> iInputCode;
		for(i = 0; i < cntStud; i++) {
			if(iInputCode == m_pOsubjectStud[i]->getSubjectCode()) {
				j = 1; break;
			}
		}
		if(j == -1) {
			cout << "해당과목이 없습니다." << endl;
		} else {
			for(i = j; i < cntStud - 1; i++) {
				m_pOsubjectStud[i] = m_pOsubjectStud[i + 1];
			}
			cntStud--;
		}
	}
	void printStud() {
		int i;
		cout << "학생명 : " << m_cNameStud << endl;
		cout << "학과 : " << m_cDepaStud << endl;
		for(i = 0; i < cntStud; i++) {
			m_pOsubjectStud[i]->printSubject();
		}
	}

public:
	Cuser_student(char* _nameStud, char* _depaStud) {
		strcpy_s(m_cNameStud, _nameStud);
		strcpy_s(m_cDepaStud, _depaStud);
	}
	~Cuser_student() {}
};
class Cuser {
private:
public:
	Cuser() {}
	~Cuser() {}
};