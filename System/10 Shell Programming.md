# shellShell Programming

### Shell script

- 유닉스의 실행 파일(executable file)

  - binary file: 예로 cat, gzip가 있고 완전 기계어 파일을 의미

    ```
    $ cd /bin
    $ ls
    $ vi pwd로 볼 수 있음
    ```

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
---------------------------------
echo Process ID: $$
echo Script Name: $0
echo Argument: $1 $2 $3 $4
echo All Argument: $*
echo Argument num: $#
---------------------------------
$ chmod 777 argument.sh
$ ./argument.sh a1 a2 a3 a4 a5
Process ID: 23901
Script Name: ./argument.sh
Argument: a1 a2 a3 a4
All Argument: a1 a2 a3 a4 a5
Argument num: 5
```

## 프로그래밍 언어로서의 Shell

주의 할 것: [] 안의 조건 앞 뒤에는 반드시 빈 칸이 있어야 한다.

### 조건 연산자

문자열 비교 연산자

| 기호 | 설명      |
| ---- | --------- |
| =    | 같다      |
| !=   | 같지 않다 |

산술 비교 연산자

| 기호 | 설명        |
| ---- | ----------- |
| -eq  | 같다        |
| -ne  | 같지 않다   |
| -gt  | 크          |
| -ge  | 크거나 같다 |
| -lt  | 작다        |
| -le  | 작거나 같다 |

file attribute 연산자

| 기호            | 설명                      |
| --------------- | ------------------------- |
| -e              | exist                     |
| -d              | exist and directory       |
| -f              | exist and regular file    |
| -s              | exist and size>0          |
| -r              | exist and readable        |
| -w              | exist and writable        |
| -x              | exist and executable      |
| file1 -nt file2 | file1 is newer than file2 |
| file1 -ot file2 | file1 is older than file2 |

논리 연산자

| 기호           | 설명       |
| -------------- | ---------- |
| expr1 -a expr2 | 논리적 and |
| expr1 -o expr2 | 논리적 or  |

### if 문

```shell
#!bin/bash

if [ -e $1 ]
then
	echo "$1 exist."
fi
if [ -f $1 ]
then
	echo "$1 is a regular file."
fi
if [ -d $1 ]
then
	echo "$1 is a directory."
fi
if [ -r $1 ]
then
	echo "$1 is readable."
fi
if [ -w $1 ]
then
	echo "$1 is writable."
fi
if [ $1 -nt $2 ]
then
	echo "$1 is newer than $2."
fi
if [ $1 -ot $2 ]
then
	echo "$1 is older than $2."
fi
if [ -f $1 -a $1 -nt $2 ]
then
	echo "$1 si a regular file and newer than $2."
fi
if [ -f $1 -a $1 -ot $2 ]
then
	echo "$1 si a regular file and older than $2."
fi
```

### for 문

```shell
for i in 1 2 3 4 5
do
	echo $i
done
```

### case 문

```
case $1 in
	"JIM") echo Hi JIM ;;
	"TOM") echo Hi TOM ;;
	"") echo Who are you? ;;
esac
```

### function

return 결과값 가능

함수 이름과 { 사이에 공백이 있어야 함

```shell
function foo {
	echo foo
	boo
}
function boo {
	echo boo
}
foo
```

### 예제 1

```
문제: 주어진 자연수의 총합, 평균, 최대값을 출력하는 shell program을 작성하시오. 단, 각각을 함수로 구현하시오.

$printSumAvgMax.sh 12 42 53 25 62 52
Sum = 246
Average = 41
Max = 62
```

```shell
!/bin/bash

sum=0; avg=0; max=0; num=$#
if [ $# -eq 0 ]
then
	echo "Usage: $0 n1 n2 ..."
	exit 1
fi
function fsum{
	for i in $@
	do
		let sum=$sum+$i
	done
}
function favg{
	let avg=$sum/$num
}
function fmax{
	for i in $@
	do
		if [ $i -gt $max ]
		then
			max=$i
		fi
	done
}

fsum $@
favg
fmax $@
echo "Sum = $sum";
echo "Average = $avg";
echo "Max = $max";
```

$0은 호출한 파일 이름

### 예제 2

```
문제: factorial을 계산하는 쉘 프로그램을 작성하시오. 단, recursive 함수 호출을 사용하시오.
$ factorial.sh 3
3!은 6이다.
```

```shell
#!/bin/bash

function fact {
	local x=$1
	let local y=$x-1
	local z=1
	
	if [ $x -gt 1 ]
	then
		fact $y
		let z=$x*$?
	fi
	return $z
}

fact $1
echo "$1!은 $?이다"
```

