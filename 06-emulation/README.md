# 06. VM·에뮬레이터·콘솔

명령어 해석·메모리 맵·입출력 타이밍을 작은 CPU부터 익힌다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

아래 모든 항목을 진행한다. 전체 학습 순서는 [로드맵](../ROADMAP.md)을 따른다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

회차는 2026-11-20에 원문 목차와 재생 시간을 대조해 나눴다. 항목마다 `원문 메모`에 근거와 확인하지 못한 부분을 적었다. 영상 항목은 제목과 길이만 보고 나눈 것이라, 실제 내용과 다르면 그날 줄을 고친다.

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

## 환경

현재 Mac(Apple Silicon)에서 2026-11-20에 확인한 상태다.

- 03·06·04·02·05는 macOS에서 할 수 있다(화면 출력에는 SDL2가 필요하다).
- 23은 cc65, 26은 GBDK, 35는 GBA 툴체인과 각 콘솔의 에뮬레이터가 필요하다. 모두 지금 설치돼 있지 않다.

## 03 simple-vm

원본: [README → Computer Architecture](../README.md#computer-architecture)

* [Implementing a Virtual Machine in C](https://felixangell.com/blog/virtual-machine-in-c)

> **원문 메모**
>
> 원문 주소는 404다. 보존본: [2018-06](http://web.archive.org/web/20180620201942/https://felixangell.com/blog/virtual-machine-in-c/). 본문 내용은 대조하지 못했다. 원문에 조건 분기가 없으면 `03.03`은 직접 추가하는 실험으로 적는다.

### Daily TODO

- [ ] `03.01` 레지스터·프로그램 카운터와 명령어 읽기 루프를 작성하고 종료 명령을 실행한다.
- [ ] `03.02` 산술과 스택 동작을 구현한다. 작은 수식의 결과를 확인한다.
- [ ] `03.03` 조건 분기와 잘못된 opcode 처리를 넣고 미니 프로그램을 실행한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 06 lc3

원본: [README → Computer Architecture](../README.md#computer-architecture)

* [Write your Own Virtual Machine](https://justinmeiners.github.io/lc3-vm/)

> **원문 메모**
>
> 원문 구성: LC-3 architecture(Memory · Registers · Instruction set · Condition flags) · Assembly examples · Executing programs · Implementing instructions(ADD, LDI와 나머지 명령) · Trap routines · Loading programs · Memory mapped registers · Platform specifics. 원문 순서에 맞게 회차 순서를 바꿨다.

### Daily TODO

- [ ] `06.01` 메모리·레지스터·조건 플래그와 실행 루프를 만들고 ADD·AND·NOT을 구현한다. 부호 확장과 플래그 갱신을 작은 명령어 벡터로 확인한다.
- [ ] `06.02` 적재·저장 계열(LD·LDI·LDR·LEA·ST·STI·STR)과 분기·점프(BR·JMP·JSR)를 구현한다. 루프가 예상 횟수에 끝나는지 확인한다.
- [ ] `06.03` TRAP 루틴과 이미지 로더를 만든다. 빅 엔디언 이미지의 시작 주소와 첫 워드가 맞게 읽히는지 확인한다.
- [ ] `06.04` 메모리 맵 레지스터(키보드 상태·데이터)와 터미널 입력 설정을 붙인다. 원문이 제공하는 샘플 프로그램 하나를 끝까지 실행한다.
## 04 chip8

원본: [README → Computer Architecture](../README.md#computer-architecture)

* Writing a Chip 8 Emulator `in-progress`
  * [Part 1](http://craigthomas.ca/blog/2014/06/21/writing-a-chip-8-emulator-part-1/)
  * [Part 2](http://craigthomas.ca/blog/2014/07/17/writing-a-chip-8-emulator-part-2/)
  * [Part 3](http://craigthomas.ca/blog/2015/02/19/writing-a-chip-8-emulator-draw-command-part-3/)
  * [Part 4](http://craigthomas.ca/blog/2017/10/15/writing-a-chip-8-emulator-built-in-font-set-part-4/)
  * [Part 5](http://craigthomas.ca/blog/2018/09/07/writing-a-chip-8-emulator-instruction-set-part-5/)

> **원문 메모**
>
> 원문 주소 5편이 모두 404다. 보존본: [1편](http://web.archive.org/web/20250427051212/http://craigthomas.ca/blog/2014/06/21/writing-a-chip-8-emulator-part-1/) · [2편](http://web.archive.org/web/20260111044638/http://craigthomas.ca/blog/2014/07/17/writing-a-chip-8-emulator-part-2/) · [3편](http://web.archive.org/web/20260530005204/https://craigthomas.ca/blog/2015/02/19/writing-a-chip-8-emulator-draw-command-part-3/) · [4편](http://web.archive.org/web/20260530005151/https://craigthomas.ca/blog/2017/10/15/writing-a-chip-8-emulator-built-in-font-set-part-4/) · [5편](http://web.archive.org/web/20260101061125/https://craigthomas.ca/blog/2018/09/07/writing-a-chip-8-emulator-instruction-set-part-5/). 본문 내용은 대조하지 못했다.

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

> **원문 메모**
>
> 자동 요청에는 403으로 응답한다. 보존본: [2024-12](http://web.archive.org/web/20241202111422/https://emulator101.com/). 목차를 확인하지 못했다.
>
> 기억으로는 8080 디스어셈블러·에뮬레이터, Space Invaders 기계 부분 외에 CHIP-8과 6502 절도 있는 큰 사이트다(미확인). 첫 회차에 목차를 옮겨 적고 회차를 다시 나눈다. 5회차로는 부족할 가능성이 높다.

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

> **원문 메모**
>
> 원문은 구현 회고 글이다(Memory · Registers · Flags · Implementing the CPU · Real time debugging · Tilesets · Maps · Sprites …). 단계별 코드는 저자의 소스를 함께 본다.

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

> **원문 메모**
>
> 원문은 평일 매일 진행된 라이브 스트림 연재다(계획상 약 6개월 분량: 언어·컴파일러 → 하드웨어 설계 → OS). 전체 편수를 확인하지 못했다.
>
> **정해야 할 것:** Handmade Hero와 같은 종류의 긴 연재다. 첫 회차에 기준 리비전과 그때까지 공개된 마지막 편을 기록하고 공개분 전체를 진행한다. 그 뒤에는 편 제목을 옮겨 1편 1회차로 줄을 추가한다.

### Daily TODO

- [ ] `01.01` 영상과 소스의 기준 시점을 기록한다. 첫 실습을 빌드하고 입력 하나를 확인한다.
- [ ] `01.02` 저수준 표현 예제 하나를 직접 작성한다. 정상값과 경계값 결과를 비교한다.
- [ ] `01.03` 강의 소스의 작은 구성 요소 하나를 입력·출력·실패 조건으로 분리해 재현한다.
- [ ] `01.04` 남은 영상은 에피소드별로 실습 출력을 붙여 일일 계획을 확장한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 23 nes-game

원본: [README → Game Development](../README.md#game-development)

* [How to Program an NES game in C](https://nesdoug.com/)

> **원문 메모**
>
> 원문은 준비 글 3편(Introduction · What you need · How cc65 works)과 강의 01~24, 부록으로 되어 있다. 기존 3회차를 강의 제목 기준으로 다시 나눴다. cc65와 NES 에뮬레이터가 필요하다(cc65는 지금 설치돼 있지 않다).

### Daily TODO

- [ ] `23.01` 준비 글 3편과 01 Our first program: cc65를 설치하고 최소 ROM을 만들어 에뮬레이터에서 화면을 띄운다.
- [ ] `23.02` 02 What's a v-blank? · 03 VRAM buffer: v-blank 동안 화면을 갱신한다. 글자가 깨지지 않고 바뀌는지 확인한다.
- [ ] `23.03` 04 Full Background · 05 Palettes: 전체 배경과 팔레트를 올린다. 팔레트를 바꿔 색이 달라지는지 확인한다.
- [ ] `23.04` 06 Sprites: 스프라이트를 표시한다. 여러 개를 띄워 위치를 확인한다.
- [ ] `23.05` 07 Controllers (and sprite collisions): 컨트롤러로 스프라이트를 움직이고 스프라이트끼리의 충돌을 판정한다.
- [ ] `23.06` 08 BG collisions: 배경과의 충돌을 만든다. 벽 모서리에서 통과하지 않는지 확인한다.
- [ ] `23.07` 09 Scrolling · 10 Game loop: 스크롤과 게임 루프를 만든다. 프레임마다 한 번만 갱신되는지 확인한다.
- [ ] `23.08` 11 Metatiles: 메타타일로 맵을 구성한다. 맵 데이터를 바꿔 화면이 따라 바뀌는지 확인한다.
- [ ] `23.09` 12 Scrolling right · 13 Scrolling up: 방향별 스크롤을 만든다. 화면 경계에서 타일이 맞게 이어지는지 확인한다.
- [ ] `23.10` 14 Platformer: 점프와 중력을 넣는다. 발판 위 착지와 낙하를 확인한다.
- [ ] `23.11` 15 Music · 16 Sound effects · 17 DPCM Sound: 음악과 효과음을 재생한다. 효과음이 음악을 끊지 않는지 듣고 확인한다.
- [ ] `23.12` 18 Sprite Zero: 스프라이트 0 히트로 화면을 나눈다. 고정 영역과 스크롤 영역이 분리되는지 확인한다.
- [ ] `23.13` 19 More things, mappers: 매퍼를 사용한다. 빌드한 ROM의 헤더에서 매퍼 번호를 확인한다.
- [ ] `23.14` 20 Platformer Again · 21 Finished Platformer: 플랫포머를 완성한다. 시작부터 종료까지 한 번 플레이한다.
- [ ] `23.15` 22 Zapper / Power Pad: 에뮬레이터가 지원하는 범위에서 실행한다. 지원하지 않으면 막힌 이유를 기록하고 체크하지 않는다.
- [ ] `23.16` 23 Advanced Mapper – MMC1 · 24 Advanced Mapper – MMC3: 뱅크 전환을 사용한다. 다른 뱅크의 코드나 데이터가 불리는지 확인한다.
## 26 gameboy-game

원본: [README → Game Development](../README.md#game-development)

* [Learn How To Develop Your Own GameBoy Games](https://www.youtube.com/playlist?list=PLeEj4c2zF7PaFv5MPYhNAkBGrkx4iPGJo) `video` `in-progress`

> **원문 메모**
>
> 재생목록은 22편, 총 338분이다. 편 제목: Hello World · Sprites · Joypad · Backgrounds · Heads Up Display · Sound · Noise · Jumping · Meta-Sprites · Sprite Collision Detection · Background Collision Detection · Splashscreens · Fade Effects · Keyboard · Save Games · Color Sprites · Color Backgrounds · composing your music · playing your music · sprite flipping & priority · Parallax Effects · NEW GBDK 2020.
>
> 22편이 새 도구(GBDK 2020)로의 전환을 다루므로 첫 회차에 22편을 먼저 보고 도구를 정한다.
>
> 영상 회차의 공통 확인: 그 구간 끝까지의 코드를 빌드·실행하고, 그날 새로 생긴 동작 하나를 다시 재현할 수 있는 입력이나 조작 순서와 함께 작업 폴더에 적는다.

### Daily TODO

- [ ] `26.01` 22편을 먼저 보고 도구를 설치한 뒤 1~2편(Hello World · Sprites, 26분): ROM을 만들어 에뮬레이터에서 스프라이트를 띄운다.
- [ ] `26.02` 3~4편(Joypad · Backgrounds, 20분): 방향키로 스프라이트를 움직이고 배경을 깐다.
- [ ] `26.03` 5~7편(Heads Up Display · Sound · Noise, 35분): 윈도 레이어로 HUD를 띄우고 효과음을 낸다.
- [ ] `26.04` 8편(Jumping, 24분): 점프와 중력을 만든다. 착지 뒤 다시 점프할 수 있는지 확인한다.
- [ ] `26.05` 9~10편(Meta-Sprites · Sprite Collision Detection, 31분): 여러 타일로 된 캐릭터와 스프라이트 충돌을 만든다.
- [ ] `26.06` 11편(Background Collision Detection, 33분): 배경 타일과의 충돌을 만든다. 벽을 통과하지 않는지 확인한다.
- [ ] `26.07` 12~13편(Splashscreens · Fade Effects, 25분): 시작 화면과 페이드를 만든다.
- [ ] `26.08` 14편(Keyboard, 27분): 화면 키보드로 이름을 입력한다. 최대 길이와 지우기를 확인한다.
- [ ] `26.09` 15~17편(Save Games · Color Sprites · Color Backgrounds, 37분): 저장과 컬러를 붙인다. 에뮬레이터를 껐다 켠 뒤 저장 값이 남는지 확인한다.
- [ ] `26.10` 18편(composing your music, 33분): 음악 데이터를 만든다.
- [ ] `26.11` 19~21편(playing your music · sprite flipping & priority · Parallax Effects, 33분): 음악 재생, 스프라이트 반전, 패럴랙스를 붙인다.
- [ ] `26.12` 지금까지 만든 요소로 시작 화면부터 종료까지 이어지는 ROM 하나를 만들어 한 번 플레이한다.
## 35 gba-game

원본: [README → Game Development](../README.md#game-development)

* [Writing a Game Boy Advance Game](https://www.reinterpretcast.com/writing-a-game-boy-advance-game)

> **원문 메모**
>
> 원문은 글 한 편이다(Setting Up A Development Environment · Writing a pong-esque game). GBA 툴체인과 에뮬레이터가 필요하다.

### Daily TODO

- [ ] `35.01` 최소 ROM에서 화면 모드를 설정하고 색을 출력한다.
- [ ] `35.02` 스프라이트·입력으로 간단한 캐릭터를 움직인다. 화면 경계를 확인한다.
- [ ] `35.03` VBlank 동기화와 충돌을 붙이고 게임 시작·종료를 재현한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
