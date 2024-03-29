#### 예상질문
1. Array vs List
2. Stack, Queue, Graph, Tree, Heap
3. Hashtable

### Array와 Linked List 비교
- 개념
  - Array: 데이터를 **연속되는 기억장소에 저장**한 자료구조
  - Linked List: 자료들을 연속적으로 저장하지 않고  **포인터부분을 이용하여 서로 연결**하여 저장한 자료구조

- 검색
  - Array: 저장된 element를 **index를 통해 직접적으로 접근**할 수 있다.(시간복잡도 O(1), Random Access)
  - Linked List: 어떤 element를 찾기 위해선 처음부터 찾는 element를 도달할 때까지 **순차적으로 검색**하면서 찾아야 한다. (시간복잡도 O(n), Sequential Access)

- 삽입/삭제
  - Array: 메모리 위치가 연속적이고 고정적이기 때문에  많은 시간을 소모한다. 중간 삽입시 그 뒤에 있는 모든 원소들의 인덱스를 shift해줘야 하므로 시간이 걸린다. 삭제도 삭제한 원소보다 큰 인덱스를 갖는 원소들을 shift해줘야한다. (둘다 O(n))
  
  - Linked List: 삽입은 첫 번째 사용가능한 빈 메모리 위치에 저장되어 빠르고, 삭제 또한 해당 element 전 후 element를 연결시켜주고 해당 element를 삭제하면 되므로 빠르다.(O(1)) 하지만 해당위치를 찾기 위해 탐색과정이 필요하다. 이게 또 O(n)
  
    ![img](https://gmlwjd9405.github.io/images/data-structure-heap/data-structure-heap-priorityqueue.png) 


### Stack

- 스택(Stack)의 개념
  - 한 쪽 끝에서만 자료를 넣고 뺄 수 있는 LIFO(Last In First Out) 형식의 자료 구조
  - 배열과 달리 스택은 상수 시간에 i번째 항목에 접근할 수 없다.
  - 하지만 삭제/삽입은 상수시간에 가능
- 스택(Stack)의 사용 사례
  - 재귀 알고리즘을 사용하는 경우 스택이 유용하다.
    - **재귀 알고리즘**
      - 재귀적으로 함수를 호출해야 하는 경우에 임시 데이터를 스택에 넣어준다.
      - 재귀함수를 빠져 나와 퇴각 검색(backtrack)을 할 때는 스택에 넣어 두었던 임시 데이터를 빼 줘야 한다.
      - 스택은 이런 일련의 행위를 직관적으로 가능하게 해 준다.
      - 또한 스택은 재귀 알고리즘을 반복적 형태(iterative)를 통해서 구현할 수 있게 해준다.
    - **웹 브라우저 방문기록 (뒤로가기)**
    - 실행 취소 (undo)
    - 역순 문자열 만들기
    - 수식의 괄호 검사 (연산자 우선순위 표현을 위한 괄호 검사)
      - Ex) 올바른 괄호 문자열(VPS, Valid Parenthesis String) 판단하기
    - 후위 표기법 계산
    -  **시스템 스택 : 함수의 호출과 복귀 순서는 스택의 구조를 응용하여 관리**



### Queue

- 큐(Queue)의 개념
  - 컴퓨터의 기본적인 자료 구조의 한가지로, 먼저 집어 넣은 데이터가 먼저 나오는 FIFO(First In First Out)구조로 저장하는 형식
- 큐(Queue)의 사용 사례
  - **데이터가 입력된 시간 순서대로 처리**해야 할 필요가 있는 상황에 이용한다.
    - 너비 우선 탐색(BFS, Breadth-First Search) 구현
      - 처리해야 할 노드의 리스트를 저장하는 용도로 큐(Queue)를 사용한다.
      - 노드를 하나 처리할 때마다 해당 노드와 인접한 노드들을 큐에 다시 저장한다.
      - 노드를 접근한 순서대로 처리할 수 있다.
    - 캐시(Cache) 구현
    - **우선순위가 같은 작업 예약 (인쇄 대기열)**
    - 선입선출이 필요한 대기열 (티켓 카운터)
    - 콜센터 고객 대기시간
    - 프린터의 출력 처리
    - 윈도우 시스템의 메시지 처리기
    - 프로세스 관리

