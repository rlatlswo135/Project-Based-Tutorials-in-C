# 04. 네트워크

본인 로컬 또는 격리 환경에서 소켓, 동시성, 메시지 형식, 패킷 계층을 익힌다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

| 원본 번호 | 순서 · 작업 폴더 |
|---|---|
| 07 | [`beej/`](#07-beej) |
| 10 | [`ntp/`](#10-ntp) |
| 08 | [`concurrent-servers/`](#08-concurrent-servers) |
| 11 | [`mqtt/`](#11-mqtt) |
| 09 | [`tcp-ip-stack/`](#09-tcp-ip-stack) |

## 07 beej

원본: [README → Computer Networking](../README.md#computer-networking)

* [Beej's Guide to Network Programming](http://beej.us/guide/bgnet/html/multi/index.html) `book`

### Daily TODO

- [ ] `07.01` 주소 해석과 소켓 생성을 구현하고 loopback에서 주소와 포트를 출력한다.
- [ ] `07.02` TCP 클라이언트/서버로 문자열을 왕복한다. 서버가 없을 때 연결 실패를 확인한다.
- [ ] `07.03` 버퍼보다 긴 메시지로 부분 송수신 처리와 EOF를 확인한다.
- [ ] `07.04` UDP 요청·응답 예제에서 송신자 주소를 표시하고 빈 데이터그램을 구분한다.
- [ ] `07.05` `poll` 예제로 클라이언트 둘을 번갈아 처리한다. 하나가 닫혀도 다른 쪽이 응답하는지 확인한다.
- [ ] `07.06` 정수 바이트 순서와 길이 프레이밍을 검증한다. 여러 조각을 한 메시지로 합친다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 10 ntp

원본: [README → Computer Networking](../README.md#computer-networking)

* [Let's make a NTP Client in C](https://lettier.github.io/posts/2016-04-26-lets-make-a-ntp-client-in-c.html)

### Daily TODO

- [ ] `10.01` 타임스탬프 필드를 포함하는 테스트 응답 바이트를 해석한다. big-endian과 epoch 변환을 고정 샘플로 확인한다.
- [ ] `10.02` 로컬 모의 UDP 서버에 요청한다. 응답 없음과 길이 부족을 각각 처리한다.
- [ ] `10.03` 응답의 모드·버전 등을 확인하고 고정 데이터에서 예상한 시각을 출력하는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 08 concurrent-servers

원본: [README → Computer Networking](../README.md#computer-networking)

* [Concurrent Servers](https://eli.thegreenplace.net/2017/concurrent-servers-part-1-introduction/)

### Daily TODO

- [ ] `08.01` 순차 서버에서 느린 클라이언트가 다음 응답을 늦추는지 로컬에서 측정한다.
- [ ] `08.02` 스레드 또는 프로세스 버전으로 클라이언트 둘을 동시에 처리한다.
- [ ] `08.03` 대기 큐와 워커 풀의 크기를 제한하고 처리량·종료 동작을 확인한다.
- [ ] `08.04` 이벤트 기반 버전에서 느린 연결 하나가 다른 연결을 막지 않는지 비교한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 11 mqtt

원본: [README → Computer Networking](../README.md#computer-networking)

* Write an MQTT broker from scratch
  * [Part 1 - The protocol](https://codepr.github.io/posts/sol-mqtt-broker)
  * [Part 2 - Networking](https://codepr.github.io/posts/sol-mqtt-broker-p2)
  * [Part 3 - Server](https://codepr.github.io/posts/sol-mqtt-broker-p3)
  * [Part 4 - Data structures](https://codepr.github.io/posts/sol-mqtt-broker-p4)
  * [Part 5 - Topic abstraction](https://codepr.github.io/posts/sol-mqtt-broker-p5)
  * [Part 6 - Handlers](https://codepr.github.io/posts/sol-mqtt-broker-p6)

### Daily TODO

- [ ] `11.01` 1편: MQTT 고정 헤더와 남은 길이를 고정 패킷으로 확인한다.
- [ ] `11.02` 2편: 루프백 소켓에서 일부만 도착한 메시지를 버퍼에 모은다.
- [ ] `11.03` 3편: 접속과 정상 종료를 처리하고 잘못 닫힌 연결을 정리한다.
- [ ] `11.04` 4편: 구독자 자료구조에 추가·삭제하고 종료된 연결을 배제한다.
- [ ] `11.05` 5편: 토픽 하나에 구독을 걸고 다른 토픽으로는 메시지가 가지 않는지 확인한다.
- [ ] `11.06` 6편: CONNECT·SUBSCRIBE·PUBLISH의 로컬 왕복을 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 09 tcp-ip-stack

원본: [README → Computer Networking](../README.md#computer-networking)

* Let's code a TCP/IP stack
  * [Part 1: Ethernet & ARP](http://www.saminiir.com/lets-code-tcp-ip-stack-1-ethernet-arp/)
  * [Part 2: IPv4 & ICMPv4](http://www.saminiir.com/lets-code-tcp-ip-stack-2-ipv4-icmpv4/)
  * [Part 3: TCP Basics & Handshake](http://www.saminiir.com/lets-code-tcp-ip-stack-3-tcp-handshake/)
  * [Part 4: TCP Data Flow & Socket API](http://www.saminiir.com/lets-code-tcp-ip-stack-4-tcp-data-flow-socket-api/)
  * [Part 5: TCP Retransmission](http://www.saminiir.com/lets-code-tcp-ip-stack-5-tcp-retransmission/)

### Daily TODO

- [ ] `09.01` 1편: 격리 Linux에서 가상 인터페이스를 만들고 Ethernet 프레임과 ARP 요청·응답을 캡처한다.
- [ ] `09.02` 2편: IPv4 헤더와 ICMP echo를 처리한다. 내부 테스트 주소에서 왕복을 확인한다.
- [ ] `09.03` 3편 준비: 합성 TCP 헤더로 포트·플래그·시퀀스 필드와 체크섬을 확인한다.
- [ ] `09.04` 3편: 로컬에서 SYN·SYN-ACK·ACK 상태 변화를 기록한다.
- [ ] `09.05` 4편: 작은 payload를 전달하고 EOF와 정상 연결 종료를 확인한다.
- [ ] `09.06` 5편: 격리 실습의 가상 연결에서 패킷 손실을 모의해 재전송과 정상 ACK 후 타이머 제거를 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
