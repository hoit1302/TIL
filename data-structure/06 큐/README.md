## QUEUE

먼저 들어온 항목이 먼저 나가는 특수한 선형 리스트

FIFO: First-In First-out

## 1) 배열을 이용한 큐

- **선형 큐**
  - 삽입을 계속하기 위해서는 원소들을 이동시켜야 함. 
  - 비효율적으로, 잘 사용되지 않음.

- **환형 큐**
  - 배열을 환형으로 사용하여 큐를 구현

### 환형 큐의 구조

- 앞(**front**): 가장 **최근에 제거된** 원소의 인덱스(빈 공간을 가리킴)

- 뒤(**rear**): 가장 **최근에 삽입**된 원소의 인덱스

### is_empty(), is_full()

- MAX_QUEUE_SIZE -1개를 저장할 수 있는, 즉 항상 한 칸을 비워 둘 경우

  ![image](https://user-images.githubusercontent.com/68107000/96698674-60010a80-13c8-11eb-99dd-7c1f948dbae9.png)

  is_empty(): front == rear

  is_full(): front == (rear+1) % MAX_QUEUE_SIZE

  +) 큐에 있는 원소의 개수 = (MAX_QUEUE_SIZE - front + rear) % MAX_QUEUE_SIZE

  

- count 변수를 두는 경우, 즉 모든 칸을 쓰는 경우

  is_empty(): count == 0

  is_full(): count == MAX_QUEUE_SIZE



## 2) 연결 큐(linked queue)

- 연결 리스트로 구현된 큐
- ![image](https://user-images.githubusercontent.com/68107000/96693930-c71bc080-13c2-11eb-9fe5-6ddf4c8ce2db.png)
- **front는 삭제**, **rear는 삽입**을 위해 유지하는 포인터
- front는 연결 리스트의 맨 앞에 있는 노드를 가리키며, rear는 맨 뒤에 있는 노드를 가리킨다.
- is_empty(): front가 NULL(또는 동시에 rear가 NULL)

### 연결 큐에서의 삽입

![image](https://user-images.githubusercontent.com/68107000/96693765-9a67a900-13c2-11eb-9913-ca3e345986c0.png)

### 연결 큐에서의 삭제

![image](https://user-images.githubusercontent.com/68107000/96693862-b2d7c380-13c2-11eb-9888-7d43d2a9aebf.png)

### 환형 연결리스트?

![image](https://user-images.githubusercontent.com/68107000/96694096-f5010500-13c2-11eb-8731-7be6262bd563.png)

## 큐의 응용 - 버퍼(buffer)

- 큐는 서로 다른 속도로 실행되는 **두 프로세스 간의 상호 작용을 조화**시키는 버퍼 역할을 담당
- CPU와 프린터 사이의 프린팅 버퍼 또는 CPU와 키보드 사이의 키보드 버퍼
- 대개 데이터를 생산하는 **생산자 프로세스**가 있고 데이터를 소비하는 **소비자 프로세스**가 있으며 이 사이에 큐로 구성되는 버퍼가 존재

```C
QueueType buffer;
// 생산자 프로세스
producer() {
    while(1){
        데이터 생산;
        while( lock(buffer) != SUCCESS ) ;  // 소비자 프로세스가 끝나고 락이 풀려야 락을 걸 수 있음. 소비자 프로세스가 끝날 때까지 기다림
        if( !is_full(buffer) )
        	enqueue(buffer, 데이터);
        unlock(buffer); // 다시 소비자 프로세스가 쓸 수 있도록 unlock
    }
}
// 소비자 프로세스
consumer() {
    while(1){
        while( lock(buffer) != SUCCESS ) ;
        if( !is_empty(buffer) ){
            데이터 = dequeue(buffer);
            데이터 소비;
        }
        unlock(buffer);
    }
}
```

