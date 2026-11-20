# 05. 게임과 멀티미디어

입력·상태 갱신·그리기 루프를 만들고 충돌, 리소스, 오디오·영상 처리로 확장한다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

회차는 2026-11-20에 원문 목차와 재생 시간을 대조해 나눴다. 항목마다 `원문 메모`에 근거와 확인하지 못한 부분을 적었다. 영상 항목은 제목과 길이만 보고 나눈 것이라, 실제 내용과 다르면 그날 줄을 고친다.

| 원본 번호 | 순서 · 작업 폴더 |
|---|---|
| 29 | [`tetris/`](#29-tetris) |
| 17 | [`rogue/`](#17-rogue) |
| 34 | [`sdl-intro/`](#34-sdl-intro) |
| 32 | [`tic-tac-toe-sdl/`](#32-tic-tac-toe-sdl) |
| 14 | [`brickout/`](#14-brickout) |
| 13 | [`astroids/`](#13-astroids) |
| 25 | [`invaders/`](#25-invaders) |
| 27 | [`video-game-c/`](#27-video-game-c) |
| 28 | [`dangerous-dave/`](#28-dangerous-dave) |
| 18 | [`platformer/`](#18-platformer) |
| 19 | [`shoot-em-up/`](#19-shoot-em-up) |
| 20 | [`top-down-shooter/`](#20-top-down-shooter) |
| 30 | [`isometric/`](#30-isometric) |
| 33 | [`physics/`](#33-physics) |
| 15 | [`chess/`](#15-chess) |
| 21 | [`handmade-hero/`](#21-handmade-hero) |
| 73 | [`svg/`](#73-svg) |
| 71 | [`ffmpeg-libav/`](#71-ffmpeg-libav) |
| 70 | [`video-player/`](#70-video-player) |

## 환경

현재 Mac(Apple Silicon)에서 2026-11-20에 확인한 상태다.

- SDL2와 ffmpeg가 설치돼 있지 않다. 34를 시작할 때 SDL2 계열을, 71을 시작할 때 ffmpeg를 설치한다.
- 14·13·25는 GTK3 + OpenGL 기준이고 창이 필요해 화면 없는 컨테이너로는 안 된다. 14의 첫 회차에 macOS 빌드 여부를 확인하고, 안 되면 화면이 있는 Linux 가상 머신을 재개 조건으로 적는다.
- 21은 Windows(Win32, MSVC) 기준이다.

## 29 tetris

원본: [README → Game Development](../README.md#game-development)

* [On Tetris and Reimplementation](https://brennan.io/2015/06/12/tetris-reimplementation/)

> **원문 메모**
>
> 원문은 단계별 튜토리얼이 아니라 구현 회고 글이다(Making C GUIs · Game Logic · User Interface). 글에 링크된 저장소의 코드를 읽으며 직접 구현한다. ncurses를 쓴다.

### Daily TODO

- [ ] `29.01` 격자와 블록 이동을 구현한다. 좌우 경계를 넘어가지 않는지 확인한다.
- [ ] `29.02` 회전·낙하와 바닥 고정을 만든다. 가려진 회전이 판을 손상하지 않는지 확인한다.
- [ ] `29.03` 줄 제거·점수·게임오버를 테스트 배치로 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 17 rogue

원본: [README → Game Development](../README.md#game-development)

* [Coding a Rogue/Nethack RPG in C](https://www.youtube.com/playlist?list=PLkTXsX7igf8erbWGYT4iSAhpnJLJ0Nk5G) `video`

> **원문 메모**
>
> 재생목록은 26편, 총 449분이다(편당 4~43분). 영상 30~45분을 1회차로 묶었다. 편별 내용은 제목이 「Part N」뿐이라 확인하지 못했다.
>
> 영상 회차의 공통 확인: 그 구간 끝까지의 코드를 빌드·실행하고, 그날 새로 생긴 동작 하나를 다시 재현할 수 있는 입력이나 조작 순서와 함께 작업 폴더에 적는다.
>
> 예상 흐름(미확인): 문자 지도와 이동 → 방과 통로 → 적의 턴 → 아이템과 전투.

### Daily TODO

- [ ] `17.01` 1~2편(32분).
- [ ] `17.02` 3~4편(30분).
- [ ] `17.03` 5~6편(26분).
- [ ] `17.04` 7~9편(41분).
- [ ] `17.05` 10~11편(32분).
- [ ] `17.06` 12편(43분).
- [ ] `17.07` 13~14편(27분).
- [ ] `17.08` 15~16편(29분).
- [ ] `17.09` 17~18편(25분).
- [ ] `17.10` 19편(23분).
- [ ] `17.11` 20편(40분).
- [ ] `17.12` 21~22편(29분).
- [ ] `17.13` 23편(27분).
- [ ] `17.14` 24~26편(46분). 사망과 재시작처럼 처음부터 끝까지 이어지는 플레이 한 번을 기록한다.
## 34 sdl-intro

원본: [README → Game Development](../README.md#game-development)

* [Writing 2D Games in C using SDL](https://www.youtube.com/watch?v=yFLa3ln16w0) `video`

> **원문 메모**
>
> 영상 한 편, 47분이다. SDL2와 SDL2_image가 필요한데 지금 설치돼 있지 않다.

### Daily TODO

- [ ] `34.01` 영상 앞 절반: SDL2를 설치하고 창·렌더러·텍스처를 만들어 그림 하나를 띄운다. 창을 닫을 때 자원을 해제하는지 확인한다.
- [ ] `34.02` 영상 뒤 절반: 애니메이션과 키보드·마우스 입력을 붙인다. 프레임 간격을 바꿔도 이동 속도가 같은지 비교한다.
## 32 tic-tac-toe-sdl

원본: [README → Game Development](../README.md#game-development)

* [Tic-tac-toe Game in C with SDL](https://www.youtube.com/watch?v=gCVMkKgs3uQ) `video`

> **원문 메모**
>
> 링크는 Part 1(17분, C 구현)이다. Part 2는 같은 게임의 Haskell 버전이라 범위 밖이다.

### Daily TODO

- [ ] `32.01` 셀 좌표와 마우스 클릭 좌표를 매핑한다. 보드 밖 클릭을 거른다.
- [ ] `32.02` 승리 표시와 재시작을 연결한다. CLI판의 승리·무승부 입력을 GUI에서 재생한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 14 brickout

원본: [README → Game Development](../README.md#game-development)

* [Brickout Clone](https://gtk.dashgl.com/?folder=Brickout)

> **원문 메모**
>
> 원문 사이트 `gtk.dashgl.com`은 인증서 오류로 열리지 않는다. 같은 내용이 저자 저장소에 있다: <https://github.com/kion-dgl/DashGL-GTK-Brickout-Tutorial> (17단계).
>
> GTK3 + OpenGL(libepoxy) 기준이며 원문은 Linux에서 설치한다. 창이 떠야 하므로 화면 없는 컨테이너로는 안 된다. 첫 회차에 macOS에서 빌드되는지 먼저 확인한다.

### Daily TODO

- [ ] `14.01` 01~04단계(Open a Window · Draw a Triangle · Separate Shaders · Shader Program): 창에 삼각형을 그린다. 셰이더 컴파일 오류가 났을 때 메시지가 출력되는지 확인한다.
- [ ] `14.02` 05~07단계(Orthagonal Coordinates · Draw a Ball · Set Ball Position): 픽셀 좌표계로 공을 그린다. 지정한 좌표에 공이 놓이는지 두 위치로 확인한다.
- [ ] `14.03` 08~10단계(Move a Ball · Bounce a Ball · Style Ball Struct): 공을 움직이고 벽에서 튕긴다. 네 벽에서 방향이 바뀌는지 확인한다.
- [ ] `14.04` 11~13단계(Draw a Paddle · Paddle Uniform Color · Keydown Callbacks): 패들을 그리고 키로 움직인다. 화면 가장자리에서 멈추는지 확인한다.
- [ ] `14.05` 14단계(Paddle Hit Detection): 공과 패들의 충돌을 판정한다. 패들에 맞을 때와 놓칠 때를 각각 재현한다.
- [ ] `14.06` 15~17단계(Array of Bricks · Grid of Bricks · Break Some Bricks): 벽돌을 깔고 맞으면 한 번만 제거한다. 모든 벽돌이 없어진 뒤의 동작을 확인한다.
## 13 astroids

원본: [README → Game Development](../README.md#game-development)

* [Astroids Clone](https://gtk.dashgl.com/?folder=Astroids)

> **원문 메모**
>
> 원문 사이트는 인증서 오류로 열리지 않는다. 저자 저장소: <https://github.com/kion-dgl/DashGL-GTK-Astroids-Tutorial> (17단계). 환경은 14번과 같다.

### Daily TODO

- [ ] `13.01` 01~04단계(Open a Window · Draw a Triangle · Shader Program · Orthographic Coordinates): 창과 좌표계를 준비한다. 14번에서 쓴 구조와 달라진 점을 적는다.
- [ ] `13.02` 05~07단계(Draw Player Sprite · Turn Left and Right · Move Player Sprite): 우주선을 그리고 회전·전진시킨다. 네 방향에서 전진 방향이 맞는지 확인한다.
- [ ] `13.03` 08~10단계(Player Acceleration · Player Position · Draw Edge Sprites): 가속과 화면 반대편 래핑을 만든다. 가장자리를 넘을 때 양쪽에 동시에 그려지는지 확인한다.
- [ ] `13.04` 11~12단계(Shoot Bullets · Fragment Shader): 총알을 쏜다. 총알이 일정 거리 뒤 사라지는지 확인한다.
- [ ] `13.05` 13~15단계(Draw Astroid · Astroid Size · Shoot Astroid): 소행성을 그리고 맞힌다. 크기가 다른 소행성의 충돌 범위를 확인한다.
- [ ] `13.06` 16~17단계(Split Astroids · Gameover Screen): 소행성 분할과 게임오버를 만든다. 난수 seed를 고정해 같은 판을 재현한다.
## 25 invaders

원본: [README → Game Development](../README.md#game-development)

* [Invaders Clone](https://gtk.dashgl.com/?folder=Invaders)

> **원문 메모**
>
> 원문 사이트는 인증서 오류로 열리지 않는다. 저자 저장소: <https://github.com/kion-dgl/DashGL-GTK-Invaders-Tutorial> (18단계). 환경은 14번과 같다.

### Daily TODO

- [ ] `25.01` 01~04단계(Open A Window · Draw A Triangle · Shader Program · Orthographic Coords): 창과 좌표계를 준비한다.
- [ ] `25.02` 05~07단계(Draw Background · Background Image · Uniform Matrix): 배경 이미지를 그린다. 없는 이미지 파일의 처리를 확인한다.
- [ ] `25.03` 08~11단계(Player Sprite · Move Player · Draw Bullet · Shoot Bullet): 플레이어를 움직이고 총알을 쏜다. 총알이 화면 밖에서 제거되는지 확인한다.
- [ ] `25.04` 12~14단계(Draw Enemy · Draw Enemies · Move Enemies): 적 편대를 그리고 움직인다. 경계에서 방향을 바꾸고 내려오는지 확인한다.
- [ ] `25.05` 15~16단계(Shoot Enemies · Enemies Shoot Back): 적을 맞히고 적이 쏘게 한다. 총알 하나가 한 번만 피해를 주는지 확인한다.
- [ ] `25.06` 17~18단계(Player Hit Detect · Gameover Screen): 피격과 게임오버를 만든다. 패배와 재시작을 실행한다.
## 27 video-game-c

원본: [README → Game Development](../README.md#game-development)

* [Learn Video Game Programming in C](https://www.youtube.com/playlist?list=PLT6WFYYZE6uLMcPGS3qfpYm7T_gViYMMt) `video`

> **원문 메모**
>
> 재생목록은 20편, 총 261분이다. Episode 1~5는 C 기초(연산자·흐름 제어·배열·구조체), 6~16은 게임(APIs · Event Loops · Pointers · Drawing Images · Collision detection 1~2 · Modularizing · Drawing Text · Dynamic Memory · Scrolling and Enemies · Sound Effects), 나머지 3편은 완성 게임 시연과 부록이다.
>
> 영상 회차의 공통 확인: 그 구간 끝까지의 코드를 빌드·실행하고, 그날 새로 생긴 동작 하나를 다시 재현할 수 있는 입력이나 조작 순서와 함께 작업 폴더에 적는다.

### Daily TODO

- [ ] `27.01` Episode 1(2편)~2 (34분): C 기초. 예제를 빌드하고 연산자 예제의 출력을 영상과 비교한다.
- [ ] `27.02` Episode 3~5 (34분): 흐름 제어·배열·구조체. 각 주제의 예제를 하나씩 직접 고쳐 실행한다.
- [ ] `27.03` Episode 6~7 (30분): API와 이벤트 루프. 창을 띄우고 종료 이벤트로 정상 종료하는지 확인한다.
- [ ] `27.04` Episode 8~9 (38분): 포인터와 이미지 그리기. 이미지 하나를 그리고 없는 파일의 처리를 확인한다.
- [ ] `27.05` Episode 10~11 (30분): 충돌 판정. 겹침과 분리 상태를 각각 재현한다.
- [ ] `27.06` Episode 12~13 (26분): 모듈 분리와 글자 그리기. 파일을 나눈 뒤에도 같은 동작인지 확인한다.
- [ ] `27.07` Episode 14~15 (24분): 동적 메모리, 스크롤과 적. 화면 밖으로 나간 적의 메모리가 해제되는지 확인한다.
- [ ] `27.08` Episode 16과 시연 영상(14분): 효과음. 완성 게임을 처음부터 종료 조건까지 한 번 플레이한다.
- [ ] `27.09` 부록 「Simple Gun Shooting」(30분): 발사 동작을 붙이고 총알의 생성과 제거를 확인한다.
## 28 dangerous-dave

원본: [README → Game Development](../README.md#game-development)

* [Let's Make: Dangerous Dave](https://www.youtube.com/playlist?list=PLSkJey49cOgTSj465v2KbLZ7LMn10bCF9) `video`

> **원문 메모**
>
> 재생목록은 10편, 총 117분이다. 편별 내용은 제목이 「Part N」뿐이라 확인하지 못했다.
>
> 원작 게임 파일에서 타일과 레벨을 꺼내 쓰는 구성으로 기억한다(미확인). 첫 회차에 필요한 원본 파일을 확인한다.
>
> 영상 회차의 공통 확인: 그 구간 끝까지의 코드를 빌드·실행하고, 그날 새로 생긴 동작 하나를 다시 재현할 수 있는 입력이나 조작 순서와 함께 작업 폴더에 적는다.
>
> 예상 흐름(미확인): 타일 추출 → 레벨 로드 → 렌더 → 이동·점프·충돌 → 보물·열쇠·출구.

### Daily TODO

- [ ] `28.01` 1~2편(24분).
- [ ] `28.02` 3~4편(18분).
- [ ] `28.03` 5~6편(34분).
- [ ] `28.04` 7~8편(23분).
- [ ] `28.05` 9~10편(18분). 첫 레벨을 시작부터 출구까지 한 번 플레이하고 과정을 기록한다.
## 18 platformer

원본: [README → Game Development](../README.md#game-development)

* [Creating a 2D platformer](https://www.parallelrealities.co.uk/tutorials/#ppp)

> **원문 메모**
>
> 원문 「2D platformer」는 6편이다. 기존 3회차를 편당 1회차로 다시 나눴다. 첫 회차에 소스 제공 방식(본문 코드만인지, 전체 소스가 따로인지)을 확인한다.

### Daily TODO

- [ ] `18.01` 1편 Loading and displaying the map: 타일 맵 파일을 읽어 그린다. 잘못된 타일 값의 처리를 확인한다.
- [ ] `18.02` 2편 Scrolling the map: 맵을 스크롤한다. 맵 가장자리에서 카메라가 멈추고 타일 경계가 이어지는지 확인한다.
- [ ] `18.03` 3편 Controlling the character: 중력·점프·좌우 이동과 타일 충돌을 만든다. 모서리에서 끼이지 않는지 확인한다.
- [ ] `18.04` 4편 Interacting with entities: 엔티티와의 상호작용을 붙인다. 닿았을 때 한 번만 반응하는지 확인한다.
- [ ] `18.05` 5편 Moving platforms: 움직이는 발판을 만든다. 발판 위에서 캐릭터가 함께 움직이는지 확인한다.
- [ ] `18.06` 6편 Finishing touches: 마무리 요소를 붙이고 스테이지 하나를 처음부터 끝까지 플레이한다.
## 19 shoot-em-up

원본: [README → Game Development](../README.md#game-development)

* [Creating a 2D shoot 'em up](https://www.parallelrealities.co.uk/tutorials/#shooter)

> **원문 메모**
>
> 원문 「2D shoot 'em up」은 15편이다. 기존 3회차를 다시 나눴다. 앞쪽 짧은 편은 둘씩 묶었다.

### Daily TODO

- [ ] `19.01` 1~2편 Opening a window · Drawing the player: 창을 열고 플레이어를 그린다.
- [ ] `19.02` 3~4편 Moving the player · Firing: 이동과 발사를 만든다. 화면 밖으로 나간 총알이 제거되는지 확인한다.
- [ ] `19.03` 5~6편 Refactoring · Enemies: 구조를 정리하고 적을 등장시킨다. 정리 전후의 동작이 같은지 확인한다.
- [ ] `19.04` 7편 Shooting enemies: 적을 맞힌다. 총알 하나가 적 하나만 없애는지 확인한다.
- [ ] `19.05` 8편 Enemies fighting back!: 적이 쏘게 한다. 플레이어 피격과 재시작을 확인한다.
- [ ] `19.06` 9편 Effects and background graphics: 폭발과 배경을 붙인다. 효과 객체가 끝난 뒤 해제되는지 확인한다.
- [ ] `19.07` 10편 Sound and music: 소리와 음악을 붙인다. 없는 음원 파일의 처리를 확인한다.
- [ ] `19.08` 11편 Bitmap fonts and scoring: 비트맵 글꼴로 점수를 표시한다. 점수 자리수가 늘어날 때의 표시를 확인한다.
- [ ] `19.09` 12편 Score pods: 점수 아이템을 만든다. 획득과 화면 밖 소멸을 각각 확인한다.
- [ ] `19.10` 13편 Highscore table (Part 1): 최고 점수 표를 만든다. 정렬 순서와 표 크기 제한을 확인한다.
- [ ] `19.11` 14편 Highscore table (Part 2): 이름 입력을 붙인다. 빈 이름과 최대 길이 이름을 확인한다.
- [ ] `19.12` 15편 Title screen and finishing touches: 타이틀 화면을 붙이고 시작부터 게임오버, 점수 등록까지 한 번 이어서 실행한다.
## 20 top-down-shooter

원본: [README → Game Development](../README.md#game-development)

* [Creating a 2D top-down shooter](https://www.parallelrealities.co.uk/tutorials/#bad)

> **원문 메모**
>
> 원문 「2D top-down shooter」는 6편이다. 기존 3회차를 편당 1회차로 다시 나눴다.

### Daily TODO

- [ ] `20.01` 1편 Reading the mouse: 마우스 위치를 읽어 조준점을 그린다.
- [ ] `20.02` 2편 Angles and rotation: 플레이어가 조준점을 향해 회전한다. 네 방향에서 각도를 확인한다.
- [ ] `20.03` 3편 Mouse buttons and shooting: 버튼으로 발사한다. 총알이 조준 방향으로 나가는지 확인한다.
- [ ] `20.04` 4편 Battling enemies: 적과의 전투를 만든다. 피격과 탄약 소진을 각각 재현한다.
- [ ] `20.05` 5편 Scrolling the arena: 경기장을 스크롤한다. 화면 좌표와 월드 좌표가 어긋나지 않는지 조준으로 확인한다.
- [ ] `20.06` 6편 Finishing touches: 마무리 요소를 붙이고 시작부터 종료까지 한 판을 실행한다.
## 30 isometric

원본: [README → Game Development](../README.md#game-development)

* [SDL 2 Isometric Game Tutorial](https://www.youtube.com/playlist?list=PL6Ikt4l3NbVjb7WR-eTgjOBMNCn7f3u7x) `video` `in-progress`

> **원문 메모**
>
> 재생목록은 11편인데 총 32시간 52분이다(편당 1시간 30분~5시간 10분의 라이브 코딩). 기존 3회차로는 볼 수조차 없는 분량이라, 영상 약 1시간을 1회차로 잡아 33회차로 나눴다.
>
> 영상 회차의 공통 확인: 그 구간 끝까지의 코드를 빌드·실행하고, 그날 새로 생긴 동작 하나를 다시 재현할 수 있는 입력이나 조작 순서와 함께 작업 폴더에 적는다.
>
> 예상 흐름(미확인): 타일 좌표↔화면 좌표 변환 → 그리기 순서 → 커서로 타일 선택 → ECS → 충돌 → 애니메이션.

### Daily TODO

- [ ] `30.01` Part 1 (1/2): 0:00~1:04 구간.
- [ ] `30.02` Part 1 (2/2): 1:04~끝 구간.
- [ ] `30.03` Part 2 (1/2): 0:00~0:58 구간.
- [ ] `30.04` Part 2 (2/2): 0:58~끝 구간.
- [ ] `30.05` Part 2.5 (1/3): 0:00~0:55 구간.
- [ ] `30.06` Part 2.5 (2/3): 0:55~1:50 구간.
- [ ] `30.07` Part 2.5 (3/3): 1:50~끝 구간.
- [ ] `30.08` Part 3 ECS Session 1 (1/5): 0:00~0:58 구간.
- [ ] `30.09` Part 3 ECS Session 1 (2/5): 0:58~1:56 구간.
- [ ] `30.10` Part 3 ECS Session 1 (3/5): 1:56~2:54 구간.
- [ ] `30.11` Part 3 ECS Session 1 (4/5): 2:54~3:53 구간.
- [ ] `30.12` Part 3 ECS Session 1 (5/5): 3:53~끝 구간.
- [ ] `30.13` Part 3 ECS Session 2 (1/5): 0:00~1:02 구간.
- [ ] `30.14` Part 3 ECS Session 2 (2/5): 1:02~2:04 구간.
- [ ] `30.15` Part 3 ECS Session 2 (3/5): 2:04~3:06 구간.
- [ ] `30.16` Part 3 ECS Session 2 (4/5): 3:06~4:08 구간.
- [ ] `30.17` Part 3 ECS Session 2 (5/5): 4:08~끝 구간.
- [ ] `30.18` Part 3 ECS Session 3 (1/3): 0:00~1:07 구간.
- [ ] `30.19` Part 3 ECS Session 3 (2/3): 1:07~2:15 구간.
- [ ] `30.20` Part 3 ECS Session 3 (3/3): 2:15~끝 구간.
- [ ] `30.21` Part 3 ECS Session 4 (1/4): 0:00~0:54 구간.
- [ ] `30.22` Part 3 ECS Session 4 (2/4): 0:54~1:49 구간.
- [ ] `30.23` Part 3 ECS Session 4 (3/4): 1:49~2:44 구간.
- [ ] `30.24` Part 3 ECS Session 4 (4/4): 2:44~끝 구간. 엔티티를 추가·삭제한 뒤에도 나머지가 그대로 그려지는지 확인한다.
- [ ] `30.25` Part 4 Collision detection (1/2): 0:00~1:03 구간.
- [ ] `30.26` Part 4 Collision detection (2/2): 1:03~끝 구간. 충돌이 타일 경계에서 맞게 판정되는지 확인한다.
- [ ] `30.27` Part 5 Animation (1/3): 0:00~1:05 구간.
- [ ] `30.28` Part 5 Animation (2/3): 1:05~2:11 구간.
- [ ] `30.29` Part 5 Animation (3/3): 2:11~끝 구간. 애니메이션 프레임이 시간에 맞춰 바뀌는지 확인한다.
- [ ] `30.30` Part 6 Bitmap Fonts (1/2): 0:00~0:45 구간.
- [ ] `30.31` Part 6 Bitmap Fonts (2/2): 0:45~끝 구간. 글자 간격과 줄바꿈을 확인한다.
- [ ] `30.32` Part 7 Terrain Generation - Hills (1/2): 0:00~1:00 구간.
- [ ] `30.33` Part 7 Terrain Generation - Hills (2/2): 1:00~끝 구간. 같은 seed에서 같은 지형이 나오는지 확인한다.
## 33 physics

원본: [README → Game Development](../README.md#game-development)

* Video Game Physics Tutorial
  * [Part I: An Introduction to Rigid Body Dynamics](https://www.toptal.com/game/video-game-physics-part-i-an-introduction-to-rigid-body-dynamics)
  * [Part II: Collision Detection for Solid Objects](https://www.toptal.com/game/video-game-physics-part-ii-collision-detection-for-solid-objects)
  * [Part III: Constrained Rigid Body Simulation](https://www.toptal.com/game/video-game-physics-part-iii-constrained-rigid-body-simulation)

> **원문 메모**
>
> 자동 요청에는 403으로 응답하고 보존본도 찾지 못했다. 브라우저에서 열리는지 첫 회차에 확인한다. 본문 내용은 대조하지 못했다.

### Daily TODO

- [ ] `33.01` 1편: 위치·속도·각속도를 적분한다. 힘이 0인 테스트를 재현한다.
- [ ] `33.02` 2편: 겹침과 분리 상태를 가려 접촉점·법선을 표시한다.
- [ ] `33.03` 3편: 충돌 응답으로 공이 바닥에서 튀는 동작을 확인한다.
- [ ] `33.04` 3편 제약 사례를 하나 더 붙인다. 동일 입력에서 시간 간격에 따른 오차를 비교한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 15 chess

원본: [README → Game Development](../README.md#game-development)

* [Chess Engine In C](https://www.youtube.com/playlist?list=PLZ1QII7yudbc-Ky058TEaOstZHVbT-2hg) `video`

> **원문 메모**
>
> 재생목록은 107편이다(확인한 100편이 812분, 편당 평균 8분). 기존 6회차로는 불가능한 분량이라 주제별로 묶어 영상 30~50분을 1회차로 잡았다. 87편이 「Vice 1.0 release, end of series」이고 그 뒤는 추가 연재다. 101~107편의 제목은 확인하지 못했다.
>
> 영상 회차의 공통 확인: 그 구간 끝까지의 코드를 빌드·실행하고, 그날 새로 생긴 동작 하나를 다시 재현할 수 있는 입력이나 조작 순서와 함께 작업 폴더에 적는다.

### Daily TODO

- [ ] `15.01` 1~5편(Resources · Board Representation · First Definitions · Board Structure · Undo-Move Structure): 기본 정의와 보드 구조체를 만든다.
- [ ] `15.02` 6~7편(Array[120]↔Array[64] · Piece Lists and ASSERT): 인덱스 변환표를 만든다. 64칸 전체의 왕복 변환을 확인한다.
- [ ] `15.03` 8~10편(Bitboards · Pop and Count · Set and Clear bits): 비트보드 연산을 만든다. 비트 수 세기와 꺼내기를 고정 값으로 확인한다.
- [ ] `15.04` 11~12편(Position Key 1~2): 포지션 해시 키를 만든다. 같은 포지션은 같은 키, 한 수 다른 포지션은 다른 키인지 확인한다.
- [ ] `15.05` 13~16편(Reset Board · FEN Notation · Parsing An FEN 1~2): FEN으로 보드를 읽는다. 시작 위치와 중반 포지션 하나를 확인한다.
- [ ] `15.06` 17~21편(Printing the board · Piece Lists · Rank and File Arrays · Checkboard · Next steps): 보드를 출력하고 내부 일관성 검사를 붙인다.
- [ ] `15.07` 22~23편(Square Attacked 1~2): 공격받는 칸을 판정한다. 기물별로 한 포지션씩 확인한다.
- [ ] `15.08` 24~27편(Move Format & Bits 1~3 · Printmove and Printsquare): 수의 비트 표현과 출력을 만든다.
- [ ] `15.09` 28~31편(Move Generation 1~4): 폰의 수를 생성한다. 시작 위치에서 폰 수의 개수를 확인한다.
- [ ] `15.10` 32~36편(Move Generation 5~9): 나머지 기물과 캐슬링의 수를 생성한다. 막힌 선을 통과하지 않는지 확인한다.
- [ ] `15.11` 37~40편(Writing MakeMove Introduction, 1~3): 기물을 지우고 놓고 옮기는 함수를 만든다. 해시 키가 함께 갱신되는지 확인한다.
- [ ] `15.12` 41~44편(MakeMove · TakeMove · Perft 소개 · Perft Testing): 수를 두고 되돌린다. 시작 위치의 알려진 perft 값과 대조한다.
- [ ] `15.13` 45~47편(MinMax and NegaMax · Alpha Beta · Overview of search): 탐색 이론 편이다. 작은 트리를 손으로 계산해 알파-베타 가지치기 결과를 적는다.
- [ ] `15.14` 48~50편(Parsing a move · Repetition Detection · Getting the time): 입력 수 해석과 반복 감지를 만든다. 같은 포지션이 반복되는 수순을 확인한다.
- [ ] `15.15` 51~53편(Principal Variation Table 1~3): PV 테이블에 저장하고 꺼낸다.
- [ ] `15.16` 54~57편(Preparation for search · Search Function Definitions · Basic Evaluation · Clear To Search): 탐색 골격과 기본 평가를 만든다.
- [ ] `15.17` 58~60편(Iterative Deepening · Alpha Beta Function · Mate in 3): 탐색을 완성한다. 영상의 3수 메이트 포지션을 푸는지 확인한다.
- [ ] `15.18` 61~65편(MVV LVA · Picking a Move · BUG ALERT · Killer, History · Quiescence): 수 정렬과 정지 탐색을 붙인다. 같은 깊이에서 탐색 노드 수가 줄어드는지 비교한다.
- [ ] `15.19` 66~70편(UCI Protocol 1~5): UCI를 구현한다. `position`과 `go` 명령에 응답하는지 터미널에서 확인한다.
- [ ] `15.20` 71~75편(Vice vs Nero · XBoard/Winboard 1~3 · BUG ALERT #2): XBoard 프로토콜을 붙인다.
- [ ] `15.21` 76~78편(In Check Extension · Evaluation Bitmasks · Pawn Bitmasks): 체크 확장과 평가용 비트마스크를 만든다.
- [ ] `15.22` 79~82편(Mirror Board · Isolani and Passed · Open Files · King Position): 평가를 개선한다. 보드를 뒤집어도 평가값이 대칭인지 확인한다.
- [ ] `15.23` 83~87편(Null Move Pruning 1~2 · Transposition Table · Test Results · Vice 1.0 release): 널 무브와 전치 테이블을 붙인다. 테스트 포지션 결과를 기록한다.
- [ ] `15.24` 88~91편(Opening Book 소개 · Polyglot Book 1~3): Polyglot 책의 해시 키와 데이터 읽기를 만든다.
- [ ] `15.25` 92~95편(Polyglot Book 4~6 · Vice 1.1): 책에서 수를 꺼내 쓰고 옵션으로 켜고 끈다.
- [ ] `15.26` 96~100편(잡담 1편 포함 · Global Hash Table · Adding age hash entries): 전역 해시 테이블로 바꾼다.
- [ ] `15.27` 101~107편: 재생목록에서 제목을 확인하고 진행한다. 내용에 따라 회차를 나눈다.
## 21 handmade-hero

원본: [README → Game Development](../README.md#game-development)

* [Handmade Hero](https://handmadehero.org/) `video` `in-progress`

> **원문 메모**
>
> 에피소드 가이드(<https://guide.handmadehero.org/>) 기준 본편은 Day 001~667이다. 여기에 Intro to C 5일과 편마다 Q&A가 있다. 하루에 1편씩 해도 평일 기준 2년 반이 넘는다.
>
> **정해야 할 것:** 이 항목을 어디까지 하면 끝으로 볼지는 직접 정한다(예: 전편, 특정 Day까지). 정하기 전에는 아래 방식으로 계속 이어 간다.
>
> 원작은 Windows(Win32, MSVC) 기준이다. Mac에서는 Windows 가상 머신을 쓰거나 플랫폼 계층을 SDL로 옮기는 방법이 있다. 첫 회차에 정한다.
>
> 아래에는 Day 018까지만 적었다(제목은 가이드에서 확인). **마지막 세 줄에 들어서면 가이드의 다음 20일 제목을 그대로 옮겨 줄을 추가한다.** 1일 1회차가 기준이고, 길면 그날의 뒷부분을 새 줄로 넘긴다.

### Daily TODO

- [ ] `21.01` 실습 환경(Windows VM 또는 SDL 포팅)과 완료 범위를 정해 작업 폴더에 적는다. 빈 창 하나를 띄워 환경을 검증한다. C가 익숙하면 Intro to C 5일은 훑기만 한다.
- [ ] `21.02` Day 001 Setting Up the Windows Build: 빌드 스크립트로 빈 프로그램을 빌드하고 디버거에서 진입점에 멈춘다.
- [ ] `21.03` Day 002 Opening a Win32 Window: 창을 열고 메시지 루프를 돈다. 닫기 메시지로 정상 종료하는지 확인한다.
- [ ] `21.04` Day 003 Allocating a Back Buffer: 백 버퍼를 할당해 창에 복사한다. 창 크기를 바꿔도 화면이 깨지지 않는지 확인한다.
- [ ] `21.05` Day 004 Animating the Back Buffer: 버퍼에 움직이는 패턴을 그린다. 줄 간격(pitch) 계산이 맞는지 패턴으로 확인한다.
- [ ] `21.06` Day 005 Windows Graphics Review: 지금까지의 그래픽 코드를 정리한다. 정리 전후 화면이 같은지 확인한다.
- [ ] `21.07` Day 006 Gamepad and Keyboard Input: 게임패드와 키보드 입력을 읽는다. 패드가 없을 때도 죽지 않는지 확인한다.
- [ ] `21.08` Day 007 Initializing DirectSound: 사운드 장치를 초기화한다. 장치가 없을 때의 처리를 확인한다.
- [ ] `21.09` Day 008 Writing a Square Wave to DirectSound: 사각파를 버퍼에 써서 재생한다.
- [ ] `21.10` Day 009 Variable-Pitch Sine Wave Output: 사인파를 재생하고 음높이를 바꾼다. 음이 끊기거나 튀지 않는지 듣고 확인한다.
- [ ] `21.11` Day 010 QueryPerformanceCounter and RDTSC: 프레임 시간과 사이클 수를 잰다. 프레임마다 출력해 값이 안정적인지 확인한다.
- [ ] `21.12` Day 011 The Basics of Platform API Design: 플랫폼 계층과 게임 코드를 파일로 나눈다. 나눈 뒤에도 같은 화면과 소리가 나오는지 확인한다.
- [ ] `21.13` Day 012 Platform-independent Sound Output: 게임 코드가 사운드 샘플을 채우게 한다.
- [ ] `21.14` Day 013 Platform-independent User Input: 입력 구조체를 게임 코드에 넘긴다. 입력에 따라 패턴이나 음이 바뀌는지 확인한다.
- [ ] `21.15` Day 014 Platform-independent Game Memory: 게임 메모리를 한 번에 할당해 넘긴다. 실행 중 추가 할당이 없는지 확인한다.
- [ ] `21.16` Day 015 Platform-independent Debug File I/O: 디버그용 파일 읽기·쓰기를 만든다. 파일 하나를 읽어 다시 쓰고 내용을 비교한다.
- [ ] `21.17` Day 016 VisualStudio Compiler Switches: 컴파일러 경고 옵션을 정리한다. 경고 없이 빌드되는지 확인한다.
- [ ] `21.18` Day 017 Unified Keyboard and Gamepad Input: 키보드와 패드 입력을 하나의 구조로 합친다. 두 장치로 같은 동작이 되는지 확인한다.
- [ ] `21.19` Day 018 Enforcing a Video Frame Rate: 프레임 속도를 고정한다. 측정한 프레임 시간이 목표와 맞는지 확인한다. 가이드에서 Day 019~038 제목을 옮겨 다음 줄을 추가한다.
## 73 svg

원본: [README → Uncategorized](../README.md#uncategorized)

* [Writing an SVG Library](http://www.codedrome.com/svg-library-in-c/)

> **원문 메모**
>
> 원문 서버가 500 오류를 낸다. 보존본: [2026-07](http://web.archive.org/web/20260712091003/https://www.codedrome.com/svg-library-in-c/). 본문 내용은 대조하지 못했다.

### Daily TODO

- [ ] `73.01` 점·선 필드 하나를 XML로 내보내 브라우저에 연다.
- [ ] `73.02` 도형과 좌표 변환을 추가하고 작은 예제에서 위치를 대조한다.
- [ ] `73.03` 텍스트·속성의 특수문자를 이스케이프한다. 생성 SVG를 XML 파서가 읽는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 71 ffmpeg-libav

원본: [README → Uncategorized](../README.md#uncategorized)

* [Learn FFmpeg libav the Hard Way](https://github.com/leandromoreira/ffmpeg-libav-tutorial) `in-progress`

> **원문 메모**
>
> 원문 구성: Intro(video · audio · codec · container) · FFmpeg command line · Common video operations(Transcoding · Transmuxing · Transrating · Transsizing) · Chapter 0 hello world · Chapter 1 syncing audio and video · Chapter 2 remuxing · Chapter 3 transcoding.
>
> ffmpeg와 libav 개발 헤더가 필요한데 지금 설치돼 있지 않다. 기존 회차의 픽셀 형식 변환은 원문에 없어 원문 장 구성에 맞게 고쳤다.

### Daily TODO

- [ ] `71.01` Intro · command line: ffmpeg를 설치한다. 샘플 영상에 변환·컨테이너 교체·비트레이트 변경·크기 변경을 명령줄로 한 번씩 적용하고 `ffprobe`로 결과를 비교한다.
- [ ] `71.02` Chapter 0: 파일을 열어 컨테이너와 스트림 정보를 출력하고, 영상 패킷을 디코드해 처음 몇 프레임을 회색조 이미지 파일로 저장한다. 저장한 이미지를 열어 확인한다.
- [ ] `71.03` Chapter 1: 타임스탬프 장을 읽는다. 샘플의 PTS·DTS·time base를 출력해 프레임 표시 시각을 직접 계산하고 `ffprobe` 값과 대조한다.
- [ ] `71.04` Chapter 2: 디코드 없이 다른 컨테이너로 옮긴다. 결과 파일의 스트림 수와 길이가 원본과 같은지 `ffprobe`로 확인한다.
- [ ] `71.05` Chapter 3: 영상 코덱을 바꿔 다시 인코딩한다. 결과가 재생되고 코덱이 바뀌었는지 `ffprobe`로 확인한다.
## 70 video-player

원본: [README → Uncategorized](../README.md#uncategorized)

* [How to Write a Video Player in Less Than 1000 Lines](http://dranger.com/ffmpeg/ffmpeg.html)

> **원문 메모**
>
> 원문은 Tutorial 01~08이다(목차 페이지에서 01~07 링크를 확인했고, 08은 기억 기준). 2015년 기준 API라 현재 FFmpeg·SDL2와 맞지 않는다. 첫 회차에 최신 API로 옮긴 소스를 찾아 함께 본다.
>
> 편별 주제는 기억 기준이다: 01 Making Screencaps · 02 Outputting to the Screen · 03 Playing Sound · 04 Spawning Threads · 05 Synching Video · 06 Synching Audio · 07 Seeking · 08 Software Scaling.

### Daily TODO

- [ ] `70.01` Tutorial 01: 옛 API와 현재 API를 대응시킨 표를 만든다. 처음 몇 프레임을 이미지 파일로 저장해 확인한다.
- [ ] `70.02` Tutorial 02: 디코드한 프레임을 SDL 창에 그린다. 재생이 끝나면 창과 자원이 닫히는지 확인한다.
- [ ] `70.03` Tutorial 03: 오디오를 디코드해 장치 콜백으로 재생한다. 패킷 큐가 비었을 때 소리가 깨지지 않는지 확인한다.
- [ ] `70.04` Tutorial 04: 디코드와 표시를 스레드로 나눈다. 종료할 때 스레드와 큐가 정리되는지 확인한다.
- [ ] `70.05` Tutorial 05: PTS 기준으로 영상 표시 시각을 맞춘다. 짧은 클립의 재생 길이가 실제 길이와 맞는지 잰다.
- [ ] `70.06` Tutorial 06: 오디오 시계에 맞춰 동기화한다. 오디오와 영상의 시작과 끝이 맞는지 확인한다.
- [ ] `70.07` Tutorial 07: 탐색을 만든다. 탐색 뒤 이전 프레임과 소리가 남지 않는지 확인한다.
- [ ] `70.08` Tutorial 08: 소프트웨어 스케일링으로 바꾼다. 다른 해상도로 출력했을 때 화면 비율이 유지되는지 확인한다.
