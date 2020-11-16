# LINUX 환경에서의 PROGRAM 실행

## gcc

- gnu c compiler
- C++ 컴파일러는 g++이다.
- 파일 이름은 반드시 .c로 끝나야 한다.
- 컴파일 결과 실행 파일 이름이 a.out이 된다.
- -o filename: 실행파일 이름을 지정한다.

### **[SeparateCompile 예제]**

**static library**

- functions are copies into executable file during gcc time
- binding: complie time
- suffix: .a (archive의 준말)
- default linking: /lib/libc.a

1. Home directory에 SeparateCompileExample 디렉토리를 생성하고 해당 디렉토리로 이동한다.

2. vi editor로 main.c 를 작성한다.

```C
#include <stdio.h>
#include "add.h"

void main(int argc, char* argv[])
{
        int result = 0;

        if (argc < 2) {
                printf("Usage : ./mytest <1st num> <2nd num>\n");
                return;
        }
    
        result = add(atoi(argv[1]), atoi(argv[2]));
    
        printf("Reuslt : %s + %s = %d\n", argv[1], argv[2], result);
    
        return;

}
```

3. vi editor로 add.h 를 작성한다.

```C
#include <stdio.h>
#include <stdlib.h>

extern int add(int, int);
```

4. vi editor로 add.c 를 작성한다.

```C 
#include "add.h"

int add(int a, int b){
        int result;
        result = a + b;
        return result;
}
```

5. main.c add.c를 단순Compile 한다. acc.o와 main.o 파일이 생성된다.

   ```
   201LinuxEx185@linux01:~$ gcc -c main.c add.c
   ```

6. 명령어 프롬프트에서 아래 Command를 실행한다. static link를 하는 것이다.

   ```
   201LinuxEx185@linux01:~$ gcc –o mytest main.o add.o
   ```

   main.o랑 add.o를 링크해서 mytest 실행파일을 만들어줘.

7. 파마미터로 숫자를 넘겨 mytest을 아래와 같이 실행해본다.

   ```
   201LinuxEx185@linux01:~$ ./mytest 1 2
   ```

### **[SharedLib 예제]**

**Shared library**

- functions are not copied during gcc time (Just mapping)
- During the run, load on demand from library (shared)
- binding: run time
- Suffix: .so (shared object)
- default linking: /lib/libc.so

1. Home directory에 위에서 작성했던 SeperateCompileExample의 내용을 포함하여 SharedLibExample 디렉토리로 복사한다.

   ```
   cp -r SeperateCompileExample SharedLibExample
   ```

2.  vi editor로 .bashrc(Home directory)의 제일 마지막에 아래 내용을 추가한다.
   .bashrc는 로그인할 때 default로 실행되는 파일이다.

   ```
   LD_LIBRARY_PATH=/home/[본인ID]/SharedLibExample:$LD_LIBRARY_PATH
   export LD_LIBRARY_PATH
   ```

   load library path의 준말이고 이전에 선언된 library path에 우리가 원하는 library path를 추가하고 export로 등록함

3. 명령어 프롬프트에서 위에서 작성한 내용을 적용시키기 위해 아래 Command를 실행한다.

   ```
   201LinuxEx185@linux01:~$ source .bashrc
   ```

4. 명령어 프람프트에서 아래 Command를 실행한다.

   ```
   201LinuxEx185@linux01:~$ gcc –fPIC –c add.c
   201LinuxEx185@linux01:~$ gcc –shared –o libadd.so add.o
   201LinuxEx185@linux01:~$ gcc –o mytest main.c libadd.so
   ```

   -fPIC: library의 location을 자유롭게 한다는 의미이다.

   add.o object를 사용해서 shared library인 libadd.so를 만들어라.

   마지막 줄에서 dynamic linking을 한다.

5. app.out을 아래와 같이 실행해본다.

   201LinuxEx185@linux01:~$ ./mytest 1 2

