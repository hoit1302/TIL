# LINUX

- smart phone, 개인 PC, 대형 클라우드 서버까지 이용할 수 있는 운영 체제

- 다중 사용 가능
  - 서버 머신에 linux를 설치해서 여러 사용자가 원격에서 로그인 -> 이 서버를 함께 사용

- 프로그램 개발에 용이

- free software

- 모든 프로그램의 소스 코드 공개
- 전세계 수많은 사람들에 의해 테스트ㅡ개선ㅡ발전 ㅡ> 막강한 성능과 안정성

<br>

# LINUX practice

- 서비스 및 포트 번호

  server (Daemon): 포트 번호를 이용하려고 요청하면 수락해서 서비스해주는 프로그램

  client 는 win-putty(원격 접속 프로그램)을 이용해 IP(주소)와 포트 번호(어떤 프로그램의 서비스를 받을 것인지) 알려주면 해당 포트 번호의 daemon과 communication 하게 된다.

  - 포트번호의 용도

    Q. 리눅스 서버는 원격 클라이언트로부터 들어오는 사용자 요청을 처리해야할 서버(데몬) 프로세스가 누구인지를 어떻게 아는가?
    
    A. port 번호로!
    
    | 포트 번호               | 용도                                             |
    | ----------------------- | ------------------------------------------------ |
    | telnet(23), **ssh(22)** | 원격 클라이언트에서 로그인할 수 있게 함          |
    | **http(80)**            | 파일(혹은 프로그램)을 웹 서비스 형태로 전송해 줌 |
    | ftp(21)                 | 원격 클라이언트로부터 파일을 보내거나 받음       |
    | smtp(25)                | 메일을 보냄                                      |

<br>

- 로그인
  1. 클라이언트 프로그램을 실행시킨다.
  2. 서버의 이름과 port번호를 지정한 후 연결한다.
  3. 사용자 ID와 패스위드를 입력한다.

<br>

- 로그아웃

  ```
  $ logout
  또는
  $ exit
  또는
  $ ^d
  ```


<br>

- passwd

패스워드 변경

```
$ passwd
  Enter the current login password:
  New password:
  Re-enter new password:
$_
```

