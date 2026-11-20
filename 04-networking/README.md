# 04. 네트워크

본인 로컬 또는 격리 환경에서 소켓, 동시성, 메시지 형식, 패킷 계층을 익힌다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

회차는 2026-11-20에 원문 목차와 재생 시간을 대조해 나눴다. 항목마다 `원문 메모`에 근거와 확인하지 못한 부분을 적었다. 영상 항목은 제목과 길이만 보고 나눈 것이라, 실제 내용과 다르면 그날 줄을 고친다.

| 원본 번호 | 순서 · 작업 폴더 |
|---|---|
| 07 | [`beej/`](#07-beej) |
| 10 | [`ntp/`](#10-ntp) |
| 08 | [`concurrent-servers/`](#08-concurrent-servers) |
| 11 | [`mqtt/`](#11-mqtt) |
| 09 | [`tcp-ip-stack/`](#09-tcp-ip-stack) |

## 환경

현재 Mac(Apple Silicon)에서 2026-11-20에 확인한 상태다.

- 07·10은 macOS에서 할 수 있다.
- 08의 epoll, 11의 epoll, 09의 TUN/TAP은 Linux가 필요하다. 09는 네트워크 장치 권한을 준 컨테이너나 가상 머신에서 한다.

## 07 beej

원본: [README → Computer Networking](../README.md#computer-networking)

* [Beej's Guide to Network Programming](http://beej.us/guide/bgnet/html/multi/index.html) `book`

> **원문 메모**
>
> 원문은 10개 장이다. 실습은 3장(주소 구조체), 5장(시스템 콜 5.1~5.11), 6장(6.1 Stream Server · 6.2 Stream Client · 6.3 Datagram Sockets), 7장(7.1 Blocking · 7.2 poll · 7.3 select · 7.4 Partial send · 7.5 Serialization · 7.6 Data Encapsulation · 7.7 Broadcast)에 있다. 8~10장은 질문 모음과 매뉴얼이다.

### Daily TODO

- [ ] `07.01` 1~3장: `getaddrinfo`로 호스트 이름의 IPv4·IPv6 주소를 출력한다. 숫자 주소와 이름 양쪽으로 확인한다.
- [ ] `07.02` 4~5장: `socket`·`bind`·`connect`·`listen`·`accept`를 차례로 호출한다. 듣는 서버가 없을 때 `connect`의 실패 사유를 확인한다.
- [ ] `07.03` 6.1~6.2절: 스트림 서버와 클라이언트로 문자열을 왕복한다. 클라이언트를 여러 번 붙였을 때 좀비 자식이 남지 않는지 확인한다.
- [ ] `07.04` 6.3절: 데이터그램 송신·수신을 만든다. 송신자 주소를 표시하고 수신 버퍼보다 긴 데이터그램이 잘리는 것을 확인한다.
- [ ] `07.05` 7.1~7.2절: `poll` 기반 채팅 서버를 만든다. 클라이언트 둘 중 하나가 끊겨도 다른 쪽이 응답하는지 확인한다.
- [ ] `07.06` 7.3절: 같은 서버를 `select`로 만든다. 7.2절 서버와 같은 입력에서 같은 동작인지 비교한다.
- [ ] `07.07` 7.4절: 부분 송신을 처리하는 `sendall`을 만든다. 버퍼보다 큰 메시지가 전부 도착하는지 바이트 수로 확인한다.
- [ ] `07.08` 7.5~7.6절: 정수·문자열을 바이트 순서에 맞게 포장하고 길이 프레이밍을 붙인다. 여러 조각으로 도착한 데이터를 한 메시지로 합친다.
- [ ] `07.09` 7.7절과 8~10장: 브로드캐스트 예제를 로컬 망에서 실행한다. 질문 모음은 훑고, 모르던 항목 하나를 실험으로 확인해 기록한다.
## 10 ntp

원본: [README → Computer Networking](../README.md#computer-networking)

* [Let's make a NTP Client in C](https://lettier.github.io/posts/2016-04-26-lets-make-a-ntp-client-in-c.html)

> **원문 메모**
>
> 원문은 글 한 편(약 1,300단어)이다. 구성: Populate our Message · Setup our Socket · Send · Read · Parse · Print. 3회차를 2회차로 줄였다.

### Daily TODO

- [ ] `10.01` 48바이트 메시지 구조체를 채우고 고정된 응답 바이트를 해석한다. 바이트 순서 변환과 1900년 기준 시각의 epoch 변환을 고정 샘플로 확인한다.
- [ ] `10.02` UDP로 요청을 보내고 응답 시각을 출력한다. 응답 없음(타임아웃)과 길이 부족을 로컬 모의 서버로 각각 확인한다.
## 08 concurrent-servers

원본: [README → Computer Networking](../README.md#computer-networking)

* [Concurrent Servers](https://eli.thegreenplace.net/2017/concurrent-servers-part-1-introduction/)

> **원문 메모**
>
> 링크는 1편이지만 연재는 현재 8편이다: 1 Introduction · 2 Threads · 3 Event-driven · 4 libuv · 5 Redis case study · 6 Callbacks, Promises and async/await · 7 Rust · 8 Go(7·8편은 2026년 추가).
>
> 1~4편이 C 구현이다. 5편은 Redis 소스 읽기, 6~8편은 다른 언어다. 5~8편은 읽고 C 버전과 비교하는 회차로 잡았다. 3편의 epoll은 Linux 컨테이너에서 한다.

### Daily TODO

- [ ] `08.01` 1편: 프로토콜 상태 기계와 순차 서버를 만든다. 느린 클라이언트가 다음 클라이언트의 응답을 늦추는 것을 로컬에서 측정한다.
- [ ] `08.02` 2편 앞부분: 연결마다 스레드를 만든다. 클라이언트 둘이 동시에 응답받는지 확인한다.
- [ ] `08.03` 2편 뒷부분: 스레드 풀로 바꾼다. 풀 크기보다 많은 연결에서 대기와 처리 순서를 확인한다.
- [ ] `08.04` 3편 앞부분: 논블로킹 소켓과 `select` 루프로 만든다. 느린 연결 하나가 다른 연결을 막지 않는지 확인한다.
- [ ] `08.05` 3편 뒷부분: `epoll`로 바꾼다(Linux). `select` 버전과 같은 테스트를 돌려 결과를 비교한다.
- [ ] `08.06` 4편: libuv로 만든다. 콜백 기반 버전이 같은 클라이언트 테스트를 통과하는지 확인한다.
- [ ] `08.07` 5편: Redis 사례를 읽는다. Redis 소스에서 이벤트 루프 진입점과 클라이언트 읽기 콜백을 찾아 파일과 함수 이름을 기록한다.
- [ ] `08.08` 6편: 콜백·프라미스·async/await 글을 읽는다. 4편의 콜백 코드에서 같은 흐름이 어디에 해당하는지 표로 적는다.
- [ ] `08.09` 7~8편: Rust·Go 편을 읽는다. C 스레드 버전·이벤트 버전과 구조가 다른 점을 각각 세 줄로 적는다.
## 11 mqtt

원본: [README → Computer Networking](../README.md#computer-networking)

* Write an MQTT broker from scratch
  * [Part 1 - The protocol](https://codepr.github.io/posts/sol-mqtt-broker)
  * [Part 2 - Networking](https://codepr.github.io/posts/sol-mqtt-broker-p2)
  * [Part 3 - Server](https://codepr.github.io/posts/sol-mqtt-broker-p3)
  * [Part 4 - Data structures](https://codepr.github.io/posts/sol-mqtt-broker-p4)
  * [Part 5 - Topic abstraction](https://codepr.github.io/posts/sol-mqtt-broker-p5)
  * [Part 6 - Handlers](https://codepr.github.io/posts/sol-mqtt-broker-p6)

> **원문 메모**
>
> 6편 모두 코드가 많다(편당 3,600~6,700단어). 1·2·3·6편은 2회차로 나눴다. epoll을 쓰므로 Linux 컨테이너에서 한다.

### Daily TODO

- [ ] `11.01` 1편 앞부분: MQTT 고정 헤더와 패킷 구조체를 정의한다. 남은 길이 인코딩을 1바이트·여러 바이트 경계 값으로 확인한다.
- [ ] `11.02` 1편 뒷부분: 바이트 pack/unpack 함수와 CONNECT 해석을 만든다. 고정 패킷 바이트를 해석한 결과를 필드별로 확인한다.
- [ ] `11.03` 2편 앞부분: 응답 패킷을 만들어 바이트로 포장한다. 포장한 것을 다시 해석해 같은 값이 나오는지 확인한다.
- [ ] `11.04` 2편 뒷부분: 소켓 설정과 epoll 루프를 만든다. loopback에서 일부만 도착한 데이터를 버퍼에 모으는지 확인한다.
- [ ] `11.05` 3편 앞부분: 서버의 accept·read·write 콜백을 연결한다. 접속과 정상 종료를 처리한다.
- [ ] `11.06` 3편 뒷부분: 공용 유틸리티와 설정을 붙인다. 잘못 닫힌 연결이 정리되는지 확인한다.
- [ ] `11.07` 4편: 해시 테이블·리스트·트라이를 만든다. 추가·삭제·조회를 자료구조별 작은 테스트로 확인한다.
- [ ] `11.08` 5편: 토픽 트라이와 구독 관리를 만든다. 토픽 하나에 건 구독이 다른 토픽 메시지를 받지 않는지 확인한다.
- [ ] `11.09` 6편 앞부분: CONNECT·DISCONNECT·SUBSCRIBE 핸들러를 만든다. 테스트 클라이언트로 접속과 구독 응답을 확인한다.
- [ ] `11.10` 6편 뒷부분: PUBLISH와 나머지 핸들러를 만든다. 구독자 하나와 발행자 하나로 메시지 왕복을 확인한다.
## 09 tcp-ip-stack

원본: [README → Computer Networking](../README.md#computer-networking)

* Let's code a TCP/IP stack
  * [Part 1: Ethernet & ARP](http://www.saminiir.com/lets-code-tcp-ip-stack-1-ethernet-arp/)
  * [Part 2: IPv4 & ICMPv4](http://www.saminiir.com/lets-code-tcp-ip-stack-2-ipv4-icmpv4/)
  * [Part 3: TCP Basics & Handshake](http://www.saminiir.com/lets-code-tcp-ip-stack-3-tcp-handshake/)
  * [Part 4: TCP Data Flow & Socket API](http://www.saminiir.com/lets-code-tcp-ip-stack-4-tcp-data-flow-socket-api/)
  * [Part 5: TCP Retransmission](http://www.saminiir.com/lets-code-tcp-ip-stack-5-tcp-retransmission/)

> **원문 메모**
>
> 원문 사이트 `saminiir.com`이 조회되지 않는다(DNS 실패). 보존본: [1편](http://web.archive.org/web/20261109214035/https://www.saminiir.com/lets-code-tcp-ip-stack-1-ethernet-arp/) · [2편](http://web.archive.org/web/20261016082318/https://www.saminiir.com/lets-code-tcp-ip-stack-2-ipv4-icmpv4/) · [3편](http://web.archive.org/web/20250825221307/http://www.saminiir.com/lets-code-tcp-ip-stack-3-tcp-handshake/) · [4편](http://web.archive.org/web/20251125100932/http://www.saminiir.com/lets-code-tcp-ip-stack-4-tcp-data-flow-socket-api/) · [5편](http://web.archive.org/web/20260215124952/https://www.saminiir.com/lets-code-tcp-ip-stack-5-tcp-retransmission/). 저자의 소스는 <https://github.com/saminiir/level-ip>에 있다.
>
> TUN/TAP 장치를 쓰므로 권한을 준 Linux 환경이 필요하다. 본문 내용은 이번에 대조하지 못했다.

### Daily TODO

- [ ] `09.01` 1편: 격리 Linux에서 가상 인터페이스를 만들고 Ethernet 프레임과 ARP 요청·응답을 캡처한다.
- [ ] `09.02` 2편: IPv4 헤더와 ICMP echo를 처리한다. 내부 테스트 주소에서 왕복을 확인한다.
- [ ] `09.03` 3편 준비: 합성 TCP 헤더로 포트·플래그·시퀀스 필드와 체크섬을 확인한다.
- [ ] `09.04` 3편: 로컬에서 SYN·SYN-ACK·ACK 상태 변화를 기록한다.
- [ ] `09.05` 4편: 작은 payload를 전달하고 EOF와 정상 연결 종료를 확인한다.
- [ ] `09.06` 5편: 격리 실습의 가상 연결에서 패킷 손실을 모의해 재전송과 정상 ACK 후 타이머 제거를 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
