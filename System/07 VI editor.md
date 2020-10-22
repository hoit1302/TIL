# VI editor

### VIsual Editor, Linux 표준 편집기

- 행단위 편집기가 아닌 전체 화면 단위

- 초기 부족한 키보드 자판으로 다양한 기능성을 부여

- 명령과 편집을 별도 모드로 구분하여 수행

- 최근에는 vim(VI iMproved)를 사용

### vi의 모드

![image-20201012165005702](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201012165005702.png)

### vi 시작

vi filename:  파일이 존재하지 않으면 새로 만들고 존재하면 해당 파일을 열어서 편집함

esc: 명령 모드 진입

------

### 편집 모드

| 키   | 기능                                     |
| ---- | ---------------------------------------- |
| i    | insert, 현재 커서 위치에서 추가          |
| a    | append, 현재 커서 **다음** 위치에서 추가 |
| o    | open, 커서 **다음 행**에 추가            |
| O    | 커서 위치 **윗쪽 행**에 추가             |



------

### 파일 저장 종료

| 명령       | 기능                                                         |
| ---------- | ------------------------------------------------------------ |
| :w         | 현재 파일 저장(write)                                        |
| :w <path>  | 현재 편집 내용을 **해당 경로**로 저장                        |
| :w! <path> | **해당 경로**에 파일이 이미 존재하는 경우 **Overwrite**하여 저장 |
| :q         | vi 수행 종료 (quit)                                          |
| :wq        | 현재 수정 내용을 **저장**하고 종료                           |
| :q!        | 수정 사항 **반영없이 강제** 종료                             |
| :w!        | 편집 도중 파일이 변경된 경우 **강제 저장**                   |



------

### 커서 이동(일반 명령 모드)

| 키             | 기능                          |
| -------------- | ----------------------------- |
| h,**j**,k,l    | ← **↓** ↑ →                   |
| Ctrl+F, Ctrl+B | 한페이지 아래(PgDn), 위(PgUp) |
| ^, $           | 행선두(Home), 행끝(End)       |
| G              | 문서 마지막행으로             |
| gg             | 문서 첫행으로                 |
| b, w           | 단어 앞, 뒤                   |

### 커서 이동(ex 모드)

| 명령 | 기능              |
| ---- | ----------------- |
| :0   | 첫행으로 이동     |
| :$   | 마지막행으로 이동 |
| :nn  | nn행으로 이동     |
| :.   | 현재행으로 이동   |



------

### 삭제 기능(명령모드)

| 키   | 기능                                                         |
| ---- | ------------------------------------------------------------ |
| x    | 커서의 한문자 삭제                                           |
| dw   | 커서에서 단어(공백이나 특수 문자. / 등으로 구분) 끝까지 삭제 |
| dd   | 커서가 위치한 현재행 전체를 삭제                             |
| dG   | 커서가 위치한 행으로부터 문서끝까지 삭제                     |
| dgg  | 커서가 위치한 행으로부터 문서첫분부분까지 삭제               |
| d$   | 커서가 위치한 곳부터 행 끝까지 삭제                          |
| d^   | 커서가 위치한 곳부터 행 처음까지 삭제                        |

### 삭제 기능(ex 모드)

| 예제    | 의미                                       |
| ------- | ------------------------------------------ |
| :12d    | 12행 삭제                                  |
| :1,100d | 1부터 100행 삭제                           |
| :1,$d   | 모든 행 삭제                               |
| :+10d   | 커서가 위치한 현재에서 10행 뒤의 행을 삭제 |
| :-2,.d  | 커서가 위치한 2행 전부터 현재행까지 삭제   |



------

### Copy

| 예시    | 의미                            |
| ------- | ------------------------------- |
| yy or Y | 1줄 복사                        |
| 2yy     | 현재행부터 2행 복사             |
| 10yy    | 현재행부터 10행 복사            |
| yw      | 현재 커서위치부터 단어까지 복사 |
| yG      | 현재행부터 문서끝까지 복사      |
| ygg     | 현재행부터 문서첫부분까지 복사  |

### Paste

| 예시 | 의미                                 | 워드 복사 시                       |
| ---- | ------------------------------------ | ---------------------------------- |
| p    | 현재행 아래에 붙여넣기               | 현재행 뒤에 붙여넣기               |
| P    | 현재행 위에 붙여넣기                 | 현재행 앞에 붙여넣기               |
| 2p   | 현재행 아래에 2번 반복해서 붙여 넣기 | 현재행 뒤에 2번 반복해서 붙여 넣기 |
