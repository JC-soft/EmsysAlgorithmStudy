/*나의 풀이
    작성자 - 신효민 
    문제 : 백준 5639번 이진 검색 트리 ( 골드 5 )
    풀이 방법 : 1. Node class를 만들어서 트리를 구성하고 후위순회한다.
    */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int first=Integer.parseInt(br.readLine()); // 최상위 루트 노드 설정을 위해서
        Node root=new Node(first); // 최상위 루트 노드 객체 생
        String s;
        while(true)
        {
            s=br.readLine();
            if(s==null||s.equals("")) // 입력이 없으면 무한루프를 빠져나간다.
                break;
            root.add(Integer.parseInt(s)); // 최상위 루트 노드부터 시작
        }
        postOrder(root); // 후위순회
    }
    static void postOrder(Node node) // 후위순회
    {
        if(node==null) // 자식이 없으면 return
        {
            return;
        }
        postOrder(node.left); // 왼쪽 순회
        postOrder(node.right); // 오른쪽 순회
        System.out.println(node.value); // 현재 노드 출력
    }
    public static class Node // 노드 클래스
    {
        int value; // 노드 값
        Node left ,right; // 왼쪽 자식 , 오른쪽 자식

        Node(int value)
        {
            this.value=value;
        }
        void add(int num)
        {
            if(num<this.value) // 값이 노드 값 보다 작으면
            {
                if(this.left==null) // 왼쪽 자식이 없으면
                {
                    this.left=new Node(num); // 왼쪽 자식 생성
                }
                else // 왼쪽 자식이 있으면
                {
                    this.left.add(num); // 왼쪽 자식으로 감 ( 왼쪽 자식으로 가서 비교 )
                }

            }
            if(num>this.value) // 값이 노드 값보다 크면
            {
                if(this.right==null) // 오른쪽 자식이 없으면
                {
                    this.right=new Node(num); // 오른쪽 자식 생성
                }
                else
                {
                    this.right.add(num); // 오른쪽 자식으로 가서 비교
                }
            }
        }

/*
 // 런타임 에러 -> 배열의 범위 값을 벗어난 로직       
// 배열로 트리 구성 및 후위순회 했다 -> 값은 잘 나오는 거 같은데 , 배열의 범위를 넘어가는 로직이다.
// 충분한 메모리가 있으면 아마 맞았을거 같은데....노드 갯수가 많을때는 위의 풀이처럼 class를 사용해서 로직을 구성하자!

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int [][]tree;
    static int root;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        // 처음 기준 값 넣기
        String s;
        tree=new int[3][1000000000];
        s= br.readLine();
        int first=Integer.parseInt(s);
        tree[0][1]=first;
        int N;
        while(true)
        {
            s= br.readLine();
            if(s==null||s.equals(""))
                break;
            N=Integer.parseInt(s);
            MakeTree(N,first,1);
        }
       /* for(int a=0;a<3;a++)
        {
            for(int b=0;b<15;b++)
            {
                System.out.print(tree[a][b]+" ");
            }
            System.out.println();
        }*/
        postOrder(1);
    }
    static void MakeTree(int num , int root , int now)
    {
        if(num <root)
        {
            if(tree[1][now]==0)
            {
                tree[1][now]=num;
                tree[0][now*2]=num;
            }
            else
            {
                MakeTree(num,tree[1][now],now*2);
            }
        }
        if(num>root)
        {
            if(tree[2][now]==0)
            {
                tree[2][now]=num;
                tree[0][(now*2)+1]=num;
            }
            else
            {
                MakeTree(num,tree[2][now],(now*2)+1);
            }
        }
    }
    static void postOrder(int i)
    {
        if(tree[1][i]==0&&tree[2][i]==0)
        {
            if(tree[0][i]!=0) {
                System.out.println(tree[0][i]);
            }
            return;
        }
        postOrder(i*2);
        postOrder((i*2)+1);
        if(tree[0][i]!=0) {
            System.out.println(tree[0][i]);
        }
        //1. 왼쪽 자식 탐색
        //2. 오른쪽 자식 탐색
        //3. 현재 노드
    }
}
    }
}
*/
