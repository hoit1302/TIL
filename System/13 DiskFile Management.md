# Disk and File Management

## 컴퓨터 시스템의 기본 구성(hardware)

![image](https://user-images.githubusercontent.com/68107000/101467251-6a319500-3985-11eb-8e16-ea4c23814b0c.png)

### 임시 기억장치

(DRAM)

- 각종 자료(데이터)를 임시로 저장해 두는 장치
- CPU(중앙처리장치) 처리 결과를 임시 저장할 수 있음. 
- 장점 : 빠른 입출력 속도 
- 단점 : 전기가 공급되지 않으면 저장 내용이 삭제됨

### 영구 기억장치

- 각종 장치에서 사용하는 자료(데이터)를 영구적으로 저장할 수 있는 장치 
  - Eg. HDD(Hard Disk Drive), SSD(Solid State Drive), USB Stick 
- 장점 : 전기가 공급되지 않아도 저장 내용이 지워지지 않음. 
- 단점 : 비교적 느린 입출력 속도

**HDD(hard disk drive)의 특성**

- 자기(Magnetic)을 이용해 데이터를 (반)영구적으로 저장함.
- 데이터를 플래터에 저장하기 위해 비교적 **복잡한 구조**를 가짐
- 용량 대비 가격이 저렴하고 저속이어서 **대량**의 데이터 저장에 적합함.

**SSD(solid state drive)의 특성**

- 메모리 반도체를 이용해 데이터를 (반)영구적으로 저장함.
- 제어기와 메모리 반도체만 사용하여 비교적 **단순한 구조**를 가짐
- 용량 대비 가격이 비싸고 고속이어서 비교적 **소량**의 데이터 저장에 적합함

### 기억장치(Memery)의 계층구조

기억 장치는 계층 구조(Hierarchy)를 갖는다.

저장하는 데이터의 성격에 따라 단계별로 다른 저장장치를 사용한다.

![image](https://user-images.githubusercontent.com/68107000/101467701-0065bb00-3986-11eb-8e9a-9fdae1ec62ef.png)

## File and File System

### File

- “A named collection of related information”
- 일반적으로 영구기억장치에 저장 
- 운영체제는 다양한 저장 장치를 file이라는 동일한 논리적 단위로 볼 수 있게 해 줌

### File attribute (혹은 파일의 metadata)

- 파일 자체의 내용이 아니라 파일을 관리하기 위한 각종 정보들
- 파일 이름, 유형, 저장된 위치, 파일 사이즈 
- 접근 권한 (읽기/쓰기/실행), 시간 (생성/변경/사용), 소유자 등

### File system

- 운영체제에서 파일을 관리하는 부분
- 파일 및 파일의 메타데이터, 디렉토리 정보 등을 관리 
- 파일의 저장 방법 결정
- 파일 보호 등

### Directory

- 파일의 메타데이터 중 일부를 보관하고 있는 일종의 특별한 파일 
- 그 디렉토리에 속한 파일 이름 및 파일 attribute들의 리스트

### Linux의 file system

![image](https://user-images.githubusercontent.com/68107000/101468877-538c3d80-3987-11eb-8b1a-941c21069a26.png)

/etc/passwd

/etc/shadow

/etc/group

## Linux System directory 구조

![image](https://user-images.githubusercontent.com/68107000/101468306-913c9680-3986-11eb-8a1d-d92edfe48fa0.png)

- Linux file system standard
  - Linux directory structure의 표준
  - 표준화를 통해 시스템 관리를 용이하게 한다.
  - 프로그램들 간 호환성 유지에 도움을 준다.

### Root file System

- 각각의 시스템에 고유하다.
- 시스템 부팅에 필요한 파일들이다.
- 고장난 시스템의 복구에 필요한 도구들이다.
- 손상 시 linux 시스템을 부팅할 수 없다.
- 일반적으로 중요한 파일들만 담아서 작게 만들었다.

**하위 directory에 대한 설명**

- /bin : 일반 사용자들이 사용하는 주요 프로그램들
- /sbin : 시스템 관리자가 사용하는 프로그램들
- /etc : 시스템의 각종 설정 파일들 
- /root : 시스템 관리자의 홈 디렉토리 
- /dev : 각종 장치(device) 파일들
- /tmp : 임시 파일들
  - 주기적으로 청소되기에 주의해야 한다.
  - 모두 접근 가능하므로 다른 유저와 파일을 주고 받을 때 쓸 수 있다.
- /lib : 공유 라이브러리 파일들
- /lib/modules : 커널 모듈 파일들 
- /boot : 시스템 부팅시에 필요한 파일들 
- /mnt : 임시 Mount 포인트
- /usr : 프로그램들이 위치하는 곳
  - 
- /etc : 여러가지 시스템 설정 파일들
  - /etc/passwd : 사용자에 대한 정보가 들어있는 파일
  - /etc/shadow : shadow passwd 파일
  - /etc/login.def : login에 대한 설정파일
  - /etc/profile : 모든 사용자에 적용되는 shell 설정 파일
- /dev : 모든 장치 (링크)파일이 저장되는 디렉토리
  - 장치 파일 목록 (시스템에 존재하는 장치에 대응하는 파일)
    - mouse: 마우스
    - 등
- /var : 시스템 동작중에 수시로 변하는 파일 (Log 자료, Spool 디렉토리)
  - /var/spool: 여러 프로그램에서 사용하는 spool directory
    - /var/spool/lpd: 프린트 대기 작업
- /proc : **시스템 내부 설정에 대한 정보 수집**, 커널 인수 설정
  - 커널 내부의 자료구조에 대한 인터페이스
  - 커널에 의해 메모리상(임시 기억 장치)에 생성됨