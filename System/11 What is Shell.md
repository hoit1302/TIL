# Shell

## What is Shell?

- command line interpreter(명령어 실행기, 번역기): ls -al하면 번역한 정보를 kernel에게 요청
- job control language(프로그래밍 언어), shell 자체적으로 프로그램 실행
  - C는 실행파일을 kernel에서 실행하고 java는 jvm에서 실행하는 것과는 다름
- 운영체제 커널과 사용자를 연결시켜주는 매개체
- 일종의 user level 프로그램

## Shell의 종류

- Bourne Shell (sh)
- C Shell (csh)
- ksh, tcsh, ...
- bash(Born Again Shell) - 표준
  - Linux default shell
  - GNU에서 만듦
  - source code is available
  - /bin/bash

위와 같은 shell을 실행시켜 shell prompt 상태(사용자의 입력을 기다리는 상태)에 도달

## bash Shell의 기능

- command의 해석 및 실행
  - $ ls -al
- 사용자 환경의 customize
- History 기능
  - ↑ 키로 이전 수행 명령어
- Alias 기능
  - $ alias myls='ls -al'
- 산술 연산 기능
- Job control 기능 (foreground / background)
- Prompt 제어 기능
- 명령문 편집 기능
- 확장된 내부 명령어
- Command를 이용한 프로그램 작성 가능 - shell script programming



## Bash Shell의 실행

- login shell
  - 시스템 관리자가 사용자의 기본 shell을 정한다.
  - ~/etc/passwd 파일에 명시
- bash가 사용하는 특별한 파일들
  - ls -a로 확인
  - 로그인 혹은 새로운 터미널 생성 시 사용
    - ~/**.bash_profile**: 로그인 시 실행
    - ~/**.bash_logout**: 로그아웃 시 실행
    - ~/**.bashrc**: shell이 시작될 때 실행 (단, 로그인 shell 제외)

