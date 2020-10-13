# LINUX command
## 명령어


- **man** - 다시 보기

  manual page

  ```
  man command_name
  man -k
  q 	// 종료
  ```

  <br>

- **pwd**

  print working directory

  ```
  $ pwd				
    /home/ewha/ewha112
  $_
  ```

  <br>

- **cat**

  concatenate 파일의 내용을 간단히 출력, 파일 만들기, 여러 파일 연속해서 출력

  cat [-n] FILE

  ​		-n: 출력에 줄 번호 표시 (number)

  stdout은 모니터

  ```
  $ cat > test		// 표준 입력(stdin, KBD) 생략. 표준 입력을 test파일에 저장.
    hi!
    I hope that you get this file.
    ^d
  $ cat -n test
    1 hi!
    2 I hope that you get this file.
  $ cat test
    hi!
    I hope that you get this file.
  $_
  ```

  <br>

- **control-c**

  프로세스 작업의 강제 종료

  ```
  $ cat > test
    hi!
    I hope that you get this file.
    ^c
  $_				// test 파일에 저장됨
  ```

  <br>

- **control-d**

  ```
  $ cat > test
    hi!
    I hope that you get this file.
    ^d		// 입력의 끝. test 파일에 저장됨
  $_	
  ```

  <br>

- **ls**

  ```
  $ ls		// 현 디렉토리의 모든 파일 출력
  $ ls -a		// all 숨겨진 파일 출력
  $ ls -l		// long 허가 정보, 소유권, 최종변경일자 등을 포함한 긴 목록 제공
  $ ls -R		// Recursive 디렉토리 내용과 그 서브 디렉토리 내용을 재귀적으로 출력
  $ ls -d		// directory 디렉토리 자체의 정보
  $ ls 폴더명
  
  활용
  $ ls -al
  $ ls -ld
  $ ls -lR
  ```

  <br>

- **head/tail**

  ```
  $ head -2 test		// test 파일의 첫번째 두줄 출력
  $ tail -2 test		// test 파일의 마지막 두줄 출력
  ```

  <br>

- **mv**

  이름 변경 및 이동

  ```
  $ mv old_file new_file		// 파일	 이름 변경
  $ mv old_dir  new_dir		// 디렉토리 이름 변경
  
  $ mv file directory			// file을 directory로 이동
  
  모든 명령에 -i 옵션 가능.
  interactive: 새로운 파일 이름이 이미 존재하는 경우, overwrite? 물어봄. y/n 대답
  ```

  <br>

- **mkdir**

  make directory

  ```
  $ mkdir new_dir
  ```

  <br>

- **cd**

  change directory

  ```
  $ cd temp
  $ cd 				// 사용자의 홈 디렉토리로 이동
  $ cd /home/user112 	// 절대경로
  ```

  <br>

- **cp**

  copy 파일 복사

  ```
  $ cp old_file new_file
  $ cp old_dir  new_dir	
  $ cp -r old_dir new_dir		// 모든 파일과 서브 디렉토리를 재귀적으로 복사
  
  $ cp test3 MakeAccount 		// test3 파일을 MakeAccount 폴더에 복사하여 저장
  $ cp ../test10 .			// 상위의 test10파일을 현재 디렉토리에 복사하여 저장
  ```

  <br>

- **rm**

  remove

  ```
  $ rm file
  $ rm -r dir			// 해당 디렉토리 내의 모든 파일 삭제
  $ rm *				// 현재 디렉토리 내의 모든 파일 삭제
  
  
  [-f]: 어떤 에러 메세지나 지시 사항도 나타내지 않는다.
  [-i]: 파일 삭제 전 사용자에게 확인 요구 (interective)
  ```

  <br>

- **rmdir**

  remove directory

  ```
  $ rmdir directory_name		// directory가 비워져 있어야 함!
  ```

  <br>

- **clear**

  ```
  $ clear
  ```

  <br>

<br>

## file attribute

<br>

```
$ ls -l test
-rw-r--r--  1  james  netwk  106  5월 16일 14:25  test
```

<br>

- 필드 속성

  | 필드 값        | 의미                          |
  | -------------- | ----------------------------- |
  | -rw-r--r--     | 접근 권한 (mode)              |
  | 1              | 하드 링크 개수                |
  | james          | 파일 소유자의 사용자 ID       |
  | netwk          | 파일의 그룹 ID                |
  | 106            | 파일의 크기. 단위는 바이트    |
  | 5월 16일 14:25 | 파일이 마지막으로 변경된 시간 |
  | test           | 파일 이름                     |

<br>

- 첫번째 문자: 파일 유형

  | 문자 | 파일 유형                                 |
  | :--: | ----------------------------------------- |
  |  -   | 일반 파일                                 |
  |  d   | 디렉토리 파일                             |
  |  l   | 심볼릭 링크 (바로가기)                    |
  |  b   | (디스크 드라이브와 같이) 버퍼된 특수 파일 |
  |  c   | (터미널 길이) 버퍼되지 않은 특수 파일     |
  |  p   | 파이프                                    |
  |  s   | 소켓                                      |

- 나머지 문자: access permission

  |                  |  r(읽기 권한)  |  w(쓰기 권한)  | x(실행 권한) |
  | :--------------: | :------------: | :------------: | :----------: |
  |  일반 파일 (-)   | 파일 내용 보기 | 파일 내용 변경 | 파일의 실행  |
  | 디렉토리 파일(d) | ls로 내용 보기 | 파일 추가/삭제 | cd로 들어감  |

  | rw-  |  r--  |  r-x   |
  | :--: | :---: | :----: |
  | user | group | others |

<br>

- **chmod**

  change mode - access permission 변경

  <br>

  1. 

     ```
     chmod [-R] mode FILE
     mode:
     		대상+허가권
     		대상-허가권
     		대상=허가권
     대상: u(user), g(group), o(others), a(all), 생략(all)
     허가권: r(read), w(write), x(execute)
     ```

     예제

     ```
     $ chmod g+w data	// 그룹에게 w 추가
     $ chmod +x data		// 모두에게 x 추가
     $ chmod go-w data	// 그룹과 others에 r 추가
     ```

     <br>

  2. 숫자를 이요한 파일 허가권 설정

     |        | user | group | others |
     | :----: | :--: | :---: | :----: |
     |  설정  | rwx  |  r-x  |  ---   |
     | 2진수  | 111  |  101  |  000   |
     | 10진수 |  7   |   5   |   0    |

     예제

     ```
     $ chmod 750 test	// -rwxr-x---
     $ chmod 777 test	// -rwxrwxrwx
     $ chmod 111 test	// ---x--x--x
     ```

     

  
