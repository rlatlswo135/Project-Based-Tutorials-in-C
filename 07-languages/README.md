# 07. 언어 구현

매칭·파싱·평가를 따로 구현한 뒤 메모리 관리·바이트코드·코드 생성으로 확장한다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

아래 모든 항목을 진행한다. 전체 학습 순서는 [로드맵](../ROADMAP.md)을 따른다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

회차는 2026-11-20에 원문 목차와 재생 시간을 대조해 나눴다. 항목마다 `원문 메모`에 근거와 확인하지 못한 부분을 적었다. 영상 항목은 제목과 길이만 보고 나눈 것이라, 실제 내용과 다르면 그날 줄을 고친다.

| 원본 번호 | 순서 · 작업 폴더 |
|---|---|
| 59 | [`regex-small/`](#59-regex-small) |
| 60 | [`regex-nfa/`](#60-regex-nfa) |
| 62 | [`lisp/`](#62-lisp) |
| 67 | [`scheme/`](#67-scheme) |
| 61 | [`gc-baby/`](#61-gc-baby) |
| 66 | [`gc-conservative/`](#66-gc-conservative) |
| 63 | [`crafting-interpreters/`](#63-crafting-interpreters) |
| 65 | [`c-interpreter/`](#65-c-interpreter) |
| 64 | [`c-x86-compiler/`](#64-c-x86-compiler) |

## 환경

현재 Mac(Apple Silicon)에서 2026-11-20에 확인한 상태다.

- 59·60·62·67·61은 macOS에서 할 수 있다. 63의 jlox에는 JDK가 필요하다(`java` 명령은 있다).
- 66·65·64는 x86 Linux 컨테이너에서 한다(32비트 빌드와 x86 어셈블리).

## 59 regex-small

원본: [README → Programming Languages](../README.md#programming-languages)

* [A Regular Expression Matcher](https://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html)

### Daily TODO

- [ ] `59.01` 문자와 `.`의 매칭을 작성한다. 일치·불일치·빈 문자열을 확인한다.
- [ ] `59.02` `^`, `$`, `*`를 처리해 전체 문자열과 부분 일치를 비교한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 60 regex-nfa

원본: [README → Programming Languages](../README.md#programming-languages)

* [A Regular Expression Matching Can Be Simple And Fast](https://swtch.com/~rsc/regexp/regexp1.html)

> **원문 메모**
>
> 원문 구성: Regular Expressions · Finite Automata · Converting Regular Expressions to NFAs · Search Algorithms · Implementation(Compiling to NFA · Simulating the NFA) · Performance · Caching the NFA to build a DFA. DFA 캐싱 절을 위한 회차를 하나 더했다.

### Daily TODO

- [ ] `60.01` 리터럴과 연결을 Thompson NFA로 구성한다. 상태 그래프를 그려 원문의 그림과 비교한다.
- [ ] `60.02` 선택과 반복(`|` `*` `+` `?`)을 추가한다. 두 분기가 동시에 활성화되는 입력을 검사한다.
- [ ] `60.03` 상태 집합으로 NFA를 시뮬레이션한다. 59번과 겹치는 문법에서 결과를 대조하고, 원문의 병적인 입력에서 처리 시간을 잰다.
- [ ] `60.04` NFA 상태 집합을 DFA 상태로 캐시한다. 같은 입력에서 앞 회차 구현과 결과가 같고 시간이 줄었는지 비교한다.
## 62 lisp

원본: [README → Programming Languages](../README.md#programming-languages)

* [Build Your Own Lisp](http://www.buildyourownlisp.com/) `book`

> **원문 메모**
>
> 원문은 16개 장과 부록이다(1 Introduction · 2 Installation · 3 Basics · 4 An Interactive Prompt · 5 Languages · 6 Parsing · 7 Evaluation · 8 Error Handling · 9 S-Expressions · 10 Q-Expressions · 11 Variables · 12 Functions · 13 Conditionals · 14 Strings · 15 Standard Library · 16 Bonus Projects). 기존 5회차를 장 기준으로 다시 나눴다. 9장과 12장은 길어서 넘치면 줄을 추가한다.

### Daily TODO

- [ ] `62.01` 1~3장: 환경을 갖추고 C 기초 예제를 빌드한다. 장 끝의 연습 문제 중 하나를 푼다.
- [ ] `62.02` 4장 An Interactive Prompt: 입력을 되돌려 주는 프롬프트를 만든다. 줄 편집과 입력 기록이 동작하는지 확인한다.
- [ ] `62.03` 5장 Languages: 파서 조합기 라이브러리로 원문의 예제 문법을 정의한다. 문법에 맞는 문장과 맞지 않는 문장을 하나씩 넣어 본다.
- [ ] `62.04` 6장 Parsing: 폴란드 표기법 문법으로 입력을 파싱한다. 파싱 트리를 출력해 구조를 확인하고 문법 오류의 메시지를 확인한다.
- [ ] `62.05` 7장 Evaluation: 파싱 트리를 평가한다. 중첩된 식의 결과를 손 계산과 비교한다.
- [ ] `62.06` 8장 Error Handling: 오류 값을 도입한다. 0으로 나누기와 잘못된 연산자가 프로그램을 죽이지 않는지 확인한다.
- [ ] `62.07` 9장 S-Expressions: S-expression을 읽고 평가한다. 메모리를 해제하는 경로를 sanitizer로 확인한다.
- [ ] `62.08` 10장 Q-Expressions: Q-expression과 리스트 내장 함수를 만든다. 빈 리스트와 잘못된 인자 타입의 오류를 확인한다.
- [ ] `62.09` 11장 Variables: 환경과 변수 정의를 만든다. 정의한 뒤 다시 조회하고, 정의되지 않은 이름의 오류를 확인한다.
- [ ] `62.10` 12장 Functions: 사용자 정의 함수를 만든다. 부분 적용과, 스코프가 다른 같은 이름을 테스트한다.
- [ ] `62.11` 13장 Conditionals: 비교와 조건을 만든다. 재귀 함수 하나를 정의해 실행한다.
- [ ] `62.12` 14장 Strings: 문자열과 파일 로딩을 만든다. 이스케이프 문자가 든 문자열과 소스 파일 실행을 확인한다.
- [ ] `62.13` 15장 Standard Library: 표준 라이브러리를 직접 만든 언어로 작성한다. 라이브러리 함수 몇 개를 호출해 결과를 확인한다.
- [ ] `62.14` 16장 Bonus Projects: 제시된 과제 중 하나를 골라 구현하고, 고른 과제와 결과를 기록한다. 부록은 읽는다.
## 67 scheme

원본: [README → Programming Languages](../README.md#programming-languages)

* Scheme from Scratch
  * [Part 1 - Introduction](http://peter.michaux.ca/articles/scheme-from-scratch-introduction)
  * [Part 2 - Integers](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_1-integers)
  * [Part 3 - Booleans](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_2-booleans)
  * [Part 4 - Characters](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_3-characters)
  * [Part 5 - Strings](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_4-strings)
  * [Part 6 - The Empty List](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_5-the-empty-list)
  * [Part 7 - Pairs](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_6-pairs)
  * [Part 8 - Symbols](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_7-symbols)
  * [Part 9 - Quote](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_8-quote)
  * [Part 10 - Environments](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_9-environments)
  * [Part 11 - if](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_10-if)
  * [Part 12 - Primitive Procedures Part 1](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_11-primitive-procedures-part-1)
  * [Part 13 - Primitive Procedures Part 2](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_12-primitive-procedures-part-2)
  * [Part 14 - Lambda the Ultimate](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_13-lambda-the-ultimate)
  * [Part 15 - Begin](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_14-begin)
  * [Part 16 - Cond](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_15-cond)
  * [Part 17 - Let](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_16-let)
  * [Part 18 - And and Or](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_17-and-and-or)
  * [Part 19 - Apply](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_18-apply)
  * [Part 20 - Eval](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_19-eval)
  * [Part 21 - I/O](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_20-io)
  * [Part 22 - Standard Library](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_21-standard-library)
  * [Part 23 - Garbage Collection](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-v0_22-garbage-collection)
  * [Part 24 - Conclusion](http://peter.michaux.ca/articles/scheme-from-scratch-bootstrap-conclusion)

### Daily TODO

- [ ] `67.01` 2~4편: 정수·불리언·문자를 읽고 출력한 결과를 원본 입력과 비교한다.
- [ ] `67.02` 5~6편: 이스케이프 문자열과 빈 리스트를 처리한다.
- [ ] `67.03` 7~8편: pair와 interned symbol을 만들고 중첩 리스트를 읽는다.
- [ ] `67.04` 9~10편: `quote`와 환경 조회를 연결한다. 미정의 이름 오류를 확인한다.
- [ ] `67.05` 11~13편: `if`와 원시 연산을 연결한다. 선택되지 않은 분기가 평가되지 않는지 확인한다.
- [ ] `67.06` 14~15편: `lambda`와 `begin`을 연결한다. 클로저에서 외부 이름을 조회한다.
- [ ] `67.07` 16~18편: `cond`·`let`·`and`/`or`를 두 동작씩 검증하고 필요 시 하루를 나눈다.
- [ ] `67.08` 19~20편: `apply`·`eval`을 원문 예제 입력으로 검증한다.
- [ ] `67.09` 21~22편: I/O와 표준 라이브러리 예제를 파일 하나로 재현한다.
- [ ] `67.10` 23~24편: GC를 연결하고 접근 가능한 객체가 보존되는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 61 gc-baby

원본: [README → Programming Languages](../README.md#programming-languages)

* [Baby's First Garbage Collector](http://journal.stuffwithstuff.com/2013/12/08/babys-first-garbage-collector/)

### Daily TODO

- [ ] `61.01` VM 객체와 root 스택을 만든다. 중첩 pair의 접근 여부를 표시한다.
- [ ] `61.02` mark와 sweep을 연결한다. 도달 불가 객체만 회수되는지 확인한다.
- [ ] `61.03` 순환 그래프와 연속 수집을 테스트한다. 살아남은 객체 수를 비교한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 66 gc-conservative

원본: [README → Programming Languages](../README.md#programming-languages)

* [Writing a Simple Garbage Collector in C](http://maplant.com/gc.html)

> **원문 메모**
>
> 원문은 Linux의 `sbrk`와 프로세스 메모리 배치를 전제로 한다(Making the malloc · Mark and Sweep: Scanning the heap, Scanning the contiguous regions · Caveats). Linux 컨테이너에서 한다.

### Daily TODO

- [ ] `66.01` 로컬 샘플 주소 범위와 할당 메타데이터를 표시하고 소스의 플랫폼 가정을 기록한다.
- [ ] `66.02` 루트 후보를 분류하고 올바른 주소와 비객체 주소를 구분한다.
- [ ] `66.03` mark/sweep 결과를 샘플 객체 그래프로 비교한다. 보수적 스캔의 오탐 사례를 기록한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 63 crafting-interpreters

원본: [README → Programming Languages](../README.md#programming-languages)

* [Crafting Interpreters](http://www.craftinginterpreters.com/) `book` `in-progress`

> **원문 메모**
>
> 원문은 30개 장이다. 1~3장은 도입, 4~13장은 Java 구현(jlox), 14~30장은 C 구현(clox)이다. 기존 9회차는 「나중에 쪼갠다」로 남긴 줄이 많아 장 기준으로 다시 나눴다. 긴 장은 2회차로 잡았다.
>
> 각 장의 확인은 본문 예제 실행을 기본으로 하고, 책 저장소에 장별 테스트가 있으면 그것을 돌린다. jlox에는 JDK가 필요하다.

### Daily TODO

- [ ] `63.01` 1~3장(Introduction · A Map of the Territory · The Lox Language): 읽고 Lox 예제 프로그램 몇 개를 손으로 따라가 예상 출력을 적는다. JDK와 C 컴파일러를 작은 빌드로 확인한다.
- [ ] `63.02` jlox 4장 Scanning: 스캐너를 만든다. 토큰 종류와 줄 번호를 대조하고 닫히지 않은 문자열의 오류를 확인한다.
- [ ] `63.03` jlox 5장 Representing Code: 구문 트리 클래스와 출력기를 만든다. 책의 예제 식이 같은 문자열로 출력되는지 확인한다.
- [ ] `63.04` jlox 6장 Parsing Expressions: 식 파서를 만든다. 연산 우선순위와 결합 방향을 트리 출력으로 확인한다.
- [ ] `63.05` jlox 7장 Evaluating Expressions: 식을 평가한다. 타입이 맞지 않는 연산의 런타임 오류를 확인한다.
- [ ] `63.06` jlox 8장 Statements and State 앞부분: 문장과 전역 변수를 만든다.
- [ ] `63.07` jlox 8장 뒷부분: 대입과 블록 스코프를 만든다. 가려진 이름이 블록 밖에서 복원되는지 확인한다.
- [ ] `63.08` jlox 9장 Control Flow: 조건과 반복을 만든다. 책의 피보나치 예제를 실행한다.
- [ ] `63.09` jlox 10장 Functions 앞부분: 함수 호출과 내장 함수를 만든다. 인자 개수가 다른 호출의 오류를 확인한다.
- [ ] `63.10` jlox 10장 뒷부분: 함수 선언, 반환, 클로저를 만든다. 책의 카운터 예제를 실행한다.
- [ ] `63.11` jlox 11장 Resolving and Binding: 변수 해석 단계를 만든다. 책이 보여 주는 클로저 스코프 문제가 고쳐졌는지 확인한다.
- [ ] `63.12` jlox 12장 Classes 앞부분: 클래스 선언, 인스턴스, 필드를 만든다.
- [ ] `63.13` jlox 12장 뒷부분: 메서드, `this`, 초기화자를 만든다. 클래스 밖에서 `this`를 쓰면 오류인지 확인한다.
- [ ] `63.14` jlox 13장 Inheritance: 상속과 `super`를 만든다. 재정의한 메서드에서 상위 메서드를 부르는 예제를 실행한다.
- [ ] `63.15` clox 14장 Chunks of Bytecode: 청크와 디스어셈블러를 만든다. 상수 하나와 반환 명령이 든 청크의 출력을 책과 비교한다.
- [ ] `63.16` clox 15장 A Virtual Machine: VM 실행 루프와 값 스택을 만든다. 산술 명령으로 된 청크의 결과를 확인한다.
- [ ] `63.17` clox 16장 Scanning on Demand: 스캐너를 만든다. 소스 한 줄의 토큰 출력을 책과 비교한다.
- [ ] `63.18` clox 17장 Compiling Expressions 앞부분: 단일 패스 컴파일러의 골격과 숫자·괄호·단항 연산을 만든다.
- [ ] `63.19` clox 17장 뒷부분: 우선순위 표로 이항 연산을 컴파일한다. 연산 우선순위가 바이트코드 순서에 반영됐는지 디스어셈블로 확인한다.
- [ ] `63.20` clox 18장 Types of Values: 값 타입(nil, 불리언, 숫자)과 런타임 오류를 만든다.
- [ ] `63.21` clox 19장 Strings: 문자열 객체와 연결을 만든다. 종료할 때 객체가 모두 해제되는지 확인한다.
- [ ] `63.22` clox 20장 Hash Tables: 해시 테이블과 문자열 인터닝을 만든다. 내용이 같은 문자열이 같은 객체가 되는지 확인한다.
- [ ] `63.23` clox 21장 Global Variables: 전역 변수와 문장을 만든다. 정의되지 않은 변수의 오류를 확인한다.
- [ ] `63.24` clox 22장 Local Variables: 지역 변수와 스코프를 만든다. 전역과 지역의 바이트코드 차이를 디스어셈블로 확인한다.
- [ ] `63.25` clox 23장 Jumping Back and Forth: 조건·반복의 점프를 만든다. 반복문의 점프 오프셋을 디스어셈블로 확인한다.
- [ ] `63.26` clox 24장 Calls and Functions 앞부분: 함수 객체와 호출 프레임을 만든다.
- [ ] `63.27` clox 24장 뒷부분: 인자, 반환, 내장 함수, 스택 추적을 만든다. 책의 피보나치로 실행 시간을 잰다.
- [ ] `63.28` clox 25장 Closures 앞부분: 클로저 객체와 upvalue 캡처를 만든다.
- [ ] `63.29` clox 25장 뒷부분: 닫힌 upvalue를 만든다. 함수가 끝난 뒤에도 캡처한 변수가 살아 있는 예제를 실행한다.
- [ ] `63.30` clox 26장 Garbage Collection 앞부분: 루트 표시와 객체 추적을 만든다.
- [ ] `63.31` clox 26장 뒷부분: 회수와 수집 시점 조절을 만든다. 책의 스트레스 모드로 테스트해 죽지 않는지 확인한다.
- [ ] `63.32` clox 27장 Classes and Instances: 클래스, 인스턴스, 필드를 만든다.
- [ ] `63.33` clox 28장 Methods and Initializers: 메서드, `this`, 초기화자를 만든다.
- [ ] `63.34` clox 29장 Superclasses: 상속과 `super` 호출을 만든다.
- [ ] `63.35` clox 30장 Optimization: 해시 테이블 탐사 최적화와 NaN boxing을 적용한다. 적용 전후의 벤치마크 시간을 비교한다. 부록은 읽는다.
## 65 c-interpreter

원본: [README → Programming Languages](../README.md#programming-languages)

* Write a C Interpreter
  * [Part 0 - Preface](https://github.com/lotabout/write-a-C-interpreter/blob/master/tutorial/en/0-Preface.md)
  * [Part 1 - Skeleton](https://github.com/lotabout/write-a-C-interpreter/blob/master/tutorial/en/1-Skeleton.md)
  * [Part 2 - Virtual Machine](https://github.com/lotabout/write-a-C-interpreter/blob/master/tutorial/en/2-Virtual-Machine.md)
  * [Part 3 - Lexer](https://github.com/lotabout/write-a-C-interpreter/blob/master/tutorial/en/3-Lexer.md)
  * [Part 4 - Top-down Parsing](https://github.com/lotabout/write-a-C-interpreter/blob/master/tutorial/en/4-Top-down-Parsing.md)
  * [Part 5 - Variables](https://github.com/lotabout/write-a-C-interpreter/blob/master/tutorial/en/5-Variables.md)
  * [Part 6 - Functions](https://github.com/lotabout/write-a-C-interpreter/blob/master/tutorial/en/6-Functions.md)
  * [Part 7 - Statements](https://github.com/lotabout/write-a-C-interpreter/blob/master/tutorial/en/7-Statements.md)
  * [Part 8 - Expressions](https://github.com/lotabout/write-a-C-interpreter/blob/master/tutorial/en/8-Expressions.md)

> **원문 메모**
>
> 원문은 0~8편이다. 포인터를 정수에 담는 코드라 32비트 빌드(`-m32`)를 전제로 한다. x86 Linux 컨테이너에서 한다. 8편(Expressions)이 가장 길어 2회차로 나눴다.

### Daily TODO

- [ ] `65.01` 0~1편: 스켈레톤을 32비트로 빌드한다. 빈 소스와 없는 파일의 동작을 확인한다.
- [ ] `65.02` 2편: VM 명령을 구현한다. 손으로 쓴 명령열로 스택·산술·호출 동작을 확인한다.
- [ ] `65.03` 3편: 렉서를 만든다. 식별자·숫자·문자열·연산자의 토큰 출력을 비교한다.
- [ ] `65.04` 4편: 하향식 파싱을 읽고 원문의 계산기 예제를 구현한다. 좌재귀를 없앤 문법으로 식 몇 개를 계산한다.
- [ ] `65.05` 5~6편: 전역 선언·enum·함수 정의를 파싱한다. 매개변수와 지역 변수의 위치가 맞는지 확인한다.
- [ ] `65.06` 7편: 조건·반복·반환 문장을 만든다. 생성된 VM 코드의 점프 위치를 확인한다.
- [ ] `65.07` 8편 앞부분: 상수·변수·함수 호출·단항 연산의 코드를 생성한다.
- [ ] `65.08` 8편 뒷부분: 이항 연산의 우선순위를 처리한다. 완성한 인터프리터로 예제 프로그램을 실행하고, 인터프리터 자신의 소스를 넣어 본다.
## 64 c-x86-compiler

원본: [README → Programming Languages](../README.md#programming-languages)

* [Let's Build a Compiler: A C & x86 version](https://github.com/lotabout/Let-s-build-a-compiler)

> **원문 메모**
>
> 저장소는 Crenshaw의 「Let's Build a Compiler」 16개 장을 C와 x86으로 옮긴 것이며 폴더 1~16으로 되어 있다. 기존 5회차를 장 기준으로 다시 나눴다. 장 제목은 원저 연재의 것을 기억으로 적었다(미확인).
>
> 32비트 x86 어셈블리를 출력하므로 x86 Linux 컨테이너에서 어셈블·실행한다.

### Daily TODO

- [ ] `64.01` 1장(Introduction): x86 Linux 환경에서 생성된 어셈블리를 어셈블·링크·실행하는 절차를 확인한다. 가장 작은 출력물의 종료값을 확인한다.
- [ ] `64.02` 2장(Expression Parsing): 식을 파싱해 코드를 낸다. 식 하나의 실행 결과를 손 계산과 비교한다.
- [ ] `64.03` 3장(More Expressions): 변수·함수 호출·대입을 추가한다.
- [ ] `64.04` 4장(Interpreters): 같은 문법을 인터프리터로 실행해 컴파일러의 결과와 비교한다.
- [ ] `64.05` 5장(Control Constructs): 조건·반복 구문의 분기 코드를 낸다. 생성된 라벨과 점프를 읽어 확인한다.
- [ ] `64.06` 6장(Boolean Expressions): 불리언 식과 관계 연산을 추가한다.
- [ ] `64.07` 7장(Lexical Scanning): 여러 글자 토큰을 읽는 스캐너를 붙인다.
- [ ] `64.08` 8~9장(A Little Philosophy · A Top View): 읽고, 프로그램 최상위 구조를 파싱하는 골격을 만든다.
- [ ] `64.09` 10장(Introducing "Tiny"): 작은 언어 전체를 컴파일한다. 완성 프로그램 하나를 실행한다.
- [ ] `64.10` 11장(Lexical Scan Revisited): 스캐너 구조를 고친다. 10장의 프로그램이 그대로 동작하는지 확인한다.
- [ ] `64.11` 12장(Miscellany): 세미콜론과 주석 처리를 추가한다.
- [ ] `64.12` 13장(Procedures): 프로시저와 인자 전달을 만든다. 호출 전후의 스택 정리를 디스어셈블로 확인한다.
- [ ] `64.13` 14장(Types): 타입별 코드를 낸다. 크기가 다른 타입 사이의 대입 결과를 확인한다.
- [ ] `64.14` 15~16장(Back to the Future · Unit Construction): 모듈 단위로 다시 구성한다. 마지막 장의 예제를 빌드해 실행한다.
