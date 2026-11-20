# 02. 프로세스와 메모리

셸이 프로세스·파일 디스크립터를 다루는 방식과 할당기의 블록 모델을 배운다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

회차는 2026-11-20에 원문 목차와 재생 시간을 대조해 나눴다. 항목마다 `원문 메모`에 근거와 확인하지 못한 부분을 적었다. 영상 항목은 제목과 길이만 보고 나눈 것이라, 실제 내용과 다르면 그날 줄을 고친다.

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

## 환경

현재 Mac(Apple Silicon)에서 2026-11-20에 확인한 상태다.

- 셸 5개(53·43·57·58·37)는 macOS에서 할 수 있다. 43의 시스템 콜 추적만 Linux 컨테이너에서 한다.
- 39·44·54는 Linux가 필요하다(x86-64 어셈블리, `sbrk`). Docker(28.5, arm64)는 설치돼 있다. 39는 `docker run --platform linux/amd64`로 x86-64 컨테이너를 쓴다. 에뮬레이션에서는 gdb가 동작하지 않을 수 있어 `objdump`와 출력으로 확인한다.

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

> **원문 메모**
>
> 원문 구성: 0 Getting started · 1 Name your shell and read input · 2 System calls · 3 Running a program · 4 Forking a new process · 5 Waiting for children · 5 Builtins · 6 Pipelines · 7 What next?
>
> 2절의 시스템 콜 추적은 Linux `strace` 기준이다. macOS에서는 Linux 컨테이너에서 한다.

### Daily TODO

- [ ] `43.01` 0~2절: 프롬프트를 출력하고 한 줄을 읽는다. Linux 컨테이너에서 `strace`로 자신의 셸이 부르는 `read`·`write`를 확인한다.
- [ ] `43.02` 3~5절: `exec`·`fork`·`wait`를 차례로 붙인다. `exec`만 했을 때 셸이 사라지는 것과 `fork` 뒤에는 프롬프트가 돌아오는 것을 비교한다.
- [ ] `43.03` 5절 Builtins: `cd`와 `exit`를 셸 프로세스 안에서 처리한다. `cd` 결과가 다음 명령에도 유지되는지 확인한다.
- [ ] `43.04` 6절 Pipelines: 두 명령을 파이프로 잇는다. 양 끝을 닫아 읽는 쪽이 EOF를 받고 끝나는지 확인한다. 7절은 읽고 다음에 볼 것을 적는다.
## 57 shell-danish

