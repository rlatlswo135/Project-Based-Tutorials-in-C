# 06. VM·에뮬레이터·콘솔

명령어 해석·메모리 맵·입출력 타이밍을 작은 CPU부터 익힌다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

| 원본 번호 | 순서 · 작업 폴더 |
|---|---|
| 03 | [`simple-vm/`](#03-simple-vm) |
| 06 | [`lc3/`](#06-lc3) |
| 04 | [`chip8/`](#04-chip8) |
| 02 | [`emulator-101/`](#02-emulator-101) |
| 05 | [`gameboy-emulator/`](#05-gameboy-emulator) |
| 01 | [`bitwise/`](#01-bitwise) |
| 23 | [`nes-game/`](#23-nes-game) |
| 26 | [`gameboy-game/`](#26-gameboy-game) |
| 35 | [`gba-game/`](#35-gba-game) |

## 03 simple-vm

원본: [README → Computer Architecture](../README.md#computer-architecture)

* [Implementing a Virtual Machine in C](https://felixangell.com/blog/virtual-machine-in-c)

### Daily TODO

- [ ] `03.01` 레지스터·프로그램 카운터와 명령어 읽기 루프를 작성하고 종료 명령을 실행한다.
- [ ] `03.02` 산술과 스택 동작을 구현한다. 작은 수식의 결과를 확인한다.
- [ ] `03.03` 조건 분기와 잘못된 opcode 처리를 넣고 미니 프로그램을 실행한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 06 lc3

원본: [README → Computer Architecture](../README.md#computer-architecture)

* [Write your Own Virtual Machine](https://justinmeiners.github.io/lc3-vm/)

### Daily TODO

- [ ] `06.01` 16비트 워드 로더를 구현한다. 엔디언이 다른 이미지의 시작 주소를 확인한다.
- [ ] `06.02` ADD·AND·NOT, 부호 확장, 조건 플래그를 작은 명령어 벡터로 검증한다.
- [ ] `06.03` LD·ST와 BR을 연결한다. 루프가 예상 횟수에 종료되는지 확인한다.
- [ ] `06.04` TRAP 입출력을 연결하고 원문 샘플 프로그램 하나를 끝까지 실행한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 04 chip8

원본: [README → Computer Architecture](../README.md#computer-architecture)

* Writing a Chip 8 Emulator `in-progress`
  * [Part 1](http://craigthomas.ca/blog/2014/06/21/writing-a-chip-8-emulator-part-1/)
  * [Part 2](http://craigthomas.ca/blog/2014/07/17/writing-a-chip-8-emulator-part-2/)
  * [Part 3](http://craigthomas.ca/blog/2015/02/19/writing-a-chip-8-emulator-draw-command-part-3/)
  * [Part 4](http://craigthomas.ca/blog/2017/10/15/writing-a-chip-8-emulator-built-in-font-set-part-4/)
  * [Part 5](http://craigthomas.ca/blog/2018/09/07/writing-a-chip-8-emulator-instruction-set-part-5/)

### Daily TODO

- [ ] `04.01` 1편: 레지스터·RAM·스택과 ROM 적재를 구현하고 진입 주소를 확인한다.
- [ ] `04.02` 2편: opcode 디코딩과 프로그램 카운터를 검증한다.
- [ ] `04.03` 3편: draw에서 스프라이트 XOR와 충돌 플래그를 확인한다.
- [ ] `04.04` 4편: 글꼴 스프라이트와 주소를 연결하고 한 글자를 표시한다.
- [ ] `04.05` 5편: 분기·산술 opcode를 작은 벡터로 검증한다.
- [ ] `04.06` 5편: 키 입력과 타이머를 처리하고 배포가 허용된 테스트 ROM을 실행한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 02 emulator-101

원본: [README → Computer Architecture](../README.md#computer-architecture)

* [Emulator 101](http://emulator101.com/)

### Daily TODO

- [ ] `02.01` 8080 명령어 테이블로 바이트 몇 개를 디스어셈블한다.
- [ ] `02.02` 레지스터·메모리·플래그를 구현해 ADD와 JUMP를 단위 확인한다.
- [ ] `02.03` CALL/RET와 스택을 연결한다. 왕복 뒤 SP와 PC를 비교한다.
- [ ] `02.04` I/O 포트와 인터럽트 타이밍을 연결한다. 고정 주기에서 이벤트 수를 확인한다.
- [ ] `02.05` 영상 출력을 구현하고 공개 테스트 ROM으로 화면·사이클 동작을 검증한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 05 gameboy-emulator

원본: [README → Computer Architecture](../README.md#computer-architecture)

* [Writing a Game Boy emulator](https://cturt.github.io/cinoop.html)

### Daily TODO

- [ ] `05.01` 카트리지 헤더와 메모리 맵을 읽고 고정 ROM을 적재한다.
- [ ] `05.02` 기초 명령과 플래그를 디코더에 연결하고 테스트 벡터를 실행한다.
- [ ] `05.03` 타이머·인터럽트를 연결한다. 간단한 ROM에서 인터럽트 순서를 관찰한다.
- [ ] `05.04` 배경 타일을 렌더한다. 프레임의 위치와 팔레트를 고정 샘플과 비교한다.
- [ ] `05.05` 입력과 스프라이트를 연결한다. 공개 테스트 ROM의 결과를 남긴다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 01 bitwise

원본: [README → Computer Architecture](../README.md#computer-architecture)

* [Bitwise](https://github.com/pervognsen/bitwise) `video` `in-progress`

### Daily TODO

- [ ] `01.01` 영상과 소스의 기준 시점을 기록한다. 첫 실습을 빌드하고 입력 하나를 확인한다.
- [ ] `01.02` 저수준 표현 예제 하나를 직접 작성한다. 정상값과 경계값 결과를 비교한다.
- [ ] `01.03` 강의 소스의 작은 구성 요소 하나를 입력·출력·실패 조건으로 분리해 재현한다.
- [ ] `01.04` 남은 영상은 에피소드별로 실습 출력을 붙여 일일 계획을 확장한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 23 nes-game

원본: [README → Game Development](../README.md#game-development)

* [How to Program an NES game in C](https://nesdoug.com/)

### Daily TODO

- [ ] `23.01` cc65 등 원문의 환경에서 최소 ROM을 만들고 에뮬레이터에서 화면을 띄운다.
- [ ] `23.02` 스프라이트와 컨트롤러 입력을 연결한다. 한 프레임의 이동을 확인한다.
- [ ] `23.03` 타일 충돌·스크롤·레벨 전환을 한 동작씩 붙이고 정상 ROM을 실행한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 26 gameboy-game

원본: [README → Game Development](../README.md#game-development)

* [Learn How To Develop Your Own GameBoy Games](https://www.youtube.com/playlist?list=PLeEj4c2zF7PaFv5MPYhNAkBGrkx4iPGJo) `video` `in-progress`

### Daily TODO

- [ ] `26.01` 원문 도구로 ROM을 만들고 에뮬레이터에서 첫 화면을 확인한다.
- [ ] `26.02` 타일·스프라이트와 키 입력을 붙여 방향별 이동을 확인한다.
- [ ] `26.03` VBlank 중 그래픽 갱신을 처리하고 점수·실패 화면을 검증한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 35 gba-game

원본: [README → Game Development](../README.md#game-development)

* [Writing a Game Boy Advance Game](https://www.reinterpretcast.com/writing-a-game-boy-advance-game)

### Daily TODO

- [ ] `35.01` 최소 ROM에서 화면 모드를 설정하고 색을 출력한다.
- [ ] `35.02` 스프라이트·입력으로 간단한 캐릭터를 움직인다. 화면 경계를 확인한다.
- [ ] `35.03` VBlank 동기화와 충돌을 붙이고 게임 시작·종료를 재현한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
