# 05. 게임과 멀티미디어

입력·상태 갱신·그리기 루프를 만들고 충돌, 리소스, 오디오·영상 처리로 확장한다.

[전체 로드맵](../ROADMAP.md) · **체크박스 한 줄 = 평일 1회차(1~2시간)**

표의 순서대로 진행한다. 폴더는 첫 작업 때 만들고, 원문 실습이 더 있으면 해당 항목 끝에 회차를 추가한다.

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

## 29 tetris

원본: [README → Game Development](../README.md#game-development)

* [On Tetris and Reimplementation](https://brennan.io/2015/06/12/tetris-reimplementation/)

### Daily TODO

- [ ] `29.01` 격자와 블록 이동을 구현한다. 좌우 경계를 넘어가지 않는지 확인한다.
- [ ] `29.02` 회전·낙하와 바닥 고정을 만든다. 가려진 회전이 판을 손상하지 않는지 확인한다.
- [ ] `29.03` 줄 제거·점수·게임오버를 테스트 배치로 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 17 rogue

원본: [README → Game Development](../README.md#game-development)

* [Coding a Rogue/Nethack RPG in C](https://www.youtube.com/playlist?list=PLkTXsX7igf8erbWGYT4iSAhpnJLJ0Nk5G) `video`

### Daily TODO

- [ ] `17.01` 문자 지도와 이동을 만들고 벽 충돌을 확인한다.
- [ ] `17.02` 방과 통로를 만든 뒤 고정 seed에서 도달 가능한 출구를 확인한다.
- [ ] `17.03` 턴마다 적이 움직이게 한다. 플레이어 입력이 없을 때 턴이 진행되지 않는지 확인한다.
- [ ] `17.04` 아이템 획득과 전투를 추가하고 사망·재시작으로 상태를 점검한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 34 sdl-intro

원본: [README → Game Development](../README.md#game-development)

* [Writing 2D Games in C using SDL](https://www.youtube.com/watch?v=yFLa3ln16w0) `video`

### Daily TODO

- [ ] `34.01` SDL 창을 띄우고 종료 이벤트를 받아 자원을 해제한다.
- [ ] `34.02` 입력에 따라 사각형을 움직인다. 시간 간격을 바꿔 이동 속도를 비교한다.
- [ ] `34.03` 충돌·사운드 중 원문에서 다루는 기능을 하나 연결해 실행 예제를 재현한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 32 tic-tac-toe-sdl

원본: [README → Game Development](../README.md#game-development)

* [Tic-tac-toe Game in C with SDL](https://www.youtube.com/watch?v=gCVMkKgs3uQ) `video`

### Daily TODO

- [ ] `32.01` 셀 좌표와 마우스 클릭 좌표를 매핑한다. 보드 밖 클릭을 거른다.
- [ ] `32.02` 승리 표시와 재시작을 연결한다. CLI판의 승리·무승부 입력을 GUI에서 재생한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 14 brickout

원본: [README → Game Development](../README.md#game-development)

* [Brickout Clone](https://gtk.dashgl.com/?folder=Brickout)

### Daily TODO

- [ ] `14.01` 공과 패들을 그린다. 벽과 패들 충돌 후 공의 방향을 확인한다.
- [ ] `14.02` 벽돌이 맞으면 한 번 제거하고 점수를 올린다.
- [ ] `14.03` 공을 놓쳤을 때 재시작과 모든 벽돌 제거 후 승리를 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 13 astroids

원본: [README → Game Development](../README.md#game-development)

* [Astroids Clone](https://gtk.dashgl.com/?folder=Astroids)

### Daily TODO

- [ ] `13.01` 회전·추력과 화면 반대편 래핑을 구현한다.
- [ ] `13.02` 발사체 수명과 소행성 충돌을 확인한다.
- [ ] `13.03` 소행성 분할과 게임오버를 고정 seed에서 재현한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 25 invaders

원본: [README → Game Development](../README.md#game-development)

* [Invaders Clone](https://gtk.dashgl.com/?folder=Invaders)

### Daily TODO

- [ ] `25.01` 적 편대가 경계에서 방향을 바꾸고 내려오는지 확인한다.
- [ ] `25.02` 발사체가 적 또는 플레이어에 한 번만 피해를 주는지 확인한다.
- [ ] `25.03` 웨이브 클리어·패배·재시작을 실행한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 27 video-game-c

원본: [README → Game Development](../README.md#game-development)

* [Learn Video Game Programming in C](https://www.youtube.com/playlist?list=PLT6WFYYZE6uLMcPGS3qfpYm7T_gViYMMt) `video`

### Daily TODO

- [ ] `27.01` 자료의 첫 플레이 가능한 예제를 빌드한다. 입력·업데이트·렌더가 연결되는 지점을 표시한다.
- [ ] `27.02` 텍스처나 사운드 리소스 하나를 로드하고 누락 파일의 처리도 확인한다.
- [ ] `27.03` 시리즈에 나오는 게임별 실행 목표를 분리하고 첫 게임의 종료 조건을 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 28 dangerous-dave

원본: [README → Game Development](../README.md#game-development)

* [Let's Make: Dangerous Dave](https://www.youtube.com/playlist?list=PLSkJey49cOgTSj465v2KbLZ7LMn10bCF9) `video`

### Daily TODO

- [ ] `28.01` 타일 레벨을 로드한다. 잘못된 타일은 즉시 식별한다.
- [ ] `28.02` 이동·점프·바닥 충돌을 연결하고 모서리에서 재현한다.
- [ ] `28.03` 보물·열쇠·출구를 연결하고 획득 전후의 완료 동작을 비교한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 18 platformer

원본: [README → Game Development](../README.md#game-development)

* [Creating a 2D platformer](https://www.parallelrealities.co.uk/tutorials/#ppp)

### Daily TODO

- [ ] `18.01` 타일 맵과 카메라를 그린다. 이동해도 타일 경계가 이어지는지 확인한다.
- [ ] `18.02` 중력·점프·수직 충돌을 검증한다.
- [ ] `18.03` 적·스테이지 전환을 붙이고 체크포인트 또는 재시작 흐름을 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 19 shoot-em-up

원본: [README → Game Development](../README.md#game-development)

* [Creating a 2D shoot 'em up](https://www.parallelrealities.co.uk/tutorials/#shooter)

### Daily TODO

- [ ] `19.01` 스크롤과 플레이어 발사체를 표시한다.
- [ ] `19.02` 웨이브를 구성하고 화면을 벗어난 적·발사체를 제거한다.
- [ ] `19.03` 피격·점수·보스 또는 마지막 웨이브 동작을 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 20 top-down-shooter

원본: [README → Game Development](../README.md#game-development)

* [Creating a 2D top-down shooter](https://www.parallelrealities.co.uk/tutorials/#bad)

### Daily TODO

- [ ] `20.01` 이동과 조준을 분리하고 네 방향에서 조준 각도를 확인한다.
- [ ] `20.02` 적 탐지·투사체 충돌을 구현하고 벽이 사이에 있는 경우를 확인한다.
- [ ] `20.03` 피격·탄약·레벨 종료를 연결한다. 정상 시나리오와 실패를 모두 재현한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 30 isometric

원본: [README → Game Development](../README.md#game-development)

* [SDL 2 Isometric Game Tutorial](https://www.youtube.com/playlist?list=PL6Ikt4l3NbVjb7WR-eTgjOBMNCn7f3u7x) `video` `in-progress`

### Daily TODO

- [ ] `30.01` 타일 좌표를 화면 좌표로 바꾼다. 작은 맵에서 모서리 두 점을 계산과 비교한다.
- [ ] `30.02` 타일과 캐릭터의 그리기 순서를 바꿔 앞뒤 가림을 확인한다.
- [ ] `30.03` 커서 선택을 타일로 역변환한다. 경계에서 선택이 튀는 경우를 테스트한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 33 physics

원본: [README → Game Development](../README.md#game-development)

* Video Game Physics Tutorial
  * [Part I: An Introduction to Rigid Body Dynamics](https://www.toptal.com/game/video-game-physics-part-i-an-introduction-to-rigid-body-dynamics)
  * [Part II: Collision Detection for Solid Objects](https://www.toptal.com/game/video-game-physics-part-ii-collision-detection-for-solid-objects)
  * [Part III: Constrained Rigid Body Simulation](https://www.toptal.com/game/video-game-physics-part-iii-constrained-rigid-body-simulation)

### Daily TODO

- [ ] `33.01` 1편: 위치·속도·각속도를 적분한다. 힘이 0인 테스트를 재현한다.
- [ ] `33.02` 2편: 겹침과 분리 상태를 가려 접촉점·법선을 표시한다.
- [ ] `33.03` 3편: 충돌 응답으로 공이 바닥에서 튀는 동작을 확인한다.
- [ ] `33.04` 3편 제약 사례를 하나 더 붙인다. 동일 입력에서 시간 간격에 따른 오차를 비교한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 15 chess

원본: [README → Game Development](../README.md#game-development)

* [Chess Engine In C](https://www.youtube.com/playlist?list=PLZ1QII7yudbc-Ky058TEaOstZHVbT-2hg) `video`

### Daily TODO

- [ ] `15.01` FEN으로 보드를 읽고 시작 위치를 확인한다.
- [ ] `15.02` 기물별 이동 생성 중 슬라이딩과 점프를 분리한다. 막힌 선을 통과하지 않는지 확인한다.
- [ ] `15.03` 체크 판정과 불법 수 제거를 연결한다. 소규모 고정 포지션으로 확인한다.
- [ ] `15.04` 캐슬링·프로모션·앙파상은 각각 테스트 하나로 검증하며 필요하면 하루씩 나눈다.
- [ ] `15.05` 알려진 시작 위치 perft 결과로 수 생성과 make/unmake를 확인한다.
- [ ] `15.06` 작은 깊이의 탐색·평가를 붙이고 강제 수가 있는 포지션에서 수를 비교한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 21 handmade-hero

원본: [README → Game Development](../README.md#game-development)

* [Handmade Hero](https://handmadehero.org/) `video` `in-progress`

### Daily TODO

- [ ] `21.01` 소스를 시작하기 전에 에피소드 범위와 Windows/Linux 실습 환경을 기록한다. 작은 창 빌드로 환경을 검증한다.
- [ ] `21.02` 프레임 버퍼에 패턴을 그린다. 창 리사이즈 전후 stride가 맞는지 확인한다.
- [ ] `21.03` 프레임 시간과 입력을 비교할 수 있는 작은 루프를 만든다.
- [ ] `21.04` 오디오 버퍼를 채우고 끊김 없이 테스트 톤이 재생되는지 확인한다.
- [ ] `21.05` 플랫폼 계층과 게임 상태를 분리한다. 재시작 또는 재로딩 후 상태 경계를 확인한다.
- [ ] `21.06` 월드 좌표와 화면 좌표를 분리하고 타일 경계 이동을 재현한다.
- [ ] `21.07` 원문 에피소드 목록에서 충돌·자산·렌더링 구간을 각각 1회차 단위로 쪼개 다음 체크리스트를 추가한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 73 svg

원본: [README → Uncategorized](../README.md#uncategorized)

* [Writing an SVG Library](http://www.codedrome.com/svg-library-in-c/)

### Daily TODO

- [ ] `73.01` 점·선 필드 하나를 XML로 내보내 브라우저에 연다.
- [ ] `73.02` 도형과 좌표 변환을 추가하고 작은 예제에서 위치를 대조한다.
- [ ] `73.03` 텍스트·속성의 특수문자를 이스케이프한다. 생성 SVG를 XML 파서가 읽는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 71 ffmpeg-libav

원본: [README → Uncategorized](../README.md#uncategorized)

* [Learn FFmpeg libav the Hard Way](https://github.com/leandromoreira/ffmpeg-libav-tutorial) `in-progress`

### Daily TODO

- [ ] `71.01` 현재 libav* 헤더와 링크 정보를 확인한다. 작은 파일의 컨테이너·스트림 정보를 출력한다.
- [ ] `71.02` 영상 패킷을 디코더에 보내 첫 프레임을 얻는다. 끝에서 flush를 확인한다.
- [ ] `71.03` 프레임을 다른 픽셀 형식으로 변환한다. 해상도와 줄 간격을 확인한다.
- [ ] `71.04` 원문의 인코딩·먹싱 단계를 클립 하나로 적용한다. `ffprobe`로 결과를 비교한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.

## 70 video-player

원본: [README → Uncategorized](../README.md#uncategorized)

* [How to Write a Video Player in Less Than 1000 Lines](http://dranger.com/ffmpeg/ffmpeg.html)

### Daily TODO

- [ ] `70.01` 오래된 예제 API와 현재 FFmpeg/SDL API를 대응시킨다. 첫 디코드 프레임이 화면에 나오는지 확인한다.
- [ ] `70.02` 영상 프레임을 큐에 넣고 재생 종료 후 큐를 비운다.
- [ ] `70.03` 별도로 오디오 샘플을 디코딩해 장치 콜백과 이어준다.
- [ ] `70.04` PTS 기준 동기화를 적용한다. 짧은 클립의 오디오와 영상 시작·끝을 비교한다.
- [ ] `70.05` 탐색과 종료를 처리한다. 탐색 뒤 이전 프레임이 남지 않고 장치가 닫히는지 확인한다.

**항목 종료 조건:** 원문에서 정한 범위와 회차를 대조하고, 남은 실습이 있으면 아래에 다음 번호로 먼저 추가한다. 마지막 회차에 실행법과 원문 대비 결과를 작업 폴더에 남긴다.
