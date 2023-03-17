# minishell
As beautiful as a shell 🐚

<br>

### 🤙🏻 브랜치 규칙
- main : 과제 제출을 한 후에 `develop` 브랜치에서 `main` 브랜치로 merge 합니다.<br>❌ 그 전까지는 절대 merge 금지 ! ❌
- **develop** : 새로운 기능 추가 작업이 있는 경우 `develop` 브랜치에서 `feature` 브랜치를 생성합니다. `feature` 브랜치는 언제나 `develop` 브랜치에서 시작하게 됩니다. 기능 추가 작업이 완료되었다면 🌟`feature` 브랜치는 `develop` 브랜치로 merge🌟 됩니다.
- feature: 기능 하나 당 브랜치 하나를 생성합니다. 이 때 브랜치 이름은 `feature/OOO` 으로 합니다.<br>(예시: `feature/pipe`, `feature/env`, `feature/redirection`, `feature/builtin/echo`, `feature/builtin/cd`)
    
  <br>

### 💬 커밋 메시지
- feat : 새로운 기능 추가
- fix : 버그 수정
- docs : 문서 수정
- style : 코드 포맷팅, 세미콜론 누락, 코드 변경이 없는 경우
- refactor : 코드 리펙토링
- test : 테스트 코드, 리펙토링 테스트 코드 추가
- chore : 기타 등등

  (예시: "docs: update Makefile", "style: norminette", "refactor: seperate XXX function")