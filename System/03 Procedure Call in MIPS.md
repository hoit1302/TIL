Procedure Call in MIPS

![03-1](https://user-images.githubusercontent.com/68107000/95711338-8377d700-0c9d-11eb-9ba1-c38aee885136.PNG)

보이는 박스는 메모리이다.

메모리 주소는 프로그램(실행파일)마다 논리주소 0번지부터 존재한다.

이 주소의 범위는 물리적인 메모리를 몇 GB 쓰는 지와는 전혀 상관이 없다.

논리주소의 범위는 ISA에 의해 결정된다.

MIPS의 경우, 32bit 메모리 주소 체계를 쓰기에 2^32Byte 만큼 ㅡ> 4GB만큼

Code 부분은 내용이 바뀌지 않는다.

PC는 program counter로, 현재 실행되고 있는 코드를 가리킨다.

<br>

## Stack

- **$sp** (stack pointer): top-가장 최근 저장 위치를 가리킴

  

- stack에 정보 저장

  ```assembly
  sub $sp, $sp, 4		// $sp -= 4 아래로 이동
  sw $t0, 0($sp)		// $t0에 store
  ```

- stack에 정보 인출

  ```assembly
  lw $t0, 0($sp)		// $t0에 load
  add $sp, $sp		// $sp += 4
  ```



MIPS Procedure Call

![03-2](https://user-images.githubusercontent.com/68107000/95711339-84106d80-0c9d-11eb-8be4-2b1009336fa5.PNG)

jal(jump and link): return address를 $ra에 저장 후 jump(PC가 바뀜)

호출을 한 번 더 할 때는 $ra를 스택에 저장한 후 또다른 return address를 $ra에 저장

돌아와서는 스택의 정보를 $ra에 담고 jr $ra 돌아가기

<br>

## Stack Frame

![03-3](https://user-images.githubusercontent.com/68107000/95711340-84a90400-0c9d-11eb-87cd-8c48f6abe7cc.PNG)

- **Stack frame**

  "procedure가 사용 중인 데이터를 stack 상의 자신의 frame에 저장"

  - **$fp** (frame pointer) –를 기본 위치로 하여 procedure가 그 데이터를 접근
  - **$sp**는 **procedure** 사용 중에도 값이 변할 수 있음

- **Stack frame에 저장되는 내용**

  - 전달되는 argument 중 5번째부터. (4개까지는 register a0~a3에 저장)

  - save된 register들의 값

  - 그 procedure의 local variable들

<br>

## Register의 저장

- **변수들을 최대한** <u>**register**</u>에 **mapping**해서 사용
  - register는 memory보다 10배 이상 빠름
  - procedure 호출 시 register를 새로운 지역변수에 mapping해서 사용
  - procedure 호출 시 register의 기존 내용 저장 필요

+) procedure 는 function과 거의 같은 말!

- **callee save** **또는** **caller save**

  MIPS의 경우

  - **Callee-save register** - 여기부터 이어서!
    
    - ***Saved $s0~$s7***
- Frame pointer $fp
  
  - **Caller-save register**
  
    호출하기 전에 내 정보들을 저장 
  
    - ***Temporary $t0~$t9***
  
    - Argument $a0~$a3
  
      (나도 누군가 호출해줬어 그때의 값)
  
    - Return value $v0~$v1
  
    - Return address $ra
  
      (나도 어딘가로 돌아가야지!)

