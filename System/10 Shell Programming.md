# Shell Programming

### Shell script

- 유닉스의 실행 파일(executable file)
  - binary file: 예로 cat, gzip가 있고 완전 기계어 파일을 의미
  - script file: 사람이 읽을 수 있는 파일.
- script file
  - 일련의 statement들로 구성된 실행 파일
  - 각 statement는 command 또는 다른 script file
  - script file의 실행을 위해서는 각 line을 읽고 번역하기 위한 **interpreter process**가 필요하다. 여기에서는 shell이 그 일을 담당하므로 shell script라고 부른다.
  - script file의 첫 line은 종종 ***#!pathname***으로 시작하며 이때 pathname은 누가 그 script file을 번역해야 하는지 알려준다. 보통은 bash가 interpreter 역할을 하며 bash shell인 경우 #!/bin/bash로 파일이 시작한다.

### Shell script의 실행

- ```
  $ bash script_file
  ```

- 또는

  ```
  $ chmod +x script_file
  $ ./script.file
  ```



### Shell script argument

|     이름      | 의미                            |
| :-----------: | ------------------------------- |
|      $$       | script 수행 shell의 프로세스 id |
|      $0       | shell script의 이름             |
| $1..$9, ${10} | n번째 argument                  |
|  $* 또는 $@   | list of all arguments           |
|      $#       | number of arguments passed      |
|      $?       | return value                    |

```
$ vi argument.sh
-----------
echo Process ID: $$
echo Script Name: $0
echo Argument: $1 $2 $3 $4
echo All Argument: $*
echo Argument num: $#
-----------
$ chmod 777 argument.sh
$ ./argument.sh a1 a2 a3 a4 a5
Process ID: 23901
Script Name: ./argument.sh
Argument: a1 a2 a3 a4
All Argument: a1 a2 a3 a4 a5
Argument num: 5
```

