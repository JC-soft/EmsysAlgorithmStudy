/*
-작성자 : 신효민
 풀이 방법
 1. 친구들의 관계를 그래프로 저장
 2. DFS를 할때 깊이가 5이면 바로 함수 호출 종료후 1 출력 , 모든 노드에 대해서 탐색을 했는데도 불구하고 깊이가 5가 되지 않으면 0출력.
 */
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static ArrayList<Integer>[]list; // 그래프 노드 저장 리스트
    static boolean[]visited; // 그래프 노드 방문 배열 선언
    static boolean arrive; // depth가 5일때의 flag 값
    public static void main(String[] args){

        Scanner sc=new Scanner(System.in);
        int N; // 그래프 Node 갯수
        int M; // 엣지 갯수
        N=sc.nextInt();
        M=sc.nextInt();
        list=new ArrayList[N];
        visited=new boolean[N];
        arrive=false;
        for(int i=0;i<N;i++) // 리스트 각 인덱스 값으로 리스트 선언
        {
            list[i]=new ArrayList<Integer>();
        }
        for(int i=0;i<M;i++)
        {
            int num1=sc.nextInt();
            int num2=sc.nextInt();
            // 방향이 없으므로 양쪽에 다 추가해준다.
            list[num1].add(num2);
            list[num2].add(num1);
        }

        // 그래프의 모든 노드에 대해서 DFS 실행
        for(int i=0;i<N;i++)
        {
            //DFS 실행
            DFS(i,1);
            // depth가 5일때 바로 반복문 빠져나오기
            if(arrive)
            {
                break;
            }
        }
        if(arrive)
        {
            // 친구 관계 성립시
            System.out.println(1);
        }
        else
        {
            System.out.println(0);
        }
    }
    //DFS 함수 -> 재귀함수로 구현
    public static void DFS(int now,int depth)
    {
        // 깊이가 5일때 -> 함수 바로 종료
        if(depth==5)
        {
            arrive=true;
            return;
        }
        visited[now]=true; // 깊이가 5가 아닐때 방문 노드를 먼저 true로 바꿔준다.
        for(int i:list[now]) // 그 방문노드에 인접한 노드들을 하나씩 꺼내서 방문 준비
        {
            if(!visited[i]) // 방문노드가 아직 방문하지 않은 상태라면
            {
                DFS(i,depth+1); // DFS 함수 호출 -> depth에 1 더해준 상태에서 호출
            }
        }
        // 함수 호출이 끝나면서 원래대로 돌려주기 -> 방문배열 초기화
        visited[now]=false;
    }
}
