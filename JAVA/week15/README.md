# 캘린더 프로그래밍

기말 대체 자율 프로젝트로 10시간동안 개발했습니다.

jcalendar.jar는 제가 작성한 코드의 실행파일입니다.

## 작동 화면

제가 확인한 모든 기능에서 정상 작동하였습니다.

### #1 toggle button을 이용하여 시작하는 요일이 월요일/일요일로 바뀌는 기능

![gif1](https://user-images.githubusercontent.com/68107000/103137196-215e3800-470a-11eb-9852-88bd51fea7f0.gif)

### #2 이전 달, 다음 달로 이동하는 기능

![gif2](https://user-images.githubusercontent.com/68107000/103137198-228f6500-470a-11eb-8d5e-72a347983fb4.gif)

### #3 사용자가 입력한 시기로 이동하는 기능

![gif3](https://user-images.githubusercontent.com/68107000/103137199-228f6500-470a-11eb-86bc-726bec9d5df7.gif)

### #4 달 별 메모 작성 기능

![gif4](https://user-images.githubusercontent.com/68107000/103137201-2327fb80-470a-11eb-875b-c2a8fb90e81b.gif)

## 후기

어렵지 않은 프로젝트이지만 모두 100% 내가 계획한대로 구현이 되어서 뿌듯하다.

막혔던 부분은 월요일 시작/일요일 시작 화면 전환 부분이다. 

처음에는 전환이 안 됐고, 그 다음에는 전환이 되는데 심하게 깨졌다.

바뀐 컴포넌트 업데이트해주는 기능을 제공하는데 코드 자체의 에러인 줄 알고 검색해 볼 생각을 못했었다.

아래는 에러를 잡은 핵심 코드이다.

```java
SwingUtilities.updateComponentTreeUI(calendar); // 바뀐 컴포넌트 업데이트
```

그리고 서로 다른 월마다 그리드의 row, col 개수를 직접 다르게 하고, 시작하는 요일 전과 끝나는 요일 후의 빈 공간을 계산하는 데에도 애를 먹었다. 생각보다 많은 경우의 수에 대해서 생각해야 해서 시간이 좀 걸렸다.