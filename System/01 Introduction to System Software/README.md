![파일_001](https://user-images.githubusercontent.com/68107000/95682492-749f0f00-0c20-11eb-8edc-256c7b520a98.png)



## 시스템 소프트웨어(System Software)

- 하드웨어를 제어 및 관리하며 응용 소프트웨어를 지원하는 소프트웨어.
- 사용자 또는 응용 프로그램의 요구에 따른 컴퓨터 하드웨어 자원의 제어 및 관리를 담당
- Machine Dependent (더 정확히는 cpu에 의존적)

- 구성
  - OS
  - 언어처리기(compiler, assembler)
  - 유틸리티 프로그램(운영체제와 함께 설치되는)

<br>

## 응용 소프트웨어(Application Software)

- 특정 작업을 수행하기 위해 개발된 소프트웨어

- 사용자의 개별 목적에 따른 프로그램

- Machine independent

  <br>

## ISA

**Instruction Set Architecture** 

기계어 집합 구성, 프로세서가 이해하고 수행할 수 있는 명령어 집합 구조

컴퓨터의 hardware와 software의 interface

CPU가 가지고 있는 명령 set

+) ISA가 먼저 정해지고 이에 맞게 hw, system sw를 만든다.

- '*system software*'는 **ISA에 의존적**이다

  ㅡ> 소프트웨어 제작자가 ISA를 알고 있어야 함

  - '*OS*'

    컴퓨터 시스템의 자원(hw, sw)을 관리한다.

    컴퓨터 시스템을 편리하게 사용할 수 있는 환경을 제공해준다.

    ms-windows, LINUX가 그 예이다.

    ㅡ> 운영체제의 제작자는 그 운영체제가 사용될 ISA를 알고 있어야 한다.

  - '*compiler*'

    고급 언어로 작성한 프로그램을 ISA에 맞게 변환해준다.

  - '*assembler, linker, loader*'

<br>

- 구성 (기계어에 언급함)
  - instruction: 연산 부호와 피연산자
  - register
  - memory

<br>

- 수행

  1. instruction을 memory에서 cpu로 읽어간다.

  2. 의미 해석

  3. 연산 수행 (ALU)

  4. 결과 저장 (Register)

<br>

- 구성에 포함되지 않는 것
  - Method of instructions processing-기계어를 실행하는 방법
    - Sequential: 순차적으로 수행
    - pipelining: 중첩해서 수행
  - cache memory
    - 자주 사용하는 data
    - 메모리보다 빠름
    - 하지만 연산 결과는 없어도 같음
  - I/O device

<br>

- 종류
  - MIPS
  - IA-32(x86)
  - IA-64
  - Alpha
  - Arm
  - RISC-V

<br>

## 정보 단위

- **bit** (비트) 

  binary digit

  n bits: 2^n 가지의 정보  표현 가능

- **byte** (바이트)

  1 byte = 8 bits

  1개의 영문자를 기억하는 최소 단위

- **word** (워드)

  1w = 4 bytes = 32bits

  컴퓨터 내부의 데이터 처리 및 전송의 단위