원본: [README → Operating Systems](../README.md#operating-systems)

* [Writing a shell in C](https://danishprakash.github.io/2018/01/15/write-a-shell.html)

> **원문 메모**
>
> 원문 주소가 바뀌었다. 현재 주소: <https://danishpraka.sh/posts/write-a-shell/> (기존 주소는 404).
>
> 원문 구성: Starting of the shell · Reading user commands · Tokenizing Input · Exiting the shell · Executing commands. 리다이렉션과 파이프는 다루지 않는다. 기존 회차가 그 둘을 적고 있어 원문에 맞게 고쳤다.

### Daily TODO

- [ ] `57.01` 프롬프트 루프와 `read_line`·토큰 분리를 구현한다. 긴 줄에서 버퍼가 늘어나는지와 빈 줄을 확인한다.
- [ ] `57.02` `exit` 처리와 `fork`·`exec` 실행을 붙인다. 없는 명령의 오류 출력을 확인하고, 53번 셸과 구조가 다른 점을 세 줄로 적는다.
## 58 unix-shell-series

원본: [README → Operating Systems](../README.md#operating-systems)

* Writing a Unix Shell
  * [Part 1](https://indradhanush.github.io/blog/writing-a-unix-shell-part-1)
  * [Part 2](https://indradhanush.github.io/blog/writing-a-unix-shell-part-2)
  * [Part 3](https://indradhanush.github.io/blog/writing-a-unix-shell-part-3)

> **원문 메모**
>
> 원문 구성: 1편 Fork(부모·자식 순서와 `wait`) · 2편 Exec, Error handling, Builtin commands · 3편 Signals(시그널 핸들러, 마스크, `sigsetjmp`, `sigaction`). 3편이 가장 길어 2회차로 나눴다.

### Daily TODO

- [ ] `58.01` 1편: `fork`로 부모·자식을 나누고 `wait`로 출력 순서를 고정한다. `wait`가 없을 때 순서가 바뀔 수 있음을 반복 실행으로 관찰한다.
- [ ] `58.02` 2편: `execvp`와 오류 처리, `cd` 내장 명령을 붙인다. 없는 명령과 없는 디렉토리의 오류 메시지를 확인한다.
- [ ] `58.03` 3편 앞부분: SIGINT 핸들러를 단다. Ctrl-C가 셸을 죽이지 않고, 실행 중인 자식은 종료시키는지 확인한다.
- [ ] `58.04` 3편 뒷부분: 시그널 마스크·`sigsetjmp`·`sigaction`으로 고친다. 입력 대기 중 Ctrl-C를 누르면 새 프롬프트가 나오는지 확인한다.
## 37 shell-tokenrove

원본: [README → Operating Systems](../README.md#operating-systems)

* [Build Your Own Shell](https://github.com/tokenrove/build-your-own-shell)

> **원문 메모**
>
> 원문은 단계별 과제와 테스트로 된 워크숍이다. Stages: 1 fork/exec/wait · 2 files and pipes · 3 job control and signals · 4 quoting and expansion · 5 interactivity. 3단계가 커서 2회차로 나눴다.

### Daily TODO

- [ ] `37.01` 1단계 fork/exec/wait: 명령 하나를 실행하고 종료 상태를 돌려준다. 저장소의 1단계 테스트를 돌려 결과를 기록한다.
- [ ] `37.02` 2단계 files and pipes: 리다이렉션과 파이프를 결합한다. 빈 출력과 EOF를 확인하고 2단계 테스트를 돌린다.
- [ ] `37.03` 3단계 앞부분: 포그라운드 작업을 자기 프로세스 그룹에 넣는다. Ctrl-C 뒤 프롬프트가 살아 있는지 확인한다.
- [ ] `37.04` 3단계 뒷부분: 백그라운드 작업과 중지·재개를 처리한다. 프롬프트가 막히지 않고 끝난 자식이 회수되는지 확인한다.
- [ ] `37.05` 4단계 quoting and expansion: 따옴표와 확장을 해석한다. 공백이 든 인자 하나와 변수 확장 하나를 확인한다.
- [ ] `37.06` 5단계 interactivity: 대화형 기능을 붙인다. 터미널이 아닌 입력(파이프)에서는 프롬프트 동작이 달라지는지 확인한다.
## 39 virtual-memory

원본: [README → Operating Systems](../README.md#operating-systems)

* [Hack the Virtual Memory](https://blog.holbertonschool.com/hack-virtual-memory-stack-registers-assembly-code/)

> **원문 메모**
>
> 링크된 글은 「the stack, registers and assembly code」 편이다. 구성: The Stack · Automatic allocation · Using local variables · leave · Playing with the stack · ret · Hack the stack!
>
> 원문은 x86-64 Linux의 gcc·objdump 기준이다. 기존 회차는 LLDB와 메모리 지도·ASLR을 적고 있어 원문에 맞게 고쳤다. Apple Silicon에서는 `linux/amd64` 컨테이너에서 한다.

### Daily TODO

- [ ] `39.01` `linux/amd64` 컨테이너에서 원문 예제를 컴파일하고 `objdump`로 함수 프롤로그를 읽는다. `rbp` 저장과 `rsp` 감소가 원문과 같은지 대조한다.
- [ ] `39.02` 지역 변수의 `rbp` 기준 위치를 확인한다. 함수가 끝난 뒤 다음 함수에서 이전 값이 스택에 남아 있는 것을 출력으로 재현한다.
- [ ] `39.03` 저장된 `rbp`와 복귀 주소를 읽어 출력한다. 「Hack the stack」 절대로 복귀 주소를 바꿔 다른 함수가 실행되는 것을 재현한다.
## 44 malloc-danluu

원본: [README → Operating Systems](../README.md#operating-systems)

* [Let's Write a Malloc](https://danluu.com/malloc-tutorial/)

> **원문 메모**
>
> `sbrk` 기반이라 Linux 컨테이너에서 한다. 글 뒷부분에 연습 문제가 있다. 3회차에 다 못 하면 줄을 추가한다.

### Daily TODO

- [ ] `44.01` 할당 블록 메타데이터를 만들고 두 요청이 겹치지 않는지 확인한다.
- [ ] `44.02` 해제한 블록을 다음 요청에 재사용한다. 부족한 크기는 재사용하지 않는지 확인한다.
- [ ] `44.03` `calloc`의 0 초기화와 `realloc`의 기존 내용 보존을 작은 프로그램으로 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 54 malloc-arjun

원본: [README → Operating Systems](../README.md#operating-systems)

* [Write a Simple Memory Allocator](https://arjunsreedharan.org/post/148675821737/write-a-simple-memory-allocator)

> **원문 메모**
>
> 자동 요청에는 403으로 응답한다(브라우저에서는 열릴 가능성이 높다). 보존본: [2022-06](http://web.archive.org/web/20220611170146/https://arjunsreedharan.org/post/148675821737/write-a-simple-memory-allocator)
>
> `sbrk` 기반이라 Linux 컨테이너에서 한다. 본문 내용은 이번에 대조하지 못했다.

### Daily TODO

- [ ] `54.01` 블록 헤더를 연결 리스트로 묶는다. 연속 할당에서 필요한 정렬을 확인한다.
- [ ] `54.02` 해제·재할당에서 빈 블록을 재사용하는 경로와 새 블록을 얻는 경로를 각각 확인한다.
- [ ] `54.03` 소스의 동기화·확장 정책을 재현하고 정상 해제와 마지막 블록 해제의 차이를 기록한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
