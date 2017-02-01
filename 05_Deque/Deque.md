# Deque

덱(Deque)는 선형 자료구조의 일종이다. deque은 double-ended queue를 줄여 표현한 것이다. 덱은 큐의 전단과 후단에서 모두 삽입과 삭제가 가능한 큐를 의미한다. 스택과 큐를 조합한 형태의 자료구조로 이해하면 편하다.

## Deque의 ADT

전단과 후단에서 모두 삽입과 삭제가 가능한 것을 바탕으로 ADT를 정의한다.

---

### 객체

n개의 E타입으로 구성된 순서 있는 컬렉션

### 연산

1. isEmpty() ::= 공백 상태면 true를 반환.
2. addFirst(item) ::= 덱 전단에 item을 저장한다.
3. removeFirst() ::= 덱 전단의 요소를 반환한 뒤 삭제한다.
4. getFirst() ::= 덱 전단의 요소를 반환한다.
5. addLast(item) ::= 덱 후단에 item을 저장한다.
6. removeLast() ::= 덱 후단에 있는 원소를 반환한 뒤 삭제한다.
7. getLast() ::= 덱 후단의 요소를 반환한다.

---

