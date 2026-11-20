# 01. C와 터미널

컴파일·입출력·배열·문자열·동적 메모리를 작은 CLI로 연습한다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

| 원본 번호 | 순서 · 작업 폴더 |
|---|---|
| 49 | [`cat/`](#49-cat) |
| 50 | [`mkdir/`](#50-mkdir) |
| 72 | [`hash-table/`](#72-hash-table) |
| 22 | [`hangman/`](#22-hangman) |
| 31 | [`tic-tac-toe-cli/`](#31-tic-tac-toe-cli) |
| 16 | [`sudoku/`](#16-sudoku) |
| 24 | [`text-adventure/`](#24-text-adventure) |

## 49 cat

원본: [README → Operating Systems](../README.md#operating-systems)

* [Rewrite cat](https://learnto.computer/screencasts/bsd-cat) `video`

### Daily TODO

- [ ] `49.01` `clang -std=c17 -Wall -Wextra -Wpedantic cat.c -o mycat`로 빌드하고 파일 하나의 출력을 `cmp`로 비교한다.
- [ ] `49.02` 인자 없이 표준 입력을 복사한다. `printf 'hello\n'`을 파이프로 넣어 바이트가 같은지 확인한다.
- [ ] `49.03` 파일 두 개와 `-`를 순서대로 읽는다. `a - b` 입력에서 세 조각 출력 순서를 확인한다.
- [ ] `49.04` 없는 파일은 stderr와 실패 상태를 남긴다. 정상·빈 파일·없는 파일 각각의 종료 상태를 확인한다.
- [ ] `49.05` NUL 바이트가 섞인 파일을 복사한다. 정상·실패 사례를 확인하는 `check.sh`와 실행법을 남긴다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 50 mkdir

원본: [README → Operating Systems](../README.md#operating-systems)

* Rewrite mkdir `video`
  * [mkdir](https://learnto.computer/screencasts/bsd-mkdir)
  * [Building paths for mkdir -p](https://learnto.computer/screencasts/bsd-mkdir-p)

### Daily TODO

- [ ] `50.01` 경로 하나를 생성한다. 임시 디렉토리에서 생성 성공과 기존 경로 실패를 확인한다.
- [ ] `50.02` 여러 경로를 순서대로 처리한다. 중간 경로가 실패해도 나머지는 생성되고 최종 상태는 실패인지 확인한다.
- [ ] `50.03` `-p`로 중간 경로를 생성한다. 3단계 깊이와 같은 명령 재실행을 확인한다.
- [ ] `50.04` `-p`에서 중간 구성 요소가 파일이면 실패한다. 끝 슬래시가 있는 정상 경로도 함께 확인한다.
- [ ] `50.05` 상대·절대 경로의 결과를 시스템 `mkdir`와 비교하고, 다른 동작이 있다면 근거를 기록한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 72 hash-table

원본: [README → Uncategorized](../README.md#uncategorized)

* [Write a hash table in C](https://github.com/jamesroutley/write-a-hash-table)

### Daily TODO

- [ ] `72.01` 고정 크기 테이블에 문자열 키/값을 저장하고 없는 키와 구분한다.
- [ ] `72.02` 같은 버킷에 들어가는 두 키를 만들어 충돌 해결 후 둘 다 찾는다.
- [ ] `72.03` 동일 키 재삽입을 갱신으로 처리하고, 이전 값과 새 값의 메모리 소유권을 확인한다.
- [ ] `72.04` 삭제 후에도 충돌한 다른 키를 조회한다. 소스에서 다루는 삭제 전략으로 검증한다.
- [ ] `72.05` 임계치에서 크기를 늘리고 데이터를 옮긴다. 수백 키의 값과 해제 경로를 sanitizer로 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 22 hangman

원본: [README → Game Development](../README.md#game-development)

* [Hangman](https://www.youtube.com/playlist?list=PLZ1QII7yudbd2ZHYSEWrSddsvD5PW_r5O) `video`

### Daily TODO

- [ ] `22.01` 비밀 단어와 가려진 글자판을 출력한다. 같은 글자가 두 번 있는 단어를 쓴다.
- [ ] `22.02` 한 글자 입력으로 모든 일치 위치를 공개한다. 중복 추측은 기회를 잃지 않게 한다.
- [ ] `22.03` 정답과 기회 소진을 각각 고정 입력으로 확인하고 잘못된 입력을 거른다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 31 tic-tac-toe-cli

원본: [README → Game Development](../README.md#game-development)

* [Simple Tic Tac Toe in C](https://www.youtube.com/playlist?list=PLZ1QII7yudbc7_ZgXA-gIXmME41Rs2GP5) `video`

### Daily TODO

- [ ] `31.01` 3×3판 출력과 번갈아 놓기를 구현한다. 범위 밖과 이미 찬 칸은 턴을 넘기지 않는다.
- [ ] `31.02` 가로·세로·대각선 승리를 입력 시퀀스로 확인한다.
- [ ] `31.03` 무승부와 게임 재시작 시 보드가 초기화되는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 16 sudoku

원본: [README → Game Development](../README.md#game-development)

* [Coding A Sudoku Solver in C](https://www.youtube.com/playlist?list=PLkTXsX7igf8edTYU92nU-f5Ntzuf-RKvW) `video`

### Daily TODO

- [ ] `16.01` 9×9 퍼즐을 읽고 행·열·박스 충돌을 각각 검증한다.
- [ ] `16.02` 빈 칸에 후보 숫자를 넣고 불가능하면 되돌린다. 고정 퍼즐의 해답을 비교한다.
- [ ] `16.03` 초기 충돌과 해답 없는 퍼즐을 구분하고, 실패 후 원래 판이 유지되는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 24 text-adventure

원본: [README → Game Development](../README.md#game-development)

* [How to Program a Text Adventure in C](https://helderman.github.io/htpataic/htpataic01.html) `in-progress`

### Daily TODO

- [ ] `24.01` 방 두 개와 이동 명령을 만들어 왕복을 확인한다.
- [ ] `24.02` 물건 하나를 줍고 내려놓는다. 같은 물건이 두 장소에 동시에 남지 않는지 확인한다.
- [ ] `24.03` 명사 해석과 인벤토리를 연결한다. 없는 대상과 모호한 명령의 응답을 확인한다.
- [ ] `24.04` 문·열쇠 같은 상태 변화 하나를 추가하고 성공·실패 경로를 둘 다 재생한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
