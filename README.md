## 42gg-onboarding-be-03

### EX00 게시판 기능 확장 (댓글, 대댓글, 좋아요, 스크랩, 유저…)

자유롭게 필요한 기능 구현 - 여러 테이블 매핑해보기

**Jpa 연관관계 매핑**

- KeyWords
    - `@Emㅇbedded, @Embeddable`
    - `@Inheritance`
        - JOINED
        - SINGLE_TABLE
        - TABLE_PER_CLASS
    - 영속성 컨텍스트, 연관관계 주인
    - `@ManyToOne, @OneToMany`
    - `@OneToOne`
- Entity
<img width="461" alt="Entity" src="https://github.com/42organization/42gg-onboarding-be-03/assets/95139402/5c9d53ca-89a3-4e29-a5ae-b7f5cbee8c18">

- Table
<img width="454" alt="Table" src="https://github.com/42organization/42gg-onboarding-be-03/assets/95139402/393b0e63-6fed-4c8d-8c65-73ac8b5ca5e7">

- (선택 사항) ****
    
    **Security oauth2 login**
    spring security를 이용해서 kakao, google등 소셜로그인 하나 구현해보기
    session이나, jwt를 사용해서 로그인 상태관리 (필수 x)
    
    OAuth 관련자료
    
    - https://www.notion.so/OAuth-e64027057cdc4ce1be6f1b0c86c3070f?pvs=18
    
    Spring Security 관련자료
    
    - https://bcp0109.tistory.com/301

### EX01 Redis

redis 자료구조 공부 (string, hash, zset 등) → redis docs에 잘 나와있음
RedisTemplate 을 이용해서 redis hash, string, zset 자료구조에 접근하는 간단한 curd 로직 만들어보기
Redis 명령어를 redis-cli나 java spring에서 어떻게 쓰는지 바로 찾고 싶으면 chat gpt 이용해보기. 대부분의 상황에서는 잘 적용된다. 안되면 Redis 공식문서나 구글링하기.

- 참고자료
    - [우아한테크 세미나] 191121 우아한 레디스 by 강대명님
        - [[우아한테크세미나] 191121 우아한레디스 by 강대명님](https://youtu.be/mPB2CZiAkKM)
    - redis docs
        - https://redis.io/docs/data-types/
