

#include "main.h"
int main() {
	Cuser_staff Staf1;
	Cuser_professor* pProf1;
	Cuser_student* pStud1;
	int iUser, iFunc;
	int iSubjectCode; char cName[20], cDepa[20];
	bool bFlag_user = true, bFlag_func = true;

	while(bFlag_user) {
		cout << "Q.누구세요? 1교직원 2교수 3학생" << endl;
		cin >> iUser;
		switch(iUser) {
		case 1://교직원
			while(bFlag_func) {
				cout << "Q.할일? 1과목등록 2과목취소 3등록과목출력" << endl;
				cin >> iFunc;
				switch(iFunc) {
				case 1://과목등록
					cout << "과목명 : " << endl;
					cin >> cName;
					cout << "과목코드 : " << endl;
					cin >> iSubjectCode;
					Staf1.inputStaff(iSubjectCode, cName);
					break;
				case 2://등록취소
					cout << "취소할 과목코드 : " << endl;
					cin >> iSubjectCode;
					Staf1.cancelStaff(iSubjectCode);
					break;
				case 3://등록과목출력
					Staf1.printStaff();
					break;
				default:
					bFlag_func = false;
				}
			}
			break;
		case 2://교수
			bFlag_func = true;
			cout << "교수명 : " << endl;
			cin >> cName;
			cout << "학과명 : " << endl;
			cin >> cDepa;
			pProf1 = new Cuser_professor(cName, cDepa);
			while(bFlag_func) {
				cout << "Q.할일? 1과목개설 2개설취소 3과목정보수정 4개설과목출력" << endl;
				cin >> iFunc;
				switch(iFunc) {
				case 1://과목개설
					pProf1->openProf(&Staf1);
					break;
				case 2://개설취소
					pProf1->cancelProf();
					break;
				case 3://과목정보수정
					pProf1->editProf();
					break;
				case 4://개설과목출력
					pProf1->printProf();
					break;
				default:
					bFlag_func = false;
				}
			}
			break;
		case 3://학생
			bFlag_func = true;
			cout << "학생명 : " << endl;
			cin >> cName;
			cout << "학과명 : " << endl;
			cin >> cDepa;
			pStud1 = new Cuser_student(cName, cDepa);
			while(bFlag_func) {
				cout << "Q.할일? 1수강신청 2신청취소 3수강과목출력" << endl;
				cin >> iFunc;
				switch(iFunc) {
				case 1://수강신청
					pStud1->selectStud(&Staf1);
					break;
				case 2://신청취소
					pStud1->cancelStud();
					break;
				case 3://수강과목출력
					pStud1->printStud();
					break;
				default:
					bFlag_func = false;
				}
			}
			break;
		default:
			cout << "잘 못 입력" << endl;
			bFlag_user = false;
		}
	}
	return 0;
}
