# 07. 언어 구현

매칭·파싱·평가를 따로 구현한 뒤 메모리 관리·바이트코드·코드 생성으로 확장한다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

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

### Daily TODO

- [ ] `60.01` 리터럴과 연결을 Thompson NFA로 구성하고 상태 그래프를 그려 비교한다.
- [ ] `60.02` 선택과 반복을 추가한다. 두 분기가 동시에 활성화되는 입력을 검사한다.
- [ ] `60.03` 59번과 겹치는 문법에서 결과를 대조하고, 긴 실패 입력에서 처리 시간 차이를 측정한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 62 lisp

원본: [README → Programming Languages](../README.md#programming-languages)

* [Build Your Own Lisp](http://www.buildyourownlisp.com/) `book`

### Daily TODO

- [ ] `62.01` 입력 파서로 S-expression과 수치를 읽고 출력한다.
- [ ] `62.02` 연산자 평가와 오류 값을 연결한다. 잘못된 인자 타입을 검증한다.
- [ ] `62.03` 리스트·심벌 환경을 만든다. 변수를 정의한 뒤 다시 조회한다.
- [ ] `62.04` 함수·조건 분기를 붙인다. 스코프가 다른 같은 이름을 테스트한다.
- [ ] `62.05` 소스에서 다루는 문자열·파일 로딩·표준 함수가 있는 예제를 별도 입력으로 실행한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

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

### Daily TODO

- [ ] `66.01` 로컬 샘플 주소 범위와 할당 메타데이터를 표시하고 소스의 플랫폼 가정을 기록한다.
- [ ] `66.02` 루트 후보를 분류하고 올바른 주소와 비객체 주소를 구분한다.
- [ ] `66.03` mark/sweep 결과를 샘플 객체 그래프로 비교한다. 보수적 스캔의 오탐 사례를 기록한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 63 crafting-interpreters

원본: [README → Programming Languages](../README.md#programming-languages)

* [Crafting Interpreters](http://www.craftinginterpreters.com/) `book` `in-progress`

### Daily TODO

- [ ] `63.01` 책의 두 구현과 챕터 범위를 기록한다. jlox·clox에 필요한 도구를 각각 작은 빌드로 확인한다.
- [ ] `63.02` jlox: 첫 토큰 스캐너를 구현하고 토큰 종류·줄 번호를 대조한다.
- [ ] `63.03` jlox: 표현식 파싱과 평가를 이어 연산 우선순위를 확인한다.
- [ ] `63.04` jlox: 문장·변수·제어 흐름 중 다음 한 챕터를 구현하고 책 예제를 실행한다.
- [ ] `63.05` jlox: 함수와 이름 해석을 검증한다. 클래스·상속 챕터는 별도 회차를 추가한다.
- [ ] `63.06` clox: 바이트코드와 VM 루프를 만들고 작은 chunk의 출력을 비교한다.
- [ ] `63.07` clox: 표현식 컴파일을 연결하고 전역·지역 이름의 코드 차이를 확인한다.
- [ ] `63.08` clox: 점프·호출·클로저 챕터를 회차별로 쪼개고 첫 점프 프로그램을 확인한다.
- [ ] `63.09` clox: GC·클래스·상속은 챕터별로 쪼갠다. 첫 GC 테스트에서 root 유지 여부를 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

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

### Daily TODO

- [ ] `65.01` 0~1편: 스켈레톤을 빌드하고 빈 소스·없는 파일의 동작을 확인한다.
- [ ] `65.02` 2편: VM 명령으로 스택·산술·호출 동작을 확인한다.
- [ ] `65.03` 3편: 식별자·숫자·연산자의 토큰 출력을 비교한다.
- [ ] `65.04` 4편: 선언을 파싱하고 올바르지 않은 선언을 거른다.
- [ ] `65.05` 5~6편: 변수·함수를 연결한다. 가려진 이름과 반환값을 확인한다.
- [ ] `65.06` 7편: 조건·반복을 검증한다. 루프 종료 조건을 각각 실행한다.
- [ ] `65.07` 8편: 표현식 우선순위를 확인하고 완성 프로그램을 예제로 실행한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 64 c-x86-compiler

원본: [README → Programming Languages](../README.md#programming-languages)

* [Let's Build a Compiler: A C & x86 version](https://github.com/lotabout/Let-s-build-a-compiler)

### Daily TODO

- [ ] `64.01` 원문의 대상 x86 환경에서 최소 어셈블리 출력물을 빌드·실행한다.
- [ ] `64.02` 토큰과 AST를 추가한다. 연산 우선순위가 트리에 맞는지 확인한다.
- [ ] `64.03` 산술식의 코드 생성을 연결하고 한 프로그램의 종료값을 비교한다.
- [ ] `64.04` 변수·조건 분기의 생성 결과를 디스어셈블 결과와 비교한다.
- [ ] `64.05` 함수 호출과 스택 정리를 확인하고 원문 예제를 마지막 챕터와 대조한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
