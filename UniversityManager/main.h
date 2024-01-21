#pragma once
/*
�л�������α׷�
user	���
������	������/�������/���
����	���񰳼�/�������/�������/���
�л�	������û/����öȸ/���

����	�����ڵ�
		�����
		��������
		��������	�����ο�
					�����Ͻ�	����
								�ð�
					���ǽ�		�ǹ���
								ȣ��
������	��ϰ���
		��ϰ���
		f���
		f���
		f��ϰ������

����	������
		�а���
		����������
		�������񰳼�
		f���񰳼�
		f�������
		f������������
		f�����������

�л�	�л���
		�а���
		������û���
		������û����
		f������û
		f��û���
		f�����������
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
		cout << "���� : " << m_cDay << endl;
		cout << "�ð� : ";
		int i = 0;
		while(m_iTime[i] != -1) {
			cout << m_iTime[i] << ",";
			i++;
		}
		cout << "����" << endl;
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
		cout << "�ǹ��� : " << m_cBuildingname << endl;
		cout << "ȣ�� : " << m_iRoomnum << endl;
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
		cout << "�ο��� : " << m_iStudentnum << endl;
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

		cout << "���ǿ����� �Է��Ͻÿ�";
		cin >> day;
		cout << "�ð������� �Է��Ͻÿ�.";
		cin >> runT;
		cout << "���Ǳ��ø� �Է��Ͻÿ�";
		for(cardinal = 0; cardinal < runT; cardinal++)
			cin >> t[cardinal];
		cout << "���ǰǹ��� �Է��Ͻÿ�";
		cin >> building;
		cout << "�ǹ��� ȣ���� �Է��Ͻÿ�";
		cin >> room;
		cout << "���� ������ �Է��Ͻÿ�";
		cin >> studN;
		m_pOinfo = new Csubject_info(day, t, runT, building, room, studN);
		m_bFlag_subject = true;
	}

	void setFlag(bool _b) { m_bFlag_subject = _b; }
	bool getFlag() { return m_bFlag_subject; }

	void printSubject() { cout << "�����ڵ� : " << m_iSubjectCode << ", ����� : " << m_cSubjectName << endl; }
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
				f = false; cout << "�̹� ��ϵ� �����Դϴ�." << endl;
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
			cout << "������ �����ڵ尡 �����ϴ�." << endl;
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
		cout << "������ �����ڵ带 �Է��ϼ���.";
		cin >> iInputCode;

		for(i = 0; i < _staff->getSubjectNum(); i++) {
			if(iInputCode == ppOsubjectStaff[i]->getSubjectCode()) {
				if(!ppOsubjectStaff[i]->getFlag()) {
					ppOsubjectStaff[i]->setInfo();
					m_pOsubjectProf[cntProf] = ppOsubjectStaff[i];
					cntProf++;
				} else {
					cout << "�̹� ������ �����Դϴ�." << endl;
				}
				f = true;
				break;
			}
		}
		if(!f) {
			cout << "���� �����ڵ��Դϴ�." << endl;
		}
	}
	void cancelProf() {
		int iSubjectCode, i, j = -1;
		cout << "����� �����ڵ带 �Է��ϼ���." << endl;
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
		cout << "������ ������ �ڵ带 �Է��Ͻÿ�." << endl;
		cin >> iSubjectCode;
		for(i = 0; i < cntProf; i++) {
			if(iSubjectCode == m_pOsubjectProf[i]->getSubjectCode()) {
				//j=1;
				break;
			}
		}
		if(i == cntProf)
			cout << "�ش������ �����ϴ�." << endl;
		else {
			cout << "Q.������ ���ÿ�. 1�ð����� 2���ǽǼ��� 3�����ο�����" << endl;
			cin >> inputAction;
			switch(inputAction) {
			case 1:
				cout << "���� : ";
				cin >> day;
				cout << "�ð�����";
				cin >> runT;
				cout << "���� ����";
				for(j = 0; j < runT; j++)
					cin >> time[j];
				time[j] = -1;
				m_pOsubjectProf[i]->getInfo()->Owhen.setDate(day);
				break;
			case 2:
				cout << "���� �ǹ��� �Է��Ͻÿ�";
				cin >> building;
				cout << "���� ȣ���� �Է��Ͻÿ�";
				cin >> room;
				m_pOsubjectProf[i]->getInfo()->Owhere.setBuildingname(building);
				m_pOsubjectProf[i]->getInfo()->Owhere.setRoomnum(room);
				break;
			case 3:
				cout << "�ο� �� : ";
				cin >> studN;
				m_pOsubjectProf[i]->getInfo()->setStudentnum(studN);
				break;
			default:
				cout << "�� �� �Է��ϼ̽��ϴ�." << endl;
			}
		}
	}
	void printProf() {
		int i;
		cout << "������ : " << m_cNameProf << endl;
		cout << "�а� : " << m_cDepaProf << endl;
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
		cout << "��û�� �����ڵ带 �Է��Ͻÿ�.";
		cin >> iInputCode;
		for(i = 0; i < cntStud; i++) {
			if(cntStud == m_pOsubjectStud[i]->getSubjectCode()) {
				cout << "�̹� ��û�� �����Դϴ�." << endl;
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
			cout << "���� �����ڵ��Դϴ�." << endl;
	}
	void cancelStud() {
		int iInputCode, i, j = -1;
		cout << "����� �����ڵ带 �Է��Ͻÿ�" << endl;
		cin >> iInputCode;
		for(i = 0; i < cntStud; i++) {
			if(iInputCode == m_pOsubjectStud[i]->getSubjectCode()) {
				j = 1; break;
			}
		}
		if(j == -1) {
			cout << "�ش������ �����ϴ�." << endl;
		} else {
			for(i = j; i < cntStud - 1; i++) {
				m_pOsubjectStud[i] = m_pOsubjectStud[i + 1];
			}
			cntStud--;
		}
	}
	void printStud() {
		int i;
		cout << "�л��� : " << m_cNameStud << endl;
		cout << "�а� : " << m_cDepaStud << endl;
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