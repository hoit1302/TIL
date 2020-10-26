## Mips Register & Memory Model







MIPS의 data transfer instruction에서 operand에 메모리가 올 수 있다.

MIPS의 arithmetic instruction에서 operand에 메모리가 올 수 없다.



## MIPS Register & Memory Model

![image](https://user-images.githubusercontent.com/68107000/97178046-4dc50900-17da-11eb-9103-123b2a795920.png)

- 한 레지스터는 32bit이다.
- register를 구분하기 위해서는 5bit가 필요하며 이는 구분해야 할 register의 수가 32개이기 때문이다.
- MIPS는 32bit 의 메모리 주소 체계를 사용하여 4GB의 메모리 위치(address)를 구분할 수 있다.

## MIPS Instructions

- Arithmetic/Logic instructions
- Data Transfer (Load/Store) instructions
- Conditional branch instructions
- Unconditional jump instructions

## MIPS Instruction Format

![image](https://user-images.githubusercontent.com/68107000/97178257-97155880-17da-11eb-842a-9359a7fda5e7.png)

- MIPS의 instruction은 그 크기가 4Byte (32bit)로 균일하다.

### instruction 유형 별 예시

(a) add, slt

(b) addi, lb, sw, beq

(c) j



### Arithmetic Operations

![image](https://user-images.githubusercontent.com/68107000/97178680-2c185180-17db-11eb-9e13-1b8f5fecfaec.png)![image](https://user-images.githubusercontent.com/68107000/97178719-3c303100-17db-11eb-890a-20a3cec5226b.png)

### Logic Operations

![image](https://user-images.githubusercontent.com/68107000/97178771-4fdb9780-17db-11eb-9116-c8db939222a7.png)

### Data Transfer Instructions

![image](https://user-images.githubusercontent.com/68107000/97178821-5ff37700-17db-11eb-9bde-2b153343aa63.png)

### Conditional Branch Instructions

![image](https://user-images.githubusercontent.com/68107000/97178874-76013780-17db-11eb-841c-db766dafc3a5.png)

### Unconditional Jump Instructions

![image-20201026223512207](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201026223512207.png)



### 응용 문제

🎈 jump할 수 있는 주소 범위가 넓은 것부터 좁은 것의 순서대로 나열한 것은?

jr ($ra로 32비트) -> j (26비트) -> beq(16비트)

🎈 피연산자의 표현에 드는 총 비트수가 많은 것부터 적은 것의 순서로 나열한 것은?

lw(전체) add($ $ $ unused func_add) jr($ra)

🎈 수행 시간이 오래 걸리는 instruction: lw

🎈 피연산자에 레지스터가 가장 적게 사용되는 것부터 가장 많이 사용되는 것의 순서로 나열한 것은?

jr addi add

🎈 어떤 ISA는 64개의 레지스터를 사용하고 34비트의 메모리 주소 체계를 사용한다고 한다.

Addressing 가능한 메모리의 크기는 2^34Byte이고 레지스터를 3개 사용하는 산술 연산에서 피연산자를 표현하기 위해 필요한 총 비트 수는 6*3=18이다.

