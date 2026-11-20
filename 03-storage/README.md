# 03. 파일과 저장소

터미널 버퍼·디스크 페이지·파일시스템·직렬화를 직접 구현한다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

아래 모든 항목을 진행한다. 전체 학습 순서는 [로드맵](../ROADMAP.md)을 따른다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

회차는 2026-11-20에 원문 목차와 재생 시간을 대조해 나눴다. 항목마다 `원문 메모`에 근거와 확인하지 못한 부분을 적었다. 영상 항목은 제목과 길이만 보고 나눈 것이라, 실제 내용과 다르면 그날 줄을 고친다.

| 원본 번호 | 순서 · 작업 폴더 |
|---|---|
| 69 | [`kilo-editor/`](#69-kilo-editor) |
| 12 | [`simple-db/`](#12-simple-db) |
| 56 | [`fuse/`](#56-fuse) |
| 68 | [`blockchain/`](#68-blockchain) |

## 환경

현재 Mac(Apple Silicon)에서 2026-11-20에 확인한 상태다.

- 69·12·68은 macOS에서 할 수 있다. 12의 원문 테스트는 Ruby rspec이다(rspec 미설치).
- 56은 Linux가 필요하다. 컨테이너에는 `/dev/fuse` 장치와 마운트 권한을 줘야 한다.

## 69 kilo-editor

원본: [README → Uncategorized](../README.md#uncategorized)

* [Build Your Own Text Editor](https://viewsourcecode.org/snaptoken/kilo/)

> **원문 메모**
>
> 원문은 7개 장, 184단계다(1 Setup · 2 Entering raw mode · 3 Raw input and output · 4 A text viewer · 5 A text editor · 6 Search · 7 Syntax highlighting). 3·4·5·7장은 한 번에 끝나지 않는 분량이라 둘로 나눴다.

### Daily TODO

- [ ] `69.01` 1~2장: raw mode를 켠다(에코·정규 모드·시그널 끄기, 읽기 타임아웃). 종료 뒤 `stty -g` 값이 실행 전과 같은지 비교한다.
- [ ] `69.02` 3장 앞부분: Ctrl-Q 종료, 화면 지우기, 왼쪽 물결표 그리기를 만든다. 종료할 때 화면이 정리되는지 확인한다.
- [ ] `69.03` 3장 뒷부분: 창 크기 읽기, 출력 버퍼, 커서 이동(방향키·Home·End·Page Up/Down)을 만든다. 화면 가장자리에서 커서가 벗어나지 않는지 확인한다.
- [ ] `69.04` 4장 앞부분: 파일을 줄 단위로 읽어 표시하고 세로로 스크롤한다. 화면보다 긴 파일의 처음과 끝을 확인한다.
- [ ] `69.05` 4장 뒷부분: 가로 스크롤, 탭 렌더링, 상태 표시줄, 메시지 줄을 만든다. 탭이 든 줄에서 커서 위치가 맞는지 확인한다.
- [ ] `69.06` 5장 앞부분: 문자 삽입과 저장, 수정 여부 표시, 저장 안 한 종료 확인을 만든다. 임시 파일을 저장하고 다시 열어 내용을 비교한다.
- [ ] `69.07` 5장 뒷부분: Backspace·Enter·다른 이름으로 저장을 만든다. 줄 처음에서 지우기와 줄 중간에서 나누기를 확인한다.
- [ ] `69.08` 6장: 검색을 만든다(입력하면서 찾기, 앞뒤 이동, 취소 시 커서 복원). 일치 없음과 마지막 일치 다음 이동을 확인한다.
- [ ] `69.09` 7장 앞부분: 숫자 색칠, 검색 결과 강조, 파일 종류 감지를 만든다. `.c` 파일과 확장자 없는 파일을 비교한다.
- [ ] `69.10` 7장 뒷부분: 문자열·주석·키워드·여러 줄 주석을 색칠한다. 문자열 안의 주석 기호와 줄을 넘는 주석을 확인한다.
## 12 simple-db

원본: [README → Databases](../README.md#databases)

* [Let's Build a Simple Database](https://cstack.github.io/db_tutorial/)

> **원문 메모**
>
> 원문은 15편이다(1 REPL ~ 14 Splitting Internal Nodes, 15 Where to go next). 기존 8회차를 편당 1회차로 다시 나눴다. 7편은 읽기 위주라 8편과 묶었다.
>
> 원문의 테스트는 Ruby rspec이다. 시스템 Ruby는 있고 rspec은 설치돼 있지 않다. rspec을 설치하거나 같은 입력·출력을 셸 스크립트로 검사한다.

### Daily TODO

- [ ] `12.01` 1편: REPL을 만든다. `.exit`와 알 수 없는 명령의 응답을 확인한다.
- [ ] `12.02` 2편: 문장을 준비·실행 단계로 나눈다. `insert`·`select`·알 수 없는 키워드를 구분한다.
- [ ] `12.03` 3편: 고정 길이 행을 직렬화해 메모리 페이지에 덧붙인다. 여러 행을 넣고 `select`로 같은 값이 나오는지 확인한다.
- [ ] `12.04` 4편: 테스트를 작성한다. 테이블이 가득 찬 경우, 최대 길이 문자열, 너무 긴 문자열, 음수 id를 각각 확인한다.
- [ ] `12.05` 5편: pager로 파일에 저장한다. 종료 후 다시 열어 같은 행이 조회되는지 확인한다.
- [ ] `12.06` 6편: 커서 추상화로 바꾼다. 앞 회차의 테스트가 그대로 통과하는지 확인한다.
- [ ] `12.07` 7~8편: B-tree 소개를 읽고 리프 노드 형식으로 바꾼다. 노드 내용을 출력하는 메타 명령으로 셀 수와 키를 확인한다.
- [ ] `12.08` 9편: 리프 안에서 이진 탐색으로 삽입 위치를 찾는다. 역순 삽입 후 정렬 상태와 중복 키 거부를 확인한다.
- [ ] `12.09` 10편: 리프 노드를 분할하고 새 루트를 만든다. 분할을 일으키는 개수를 넣고 트리 출력을 원문과 대조한다.
- [ ] `12.10` 11편: 내부 노드를 따라 재귀적으로 탐색한다. 분할된 트리에서 양쪽 리프의 키를 각각 찾는다.
- [ ] `12.11` 12편: 여러 리프에 걸쳐 스캔한다. 분할 이후에도 `select`가 모든 행을 순서대로 내는지 확인한다.
- [ ] `12.12` 13편: 분할 뒤 부모 노드를 갱신한다. 리프가 세 개 이상이 되는 입력에서 트리 출력을 원문과 대조한다.
- [ ] `12.13` 14~15편: 내부 노드를 분할한다. 여러 번 분할한 파일을 다시 열어 전체 조회가 같은지 확인하고, 15편의 다음 과제를 읽어 범위 밖임을 기록한다.
## 56 fuse

원본: [README → Operating Systems](../README.md#operating-systems)

* [Writing a FUSE Filesystem](https://www.cs.nmsu.edu/~pfeiffer/fuse-tutorial/)

> **원문 메모**
>
> 원문은 직접 파일시스템을 짜는 글이 아니라, 모든 호출을 기록하는 BBFS 예제를 실행하고 읽는 튜토리얼이다. 구성: Files and Naming Conventions · Running BBFS · Callbacks and struct fuse_operations · Parsing the Command Line and Initializing FUSE · Private Data · Unclear FUSE Functions · Security Considerations and Race Conditions. 기존 회차를 이 구성에 맞게 고쳤다.
>
> Linux가 필요하다. 컨테이너에서는 `/dev/fuse` 장치와 마운트 권한을 줘야 한다.

### Daily TODO

- [ ] `56.01` Files · Running BBFS: Linux 환경에서 BBFS를 빌드하고 임시 디렉토리에 마운트·언마운트한다. 마운트 전후의 `mount` 출력을 비교한다.
- [ ] `56.02` Callbacks: 마운트한 곳에서 `ls`·`cat`·파일 쓰기를 하고 로그에 찍힌 콜백 호출 순서를 기록한다. `getattr`·`readdir`·`open`·`read`가 언제 불리는지 확인한다.
- [ ] `56.03` Parsing the Command Line · Private Data: 초기화 흐름과 사적 데이터 전달을 읽고, 콜백 하나에 로그 항목을 직접 추가해 다시 빌드한다. 추가한 항목이 로그에 나오는지 확인한다.
- [ ] `56.04` Unclear FUSE Functions · Security: 두 절을 읽고, 다른 사용자가 마운트 지점에 접근할 때의 동작을 실험해 결과를 기록한다.
## 68 blockchain

원본: [README → Uncategorized](../README.md#uncategorized)

* A dummy blockchain implementation in C
  * [Part 1](https://myram.xyz/c-blockchain-implementation-1/)
  * [Part 2](https://myram.xyz/c-blockchain-implementation-2/)

> **원문 메모**
>
> 원문은 짧은 글 두 편이다. 1편은 블록 구조체·djb2 해시·연결 리스트, 2편은 투표 예제(정당 enum, genesis 블록, 블록 추가)다. 작업 증명과 nonce는 나오지 않는다. 기존 회차가 그것을 적고 있어 원문에 맞게 고치고 2회차로 줄였다.

### Daily TODO

- [ ] `68.01` 1편: 블록 구조체, 문자열 해시, 연결 리스트를 만든다. 같은 입력의 해시가 같고 블록이 추가한 순서대로 연결되는지 확인한다.
- [ ] `68.02` 2편: genesis 블록 뒤에 투표 블록을 이어 붙인다. 각 블록의 이전 해시가 앞 블록의 해시와 같은지 출력으로 확인하고, 블록 하나를 바꾸면 그 뒤가 어긋나는지 직접 실험해 본다(원문 밖 실험).
