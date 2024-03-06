/* 풀이 -작성자 : 신효민
    1. 해시 맵에 기본적으로 선을 저장 ( key를 앞점 , value를 뒷점 )
    2.앞 점과 뒷 점이 둘다 구역 안에 포함되어 있지 않으면 -> 해시맵에 저장
    3. 앞 점과 뒷점 중 한가지라도 구역 안에 포함되어 있으면 -> 앞점과 뒷점을 그 구역(들)의 앞점과 뒷점을 서로 비교해서 새로 설정한후 map에 저장
     ( map에 저장할때는 비교한 구역들을 arraylist에 저장후 한꺼번에 없앰 -> 확장 개념 )
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static HashMap<Long, Long> map; // 해시맵 사용

    public static void main(String[] args) throws IOException {
        // Scanner를 사용해서 시간 호출이 될까봐 BufferedReader와 StringTokenizer 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long N = Long.parseLong(st.nextToken());
        map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            long min_point = Long.parseLong(st.nextToken()); // 앞점 입력
            long max_point = Long.parseLong(st.nextToken()); // 뒷점 입력
            Function(min_point, max_point); // 함수 호출
        }

        long result = 0; // 출력 값 변수 설정
        // 이 해시맵에는 서로 겹치지 않는 선들이 저장되어 있다.
        for (Map.Entry<Long, Long> entry : map.entrySet()) {
            result += entry.getValue() - entry.getKey();
        }

        System.out.println(result);
    }

    static void Function(long min_point, long max_point) {
        //삭제할 선들을 저장하는 arraylist
        List<Long> toRemove = new ArrayList<>();
        for (Map.Entry<Long, Long> entry : map.entrySet()) {
            long start = entry.getKey();
            long end = entry.getValue();

            // 이 반대의 경우는 앞점과 뒷점이 겹치지 않을때다. 왼쪽 , 오른쪽 둘다 ) , 앞점 또는 뒷점중 한 구역이라도 들어간다면 비교가 일어나야한다.
            // 5가지 경우가 존재한다.
            // 1. 입력 받은 앞점과 뒷점이 한 구역 안에 모두 포함될때
            // 2. 입력 받은 앞점이 한 구역안에 포함되고 뒷점이 그 구역의 뒷점보다 클때
            // 3. 입력 받은 앞점이 한 구역의 앞점보다 작고 뒷점이 그 구역안에 포함될때
            // 4. 입력 받은 앞점과 뒷점을 연결한 구역이 그 구역을 포함할때
            // 5. 입력 받은 앞점과 뒷점이 모두 그 구역안에 포함되지 않을때
            
            // 여기는 1~4의 경우에 해당하는 로직
            if (min_point <= end && max_point >= start) {
                min_point = Math.min(min_point, start);
                max_point = Math.max(max_point, end);
                toRemove.add(start); // 비교한 구역은 삭제하기 위해 arraylist에 추가
            }
            // 이 반대의 경우는 입력 받은 앞점과 뒷점이 모두 그 구역안에 포함되지 않을때다. ( 왼쪽 , 오른쪽 둘다 ) 
        }

        //비교한 구역들을 한꺼번에 삭제
        for (long key : toRemove) {
            map.remove(key);
        }

        // map에 추가한다.
        map.put(min_point, max_point);
    }
}
