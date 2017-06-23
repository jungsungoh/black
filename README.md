# blackjack
termproject[blackjack]
- 카드게임 중에 하나인 BlackJack 게임을 리눅스환경에서 작동가능 하도록 프로그램을 제작한다.

compile 방법

- gcc -o blackjack blackjack.c

프로그램  실행 방법
compile 후 blackjack 실행파일이 생성되고
./blackjack 을  입력해서 실행한다

BlackJack의 기본 룰
- 카드에 적힌 숫자의 합이 21(Black jack)에 가까운 Player의 승리
- 숫자의 합이 21보다 커지면 패배- 기본으로 두장을받고 player가 원하면 카드를 더받을수있다.
- 카드는 한번에 한 장씩만 받는다.- A는 1 or 11으로 player가 선택가능 J,Q,K는 10으로 취급- 문양(♠,♥,♣,◆)은 따지지 않음
- 컴퓨터와 1대1로 대결하는 게임 프로그램
