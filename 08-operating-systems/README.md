# 08. 커널과 운영체제

에뮬레이터와 격리 Linux에서 부팅·메모리·프로세스·디바이스 경계를 검증한다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

아래 모든 항목을 진행한다. 전체 학습 순서는 [로드맵](../ROADMAP.md)을 따른다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

회차는 2026-11-20에 원문 목차와 재생 시간을 대조해 나눴다. 항목마다 `원문 메모`에 근거와 확인하지 못한 부분을 적었다. 영상 항목은 제목과 길이만 보고 나눈 것이라, 실제 내용과 다르면 그날 줄을 고친다.

| 원본 번호 | 순서 · 작업 폴더 |
|---|---|
| 47 | [`os-dummies/`](#47-os-dummies) |
| 48 | [`os-from-zero-to-one/`](#48-os-from-zero-to-one) |
| 52 | [`little-os-book/`](#52-little-os-book) |
| 45 | [`kernel-arjun/`](#45-kernel-arjun) |
| 40 | [`os-from-scratch/`](#40-os-from-scratch) |
| 55 | [`system-call/`](#55-system-call) |
| 36 | [`mini-arm-os/`](#36-mini-arm-os) |
| 38 | [`raspberry-pi-os-js/`](#38-raspberry-pi-os-js) |
| 42 | [`raspberry-pi-os-matyukevich/`](#42-raspberry-pi-os-matyukevich) |
| 51 | [`toy-unix/`](#51-toy-unix) |
| 46 | [`linux-containers/`](#46-linux-containers) |
| 41 | [`kvm/`](#41-kvm) |

## 환경

현재 Mac(Apple Silicon)에서 2026-11-20에 확인한 상태다.

- `qemu-system-i386`·`x86_64`·`arm`·`aarch64`는 설치돼 있다. nasm, x86 크로스 컴파일러, `arm-none-eabi-gcc`는 설치돼 있지 않다. 47의 첫 회차에 x86 쪽을, 36의 첫 회차에 ARM 쪽을 설치한다.
- 55는 커널을 빌드해 부팅할 Linux 가상 머신, 46은 루트 권한을 줄 격리된 Linux가 필요하다.
- 41은 x86-64 KVM이 필요해 Apple Silicon Mac에서는 할 수 없다. x86-64 Linux 실기기나 원격 머신을 구해야 한다.

## 47 os-dummies

원본: [README → Operating Systems](../README.md#operating-systems)

* [Operating systems development for Dummies](https://medium.com/@lduck11007/operating-systems-development-for-dummies-3d4d786e8ac)

> **원문 메모**
>
> 자동 요청에는 403으로 응답한다. 보존본: [2026-07](http://web.archive.org/web/20260728163005/https://medium.com/@lduck11007/operating-systems-development-for-dummies-3d4d786e8ac). 본문 내용은 대조하지 못했다.

### Daily TODO

- [ ] `47.01` 원문의 부팅 흐름을 그림으로 정리하고 대상 아키텍처의 최소 부트 이미지를 실행한다.
- [ ] `47.02` 부팅 메시지가 나오는 경로를 찾는다. 에뮬레이터 재실행 명령과 확인 로그를 남긴다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 48 os-from-zero-to-one

원본: [README → Operating Systems](../README.md#operating-systems)

* [Operating Systems: From 0 to 1](https://tuhdo.github.io/os01/) `book`

> **원문 메모**
>
> 책은 Part 1(1~6장)과 Part 2(7~8장)가 완성돼 있고 Part 3(9~13장)은 미완성이다. 저자는 앞 8개 장을 끝내면 책의 목적을 달성한 것이라고 적고 있다. 완료 범위는 1~8장 + Part 3 중 공개된 부분으로 잡았다.
>
> 장 제목은 기억 기준이다(미확인). 4장이 가장 길다. 첫 회차에 목차와 쪽수를 보고 회차를 조정한다.

### Daily TODO

- [ ] `48.01` 1~2장(도메인 문서, 하드웨어에서 소프트웨어까지): 읽고 책이 요구하는 도구를 설치한다. 책의 첫 환경 확인 예제를 재현한다.
- [ ] `48.02` 3장(컴퓨터 아키텍처): 읽고, 책이 참고하라는 데이터시트나 매뉴얼에서 예제로 든 항목 하나를 직접 찾아 적는다.
- [ ] `48.03` 4장 x86 어셈블리와 C (1/3): 어셈블러와 `objdump`로 명령어 인코딩을 확인한다.
- [ ] `48.04` 4장 (2/3): C 코드의 데이터 선언이 어셈블리에서 어떻게 표현되는지 예제를 컴파일해 대조한다.
- [ ] `48.05` 4장 (3/3): 함수 호출과 스택 프레임을 디스어셈블로 대조한다.
- [ ] `48.06` 5장 프로그램의 구조 (1/2): `readelf`로 ELF 헤더와 섹션을 읽는다.
- [ ] `48.07` 5장 (2/2): 프로그램 헤더와 세그먼트를 읽고, 섹션이 세그먼트에 묶이는 방식을 예제로 확인한다.
- [ ] `48.08` 6장(런타임 조사와 디버그): gdb로 실행 중인 프로그램의 레지스터와 메모리를 조사한다.
- [ ] `48.09` 7장 부트로더 (1/2): 부트 섹터를 만들어 에뮬레이터에서 실행한다. 진입 주소를 확인한다.
- [ ] `48.10` 7장 (2/2): 디스크에서 다음 섹터를 읽어 실행을 넘긴다.
- [ ] `48.11` 8장 베어메탈에서의 링킹과 로딩 (1/2): 링커 스크립트로 커널 이미지의 배치를 정한다.
- [ ] `48.12` 8장 (2/2): 부트로더가 커널을 올리고, 에뮬레이터에 붙인 gdb로 커널 코드를 디버그한다.
- [ ] `48.13` Part 3(9~13장): 공개된 범위를 확인하고 실습할 수 있는 부분만 진행한다. 미완성이라 더 못 가는 지점과 이유를 기록한다.
## 52 little-os-book

원본: [README → Operating Systems](../README.md#operating-systems)

* [The little book about OS development](https://littleosbook.github.io/) `book`

> **원문 메모**
>
> 원문은 14개 장이다(2 First Steps · 3 Getting to C · 4 Output · 5 Segmentation · 6 Interrupts and Input · 7 The Road to User Mode · 8 A Short Introduction to Virtual Memory · 9 Paging · 10 Page Frame Allocation · 11 User Mode · 12 File Systems · 13 System Calls · 14 Multitasking). 기존 3회차를 장 기준으로 다시 나눴다.
>
> 뒤쪽 장은 코드보다 설명이 많아 직접 채워야 할 부분이 크다고 기억한다(미확인). 넘치면 줄을 추가한다. 32비트 x86 툴체인·nasm·에뮬레이터가 필요하다(nasm과 크로스 컴파일러는 지금 설치돼 있지 않다).

### Daily TODO

- [ ] `52.01` 1~2장 First Steps: 도구를 설치하고 부트로더로 가장 작은 커널을 부팅한다. 레지스터에 원문이 지정한 값이 들어갔는지 에뮬레이터 로그로 확인한다.
- [ ] `52.02` 3장 Getting to C: 스택을 잡고 C 함수를 호출한다. C 함수의 반환값을 로그로 확인한다.
- [ ] `52.03` 4장 Output 앞부분: 프레임 버퍼에 글자를 쓰고 커서를 옮긴다.
- [ ] `52.04` 4장 뒷부분: 시리얼 포트로 로그를 낸다. 에뮬레이터의 시리얼 출력 파일에 로그가 남는지 확인한다.
- [ ] `52.05` 5장 Segmentation: GDT를 올린다. 세그먼트 레지스터가 바뀐 뒤에도 출력이 되는지 확인한다.
- [ ] `52.06` 6장 Interrupts and Input: IDT와 PIC를 설정하고 키보드 인터럽트를 받는다. 누른 키의 스캔 코드를 로그로 확인한다.
- [ ] `52.07` 7장 The Road to User Mode: 부트로더로 모듈을 올려 그 코드로 점프한다.
- [ ] `52.08` 8~9장 Virtual Memory · Paging: 페이징을 켜고 커널을 상위 주소로 옮긴다. 켠 뒤에도 출력과 인터럽트가 동작하는지 확인한다.
- [ ] `52.09` 10장 Page Frame Allocation: 페이지 프레임 할당기를 만든다. 할당한 프레임 주소가 겹치지 않는지 확인한다.
- [ ] `52.10` 11장 User Mode: 사용자 모드로 전환해 프로그램을 실행한다.
- [ ] `52.11` 12~13장 File Systems · System Calls: 읽고 시스템 콜 하나를 구현한다. 사용자 프로그램의 호출이 커널 로그에 남는지 확인한다.
- [ ] `52.12` 14장 Multitasking: 프로세스 둘을 번갈아 실행한다. 두 프로세스의 출력이 섞여 나오는지 확인한다.
## 45 kernel-arjun

원본: [README → Operating Systems](../README.md#operating-systems)

* Let’s write a Kernel
  * [Part 1 - Kernel 101](https://arjunsreedharan.org/post/82710718100/kernel-101-lets-write-a-kernel)
  * [Part 2 - Kernel 201](https://arjunsreedharan.org/post/99370248137/kernel-201-lets-write-a-kernel-with-keyboard)

> **원문 메모**
>
> 자동 요청에는 403으로 응답한다. 보존본: [Kernel 101](http://web.archive.org/web/20220611170101/https://arjunsreedharan.org/post/82710718100/kernel-101-lets-write-a-kernel) · [Kernel 201](http://web.archive.org/web/20180923040237/https://arjunsreedharan.org/post/99370248137/kernel-201-lets-write-a-kernel-with-keyboard). 본문 내용은 대조하지 못했다.

### Daily TODO

- [ ] `45.01` 101: 부트로더에서 C 커널로 넘어가 텍스트 출력을 확인한다.
- [ ] `45.02` 201: 키보드 인터럽트로 키 입력 하나를 표시한다. 종료 후 에뮬레이터로 다시 재현한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 40 os-from-scratch

원본: [README → Operating Systems](../README.md#operating-systems)

* [How to Create an OS from Scratch](https://github.com/cfenollosa/os-tutorial) `in-progress`

> **원문 메모**
>
> 저장소는 레슨 폴더 00~24로 되어 있다. 기존 4회차를 폴더 이름 기준으로 다시 나눴다. 레슨이 짧아 둘셋씩 묶었다. nasm과 크로스 컴파일러가 필요하다(지금 설치돼 있지 않다).

### Daily TODO

- [ ] `40.01` 00-environment · 01-bootsector-barebones: 도구를 설치하고 빈 부트 섹터를 에뮬레이터에서 부팅한다.
- [ ] `40.02` 02-bootsector-print · 03-bootsector-memory: BIOS로 글자를 출력하고 메모리 오프셋을 확인한다.
- [ ] `40.03` 04-bootsector-stack · 05-bootsector-functions-strings: 스택과 함수, 문자열 출력 루틴을 만든다.
- [ ] `40.04` 06-bootsector-segmentation · 07-bootsector-disk: 세그먼트를 다루고 디스크에서 다음 섹터를 읽는다. 읽은 값이 써 둔 값과 같은지 확인한다.
- [ ] `40.05` 08-32bit-print · 09-32bit-gdt · 10-32bit-enter: GDT를 올리고 32비트 보호 모드로 들어간다. 전환 뒤 화면 출력을 확인한다.
- [ ] `40.06` 11-kernel-crosscompiler · 12-kernel-c · 13-kernel-barebones: 크로스 컴파일러를 준비하고 C 커널로 진입한다.
- [ ] `40.07` 14-checkpoint · 15-video-ports: 빌드 구조를 정리하고 포트 입출력으로 커서 위치를 읽는다.
- [ ] `40.08` 16-video-driver · 17-video-scroll: 화면 드라이버와 스크롤을 만든다. 화면을 넘는 출력에서 스크롤되는지 확인한다.
- [ ] `40.09` 18-interrupts: IDT와 ISR을 설치한다. 소프트웨어 인터럽트를 일으켜 핸들러 출력을 확인한다.
- [ ] `40.10` 19-interrupts-irqs · 20-interrupts-timer: IRQ와 타이머, 키보드를 붙인다. 틱 수와 키 입력을 확인한다.
- [ ] `40.11` 21-shell: 간단한 셸을 만든다. 명령 하나를 입력해 응답을 확인한다.
- [ ] `40.12` 22-malloc: 간단한 메모리 할당을 만든다. 연속 할당의 주소가 겹치지 않는지 확인한다.
- [ ] `40.13` 23-fixes · 24-el-capitan: 수정 사항을 반영하고 macOS 관련 메모를 읽는다. 저장소가 여기서 끝나는 것을 확인하고 범위를 기록한다.
## 55 system-call

원본: [README → Operating Systems](../README.md#operating-systems)

* [Write a System Call](https://brennan.io/2016/11/14/kernel-dev-ep3/)

> **원문 메모**
>
> 원문 구성: What is a system call? · Set up your VM · Acquire Source Code · Configure Your Kernel · Add Your System Call(System call table · System call function) · Compile and boot the kernel · Testing Your Syscall. 기존 회차를 이 순서에 맞게 고쳤다.
>
> 커널을 직접 빌드해 부팅할 수 있는 Linux 가상 머신이 필요하다. 원문은 x86-64 기준이라 ARM 가상 머신에서는 시스템 콜 표의 위치가 다르다. 커널 빌드는 시간이 오래 걸린다.

### Daily TODO

- [ ] `55.01` Set up your VM ~ Configure Your Kernel: 가상 머신에 커널 소스를 받고 설정한 뒤 수정 없이 빌드해 부팅한다. `uname -r`로 새 커널임을 확인한다.
- [ ] `55.02` Add Your System Call ~ Compile and boot: 시스템 콜 표에 항목을 넣고 함수를 작성해 다시 빌드·부팅한다.
- [ ] `55.03` Testing Your Syscall: 사용자 프로그램에서 번호로 호출한다. 인자와 반환값, 커널 로그를 확인하고 등록되지 않은 번호의 응답과 비교한다.
## 36 mini-arm-os

원본: [README → Operating Systems](../README.md#operating-systems)

* [Build a minimal multi-tasking OS kernel for ARM from scratch](https://github.com/jserv/mini-arm-os)

> **원문 메모**
>
> 저장소 단계: 00-Semihosting · 00-HelloWorld · 01-HelloWorld · 02-ContextSwitch-1 · 03-ContextSwitch-2 · 04-Multitasking · 05-TimerInterrupt · 06-Preemptive · 07-Threads · 08-CMSIS. 기존 3회차를 단계 기준으로 다시 나눴다.
>
> ARM 베어메탈 툴체인(`arm-none-eabi-gcc`, 지금 설치돼 있지 않다)과 저장소가 지정하는 STM32 에뮬레이터가 필요하다.

### Daily TODO

- [ ] `36.01` 00-Semihosting · 00-HelloWorld · 01-HelloWorld: 툴체인과 에뮬레이터를 준비해 시리얼로 문자열을 출력한다.
- [ ] `36.02` 02-ContextSwitch-1 · 03-ContextSwitch-2: 커널과 태스크 사이를 오간다. 레지스터를 저장하고 복원하는 지점을 기록한다.
- [ ] `36.03` 04-Multitasking: 두 태스크를 협력적으로 번갈아 실행한다. 출력 순서를 확인한다.
- [ ] `36.04` 05-TimerInterrupt · 06-Preemptive: 타이머 틱으로 선점 전환을 만든다. 양보하지 않는 두 태스크의 카운터가 둘 다 증가하는지 확인한다.
- [ ] `36.05` 07-Threads: 스레드 생성과 종료를 다룬다. 끝난 스레드가 다시 스케줄되지 않는지 확인한다.
- [ ] `36.06` 08-CMSIS: CMSIS 기반 버전을 빌드해 저장소가 설명하는 명령을 실행한다. 실기기 전용 단계는 범위 밖임을 기록한다.
## 38 raspberry-pi-os-js

원본: [README → Operating Systems](../README.md#operating-systems)

* [Building an Operating System for the Raspberry Pi](https://jsandler18.github.io/)

> **원문 메모**
>
> 원문은 Part 01~10과 참고 글(Extra Information) 9편이다. 기존 3회차를 편 기준으로 다시 나눴다. 참고 글은 해당 편에서 필요할 때 읽는다. ARM 베어메탈 툴체인이 필요하다.

### Daily TODO

- [ ] `38.01` Part 01 Setting up the Development Environment · Part 02 Getting Something to Boot: 환경을 준비하고 에뮬레이터에서 UART 출력을 확인한다.
- [ ] `38.02` Part 03 Organizing our Project: 프로젝트 구조와 빌드 파일을 정리한다. 정리 뒤에도 같은 출력이 나오는지 확인한다.
- [ ] `38.03` Part 04 Wrangling Memory: 부팅 정보에서 메모리 크기를 얻고 페이지 목록을 만든다. 구한 페이지 수를 출력해 확인한다.
- [ ] `38.04` Part 05 Dynamic Memory Allocator: 힙 할당기를 만든다. 할당·해제·재할당에서 블록이 재사용되는지 확인한다.
- [ ] `38.05` Part 06 Printing to a Real Screen: 프레임 버퍼에 글자를 그린다. 에뮬레이터에서 지원되지 않으면 막힌 이유를 기록한다.
- [ ] `38.06` Part 07 Interrupts: 예외 벡터와 타이머 인터럽트를 설정한다. 주기적으로 핸들러가 불리는지 로그로 확인한다.
- [ ] `38.07` Part 08 Processes: 프로세스 제어 블록과 문맥 전환을 만든다. 두 프로세스의 출력이 번갈아 나오는지 확인한다.
- [ ] `38.08` Part 09 Locks: 스핀락과 뮤텍스를 만든다. 락이 없을 때 깨지던 공유 카운터가 맞게 나오는지 확인한다.
- [ ] `38.09` Part 10 Virtual Memory: 원문에 공개된 범위를 진행하고 어디까지 구현되는지 기록한다.
## 42 raspberry-pi-os-matyukevich

원본: [README → Operating Systems](../README.md#operating-systems)

* [Learning operating system development using Linux kernel and Raspberry Pi](https://github.com/s-matyukevich/raspberry-pi-os) `in-progress`

> **원문 메모**
>
> 공개된 범위는 Lesson 1~6이다(1 Kernel Initialization · 2 Processor initialization · 3 Interrupt handling · 4 Process scheduler · 5 User processes and system calls · 6 Virtual memory management). Lesson 7~11은 「To be done」이므로 완료 범위는 6까지다.
>
> 레슨마다 RPi OS 구현, 같은 주제의 Linux 커널 코드 읽기, 연습 문제로 되어 있다. 레슨당 2회차로 잡았다. AArch64 툴체인과 에뮬레이터가 필요하다.

### Daily TODO

- [ ] `42.01` Lesson 1 RPi OS(1.1): bare-metal 이미지를 띄우고 UART 출력을 확인한다.
- [ ] `42.02` Lesson 1 Linux(1.2~1.4)와 연습(1.5): 커널의 구조·빌드·시작 순서를 읽고 연습 문제 하나를 푼다.
- [ ] `42.03` Lesson 2 RPi OS(2.1): 예외 레벨을 전환한다. 전환 전후의 레벨을 출력해 확인한다.
- [ ] `42.04` Lesson 2 Linux(2.2)와 연습(2.3): 커널의 프로세서 초기화 코드를 읽고 연습 문제 하나를 푼다.
- [ ] `42.05` Lesson 3 RPi OS(3.1): 인터럽트를 초기화하고 타이머 틱을 받는다.
- [ ] `42.06` Lesson 3 Linux(3.2~3.4)와 연습(3.5): 커널의 예외 처리·인터럽트 컨트롤러·타이머 코드를 읽고 연습 문제 하나를 푼다.
- [ ] `42.07` Lesson 4 RPi OS(4.1): 스케줄러로 태스크를 전환한다. 전환 로그를 확인한다.
- [ ] `42.08` Lesson 4 Linux(4.2~4.4)와 연습(4.5): 커널의 스케줄러 구조·fork·스케줄링 코드를 읽고 연습 문제 하나를 푼다.
- [ ] `42.09` Lesson 5 RPi OS(5.1): 사용자 프로세스와 시스템 콜을 만든다. 사용자 모드에서 부른 시스템 콜의 결과를 확인한다.
- [ ] `42.10` Lesson 5 Linux(5.2)와 연습(5.3): 커널의 해당 코드를 읽고 연습 문제 하나를 푼다.
- [ ] `42.11` Lesson 6 RPi OS(6.1): 가상 메모리를 켠다. 프로세스마다 같은 가상 주소가 다른 물리 주소로 매핑되는지 확인한다.
- [ ] `42.12` Lesson 6 연습(6.3): 연습 문제 하나를 푼다. Linux 편(6.2)이 아직 미공개인지 확인하고 범위를 기록한다.
## 51 toy-unix

원본: [README → Operating Systems](../README.md#operating-systems)

* [Roll your own toy UNIX-clone OS](http://www.jamesmolloy.co.uk/tutorial_html/)

> **원문 메모**
>
> 원문 서버에 연결되지 않는다. 보존본: [2024-01](http://web.archive.org/web/20240109133025/http://jamesmolloy.co.uk/tutorial_html/). 목차를 확인하지 못했다.
>
> 기억으로는 10개 장(환경 → 화면 → GDT/IDT → IRQ와 타이머 → 페이징 → 힙 → VFS와 initrd → 멀티태스킹 → 사용자 모드) 구성이다(미확인). 첫 회차에 목차를 옮겨 적고 장당 1회차로 다시 나눈다. 4회차로는 부족할 가능성이 높다.

### Daily TODO

- [ ] `51.01` 원문에 맞는 x86 실습 이미지를 부팅하고 콘솔에서 출력한다.
- [ ] `51.02` 인터럽트·페이지 할당을 확인한다. 할당한 프레임 주소가 겹치지 않는지 검사한다.
- [ ] `51.03` 타이머·프로세스 전환을 확인하고 각 프로세스의 출력 순서를 기록한다.
- [ ] `51.04` 파일시스템 또는 사용자 모드 실습을 원문 순서로 연결한다. 첫 파일 읽기나 사용자 출력 예제를 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 46 linux-containers

원본: [README → Operating Systems](../README.md#operating-systems)

* [Linux Containers in 500 Lines of Code](https://blog.lizzie.io/linux-containers-in-500-loc.html)

> **원문 메모**
>
> 원문은 전체 코드가 본문에 들어 있는 긴 글이다(약 25,000단어). 구성: Container setup · Namespaces · Capabilities · Mounts · System Calls · 자원 제한과 네트워킹. 기존 4회차에 capabilities와 시스템 콜 필터가 빠져 있어 다시 나눴다.
>
> 루트 권한을 줄 수 있는 격리된 Linux 환경이 필요하다. 호스트에서 직접 하지 않는다.

### Daily TODO

- [ ] `46.01` Container setup: 인자 처리와 자식 프로세스 생성 골격을 만든다. 자식이 명령 하나를 실행하고 종료 상태가 부모에게 전달되는지 확인한다.
- [ ] `46.02` Namespaces: 네임스페이스를 분리하고 사용자 ID를 매핑한다. 안팎의 호스트명과 PID가 다른지 확인한다.
- [ ] `46.03` Capabilities: 권한을 떨어뜨린다. 컨테이너 안에서 제거한 권한이 필요한 작업이 실패하는지 확인한다.
- [ ] `46.04` Mounts: 임시 루트로 바꾸고 옛 루트를 떼어 낸다. 호스트의 마운트 상태가 바뀌지 않는지 확인한다.
- [ ] `46.05` System Calls: 시스템 콜 필터를 건다. 막은 시스템 콜을 부르면 실패하는지 작은 프로그램으로 확인한다.
- [ ] `46.06` 자원 제한: cgroup과 rlimit을 적용한다. 제한이 지정한 자식에만 적용되고 끝난 뒤 cgroup이 정리되는지 확인한다.
## 41 kvm

원본: [README → Operating Systems](../README.md#operating-systems)

* [Learning KVM - implement your own kernel](https://david942j.blogspot.com/2018/10/note-learning-kvm-implement-your-own.html)

> **원문 메모**
>
> `/dev/kvm`이 있는 x86-64 Linux가 필요하다. Apple Silicon Mac에서는 x86 KVM을 쓸 수 없으므로 x86-64 Linux 실기기나 중첩 가상화를 지원하는 원격 머신이 있어야 한다. 이 항목은 하드웨어를 구하기 전에는 시작할 수 없다.

### Daily TODO

- [ ] `41.01` Linux 호스트에서 `/dev/kvm`과 사용할 게스트 아키텍처를 확인한다. 지원 안 되면 환경 체크만 기록한다.
- [ ] `41.02` KVM 예제에서 VM과 vCPU를 만들고 메모리 슬롯과 게스트 코드 진입을 확인한다.
- [ ] `41.03` 작은 게스트의 I/O exit와 halt를 처리하고 예상 시리얼 출력과 비교한다.
- [ ] `41.04` 원문의 나머지 단계와 각 exit 사유를 대조한다. 종료 후 자원을 닫고 같은 실행을 반복한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
