# 08. 커널과 운영체제

에뮬레이터와 격리 Linux에서 부팅·메모리·프로세스·디바이스 경계를 검증한다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

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

## 47 os-dummies

원본: [README → Operating Systems](../README.md#operating-systems)

* [Operating systems development for Dummies](https://medium.com/@lduck11007/operating-systems-development-for-dummies-3d4d786e8ac)

### Daily TODO

- [ ] `47.01` 원문의 부팅 흐름을 그림으로 정리하고 대상 아키텍처의 최소 부트 이미지를 실행한다.
- [ ] `47.02` 부팅 메시지가 나오는 경로를 찾는다. 에뮬레이터 재실행 명령과 확인 로그를 남긴다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 48 os-from-zero-to-one

원본: [README → Operating Systems](../README.md#operating-systems)

* [Operating Systems: From 0 to 1](https://tuhdo.github.io/os01/) `book`

### Daily TODO

- [ ] `48.01` 책 목차를 훑어 필요한 도구와 장별 산출물을 기록한다. 첫 환경 실습을 재현한다.
- [ ] `48.02` 첫 부트 코드를 에뮬레이터에서 실행하고 진입 주소를 확인한다.
- [ ] `48.03` 커널 진입 전후 레지스터 상태를 비교한다. 다음 장은 반드시 실제 목차 기준으로 회차를 추가한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 52 little-os-book

원본: [README → Operating Systems](../README.md#operating-systems)

* [The little book about OS development](https://littleosbook.github.io/) `book`

### Daily TODO

- [ ] `52.01` 크로스 컴파일러·링커와 에뮬레이터로 시작 커널을 부팅한다.
- [ ] `52.02` 시리얼로 초기화 로그를 낸다. 부트 이미지 재빌드 결과를 확인한다.
- [ ] `52.03` 책의 가상 메모리·인터럽트·사용자 모드 실습을 장별로 분리한다. 먼저 인터럽트 하나를 재현한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 45 kernel-arjun

원본: [README → Operating Systems](../README.md#operating-systems)

* Let’s write a Kernel
  * [Part 1 - Kernel 101](https://arjunsreedharan.org/post/82710718100/kernel-101-lets-write-a-kernel)
  * [Part 2 - Kernel 201](https://arjunsreedharan.org/post/99370248137/kernel-201-lets-write-a-kernel-with-keyboard)

### Daily TODO

- [ ] `45.01` 101: 부트로더에서 C 커널로 넘어가 텍스트 출력을 확인한다.
- [ ] `45.02` 201: 키보드 인터럽트로 키 입력 하나를 표시한다. 종료 후 에뮬레이터로 다시 재현한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 40 os-from-scratch

원본: [README → Operating Systems](../README.md#operating-systems)

* [How to Create an OS from Scratch](https://github.com/cfenollosa/os-tutorial) `in-progress`

### Daily TODO

- [ ] `40.01` 부트 섹터를 만들고 디스크에서 후속 섹터를 읽어 확인한다.
- [ ] `40.02` 32비트 전환과 C 엔트리 진입을 로그로 확인한다.
- [ ] `40.03` 화면 드라이버와 인터럽트 중 키보드 입력 경로를 확인한다.
- [ ] `40.04` 남은 원문 레슨에 대한 회차를 추가한다. 첫 메모리 또는 파일시스템 레슨을 실행한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 55 system-call

원본: [README → Operating Systems](../README.md#operating-systems)

* [Write a System Call](https://brennan.io/2016/11/14/kernel-dev-ep3/)

### Daily TODO

- [ ] `55.01` 실습 커널에서 사용자 모드와 커널 모드 전환 지점을 확인한다.
- [ ] `55.02` 원문의 테스트 시스템 콜을 등록한다. 정상 번호와 등록되지 않은 번호의 기대 응답을 비교한다.
- [ ] `55.03` 작은 사용자 프로그램이 시스템 콜을 호출하도록 연결하고 인자·반환값을 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 36 mini-arm-os

원본: [README → Operating Systems](../README.md#operating-systems)

* [Build a minimal multi-tasking OS kernel for ARM from scratch](https://github.com/jserv/mini-arm-os)

### Daily TODO

- [ ] `36.01` ARM 대상 툴체인으로 예제 커널을 부팅하고 시리얼 출력을 확인한다.
- [ ] `36.02` 두 태스크의 레지스터 저장·복원 시점을 기록하고 협력 전환을 실행한다.
- [ ] `36.03` 타이머 틱으로 선점 전환을 관찰한다. 태스크별 카운터가 둘 다 증가하는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 38 raspberry-pi-os-js

원본: [README → Operating Systems](../README.md#operating-systems)

* [Building an Operating System for the Raspberry Pi](https://jsandler18.github.io/)

### Daily TODO

- [ ] `38.01` 원문 대상 보드·에뮬레이터를 확인한다. 첫 부팅과 UART 출력을 재현한다.
- [ ] `38.02` 예외 벡터 및 타이머 중 첫 예제를 실행해 로그를 남긴다.
- [ ] `38.03` 스레드나 입력 장치 등 공개된 나머지 실습을 장별로 쪼개고 첫 추가 동작을 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 42 raspberry-pi-os-matyukevich

원본: [README → Operating Systems](../README.md#operating-systems)

* [Learning operating system development using Linux kernel and Raspberry Pi](https://github.com/s-matyukevich/raspberry-pi-os) `in-progress`

### Daily TODO

- [ ] `42.01` 원문 도구로 첫 bare-metal 이미지를 띄우고 UART 출력을 비교한다.
- [ ] `42.02` 예외 레벨과 인터럽트 초기화를 추적한다. 타이머 틱을 확인한다.
- [ ] `42.03` 스케줄러와 사용자 프로세스의 전환 로그를 확인한다.
- [ ] `42.04` 가상 메모리 실습에서 매핑 주소를 확인한다. 공개 레슨의 나머지를 회차로 추가한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 51 toy-unix

원본: [README → Operating Systems](../README.md#operating-systems)

* [Roll your own toy UNIX-clone OS](http://www.jamesmolloy.co.uk/tutorial_html/)

### Daily TODO

- [ ] `51.01` 원문에 맞는 x86 실습 이미지를 부팅하고 콘솔에서 출력한다.
- [ ] `51.02` 인터럽트·페이지 할당을 확인한다. 할당한 프레임 주소가 겹치지 않는지 검사한다.
- [ ] `51.03` 타이머·프로세스 전환을 확인하고 각 프로세스의 출력 순서를 기록한다.
- [ ] `51.04` 파일시스템 또는 사용자 모드 실습을 원문 순서로 연결한다. 첫 파일 읽기나 사용자 출력 예제를 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 46 linux-containers

원본: [README → Operating Systems](../README.md#operating-systems)

* [Linux Containers in 500 Lines of Code](https://blog.lizzie.io/linux-containers-in-500-loc.html)

### Daily TODO

- [ ] `46.01` 격리 Linux에서 UTS·PID 네임스페이스 안팎의 호스트명·PID 차이를 검증한다.
- [ ] `46.02` 별도 임시 루트와 마운트를 연결한다. 호스트의 마운트 상태가 바뀌지 않는지 확인한다.
- [ ] `46.03` cgroup 한도를 적용한다. 제한이 지정한 자식에만 적용되는지 확인한다.
- [ ] `46.04` 권한을 분리해 실습 프로세스를 실행하고 마운트·cgroup 정리 여부를 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 41 kvm

원본: [README → Operating Systems](../README.md#operating-systems)

* [Learning KVM - implement your own kernel](https://david942j.blogspot.com/2018/10/note-learning-kvm-implement-your-own.html)

### Daily TODO

- [ ] `41.01` Linux 호스트에서 `/dev/kvm`과 사용할 게스트 아키텍처를 확인한다. 지원 안 되면 환경 체크만 기록한다.
- [ ] `41.02` KVM 예제에서 VM과 vCPU를 만들고 메모리 슬롯과 게스트 코드 진입을 확인한다.
- [ ] `41.03` 작은 게스트의 I/O exit와 halt를 처리하고 예상 시리얼 출력과 비교한다.
- [ ] `41.04` 원문의 나머지 단계와 각 exit 사유를 대조한다. 종료 후 자원을 닫고 같은 실행을 반복한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
