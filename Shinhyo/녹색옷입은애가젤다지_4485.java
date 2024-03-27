/* 나의풀이 -신효민*/ - 방문 배열 처리 안했더니 통과됨 -> 더 이해 필요 , 우선순위 큐 작동방식도 더 이해 필요
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int []dx={-1,0,0,1}; // 상하좌우 배열 탐색
    static int []dy={0,-1,1,0}; // 상하좌우 배열 탐색
    //static boolean [][]visited;
    static int [][] rufy; // rufy 최소값 담는 배열
    static int [][] zellda; // zellda 맵
    static int i;
    public static PriorityQueue<Node> queue=new PriorityQueue<Node>(); // 우선순위 큐
    public static void main(String[] args)throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      i=1;
        while(true)
      {
          StringTokenizer st=new StringTokenizer(br.readLine());
          N=Integer.parseInt(st.nextToken());
          if(N==0)
              break;
          //visited=new boolean[N][N];
          rufy=new int[N][N];
          zellda=new int[N][N];
          for(int i=0;i<N;i++)
          {
              for(int j=0;j<N;j++)
              {
                  rufy[i][j]=Integer.MAX_VALUE; // 최소값에 최대값 넣어줌
              }
          }
          for(int i=0;i<N;i++)
          {
              st=new StringTokenizer(br.readLine());
              for(int j=0;j<N;j++)
              {
                  int num=Integer.parseInt(st.nextToken());
                  zellda[i][j]=num;
              }
          }
          BFS(0,0,zellda[0][0]); // BFS 탐색
          System.out.println("Problem "+i+": "+rufy[N-1][N-1]);
          i++;
      }
    }
    static void BFS(int s_x,int s_y,int value)
    {
        rufy[0][0]=value;
        queue.add(new Node(0,0,value)); // 초기값 넣어줌
        //visited[0][0]=true;
        while(!queue.isEmpty())
        {
            Node now=queue.poll();
            for(int i=0;i<4;i++)
            {
                int x=now.x+dx[i]; // 주변 배열 탐색
                int y=now.y+dy[i]; // 주변 배열 탐색
                if(x>=0&&y>=0&&x<N&&y<N)
                {
                    /*if(!visited[x][y])
                        continue;*/ // 여기 문제?
                    //visited[x][y]=true;
                    if(rufy[x][y]>rufy[now.x][now.y]+zellda[x][y]) // 최소값 업데이트
                    {
                            rufy[x][y]=rufy[now.x][now.y]+zellda[x][y];
                            queue.add(new Node(x,y,rufy[x][y])); // 우선순위큐에 추가.
                    }
                }
            }

        }
    }
}
class Node implements Comparable<Node> // 우선순위 큐를 이용해서 객체 비교를 하기 위해 Comparable implement 해준다.
{
    int x;
    int y;
    int value;

    Node(int x,int y,int value)
    {
        this.x=x;
        this.y=y;
        this.value=value;
    }

    @Override
    public int compareTo(Node o) { // 들어온 값이 더 작으면 swap해준다.
        if(this.value>o.value)
            return 1;
        else {
            return -1;
        }
    }
}
