# 42gg-onboarding-be-03

### 개발 환경 세팅

- IDE는 IntelliJ 추천
- IntelliJ Community 버전에서 Ultimate 버전 업그레이드 하기 (학생 라이센스 신청)
    
     Email address : 대학 재학생 혹은 졸업생일 경우 학교 이메일 또는 42계정 이메일(”intraId”@student.42seoul.kr) 사용 가능
    
    https://goddaehee.tistory.com/215
    
- MySQL 설치
    - MySQLWorkbench 이용
    - MySQL workbench에서 외부 접속하기
        
        [https://velog.io/@woals4815/MySQL-외부-접속-하기MySQLWorkbench-이용](https://velog.io/@woals4815/MySQL-%EC%99%B8%EB%B6%80-%EC%A0%91%EC%86%8D-%ED%95%98%EA%B8%B0MySQLWorkbench-%EC%9D%B4%EC%9A%A9)
        
- redis 설치

</br>

## 공통 조건
- 온보딩 프로젝트는 개인 계정으로 fork하여 진행하고 PR로 제출합니다.
- git / github / code 컨벤션은 42gg notion에 있는 자료를 적극 반영 합니다.  
</br>

## EX00 Redis
- redis 자료구조 공부 (string, hash, zset 등) → redis docs에 잘 나와있음
- `RedisTemplate` 을 이용해서 redis hash, string, zset 자료구조에 접근하는 간단한 curd 로직 만들어보기
- Redis 명령어를 redis-cli나 java spring에서 어떻게 쓰는지 바로 찾고 싶으면 chat gpt 이용해보기. 대부분의 상황에서는 잘 적용된다. 안되면 Redis 공식문서나 구글링하기.
- 참고자료
    - [우아한테크 세미나] 191121 우아한 레디스 by 강대명님   
        - [[우아한테크세미나] 191121 우아한레디스 by 강대명님](https://youtu.be/mPB2CZiAkKM)

    - redis docs   
        - https://redis.io/docs/data-types/

</br>

## EX01 Security oauth2 login
- `spring security`를 이용해서 kakao, google등 소셜로그인 하나 구현해보기
- session이나, jwt를 사용해서 로그인 상태관리 (필수 x)
- 참고자료
    - OAuth 관련자료   
    [https://www.notion.so/OAuth-e64027057cdc4ce1be6f1b0c86c3070f?pvs=18]