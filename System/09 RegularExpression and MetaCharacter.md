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

