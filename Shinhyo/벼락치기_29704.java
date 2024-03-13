/*나의 풀이 -> 작성자 : 신효민
    -배낭 알고리즘 사용
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int [][]dp_map;
    static ArrayList<Problem> problemList=new ArrayList<>();
    static int []limit;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken()); // 문제의 갯수
        int T=Integer.parseInt(st.nextToken()); // 남은 제출 기한
        dp_map=new int[N+1][T+1]; // DP 맵 설정
        limit=new int[T+1]; // 남은 제출 기한 배열
        problemList.add(new Problem(0,0)); // 처음에 넣어준다.
        int sum=0;
        int d,m;
        for(int a=0;a<N;a++)
        {
            st=new StringTokenizer(br.readLine());
            d=Integer.parseInt(st.nextToken()); // 걸리는 기한 입력
            m=Integer.parseInt(st.nextToken()); // 벌금 입력
            sum+=m; // 합 계산
            problemList.add(new Problem(d,m));
        }
        for(int a=0;a<=T;a++)
        {
            limit[a]=a; // 남은 제출 기한 배열에 값 넣어줌
        }
        //DP 테이블 채움
        for(int i=1;i<problemList.size();i++)
        {
            int fix=problemList.get(i).getDay(); // 새롭게 넣어줄려는 값의 걸리는 기한을 fix 변수에 고정
            for(int j=0;j<limit.length;j++)
            {
                if(fix>limit[j])
                {
                    dp_map[i][j]=dp_map[i-1][limit[j]]; // 그대로 바로 위 배열의 값을 넣어줌 -> 새롭게 넣게 되면 제한 무게를 넘어가기 때문에
                }
                else
                {
                    dp_map[i][j]=Math.max( dp_map[i-1][limit[j]],dp_map[i-1][limit[j]-problemList.get(i).getDay()]+problemList.get(i).getPenalty()); 
                    // 새롭게 넣었을때 vs 새롭게 넣지 않았을때 비교한다.
                }
            }
        }
      /* for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=T;j++)
            {
                System.out.print(dp_map[i][j]+" ");
            }
            System.out.println();
        }*/
        System.out.println(sum-dp_map[N][T]); // 전체 더한 값에서 최댓값을 빼준것이 정답!!
    }
    // 문제 클래스
    public static class Problem{
        private int penalty;
        private int day;

        Problem(int day,int penalty)
        {
            this.day=day;
            this.penalty=penalty;
        }
        public int getPenalty()
        {
            return this.penalty;
        }
        public int getDay()
        {
            return this.day;
        }

    }
}
