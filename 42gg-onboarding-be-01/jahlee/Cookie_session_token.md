# 쿠키

>웹브라우저에서 쿠키(Cookie)는 서버가 사용자의 웹 브라우저에 전송하는 작은 데이터 조각으로, key=value 형식의 문자열 데이터 묶음이다.
브라우저는 이 문자열 데이터 조각들을 저장해놓았다가 동일한 서버에 재요청시 쿠키 데이터를 전송할 수 있다.
>
HTTP 프로토콜은 기본적으로 무상태성을 가지고 있기 때문에
서버와 클라이언트 간의 연결 유지를 구현하기 위해 서로를 인식할 수 있는 식별데이터가 쿠키 데이터 조각이라고 생각하면 된다.


> ### 주요 사용처
- 세션관리
서버에 저장해야할 로그인, 장바구니, 게임 스코어 등의 정보 관리
ex) 로그인 유지, 장바구니에 담은 제품 유지 등
- 개인화
사용자 선호, 테마 등 사용자의 개인 세팅을 저장, 관리
ex) 다크모드 사용, 언어설정, 메뉴 순서 최적화 등
- 트래킹
분석 및 광고 개제를 위해 웹사이트 내 사용자 행동 기록, 관리
ex) 분석데이터 수집, 리타게팅 광고에 기여 등

> ### 쿠키 인증 방식
1. 브라우저(클라이언트)가 서버에 요청을 보낸다.
2. 서버는 클라이언트의 요청에 대한 응답을 작성할 때, 클라이언트 측에 저장하고 싶은 정보를 응답 헤더의 Set-Cookie에 담는다.
3. 이후 해당 클라이언트는 요청을 보낼 때마다, 매번 저장된 쿠키를 요청 헤더의 Cookie에 담아 보낸다.

> ## 단점
- 요청시 쿠키의 값을 그대로 보내기 때문에 유출, 조작 당할 위험존재하기 때문에 보안에 취약
- 쿠키에는 용량 제한이 있어 많은 정보를 담을 수 없다.
- 웹 브라우저마다 쿠키에 대한 지원 형태가 다르기 때문에 브라우저간 공유 불가능
- 쿠키의 사이즈가 커질수록 네트워크에 부하가 심해진다.

# 세션

> 
쿠키의 단점을 해결하기 위해서 세션은 비밀번호, 카드번호 등의 중요한 정보는 서버측에서 관리하는 방식이다.

> - 클라이언트는 세션Id를 쿠키를 통해서 기억한다.
- 브라우저에 세션Id를 저장해둔 클라이언트는 다음 요청때마다
헤더의 cookie에 세션Id를 담아서 전송한다.
- 서버는 클라이언트가 보낸 요청의 쿠키에 담긴 세션Id와,
세션 스토리지에 담긴 세션Id를 대조해 인증상태를 판단하는 것이다.
(즉, 세션은 쿠키를 기반으로 한다.)

> ### 세션 인증 방식
1. 사용자가 로그인을 요청
2. 서버에서 계정 정보를 읽어 사용자를 확인, 사용자의 고유한 Id를 부여하여 세션 저장소에 저장한후, 이와 연결된 세션Id를 발급한다.
3. 사용자는 서버에서 해당 세션Id를 받아 쿠키에 저장한 후, 인증이 필요한 요청마다 쿠키를 헤더에 실어 보낸다.
4. 서버는 쿠키를 받아 세션 저장소에서 대조 후 대응되는 정보를 가져온다.
5. 인증이 완료되면 서버는 사용자에 맞는 데이터를 보내준다.

> ## 단점
키를 포함한 요청이 외부에 노출되더라도 세션Id 자체에는 유의미한 개인정보를 담고있지 않다.
그러나, 탈취자가 세션Id 자체를 탈취하여 클라이언트인척 위장할 수 있다는 한계가 있다. 서버에서 세션 저장소를 사용하므로 요청이 많아지면 서버에 부하가 심해진다.

# 토큰

