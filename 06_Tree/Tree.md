# Tree

트리(Tree)는 비선형 자료구조중 하나로 고급 자료구조에 속한다. 트리는 계층적인 구조를 갖는 자료들을 관리하는데 용이하다. 대표적으로 결정 트리가 있다.

## Tree 관련 용어

1. 노드(node): 트리의 구성 요소에 해당하는 것들.
2. 간선(edge): 노드와 노드를 연결하는 선.
3. 루트 노드(root node): 트리 구조에서 최상위에 존재하는 노드.
4. 단말 노드(terminal node): 하위에 연결된 노드가 없는 노드. (잎사귀 노드, leaf node)
5. 내부 노드(internal node): 단말 노드를 제외한 모든 노드. (비단말 노드, nonterminal node)
6. 노드간 관계: 부모(parent), 자식(child), 형제(sibling), 조상(Ancestor), 후손(Descendant) 
7. 레벨(level): 트리의 각 층에 번호를 매긴 것
8. 높이(height): 트리의 최고 레벨

## 이진 트리(Binary Tree), 서브 트리(Sub Tree)

**서브 트리**: 트리는 한 개 이상의 노드로 이루어진 유한 집합이다. 이들 중 하나의 노드는 루트 노드라고 불리고 나머지 노드들은 서브 트리라고 불린다.

**이진 트리**: 1. 공집합이거나, 2. 루트 노드를 기준으로 2개의 서브 트리로 구성된 유한 집합으로 정의된다. 이진 트리의 서브 트리들은 모두 이진 트리여야 한다.

## 포화 이진 트리(Full Binary Tree), 완전 이진 트리(Complete Binary Tree)

**포화 이진 트리**: 트리의 각 레벨에 노드가 꽉 차 있는 이진 트리.

**완전 이진 트리**: 트리의 높이가 k일 때 레벨 0부터 k-1까지는 노드가 모두 채워져 있고 마지막 레벨 k에서는 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 있는 이진 트리. 따라서 포화 이진 트리는 완전 이진 트리다.

## 이진 트리의 순회(Traversal)

**1. 전위 순회(Preorder Traversal)**: 루트 노드를 먼저 방문

**2. 중위 순회(Inorder Traversal)**: 루트 노드를 중간에 방문

**3. 후위 순회(Postorder Traversal)**: 루트 노드를 나중에 방문

## BinaryTree의 ADT

트리가 계층적 관계를 **표현**하기위한 자료구조라는 점을 중심으로 ADT를 정의한다.

---

### 객체

n개의 E타입의 계층적인 관계를 가진 요소들의 모임

### 연산

getItem() ::= 노드에 저장된 데이터를 반환한다.

setItem(data) ::= 노드에 data를 저장한다.

getLeftSubTree() ::= 왼쪽 서브 트리의 주소 값을 반환한다.

getRightSubTree() ::= 오른쪽 서브 트리의 주소 값을 반환한다.

connectLeftSubTree(sub) ::= 왼쪽 서브트리로 sub를 연결한다.

connectRightSubTree(sub) ::= 오른쪽 서브트리로 sub를 연결한다.

preorderTraverse(void (*action)(E data)) ::= 트리를 전위 순회한다.

inorderTraverse(void (*action)(E data)) ::= 트리를 중위 순회한다.

postorderTraverse(void (*action)(E data)) ::= 트리를 후위 순회한다.

---

