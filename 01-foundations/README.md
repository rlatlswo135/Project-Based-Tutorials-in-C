# 01. C와 터미널

컴파일·입출력·배열·문자열·동적 메모리를 작은 CLI로 연습한다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

회차는 2026-11-20에 원문 목차와 재생 시간을 대조해 나눴다. 항목마다 `원문 메모`에 근거와 확인하지 못한 부분을 적었다. 영상 항목은 제목과 길이만 보고 나눈 것이라, 실제 내용과 다르면 그날 줄을 고친다.

| 원본 번호 | 순서 · 작업 폴더 |
|---|---|
| 49 | [`cat/`](#49-cat) |
| 50 | [`mkdir/`](#50-mkdir) |
| 72 | [`hash-table/`](#72-hash-table) |
| 22 | [`hangman/`](#22-hangman) |
| 31 | [`tic-tac-toe-cli/`](#31-tic-tac-toe-cli) |
| 16 | [`sudoku/`](#16-sudoku) |
| 24 | [`text-adventure/`](#24-text-adventure) |

## 환경

현재 Mac(Apple Silicon)에서 2026-11-20에 확인한 상태다.

- C 컴파일러(Apple clang 21)와 LLDB는 설치돼 있다. 추가 설치 없이 시작할 수 있다.

## 49 cat

원본: [README → Operating Systems](../README.md#operating-systems)

* [Rewrite cat](https://learnto.computer/screencasts/bsd-cat) `video`

> **원문 메모**
>
> 원문 사이트 `learnto.computer`는 사라졌다(DNS 조회 안 됨). 보존본: [bsd-cat](http://web.archive.org/web/20200414231251/https://learnto.computer/screencasts/bsd-cat) — 영상 파일까지 응답하는 것을 확인했다.
>
> 아래 회차는 영상을 보지 않고 `cat`의 동작 기준으로 쓴 것이다. 첫 회차에 영상 범위와 대조하고 다르면 줄을 고친다.

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

> **원문 메모**
>
> 원문 사이트가 사라졌다. 보존본: [mkdir](http://web.archive.org/web/20191115152104/https://learnto.computer/screencasts/bsd-mkdir) · [mkdir -p](http://web.archive.org/web/20191115162257/https://learnto.computer/screencasts/bsd-mkdir-p) — 페이지는 남아 있고 영상 재생은 확인하지 못했다.
>
> 영상이 재생되지 않으면 FreeBSD `bin/mkdir/mkdir.c`를 읽으며 같은 회차를 진행하고, 그 사실을 작업 폴더에 적는다.

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

> **원문 메모**
>
> 원문은 6개 절(Introduction · Hash table structure · Hash functions · Handling collisions · Hash table methods · Resizing tables)과 부록 1개다. 개방 주소법 + 이중 해싱 구현이며, 원문은 전체를 1~2시간 분량이라고 적고 있다. 검증까지 넣어 5회차로 잡았다.

### Daily TODO

- [ ] `72.01` 1~2절: 항목·테이블 구조체와 생성/해제 함수를 만든다. 빈 테이블을 만들고 지운 뒤 sanitizer에 누수가 없는지 확인한다.
- [ ] `72.02` 3절: 해시 함수를 구현한다. 같은 문자열은 같은 값, 버킷 수를 넘지 않는 값이 나오는지 고정 입력으로 확인한다.
- [ ] `72.03` 4~5절: 이중 해싱으로 삽입·조회를 구현한다. 첫 해시가 같은 두 키를 만들어 둘 다 찾고, 없는 키와 구분한다.
- [ ] `72.04` 5절: 삭제(삭제 표시 항목)와 같은 키 갱신을 구현한다. 삭제 뒤에도 충돌했던 다른 키가 조회되는지 확인한다.
- [ ] `72.05` 6절: 적재율에 따라 크기를 늘리고 줄인다. 수백 키를 넣고 뺀 뒤 값과 해제 경로를 sanitizer로 확인한다. 부록(다른 충돌 처리)은 읽고 차이를 한 줄 적는다.
## 22 hangman

원본: [README → Game Development](../README.md#game-development)

* [Hangman](https://www.youtube.com/playlist?list=PLZ1QII7yudbd2ZHYSEWrSddsvD5PW_r5O) `video`

> **원문 메모**
>
> 재생목록은 5편, 총 50분이다(Hangman Game 1~4 + 「Read in hangman words from a file」).

### Daily TODO

- [ ] `22.01` 1~2편(15분): 비밀 단어와 가려진 글자판을 출력한다. 같은 글자가 두 번 있는 단어를 쓴다.
- [ ] `22.02` 3~4편(22분): 한 글자 입력으로 모든 일치 위치를 공개한다. 정답과 기회 소진을 각각 고정 입력으로 확인하고, 중복 추측은 기회를 잃지 않게 한다.
- [ ] `22.03` 5편(14분): 단어 목록을 파일에서 읽는다. 없는 파일과 빈 파일의 처리를 확인한다.
## 31 tic-tac-toe-cli

원본: [README → Game Development](../README.md#game-development)

* [Simple Tic Tac Toe in C](https://www.youtube.com/playlist?list=PLZ1QII7yudbc7_ZgXA-gIXmME41Rs2GP5) `video`

> **원문 메모**
>
> 재생목록은 9편, 총 80분이다(#1~#6 Playable Game, #7~#8 Adding AI, #9 Proper AI).

### Daily TODO

- [ ] `31.01` 1~3편(21분): 3×3판 출력과 번갈아 놓기를 구현한다. 범위 밖과 이미 찬 칸은 턴을 넘기지 않는다.
- [ ] `31.02` 4~6편(27분): 승리·무승부 판정을 붙여 끝까지 둘 수 있게 한다. 가로·세로·대각선·무승부를 입력 시퀀스로 확인한다.
- [ ] `31.03` 7~8편(14분): 컴퓨터 상대를 추가한다. 컴퓨터가 빈 칸에만 두고, 판이 차면 멈추는지 확인한다.
- [ ] `31.04` 9편(18분): 개선된 AI를 붙인다. 한 수로 이길 수 있는 판과 한 수로 막아야 하는 판에서 컴퓨터의 수를 확인한다.
## 16 sudoku

원본: [README → Game Development](../README.md#game-development)

* [Coding A Sudoku Solver in C](https://www.youtube.com/playlist?list=PLkTXsX7igf8edTYU92nU-f5Ntzuf-RKvW) `video`

> **원문 메모**
>
> 재생목록은 8편이다. 편별 제목과 길이는 확인하지 못했다. 첫 회차에 길이를 보고 3회차로 부족하면 줄을 추가한다.

### Daily TODO

- [ ] `16.01` 9×9 퍼즐을 읽고 행·열·박스 충돌을 각각 검증한다.
- [ ] `16.02` 빈 칸에 후보 숫자를 넣고 불가능하면 되돌린다. 고정 퍼즐의 해답을 비교한다.
- [ ] `16.03` 초기 충돌과 해답 없는 퍼즐을 구분하고, 실패 후 원래 판이 유지되는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 24 text-adventure

원본: [README → Game Development](../README.md#game-development)

* [How to Program a Text Adventure in C](https://helderman.github.io/htpataic/htpataic01.html) `in-progress`

> **원문 메모**
>
> 원문은 25개 장이다(1 Introduction ~ 25 Speech). 기존 4회차는 6장 정도까지만 다루고 있었다. 장마다 코드가 조금씩 늘어나는 구성이라 1~2장을 1회차로 잡았다.
>
> 21~25장은 소켓·WebSocket·데이터베이스·음성을 다룬다. 04 묶음보다 먼저 나오지만 원문 순서대로 여기서 끝낸다.

### Daily TODO

- [ ] `24.01` 1~2장 The main loop: 입력을 읽고 응답하는 루프를 만든다. `quit`과 EOF로 정상 종료하는지 확인한다.
- [ ] `24.02` 3장 Locations: 장소 두 개와 `look`·`go`를 만든다. 왕복 이동과 없는 장소로의 이동을 확인한다.
- [ ] `24.03` 4장 Objects: 장소와 물건을 하나의 객체 표로 합친다. 현재 장소에 있는 물건만 보이는지 확인한다.
- [ ] `24.04` 5장 Inventory: 줍기·내려놓기·소지품 보기를 만든다. 같은 물건이 두 곳에 동시에 남지 않는지 확인한다.
- [ ] `24.05` 6장 Passages: 장소 사이의 통로를 객체로 만든다. 통로가 없는 방향으로는 이동하지 못하는지 확인한다.
- [ ] `24.06` 7장 Distance: 대상과의 거리 판정을 넣는다. 손에 든 것·같은 방·다른 방의 물건에 대한 응답이 다른지 확인한다.
- [ ] `24.07` 8장 North, east, south, west: 방위 이동을 붙인다. 네 방향과 막힌 방향을 한 번씩 재생한다.
- [ ] `24.08` 9장 Code generation: 객체 정의를 생성 스크립트로 옮긴다. 생성한 코드로 빌드해 앞 회차의 입력 시퀀스가 같은 출력을 내는지 확인한다.
- [ ] `24.09` 10~11장 More attributes · Conditions: 속성과 조건을 추가한다. 조건이 맞을 때와 아닐 때 통로의 응답이 달라지는지 확인한다.
- [ ] `24.10` 12장 Open and close: 열고 닫는 대상을 추가한다. 닫힌 상태에서 실패하고 연 뒤 성공하는 경로를 둘 다 재생한다.
- [ ] `24.11` 13장 The parser: 패턴 기반 파서로 바꾼다. 기존 명령이 그대로 동작하고 알 수 없는 문장은 거르는지 확인한다.
- [ ] `24.12` 14장 Multiple nouns: 명사가 둘인 명령을 처리한다. 두 번째 명사가 없거나 잘못된 경우의 응답을 확인한다.
- [ ] `24.13` 15장 Light and dark: 빛과 어둠을 넣는다. 어두운 곳에서 보이지 않던 것이 조명이 있으면 보이는지 확인한다.
- [ ] `24.14` 16~17장 Savegame · Test automation: 진행 상태를 저장하고 새 프로세스에서 불러와 위치와 소지품이 같은지 확인한다. 원문의 자동 테스트를 돌려 통과를 기록한다.
- [ ] `24.15` 18~19장 Abbreviations · Conversations: 줄임 명령과 대화를 추가한다. 줄임말과 원래 명령이 같은 결과를 내는지 확인한다.
- [ ] `24.16` 20장 Combat: 전투를 추가한다. 난수 seed를 고정해 승리와 패배 경로를 각각 재생한다.
- [ ] `24.17` 21장 Multi-player: 플레이어를 여러 명으로 늘린다. 한 플레이어의 줍기가 다른 플레이어 화면에 반영되는지 확인한다.
- [ ] `24.18` 22장 Client-server: 서버와 클라이언트로 나눈다. loopback에서 클라이언트 둘을 붙이고 하나가 끊겨도 서버가 살아 있는지 확인한다.
- [ ] `24.19` 23장 WebSockets: WebSocket 접속을 붙인다. 브라우저 또는 테스트 클라이언트로 명령 하나를 왕복한다.
- [ ] `24.20` 24장 Database: 상태를 데이터베이스에 둔다. 서버를 재시작한 뒤 상태가 유지되는지 확인한다.
- [ ] `24.21` 25장 Speech: 음성 장을 원문 환경에서 실행한다. 환경이 맞지 않으면 막힌 이유와 재개 조건을 기록하고 체크하지 않는다.
