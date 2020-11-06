# Linux Command

## Command vs Instruction

### command

일종의 **독립적인 프로그램(실행파일)**임 

기계어들의 모임

(복잡한 것은 software, utility라고 부름)

- cat ls cp vash vi gcc
- 단, 내부 명령어는 bash가 직접 처리함(예: cd)

### Instruction

**CPU가 수행하는 기계어**

기계어의 한 줄

- add sub jump branch load store

## Command                             

### more 파일이름

- 텍스트 파일의 내용을 화면에 출력한다.
- 내용이 길 경우에 **한 화면씩 끊어서 보여준다**는 점에서 cat과 다르다.
- space bar 나 b, f로 앞뒤 움직임
- Pipe("|")를 이용해서 다른 프로그램들과 동시에 사용되기도 한다.

### less

-  more와 비슷하게 텍스트의 내용을 한 화면씩 끊어서 보여준다.
- 앞의 내용으로 돌아갈 수 있다.

### date

- 시스템의 날짜, 시간 표시 및 변경

- (변경은 수퍼유저만 할 수 있다)

- ```
  $ date			
  2003. 03. 28. (금) 11:00:25 KST
  $ date 03281101 // 수정
  2003. 03. 28. (금) 11:01:00 KST
  ```

### cal

- 달력 출력

### wc

wc [-lwc] FILE

파일 낸 단어 수 세기

-l: line 수

-w: word 수

-c: character 수

```
$ wc -lwc heart
4 19 106 heart
```

### su

su *user_id* 

다른 사용자로 로그인

super user의 약자

user_id를 명시하지 않으면 root로 사용자 변경 (막강한 관리자로.)

```
[ewha100@csn0 ewha112]$ su ewha200
Password: ewha200의 패스워드 입력하면 변경됨.
[ewha200@csn0 ewha112]$
```

### cmp (X)

### id

id [options] [usre_name]

사용자의 id, group id 등의 정보를 출력한다.

### logname

현재 사용자의 login name을 출력한다.

**whoami**와 동일하게 작동

### w (who)

w [options] [user name]

현재 시스템을 사용 중인 사용자들에 대한 정보를 출력한다.

### (un)compress (X)

### grip

간단하게 

```
$ gzip foo.txt 			ㅡ> foo.txt는 사라지고 foo.txt.gz 파일이 생김
$ gzip -d foo.txt.gz	ㅡ> foo.txt.gz이 사라지고 foo.txt파일이 생김
```

-d: decompress

gunzip == gzip -d

### tar

Tape ARchive의 약자

여러 파일을 묶어서 하나로 만드는 기능

c: create

x: extract

v: verbose 긴 출력 정보 (어떤 파일을 압축하는지, 풀었는지)

f: 파일 이름

z: 압축

```
$ tar cvfz MakeAccount.tar.gz MakeAccount 
$ tar xvfz MakeAccount.tar.gz
```

원본 파일이 지워지지 않음.

추가적으로 압축 파일이 생성, 압축해제 파일이 생성

### split (X)

### sort

sort [options] [FILE]

입력을 ASCII값 기준으로 정렬한다.

공백<대문자<소문자

옵션

- -r: 내림차순(reverse order)으로 정렬
- -b: 줄의 앞에 있는 공백을 무시
- -f: 대소문자 무시
- -t: 항목 분리자를 명시하기 위해서 사용 ㅡ> (?)
- -n: 숫자 순으로 정렬

### uniq

uniq [options] [FILE]

중복된 행을 제거한다.

### finger

finger [options] [user_id]

사용자의 정보를 출력한다.(/etc/passwd에서 읽어옴)

- user_id를 지정하지 않으면 현재 로그인한 모든 사용자의 정보출력
- options
  - -l: long form으로 표시한다
  - -s: short form으로 표시다.

### chfn

change finger: 사용자의 finger를 변경한다.

```
[jueun@csn0 ewha]$ chfn
Changing finger information for jueun.

Password:
Name []:
Office []:
Office Phone []:
Home Phone []:

Finger information changed.
[jueun@csn0 ewha]$ finger // 정보 출력
```

### write, talk(X)

### wall

wall [FILE]

모든 사용자에게 메세지 전송

```
$ wall
Hi, I'm Jueun.
^c
```

### mesg (X)



