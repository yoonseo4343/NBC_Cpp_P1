// Copyright 2025 ys
#include <iostream>

using namespace std; // NOLINT

// 포션 지급 함수, 카운트 만큼 포션 증가 // NOLINT
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion += count;
    *p_MPPotion += count;
}
void printSystem() {
    cout << "1. HP UP" << endl;
    cout << "2. MP UP" << endl;
    cout << "3. 공격력 UP" << endl; // NOLINT
    cout << "4. 방어력 UP" << endl; // NOLINT
    cout << "5. 현재 능력치" << endl; // NOLINT
    cout << "6. Level UP" << endl;

    cout << "0. 나가기" << endl; // NOLINT
}
void hpUp(int& hp, int& po) {
    if (po < 1) {
        cout << "포션이 부족합니다." << endl; // NOLINT
        return;
    }
    hp += 20;
    po--;
    cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl; // NOLINT
    cout << "현재 HP: " << hp << endl; // NOLINT
}
void mpUp(int& mp, int& po) {
    if (po < 1) {
        cout << "포션이 부족합니다." << endl; // NOLINT
        return;
    }
    mp += 20;
    po--;
    cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl; // NOLINT
    cout << "현재 MP: " << mp << endl; // NOLINT
}
void atkUp(int& atk) {
    atk *=2;
    cout << "* 공격력이 2배로 증가되었습니다." << endl; // NOLINT
    cout << "현재 공격력: " << atk << endl; // NOLINT
}
void defUp(int& def) {
    def *= 2;
    cout << "* 방어력이 2배로 증가되었습니다." << endl; // NOLINT
    cout << "현재 방어력: " << def << endl; // NOLINT
}
void printStatus(int(&arr)[5], int& hpp, int& mpp) {
    cout << "* HP: " << arr[0] << ", MP: " << arr[1]
        << ", 공격력: " << arr[2] << ", 방어력: " << arr[3] << endl; // NOLINT
    cout << "* Lv: " << arr[4]
        << ", 남은 HP/MP 포션 수: " << hpp << "/" << mpp << endl; // NOLINT
}
void lvUp(int& lv, int& hpp, int& mpp) {
    lv++;
    setPotion(1, &hpp, &mpp);
    cout << "* 레벨업! HP/MP 포션이 지급됩니다." << endl; // NOLINT
    cout <<"남은 HP/MP 포션 수: " << hpp << "/" << mpp << endl; // NOLINT
}
int main() {
    int status[5] = { 0, 0, 0, 0, 1 };  // HP,MP,공격력,방어력,레벨 초기화 // NOLINT

    while (status[0] <= 50 || status[1] <= 50) {  // HP와 MP를 입력 // NOLINT
        cout << "HP와 MP를 입력해주세요: "; // NOLINT
        cin >> status[0] >> status[1];
        if (status[0] <= 50 || status[1] <= 50)
            cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl; // NOLINT
    }

    while (status[2] <= 0 || status[3] <= 0) {  // 공격과 방어를 입력 // NOLINT
        cout << "공격력과 방어력을 입력해주세요: "; // NOLINT
        cin >> status[2] >> status[3];
        if (status[2] <= 0 || status[3] <= 0)
            cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl; // NOLINT
    }

    int HPPotion = 0;  // 포션 갯수 // NOLINT
    int MPPotion = 0;
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl; // NOLINT
    setPotion(5, &HPPotion, &MPPotion);  // 포션 지급 // NOLINT

    cout << "##############################################" << endl;

    cout << "스탯 관리 시스템" << endl; // NOLINT
    printSystem();
    while (true) {
        int num;
        cout << "번호를 선택해주세요: "; // NOLINT
        cin >> num;

        if (cin.fail()) {
            cin.clear();             // fail 상태 복구 // NOLINT
            cin.ignore(1000, '\n');  // 잘못된 입력 버퍼 비우기 // NOLINT
            cout << "번호를 입력해주세요.\n"; // NOLINT
            continue;
        }

        if (num == 0) {
            cout << "프로그램을 종료합니다." << endl; // NOLINT
            break;
        } else if (num == 1) {
            hpUp(status[0], HPPotion);
        } else if (num == 2) {
            mpUp(status[1], MPPotion);
        } else if (num == 3) {
            atkUp(status[2]);
        } else if (num == 4) {
            defUp(status[3]);
        } else if (num == 5) {
            printStatus(status, HPPotion, MPPotion);
        } else if (num == 6) {
            lvUp(status[4], HPPotion, MPPotion);
        } else {
            cout << "잘못된 입력" << endl; // NOLINT
        }
    }
    return 0;
}