### Graph

- 그래프(Graph)의 개념
  - 단순히 노드(N, node)와 그 노드를 연결하는 간선(E, edge)을 하나로 모아 놓은 자료 구조
    - 즉, **연결되어 있는 객체 간의 관계를 표현할 수 있는 자료 구조**이다.
    - Ex) 지도, 지하철 노선도의 최단 경로, 전기 회로의 소자들, 도로(교차점과 일방 통행길), 선수 과목 등
    - 그래프는 여러 개의 고립된 부분 그래프(Isolated Subgraphs)로 구성될 수 있다.
- 그래프(Graph)의 특징
  - 그래프는 **네트워크 모델** 이다.
  - **2개 이상의 경로가 가능하다.**
    - 즉, 노드들 사이에 무방향/방향에서 양방향 경로를 가질 수 있다.
  - self-loop 뿐 아니라 loop/circuit 모두 가능하다.
  - **루트 노드라는 개념이 없다.**
  - **부모-자식 관계라는 개념이 없다.**
  - 순회는 DFS나 BFS로 이루어진다.
  - 그래프는 순환(Cyclic) 혹은 비순환(Acyclic)이다.
  - 그래프는 크게 방향 그래프와 무방향 그래프가 있다.
  - 간선의 유무는 그래프에 따라 다르다.

### Tree

- 트리(Tree)의 개념
  - 트리는 노드로 이루어진 자료 구조
    1. 트리는 **하나의 루트 노드를 갖는다.**
    2. 루트 노드는 0개 이상의 자식 노드를 갖고 있다.
    3. 그 자식 노드 또한 0개 이상의 자식 노드를 갖고 있고, 이는 반복적으로 정의된다.
  - 노드(node)들과 노드들을 연결하는 간선(edge)들로 구성되어 있다.
    - **트리에는 사이클(cycle)이 존재할 수 없다.**
    - 노드들은 특정 순서로 나열될 수도 있고 그럴 수 없을 수도 있다.
    - 각 노드는 부모 노드로의 연결이 있을 수도 있고 없을 수도 있다.
    - 각 노드는 어떤 자료형으로도 표현 가능하다.
  - 비선형 자료구조로 **계층적 관계를 표현**한다. Ex) 디렉터리 구조, 조직도
  - 그래프의 한 종류
    - 사이클(cycle)이 없는 하나의 연결 그래프(Connected Graph)
    - 또는 DAG(Directed Acyclic Graph, 방향성이 있는 비순환 그래프)의 한 종류 이다.
  - 트리(Tree)의 특징
    - 그래프의 한 종류이다. ‘최소 연결 트리’ 라고도 불린다.
    - 트리는 계층 모델 이다.
    - 트리는 DAG(Directed Acyclic Graphs, 방향성이 있는 비순환 그래프)의 한 종류이다.
      - loop나 circuit이 없다. 당연히 self-loop도 없다.
      - 즉, 사이클이 없다.
    - 노드가 N개인 트리는 항상 N-1개의 간선(edge)을 가진다.
      - 즉, 간선은 항상 (정점의 개수 - 1) 만큼을 가진다.
    - **루트에서 어떤 노드로 가는 경로는 유일**하다.
      - 임의의 두 노드 간의 경로도 유일하다. 즉, 두 개의 정점 사이에 반드시 1개의 경로만을 가진다.
    - 한 개의 루트 노드만이 존재하며 모든 자식 노드는 한 개의 부모 노드만을 가진다.
      - 부모-자식 관계이므로 흐름은 top-bottom 아니면 bottom-top으로 이루어진다.
    - 순회는 Pre-order, In-order 아니면 Post-order로 이루어진다. 이 3가지 모두 DFS/BFS 안에 있다.
    - 트리는 이진 트리, 이진 탐색 트리, 균형 트리(AVL 트리, red-black 트리), 이진 힙(최대힙, 최소힙) 등이 있다.

