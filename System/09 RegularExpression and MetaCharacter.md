# Regular Expression and Meta Character

## Regular Expression(정규식)

### Regular Expression

- character들의 특정 pattern을 나타내기 위한 expression
- 검색을 위한 목적으로 활용
- vi, grep, ex, sed, awk, emacs, more, less 등에서 사용

### 정규식의 메타문자(특수 문자)

- 정규식의 행동을 제어하는 특별한 문자
- . * \ [] ^ $
- Shell이 사용하는 메타문자와는 약간 다름!



| 메타문자 | 의미                                                         |
| :------: | ------------------------------------------------------------ |
|    .     | Any single character                                         |
|    *     | Zero or more repeat                                          |
|    \     | Character escape                                             |
|    ^     | Begin of line(정규식의 첫문자로 쓰인 경우에만)               |
|    $     | End of line(정규식의 마지막 문자로 쓰인 경우에만)            |
|    []    | []안에서는 메타 문자의 성질을 잃는다. 다만 ^이 첫문자일 땐 negation, -이 중간에 있을 땐 range를 뜻하는 메타 문자로 사용된다. |

| 예시   | 의미                   |
| ------ | ---------------------- |
| a.c    | abc, aac, a1c 등       |
| a*c    | ac, a1c, a11c          |
| ^abc   | abc가 항상 제일 앞에   |
| abc^   | abc^만 가능            |
| abc$   | abc로 끝나기           |
| ab$c   | ab$c만 가능            |
| [a*c]  | a \|\| * \|\| c        |
| [a.c]  | a \|\| . \|\| c        |
| [a-z]  | a~z 중 한 글자         |
| [^a-c] | a, b, c가 아닌 한 글자 |
| [a^bc] | a \|\| ^ \|\| b \|\| c |

| 메타문자  | 의미                                      |
| --------- | ----------------------------------------- |
| c\{m\}    | 문자 c가 m번 반복될 때 매치               |
| c\{m,\}   | 문자 c가 m번 이상 반복될 때 매치          |
| c\{m,n\}  | 문자 c가 m번 이상 n번 이하 반복될 때 매치 |
| \{e\}     | 정규식을 하나의 문자처럼 묶어줌           |
| \n (무시) |                                           |

```
예시
a\{3,5\}\(bb\)*cd\(dd\)*

1. a가 3번~5번
2. bb가 m번(짝수) 반복
3. c
4. d가 홀수번(1번 3번 5번) 반복

가능한 경우
aaaabbcd
aaacddd
```



## Meta Character

|        분류         | 메타문자 | 의미                       |
| :-----------------: | :------: | -------------------------- |
| File name expansion |    *     | 문자열 wildcard            |
| File name expansion |    ?     | 한 문자 wildcard           |
| File name expansion |    []    | 문자 집합 wildcard         |
| File name expansion |    {}    | 문자열 집합 (comma로 분리) |
|                     |          |                            |
|                     |          |                            |
|                     |          |                            |
|                     |          |                            |
|                     |          |                            |
|                     |          |                            |
|                     |          |                            |
|                     |          |                            |
|                     |          |                            |
|                     |          |                            |
|                     |          |                            |



## File Name Expansion

### wildcard: 임의의 문자와 매칭

있는 파일로만 확장시킴

|                   |                                            |
| ----------------- | ------------------------------------------ |
| ?                 | 한 문자와 매칭                             |
| *                 | 임의의 길이의 문자열과 매칭 (널 문자 포함) |
| [set]             | set의 문자 중의 하나와 매칭                |
| [a-f]             | a와 f 사이의 알파벳과 매칭                 |
| [!set] or [ ^set] | set에 없는 문자 중의 하나와 매칭           |

예시

```pseudocode
ls 명령어가 앞에 붙었다고 생각하고.

a.?				a.c a.o 등
*e*  			e가 중간에
*				다
[abc] 			a||b||c					
[.,;]			.||,||;
[!0-9]			숫자가 아닌 문자
[0-9!]			숫자와 느낌표
[a-zA-Z0-9_-]	모든 알파벳, 숫자, underscore, dash
```

### 괄호 확장

일단 모두 확장시킨 뒤 찾음

|                    |                                                    |
| ------------------ | -------------------------------------------------- |
| ls /a/b/{c.h,d.h}  | ls /a/b/c.h  /a/b/d.h                              |
| ls a{a1, b1, c1}.c | ls a1.c b1.c c1.c로 a1.c가 없으면 오류 메세지 나옴 |

### 입출력

- **표준 입출력**

  - standard output: screen
  - standard error: error message
  - standart input: keyboard

- **입출력 재지정**

  - | 종류            | 의미                                                     |
    | --------------- | -------------------------------------------------------- |
    | command > file1 | command의 표준 출력을 file1로 보냄                       |
    | command < file2 | file2의 내용을 표준 입력으로 사용하여 command 실행       |
    | >>              | 이미 파일이 존재하는 경우 append                         |
    | >&              | 표준 출력 뿐 아니라 standard error까지 파일로 보냄 (>>&) |

  - 예시

    ```
    $ cat < file1 > file2 // file1의 내용을 cat이 입력받아 file2에 새로 씀
    $ cat < file1 >> file2 // file1의 내용을 cat이 입력받아 file2에 붙여 씀
    $ cat < file1 >& file2 
    $ abcdefg >& error.txt // 명령어를 수행하지 못했다는 에러 내용을 error.txt에 저장
    ```

    

- **파이프(Pile, |)**

  command1의 표준 출력을 command2의 표준 입력으로 사용

  - 예시1

    ```
    $ ls
    a.c b.c cc.c
    $ ls | wc -w // space나 .d으로 구분된 단어 수
    5
    ```

  - 예시2

    ```
    $ cat userid | sort
    glass
    james
    john
    kang
    tim
    ```

    ```
    $ cut -d: -f1 /etc/passwd | sort > users
    1 /etc/passwd의 파일을 ':'을 delimeter로 첫번째 field(즉, 아이디)만 잘라내라
    2 앞 선 명령어의 내용을 sort해라
    3 결과를 users 파일에 저장해라
    ```

     

### shell 변수 ($)

```
$ name1 = p
$ name2 = je
$ echo $name1 $name2
p je
```

### command substitution (``)

명령어가 수행되어 대체된다.

```
$ d=`date`
$ echo $d
Tue Nov 17 10:25:21 PST 2020
```

### Escape Character

- **\: back slash**

  ```
  $ echo *
  파일 리스트 출력
  $ echo \*
  *
  $ grep [a-z]* *.c
  ```

  ```
  $ echo hi > file // echo의 출력을 file에 저장
  $ echo hi \> file // 메타 문자 escape
  hi > file
  ```

- **"": double quote**

  ```
  $ echo "This part not for shell except $PATH"
  This part not for shell except 변수에게 입력된 값
  $ echo "Today is `date`"
  Today is Tue Nov 17 10:25:21 PST 2020
  ```

- **'': single quote**

  ```
  $ echo 'This part not for shell except $PATH'
  This part not for shell except $PATH
  $ echo 'Today is `date`'
  Today is `date`
  ```

### 명령 분리자

```
$ date; pwd; ls
```

### Subshell

로그인 시 유닉스는 초기 로그인 shell을 제공한다.

입력된 단순 명령들은 초기 shell에 의해 실행된다.

명령어 그룹(command group): 괄호 안에 명령분리자로 묶인 command들에 대해서는 자식 shell을 별도로 생성하여 실행시킴

```
$ a=yes
$ (a=no; echo $a)
no
$ echo $a
yes
$ (date; cd Promgramming; pwd) > output
```

### 조건부 실행

```
$ gcc a.c && a.out	// 앞 명령어가 성공적으로 끝날 경우에만 뒤 명령어가 실행된다.
$ gcc a.c || echo compile error // 앞 명령어가 실패할 경우에만 뒤 명령어가 실행된다.
```

### home directory ~: tilde

### grep

패턴을 찾아 그 패턴이 있는 line을 보여준다.

grep [options] pattern [File]

options:

​	-c: count, 패턴이 나타난 횟수만 명시한다.

​	-h: hide, 파일 이름을 명시하지 않는다.

​	-n: number, 줄 번호도 표시해준다.

​	-l: 파일 목록만 표시한다.

​	-v: pattern이 없는 라인을 보여준다.

​	-w: word, word 단위로 정확히 일치할 때만 출력한다.

​	-x: line, line 단위로 정확히 일치할 때만 출력한다.

​	-i: ignore, pattern의 대소문자 무시하고 찾는다.

주의할 점은 띄어쓰기를 기준으로 구분이 되기 때문에 패턴에 공백이 있을 땐 "패턴 패턴"으로 묶어주어야 한다.

옵션은 -wn 섞어쓸 수 있다.

### find