>토큰 인증은 클라이언트가 서버에 접속을 하면 서버에서 해당 클라이언트에게
인증되었다는 의미로 '토큰'을 부여한다.
이 토큰은 유일하며, 토큰을 발급받은 클라이언트는 또 다시 서버에 요청을 보낼 때 요청 헤더에 토큰을 심어서 보낸다.
그러면 서버에서는 클라이언트로부터 받은 토큰을 서버에서 제공한 토큰과의 일치 여부를 체크하여 인증과정을 처리
기존의 세션 인증은 서버가 파일이나 데이터베이스에 세션정보를 가지고 있어야 하고, 이를 조회하는 과정이 필요하기 때문에 많은 오버헤드가 발생했다.
하지만, 토큰은 그와 달리 서버가 아닌 클라이언트에 저장되기 때문에 메모리나 스토리지 등을 통해 세션을 관리했던 서버의 부담을 덜 수 있다.
토큰 자체에 데이터가 들어있기 때문에 클라이언트에서 받아 위조되었는지 판별만 하면 되기 때문이다.

 
> ### 토큰 인증 방식
1. 사용자가 아이디와 비밀번호로 로그인을 한다.
2. 서버측에서 사용자에게 유일한 토큰을 발급한다.
3. 클라이언트는 서버측에서 전달받은 토큰을 쿠키나 스토리지에 저장해두고, 서버에 요청을 할 때마다 해당 토큰을 HTTP요청 헤더에 포함시켜 전달한다.
4. 서버는 전달받은 토큰을 검증하고 요청에 응답한다.
   토큰에는 요청한 사람의 정보가 담겨있어서 서버는 DB를 조회하지않고 누가 요청했는지 알 수 있다.

> ## 단점
쿠키 / 세션과 다르게 토큰 자체의 데이터 길이가 길어서,
인증 요청이 많아질수록 네트워크 부하가 심해질 수 있다.
Payload 자체는 조회가 가능하기 때문에 유저의 중요한 정보를 담을 수 없다.
토큰은 발급하면 만료될 때까지 계속 사용이 가능하기 때문에
토큰이 탈취당하면 대처하기가 어렵다.

# JWT

> JWT (JSON Web Token)은 인증에 필요한 정보들을 암호화시킨 JSON 토큰을 의미한다. 세션 / 쿠키와 함께 가장 대표적인 인증 수단이다.
JWT 기반인증은 JWT 토큰을 HTTP 헤더에 실어 서버가 클라이언트를 식별하는 방식이다.
JWT는 JSON 데이터를 Base64 URL-safe-Encode 를 통해 인코딩을 직렬화 한것이며, 토큰 내부에는 위.변조 방지를 위해 개인키를 통한 전자서명도 들어가있다.
따라서 사용자가 JWT를 서버로 전송하면 서버는 서명을 검증하는 과정을 거치고 검증이 완료되면 요청한 응답을 돌려준다.

