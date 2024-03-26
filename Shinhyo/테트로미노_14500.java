// 나의 풀이 -신효민
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static int N,M; // 테트로미노 배열의 크기 변수
    static int [][]tetromino; // 테트로미노 배열
    static ArrayList<Integer> result; // 4개의 숫자를 더한 값들을 저장하는 리스트
    public static void main(String[] args)throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        tetromino=new int[N+2][M+2]; // Zero-padding을 이용할것이기 때문에 한줄씩 상하좌우에 붙인다.
        for(int i=1;i<N+1;i++)
        {
            st=new StringTokenizer(br.readLine());
            for(int j=1;j<M+1;j++)
            {
                int num=Integer.parseInt(st.nextToken());
                tetromino[i][j]=num; // 값 입력 받기
            }
        }
        result=new ArrayList<Integer>();
        case1_tetromino(); // 나란히 4개가 붙어있을때 경우들
        case2_tetromino(); // 그밖에 테트로미노 경우들
        Collections.sort(result); // 정렬 수행
        System.out.println(result.get(result.size()-1)); // 정렬수행한 리스트의 맨 끝이 최댓값이다.
    }
    static void case1_tetromino() // 나란히 4개가 붙어있을때의 경우
    {
        for(int x=1;x<N+1;x++) // 가로로 4개가 나란히 붙어있을때
        {
            for(int y=1;y<M+1&&(y+3)<M+1;y++) // 범위를 넘으면 안되므로 조건식에 조건 추가
            {
                int t=y;

                int sum=tetromino[x][t]+tetromino[x][t+1]+tetromino[x][t+2]+tetromino[x][t+3];
                result.add(sum);

            }
        }
        for(int y=1;y<M+1;y++) // 세로로 4개가 나란히 붙어있을때
        {
            for(int x=1;x<N+1&&(x+3)<N+1;x++) // 범위를 넘으면 안되므로 조건식에 조건 추가
            {
                int t=x;
                int sum=tetromino[x][y]+tetromino[x+1][y]+tetromino[x+2][y]+tetromino[x+3][y];
                result.add(sum);
            }
        }
    }
    static void case2_tetromino() // 그 밖에 테트로미노 경우의 수
    {
        for(int x=0;x<N+2;x++) // 4*4 배열로 자르기 위한 코드
        {
            for(int y=0;y<M+2;y++)
            {
                int [][] test=new int[4][4];
                for(int a=0;a<4;a++)
                {
                    for(int b=0;b<4;b++)
                    {
                        if((x+a)<(N+2)&&(y+b)<(M+2))
                        {
                            test[a][b]=tetromino[x+a][y+b];
                        }
                        else
                        {
                            test[a][b]=0;
                        }
                    }
                }
                test_tetromino(test); // 4개의 숫자를 더하기 위한 함수 실행
            }
        }
    }

    static void test_tetromino(int [][] test)
    {
        int [] sum=new int[5]; // 가운데 정사각형의 합들을 저장하는 배열
        sum[0]=test[1][1]+test[1][2]+test[2][1]+test[2][2]; // 가운데 정사각형의 4개를 다 더한 값
        sum[1]=test[1][2]+test[2][1]+test[2][2]; // 가운데 정사각형의 상단 왼쪽의 숫자를 빼고 다 더한 값
        sum[2]=test[1][1]+test[2][1]+test[2][2]; // 가운데 정사각형의 상단 오른쪽의 숫자를 빼고 다 더한 값
        sum[3]=test[1][1]+test[1][2]+test[2][2]; // 가운데 정사각형의 하단 왼쪽의 숫자를 빼고 다 더한 값
        sum[4]=test[1][1]+test[1][2]+test[2][1]; // 가운데 정사각형의 하단 오른쪽의 숫자를 빼고 다 더한 값

        test[1][1]=0;test[1][2]=0;test[2][1]=0;test[2][2]=0; // 위에서 합을 다 저장했으므로 가운데 정사각형의 수들을 다 0으로 바꿔준다.
        result.add(sum[0]); // 가운데 정사각형의 4개를 다 더한 값을 결과 리스트에 저장
        for(int i=1;i<sum.length;i++)
        {
            int [][]test2= new int[4][4];
            for(int a=0;a<4;a++) // 배열의 깊은 복사 실행
            {
                for(int b=0;b<4;b++)
                {
                    test2[a][b]=test[a][b];
                }
            }
            
            switch(i)
            {
                case 1: // 연결될수 없는 수가 들어있는 곳을 다 0으로 만든다.
                    test2[0][0]=0; test2[0][1]=0; test2[1][0]=0;
                    test2[0][3]=0; test2[3][3]=0; test2[3][0]=0;
                    calculate_test(test2,sum[i]);
                    break;
                case 2: // 연결될수 없는 수가 들어있는 곳을 다 0으로 만든다.
                    test2[0][2]=0; test2[0][3]=0; test2[1][3]=0;
                    test2[0][0]=0; test2[3][0]=0; test2[3][3]=0;
                    calculate_test(test2,sum[i]);
                    break;
                case 3: // 연결될수 없는 수가 들어있는 곳을 다 0으로 만든다.
                    test2[2][0]=0; test2[3][0]=0; test2[3][1]=0;
                    test2[0][0]=0; test2[0][3]=0; test2[3][3]=0;
                    calculate_test(test2,sum[i]);
                    break;
                case 4: // 연결될수 없는 수가 들어있는 곳을 다 0으로 만든다.
                    test2[2][3]=0; test2[3][2]=0; test2[3][3]=0;
                    test2[0][0]=0; test2[0][3]=0; test2[3][0]=0;
                    calculate_test(test2,sum[i]);
                    break;
            }
        }

    }

    // 4개의 수를 더한 값을 리스트에 저장하는 함수
    static void calculate_test(int [][] test2,int k)
    {

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(test2[i][j]!=0)
                result.add( test2[i][j]+k);
            }
        }
    }
}
