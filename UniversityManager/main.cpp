

#include "main.h"
int main() {
	Cuser_staff Staf1;
	Cuser_professor* pProf1;
	Cuser_student* pStud1;
	int iUser, iFunc;
	int iSubjectCode; char cName[20], cDepa[20];
	bool bFlag_user = true, bFlag_func = true;

	while(bFlag_user) {
		cout << "Q.��������? 1������ 2���� 3�л�" << endl;
		cin >> iUser;
		switch(iUser) {
		case 1://������
			while(bFlag_func) {
				cout << "Q.����? 1������ 2������� 3��ϰ������" << endl;
				cin >> iFunc;
				switch(iFunc) {
				case 1://������
					cout << "����� : " << endl;
					cin >> cName;
					cout << "�����ڵ� : " << endl;
					cin >> iSubjectCode;
					Staf1.inputStaff(iSubjectCode, cName);
					break;
				case 2://������
					cout << "����� �����ڵ� : " << endl;
					cin >> iSubjectCode;
					Staf1.cancelStaff(iSubjectCode);
					break;
				case 3://��ϰ������
					Staf1.printStaff();
					break;
				default:
					bFlag_func = false;
				}
			}
			break;
		case 2://����
			bFlag_func = true;
			cout << "������ : " << endl;
			cin >> cName;
			cout << "�а��� : " << endl;
			cin >> cDepa;
			pProf1 = new Cuser_professor(cName, cDepa);
			while(bFlag_func) {
				cout << "Q.����? 1���񰳼� 2������� 3������������ 4�����������" << endl;
				cin >> iFunc;
				switch(iFunc) {
				case 1://���񰳼�
					pProf1->openProf(&Staf1);
					break;
				case 2://�������
					pProf1->cancelProf();
					break;
				case 3://������������
					pProf1->editProf();
					break;
				case 4://�����������
					pProf1->printProf();
					break;
				default:
					bFlag_func = false;
				}
			}
			break;
		case 3://�л�
			bFlag_func = true;
			cout << "�л��� : " << endl;
			cin >> cName;
			cout << "�а��� : " << endl;
			cin >> cDepa;
			pStud1 = new Cuser_student(cName, cDepa);
			while(bFlag_func) {
				cout << "Q.����? 1������û 2��û��� 3�����������" << endl;
				cin >> iFunc;
				switch(iFunc) {
				case 1://������û
					pStud1->selectStud(&Staf1);
					break;
				case 2://��û���
					pStud1->cancelStud();
					break;
				case 3://�����������
					pStud1->printStud();
					break;
				default:
					bFlag_func = false;
				}
			}
			break;
		default:
			cout << "�� �� �Է�" << endl;
			bFlag_user = false;
		}
	}
	return 0;
}
