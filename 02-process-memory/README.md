# 02. 프로세스와 메모리

셸이 프로세스·파일 디스크립터를 다루는 방식과 할당기의 블록 모델을 배운다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

| 원본 번호 | 순서 · 작업 폴더 |
|---|---|
| 53 | [`shell-brennan/`](#53-shell-brennan) |
| 43 | [`shell-workshop/`](#43-shell-workshop) |
| 57 | [`shell-danish/`](#57-shell-danish) |
| 58 | [`unix-shell-series/`](#58-unix-shell-series) |
| 37 | [`shell-tokenrove/`](#37-shell-tokenrove) |
| 39 | [`virtual-memory/`](#39-virtual-memory) |
| 44 | [`malloc-danluu/`](#44-malloc-danluu) |
| 54 | [`malloc-arjun/`](#54-malloc-arjun) |

## 53 shell-brennan

원본: [README → Operating Systems](../README.md#operating-systems)

* [Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)

### Daily TODO

- [ ] `53.01` 한 줄을 읽고 인자를 분리한다. 빈 줄과 여러 공백을 확인한다.
- [ ] `53.02` `fork`·`execvp`·`waitpid`를 연결한다. 존재하는 명령과 없는 명령을 실행한다.
- [ ] `53.03` `cd`와 `exit`를 부모에서 처리한다. 디렉토리가 다음 명령에도 유지되는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 43 shell-workshop

원본: [README → Operating Systems](../README.md#operating-systems)

* [Let's build a shell!](https://github.com/kamalmarhubi/shell-workshop)

### Daily TODO

- [ ] `43.01` 워크숍 예제에서 부모·자식 PID와 반환값을 관찰한다.
- [ ] `43.02` 자식 종료 상태와 `exec` 실패를 구분한다. 성공·일반 실패·실행 불가로 확인한다.
- [ ] `43.03` 파일 디스크립터 복제 예제를 연결하고 부모 쪽 표준 출력이 유지되는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 57 shell-danish

원본: [README → Operating Systems](../README.md#operating-systems)

* [Writing a shell in C](https://danishprakash.github.io/2018/01/15/write-a-shell.html)

### Daily TODO

- [ ] `57.01` 리다이렉션 토큰을 실행 인자에서 분리한다. 파일 이름 누락을 거른다.
- [ ] `57.02` 입력과 출력을 파일에 연결하고 복사 결과를 바이트 비교한다.
- [ ] `57.03` 파이프로 두 명령을 연결하고 양 끝을 닫아 읽는 쪽이 EOF를 받는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 58 unix-shell-series

원본: [README → Operating Systems](../README.md#operating-systems)

* Writing a Unix Shell
  * [Part 1](https://indradhanush.github.io/blog/writing-a-unix-shell-part-1)
  * [Part 2](https://indradhanush.github.io/blog/writing-a-unix-shell-part-2)
  * [Part 3](https://indradhanush.github.io/blog/writing-a-unix-shell-part-3)

### Daily TODO

- [ ] `58.01` 1편의 기동·명령 실행 흐름을 구현하고 인자 전달을 확인한다.
- [ ] `58.02` 2편에서 추가한 기능을 별도 입력 사례로 확인하고 1편 동작을 다시 실행한다.
- [ ] `58.03` 3편의 기능을 연결하고 마지막 예제 실행 결과와 이전 셸과의 차이를 기록한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 37 shell-tokenrove

원본: [README → Operating Systems](../README.md#operating-systems)

* [Build Your Own Shell](https://github.com/tokenrove/build-your-own-shell)

### Daily TODO

- [ ] `37.01` 과제 목록을 쪼개고 명령 하나와 인용 인자 하나를 해석한다.
- [ ] `37.02` 파이프·리다이렉션을 결합하고 빈 출력과 EOF를 확인한다.
- [ ] `37.03` 포그라운드 작업의 프로세스 그룹을 관찰하고 Ctrl-C 후 프롬프트가 살아 있는지 확인한다.
- [ ] `37.04` 백그라운드 작업이 프롬프트를 막지 않고 종료된 자식이 회수되는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 39 virtual-memory

원본: [README → Operating Systems](../README.md#operating-systems)

* [Hack the Virtual Memory](https://blog.holbertonschool.com/hack-virtual-memory-stack-registers-assembly-code/)

### Daily TODO

- [ ] `39.01` 본인 샘플의 코드·전역·스택·힙 주소를 출력해 메모리 지도와 대조한다.
- [ ] `39.02` 스택 프레임을 LLDB에서 관찰하고 같은 함수의 연속 호출이 다른 프레임을 만드는지 확인한다.
- [ ] `39.03` 샘플의 주소가 재실행 시 달라지는지 기록하고, 오프셋과 절대 주소를 구분한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 44 malloc-danluu

원본: [README → Operating Systems](../README.md#operating-systems)

* [Let's Write a Malloc](https://danluu.com/malloc-tutorial/)

### Daily TODO

- [ ] `44.01` 할당 블록 메타데이터를 만들고 두 요청이 겹치지 않는지 확인한다.
- [ ] `44.02` 해제한 블록을 다음 요청에 재사용한다. 부족한 크기는 재사용하지 않는지 확인한다.
- [ ] `44.03` `calloc`의 0 초기화와 `realloc`의 기존 내용 보존을 작은 프로그램으로 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 54 malloc-arjun

원본: [README → Operating Systems](../README.md#operating-systems)

* [Write a Simple Memory Allocator](https://arjunsreedharan.org/post/148675821737/write-a-simple-memory-allocator)

### Daily TODO

- [ ] `54.01` 블록 헤더를 연결 리스트로 묶는다. 연속 할당에서 필요한 정렬을 확인한다.
- [ ] `54.02` 해제·재할당에서 빈 블록을 재사용하는 경로와 새 블록을 얻는 경로를 각각 확인한다.
- [ ] `54.03` 소스의 동기화·확장 정책을 재현하고 정상 해제와 마지막 블록 해제의 차이를 기록한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