![](https://velog.velcdn.com/images/aoleejohn/post/81ce718d-aea8-4f9a-b558-7974bdbce3aa/image.png)

>
Header는 JWT에서 사용할 타입과 해시 알고리즘의 종류가 담겨있으며,
Payload는 서버에서 첨부한 사용자 권한 정보와 데이터가 담겨있고,
Payload에는 해독이 가능하기 때문에 중요한 정보는 포함해서는 안된다.
Signature에는 Header, Payload를 Base64 URL-safe Encode를 한 이후
Header에 명시된 해시함수를 적용하고, 개인키로 서명한 전자서명이 담겨있다.

> ### JWT 인증 과정
1. 사용자가 로그인을 한다.
2. 서버에서는 계정 정보를 읽어 사용자를 확인 후, 사용자 고유ID값을 부여한 후,
기타 정보와 함께 Payload에 넣는다.
3. JWT의 유효기간 설정
4. 암호화할 SECRET KEY를 이용하여 Access Token을 발급 한다.
5. 사용자는 Access Token을 받아 로컬 스토리지(혹은 쿠키)에
    저장한 후, 인증이 필요한 요청마다 토큰을 헤더에 실어서 보낸다.
6. 서버에서는 해당 토큰의 Verify Signature을 SECRET KEY로 복호화한 후,
    조작여부, 유효기간을 확인한다.
7. 검증이 완료되면, Payload를 디코딩하여 사용자의 ID에 맞는 데이터를 가져온다.

> ### JWT 장점
Header와 Payload를 가지고 Signature를 생성하여 데이터 위.변조를 막을 수 있다.
인증 정보에 대한 별도의 저장소가 필요없다.
토큰 기반으로 다른 로그인 시스템에 접근 및 권한 공유가 가능하다.
(Facebook로그인, Goggle로그인 등이 모두 토큰을 기반으로 인증)
JWT는 발급한 후 검증만 하면 되기 때문에 Stateless한 서버를 만드는 입장에선 아주 큰 장점이다.

> ## JWT 단점
이미 발급된 JWT에 대해서는 돌이킬 수 없다.  세션 / 쿠키의 경우 만일 쿠키가 악의적으로 이용되고 있다면,
해당하는 세션을 지워버리면 된다.
하지만 JWT는 한번 발급되면 유효기간이 완료될 때까지 계속 사용이 가능하다.
따라서 악의적인 사용자는 유효기간이 지나기 전까지 정보를 털어갈 수 있다.
Payload의 정보가 제한적이다. Payload는 암호화 되지않기 때문에 디코딩하면 누구나 정보를 확인할 수 있다.
따라서 유저의 중요한 정보들은 Payload에 넣을 수 없다.
인증이 필요한 요청이 많아질수록 서버의 자원 낭비가 발생한다.

> ## 개선을 위한 Refresh Token !!
JWT의 단점을 해결하기 위해 Access Token, Refresh Token으로 이중으로 나누어 인증을 한다.
유효기간을 짧게 하면서 더 좋은 방법으로 나온게 Refresh Token인 것이다.
처음에 로그인했을 때 Access Token과 동시에 발급되는 Refresh Token은 긴 유효기간을 가지면서,
Access Token이 만료됐을 때 새로 발급해주는 열쇠가 된다.
즉, Access Token의 유효기간을 짧게 만들고, 유효기간이 만료될 때마다 Refresh Token을 통해 새로운 Access Token을 만들어서 보안을 조금이라도 더 안전하게 한것이다.

> ### Refresh Token 사용하는 과정
1. 사용자가 ID, PW를 통해 로그인
2. 서버에서는 회원 DB에서 값을 비교한다. (보통 PW는 암호화해서 들어간다.)
3. 사용자 인증이 되면 서버에서 Access Token, Refresh Token을 발급, 보통 회원 DB에 Refresh Token을 저장
4. 서버는 사용자에게 Access Token, Refresh Token을 보낸다.
5. 사용자는 Refresh Token을 안전한 저장소에 저장 후, Access Token을 헤더에 실어 요청을 보낸다.
6. 서버는 Access Token을 검증 후
7. 이에 맞는 데이터를 사용자에게 보내준다.
8. 시간이 흘러 Access Token이 만료
9. 사용자는 만료된 Access Token을 헤더에 실어 요청을 보낸다.
10. 서버는 Access Token이 만료됐음을 확인
11. 만료된 토큰임을 알리고 권한없음을 신호로 보낸다.
     Access Token이 만료될때 마다 9~11 과정을 거칠 필요는 없다.
     Access Token의 Payload를 통해 유효기간을 알 수 있다.
     따라서 프론트엔드 단에서 API 요청전에 토큰이 만료 됐다면 바로 재발급 요청 가능
12. 사용자는 Refresh Token 과 Access Token을 함께 서버로 보낸다.
13. 서버는 받은 Access Token이 조작되지 않았는지 확인하고,
      Refresh Token과 사용자의 DB에 저장되어 있던 Refresh Token을 비교한다.
14. 서버는 Refresh Token이 동일하고 유효기간도 지나지 않았다면 Access Token을 사용자에게 보내준다.
15. 새로운 Access Token을 헤더에 실어 API 요청을 한다.

# 참조

>https://jhbljs92.tistory.com/entry/1-JWT-%ED%86%A0%ED%81%B0-%EC%9D%B8%EC%A6%9D%EA%B3%BC-%EC%BF%A0%ED%82%A4-%EC%84%B8%EC%85%98-%ED%86%A0%ED%81%B0