### **[Makefile 예제]**

1. Home directory에 위에서 작성했던 SeperateCompileExample의 내용을 포함하여 makeExample 디렉토리로 복사한다.

2. vi editor로 Makefile 파일을 생성한다.

   ```
   all : mytest
   
   mytest: main.o add.o
           	gcc -o mytest main.o add.o
   
   main.o: add.h main.c
   
   add.o: add.h add.c
   ```

   make라고 치면 일단 all을 찾게 되는데 all 이 mytest를 찾는다.
   mytest는 main.o랑 add.o로 구성이 되어 있는데 my test를 만들려면 아래의 명령어를 실행해야한다.
   main.o는 add.h와 main.c가 수정되면 다시 만들어져야 한다.

   add.o는 add.h와 add.c가 수정되면 다시 만들어져야 한다.

3. 명령어 프람프트에서 아래 Command를 실행한다.

   ```
   student50@linux01:~/make_example$ make
   ```

4. mytest을 아래와 같이 실행해본다.

   ```
   student50@linux01:~/make_example$ ./mytest 1 2
   ```



## 프로세스 관리

프로세스: 컴퓨터에서 연속적으로 실행되고 있는 컴퓨터 프로그램

1. **프로세스 관리와 관련한 명령어(command)**

   **ps**

   - 현재 동작 중인 프로세스들을 출력
   - ps [option]
     - ps : 현재 창(putty)에서 실행한 프로세스만 출력한다.
     - ps -x : 자신이 사용하는 모든 프로세스 출력한다.
     - ps -aux: 시스템에서 동작하는 모든 프로세스들을 출력한다.

   **kill**

   - 프로세스에게 signal을 보낼 때 사용
   - kill [option] pid
     - option을 쓰지 않으면 SIGTERM 시그널을 프로세스에게 보내 스로세스를 종료한다.
     - -s signal: 프로세스에게 보낼 signal을 명시
     - -KILL or -9: 보통의 kill로 죽지 않는 경우 강제로 죽이는 기능
     - -HUP: 데몬 프로세스를 다시 실행할 때 사용

   **top**

   - CPU 사용량이 top인 프로세스들을 출력

   - top [-] [d delay] [q] [c] [i] // 옵션 생략

   - 화면 설명

     | 항목 | 설명                                                         |
     | ---- | ------------------------------------------------------------ |
     | PID  | process ID                                                   |
     | PPID | Parent Process ID                                            |
     | UID  | 소유자의 User ID                                             |
     | USER | 소유자                                                       |
     | STAT | S: sleeping, R: running, D: uninterruptible sleeping, Z: zombie, T:stop or trace |
     | %CPU | CPU 사용 퍼센트                                              |
     | %MEM | 메모리 사용 퍼센트                                           |

     

   **nohup**

   - 로그아웃 후에도 계속 프로세스가 수행되도록 함
   - nohup 실행파일이름 &

   **nice**

   - 프로세스를 매우 낮은 우선순위로 수행시킴
   - nice 실행파일이름

2. **프로세스 관리와 관련한 내부 명령어**

   **jobs**

   - command 뒤에 &를 붙이면 background로 process 수행
   - ./mytest &

   **fg** [job_id]

   - job_id의 process를 foreground로 전환
   - job_id를 입력하지 않으면 '가장 최근에 stop시킨 process' or 'bg로 수행시킨 process'를 전환

   **bg** [job_id]

   - job_id의 process를 background로 실행 재개
   - job_id를 입력하지 않으면 '가장 최근에 stop된 process'를 실행 재개

3. **프로세스 관리와 관련한 제어키**

   **control-c**

   - foreground process의 종료

   **control-z**

   - foreground process의 stop(suspended, 일시중지)
   - fg 혹은 bg로 계속 실행 가능

   background일 경우 fg로 바꿔서 중지하거나 바로 kill하는 방법이 있음.

