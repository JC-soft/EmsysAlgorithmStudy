import java.util.*;

public class Main {
    static char [][][] sangbeom_building; // 상범 빌딩 
    static int [][][] minute; // 걸리는 시간 표시 배열
    static boolean [][][] visited; // 방문배열
    static int []dx={-1,1,0,0,0,0}; // x좌표
    static int []dy={0,0,-1,1,0,0}; // y 좌표
    static int []dz={0,0,0,0,-1,1}; // z 좌표
    static int s_x,s_y,s_z;
    static int e_x,e_y,e_z;
    static int L,R,C;
    public static void main(String[] args)  {
        Scanner sc=new Scanner(System.in);
        while(true)
        {
            L=sc.nextInt(); // z
            R=sc.nextInt(); // y
            C=sc.nextInt(); // x
            if(L==0&&R==0&&C==0)
                break;
            sangbeom_building=new char[L][R][C];
            minute=new int[L][R][C];
            visited=new boolean[L][R][C];
            // 값 넣기
            for(int i=0;i<L;i++)
            {
                for(int j=0;j<R;j++)
                {
                    String line=sc.next();
                    for(int t=0;t<C;t++)
                    {
                        sangbeom_building[i][j][t]=line.charAt(t);
                        if(line.charAt(t)=='S')
                        {
                            s_x=t; s_y=j; s_z=i;
                        }
                        if(line.charAt(t)=='E')
                        {
                            e_x=t; e_y=j; e_z=i;
                        }
                        if(line.charAt(t)=='.')
                        {
                            minute[i][j][t]=1;
                        }
                    }
                }
            }
            BFS(s_x,s_y,s_z); // BFS 실행
           if(minute[e_z][e_y][e_x]==0)
            {
                System.out.println("Trapped!");
            }
            else
            {
                System.out.println("Escaped in "+minute[e_z][e_y][e_x]+" minute(s).");
            }
        }
    }
  // BFS실행 -> 실행되면서 값 업데이트하기.
    static void BFS(int i,int j,int t)
    {
        Queue<int []> queue= new LinkedList<>();
        queue.offer(new int[]{i,j,t});
        visited[t][j][i]=true;
        while(!queue.isEmpty())
        {
            int now[]=queue.poll();
            for(int k=0;k<6;k++)
            {
                int x=now[0]+dx[k];
                int y=now[1]+dy[k];
                int z=now[2]+dz[k];
                if(x>=0&&y>=0&&z>=0&&x<C&&y<R&&z<L) // 좌표검사
                {
                    if((sangbeom_building[z][y][x]=='.'&&!visited[z][y][x])||(sangbeom_building[z][y][x]=='E'&&!visited[z][y][x])) // 끝날때도 1더해줘야한다.
                    {
                        visited[z][y][x]=true;
                        minute[z][y][x]=minute[now[2]][now[1]][now[0]]+1;
                        queue.add(new int[]{x,y,z});
                    }
                }
            }
        }

    }
}
//값 잘 들어갔는지 확인
           /*for(int i=0;i<L;i++)
            {
                for(int j=0;j<R;j++)
                {

                    for(int t=0;t<C;t++)
                    {
                        System.out.print(sangbeom_building[i][j][t]);
                    }
                    System.out.println();
                }
                System.out.println();
            }
            System.out.println();
            for(int i=0;i<L;i++)
            {
                for(int j=0;j<R;j++)
                {

                    for(int t=0;t<C;t++)
                    {
                        System.out.print(minute[i][j][t]);
                    }
                    System.out.println();
                }
                System.out.println();
            }*/
