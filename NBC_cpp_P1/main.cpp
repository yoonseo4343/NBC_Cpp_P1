#include <iostream>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) { // 포션 지급 함수, 카운트 만큼 포션 증가
	*p_HPPotion += count;
	*p_MPPotion += count;
}
void printSystem() {
	cout << "1. HP UP" << endl;
	cout << "2. MP UP" << endl;
	cout << "3. 공격력 UP" << endl;
	cout << "4. 방어력 UP" << endl;
	cout << "5. 현재 능력치" << endl;
	cout << "6. Level UP" << endl;

	cout << "0. 나가기" << endl;
}
void hpUp(int& hp, int& po) {
	if (po < 1)
	{
		cout << "포션이 부족합니다." << endl; 
		return;
	}
	hp += 20;
	po--;
	cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
	cout << "현재 HP: " << hp << endl;
}
void mpUp(int& mp, int& po) {
	if (po < 1)
	{
		cout << "포션이 부족합니다." << endl; 
		return;
	}
	mp += 20;
	po--;
	cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
	cout << "현재 MP: " << mp << endl;
}
void atkUp(int& atk) {
	atk *=2;
	cout << "* 공격력이 2배로 증가되었습니다." << endl;
	cout << "현재 공격력: " << atk << endl;
}
void defUp(int& def) {
	def *= 2;
	cout << "* 방어력이 2배로 증가되었습니다." << endl;
	cout << "현재 방어력: " << def << endl;
}
void printStatus(int(&arr)[5], int& hpp, int& mpp) {
	cout << "* HP: " << arr[0] << ", MP: " << arr[1] << ", 공격력: " << arr[2] << ", 방어력: " << arr[3] << endl;
	cout << "* Lv: " << arr[4] << ", 남은 HP/MP 포션 수: " << hpp << "/" << mpp << endl;
}
void lvUp(int& lv, int& hpp, int& mpp) {
	lv++;
	setPotion(1, &hpp, &mpp);
	cout << "* 레벨업! HP/MP 포션이 지급됩니다." << endl;
	cout<<"남은 HP/MP 포션 수: " << hpp << "/" << mpp << endl; 
}
int main() {
	int status[5] = { 0,0,0,0,1 }; // HP,MP,공격력,방어력,레벨 초기화

	while (status[0] <= 50 || status[1] <= 50) { // HP와 MP를 입력
		cout << "HP와 MP를 입력해주세요: ";
		cin >> status[0] >> status[1];
		if (status[0] <= 50 || status[1] <= 50)
			cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
	}

	while (status[2] <= 0 || status[3] <= 0) { // 공격과 방어를 입력
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> status[2] >> status[3];
		if (status[2] <= 0 || status[3] <= 0)
			cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
	}

	int HPPotion = 0; // 포션 갯수
	int MPPotion = 0;
	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
	setPotion(5, &HPPotion, &MPPotion); // 포션 지급

	cout << "##############################################" << endl;

	cout << "스탯 관리 시스템" << endl;
	printSystem();
	while (true) {
		int num;
		cout << "번호를 선택해주세요: ";
		cin >> num;
		if (num == 0)
		{
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		else if (num == 1)
			hpUp(status[0], HPPotion);
		else if (num == 2)
			mpUp(status[1], MPPotion);
		else if (num == 3)
			atkUp(status[2]);
		else if (num == 4)
			defUp(status[3]);
		else if (num == 5)
			printStatus(status, HPPotion, MPPotion);
		else if (num == 6)
			lvUp(status[4], HPPotion, MPPotion);
		else
			cout << "잘못된 입력" << endl;
	}
	
	return 0;
}