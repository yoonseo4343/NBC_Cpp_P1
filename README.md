## [1번 과제] 상태창 구현

<https://zzageuli.tistory.com/16>
---

### 정보 입력
int status[5] -> HP, MP, 공격력, 방어력, 레벨 저장

HP/MP 입력 받기 -> 50 이하 -> 다시 입력 -> while

공격/방어력 입력 받기 -> 0 이하 -> 다시 입력 -> while

### 스탯 관리 시스템
1. HP UP 2. MP UP 3. 공격력 UP 4. 방어력 UP 5. 현재 능력치 6. Level Up 0. 나가기

선택지 출력 -> int로 입력 받기 -> 선택지 실행

### 함수
void setPotion() //포션 지급 함수 -> 기본 5개 지급

void printSystem() //시스템 선택지 출력

void hpUp() //HP 강화 +20 //포션 -1 ->포션 갯수 체크

void mpUp() //MP 강화 +20 //포션 -1 ->포션 갯수 체크

void atkUp() //공격력 강화 2배

void defUp() //방어력 강화 2배

void printStatus() //상태 출력

void lvUp() //레벨업 //포션 각 +1

