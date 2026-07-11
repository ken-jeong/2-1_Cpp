# 2-1 C++ (객체지향 프로그래밍)

![C++](https://img.shields.io/badge/C%2B%2B-00599C?logo=cplusplus&logoColor=white)
![Make](https://img.shields.io/badge/Make-Makefile-427819?logo=gnu&logoColor=white)
![Course](https://img.shields.io/badge/2025--1-OOP%20Coursework-blue)

2학년 1학기 C++ 수업 과제 및 연습 코드 모음.

## 구성

**연습 코드**

- `ex01.cpp` — 상속 연습. `Circle`을 상속한 `NamedCircle`
- `ex02.cpp` — 다중 상속 연습. `Adder`/`Subtractor`/`Multiplier`/`Divider`를 조합한 계산기

**과제**

- `hw01/` (2025-04-30) — `Shape` 가상 함수(`draw`) 오버라이딩. 단일 `main.cpp`
- `hw02/` (2025-05-07) — `Shape`/`Line`/`Circle`/`Rect` 연결 리스트. 헤더/소스 분리, Makefile 포함
- `hw03/` (2025-06-02) — 도형 연결 리스트 + `operator<<` 오버로딩, 파일 입출력(`objects.txt`). Makefile 포함 (`Iredirect`는 입력 리다이렉션용 샘플)

**참고 예제**

- `atm/` — ATM 예제. 계좌 개설/조회/입출금/이체 및 거래 통계(`Statistics`). 헤더/소스 분리, Makefile 포함

## 빌드 및 실행

단일 파일:

```sh
g++ ex01.cpp -o ex01 && ./ex01
```

Makefile이 있는 과제:

```sh
cd hw02   # 또는 hw03, atm
make
```