![img](https://github.com/WeareSoft/tech-interview/raw/master/contents/images/graph-vs-tree.png) 

### Heap

- 개념: **부모 노드의 키값이 자식 노드의 키 값보다 항상 큰(작은) 이진 트리**를 말한다. 자료구조의 일종으로 Tree 의 형식. Tree 중에서도 배열에 기반한 `Complete Binary Tree`이다. 여러 개의 값들 중에서 최댓값이나 최솟값을 빠르게 찾아내도록 만들어진 자료구조

- 종류:
  - Max Heap: 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진 트리
  - Min Heap: 부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진 트리

- 사용사례
  - 시뮬레이션 시스템
  - 네트워크 트래픽 제어
  - 운영 체제의 작업 스케줄링

`Max heap`에서는 Root node 에 있는 값이 제일 크므로, 최대값을 찾는데 소요되는 연산의 time complexity 이 O(1)이다. 그리고 `complete binary tree`이기 때문에 배열을 사용하여 효율적으로 관리할 수 있다. (즉, random access 가 가능하다. Min heap 에서는 최소값을 찾는데 소요되는 연산의 time complexity 가 O(1)이다.) 하지만 heap 의 구조를 계속 유지하기 위해서는 제거된 루트 노드를 대체할 다른 노드가 필요하다. 여기서 heap 은 맨 마지막 노드를 루트 노드로 대체시킨 후, 다시 heapify 과정을 거쳐 heap 구조를 유지한다. 이런 경우에는 결국 O(log n)의 시간복잡도로 최대값 또는 최소값에 접근할 수 있게 된다.

* 삽입/삭제 과정 참조

 https://kingpodo.tistory.com/30 

 https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html 



### BST(Binary Search Tree)

**이진 탐색 트리는 이진 트리의 일종**이다. 단 이진 탐색 트리에는 **데이터를 효율적으로 탐색하기 위해서 데이터를 저장하는 규칙**이 있다. 그리고 그 규칙은 특정 데이터의 위치를 찾는데 사용할 수 있다.

 ![img](http://postfiles14.naver.net/MjAxODEwMDVfNTkg/MDAxNTM4NzA1NDA4MDcz.U-7epFhjmqVBox6DqndQ0uVP4fdERPib8Lm8vHDgJRog.5WNq1hscfj1tNB8bjPAccENZAbr8WAkRTEB1xvOUWaog.PNG.qbxlvnf11/300px-Binary_search_tree.svg.png?type=w773) 

- 규칙 1. 이진 탐색 트리의 노드에 저장된 키는 **유일**하다.
- 규칙 2. 루트 노드의 키가 **왼쪽 서브 트리**를 구성하는 어떠한 노드의 키**보다** **크다**.
- 규칙 3. 루트 노드의 키가 **오른쪽 서브 트리**를 구성하는 어떠한 노드의 키**보다 작다.**
- 규칙 4. 왼쪽과 오른쪽 서브트리도 이진 탐색 트리이다.

이진 탐색 트리의 **탐색 연산은 O(log n)의 시간 복잡도**를 갖는다. 사실 정확히 말하면 O(h)라고 표현하는 것이 맞다. 트리의 높이를 하나씩 더해갈수록 추가할 수 있는 노드의 수가 두 배씩 증가하기 때문이다. 하지만 이러한 이진 탐색 트리는 Skewed Tree(편향 트리)가 될 수 있다. 저장 규칙에 따라 계속 한 쪽으로만 노드가 추가되는 경우가 발생하기 때문이다. 이럴 경우 성능에 영향을 미치게 되며, **탐색의 Worst Case 가 되고 시간 복잡도는 O(n)**이 된다.

 ![img](http://postfiles15.naver.net/MjAxODEwMDVfMTkw/MDAxNTM4NzEyODA4Mzkw.D5sepz5FVt25JXtJGzM-qQ08APGSMwF881NmkbNOFRIg.4xbH5ZPNXffUgksINhHydyE-vil3VEtm87gos0q9p6sg.GIF.qbxlvnf11/94_b.gif?type=w773) 

배열보다 많은 메모리를 사용하며 데이터를 저장했지만 탐색에 필요한 시간 복잡도가 같게 되는 비효율적인 상황이 발생한다. **이를 해결하기 위해 `Rebalancing` 기법**이 등장하였다. 균형을 잡기 위한 트리 구조의 재조정을 `Rebalancing`이라 한다. **이 기법을 구현한 트리에는 여러 종류가 존재하는데 그 중에서 하나가 뒤에서 살펴볼 `Red-Black Tree`이다.**



### HashTable

* 개념: Hash는 배열구조에 각 아이템의 Hash함수에 의해 만들어진 Hash값을 인덱스로 저장되는 자료구조로, 각 아이템의 Hash값을 통해 해당 값에 바로 접근할 수 있는 자료구조이며, Key-Value 한쌍으로 구성된다. 

예를들면 Key로는 홍길동 value로는 32, 즉 홍길동이라는 문자열이 Hash함수에 의해 4가되고 배열의 4에 해당하는 위치에 32가 저장되어 있다.

 ![img](https://t1.daumcdn.net/cfile/tistory/216FCE3353C1E8A80E) 

* 장점: 값을 거의 바로 찾을 수 있다.(평균 시간복잡도O(1)) 위의 예에서 32라는 값을 찾기위해 일일이 정렬되지 있지 않으면 값을 비교하면서 찾아야 한다. 하지만 해쉬는 정렬이 되어 있지 않더라도 Hash함수가 만들어준 인덱스로 바로 접근하기 때문에 바로 찾을 수 있다. 

* 단점:  서로 다른 키 값이 해쉬 함수를 통해 같은 해쉬 값이 나오는 상황이 발생할 수 있다. 이를 해시 충돌이라한다. 
   ![img](https://t1.daumcdn.net/cfile/tistory/2373383953C9424C04) 

* ![img](https://t1.daumcdn.net/cfile/tistory/2760EC4553C942FE10) 
  

![img](https://t1.daumcdn.net/cfile/tistory/261C9F3F53C9442B34) 

* 해시충돌 해결방법

   * Open addressing:  해쉬 값과 실제 저장된 위치가 다를 수 있다. 즉 충돌이 일어나면 다른 인덱스에 저장하도록 조정한다.

      - 선형 탐사 : 위의 예에서 트랜스포머도 3번에 저장되어 있고 좋은친구들도 3번에 배정된다면 3번은 이미 차지하고 있으므로 다음 칸이 비어 있는지를 검사한다. 4번칸이 비어 있으므로 4번칸에다가 배정한다.

      - 제곱 탐사 : 위의 예에서 트랜스포머가 3번을 차지 하고 있을 때 좋은친구들은 +1^2=1칸인 4에, 그 다음 "신의한수"가 또 충돌이 나면 +2^2칸+3=7칸(배열의 길이를 벗어난다면 0부터 시작한다), "혹성탈출"도 3으로 충돌이 난다면 +3^2칸=9+3=12칸 건너띄어 빈칸이면 넣는 방법

      - 이중해쉬 : 해쉬 함수를 2개를 두고 평소에는 해쉬함수1만 쓰다가 충돌시 해쉬함수2를 써서 새로운 인덱스로 조정하는 방법

    * Close addressing:  해쉬값과 실제 저장된 위치는 다를 수 없다. 충돌이 일어나도 해당 위치에 저장한다. 다만 다른 방법을 써서 기존 값을 버리거나 덮어씌우는 멍청한 짓은 하지 않는ek.

      - 버켓 : 배열의 한 요소가 다시 배열이다. 즉 위처럼 1차원 배열이 아닌 2차원 배열이다.

        충돌이 일어나면 다른 위치로 재조정하지 않고 해당 위치에 배열로 쌓는다.
      
      - 체이닝 : 충돌된 값들을 연결리스트로 연결한다. 
      

#### Reference

[https://stdin2stdout.tistory.com/entry/QHash%EC%97%90-%EB%8C%80%ED%95%B4%EC%84%9C-%EC%84%A4%EB%AA%85%ED%95%A0-%EC%88%98-%EC%9E%88%EB%82%98%EC%9A%94](https://stdin2stdout.tistory.com/entry/QHash에-대해서-설명할-수-있나요) 

https://kingpodo.tistory.com/30 

https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html 
 
https://github.com/JaeYeopHan/Interview_Question_for_Beginner/tree/master/DataStructure

https://github.com/WeareSoft/tech-interview/blob/master/contents/datastructure.md

http://blog.naver.com/PostView.nhn?blogId=qbxlvnf11&logNo=221371437794&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView




