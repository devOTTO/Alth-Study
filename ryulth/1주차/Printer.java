import java.util.*;

public class Printer {
    public static void main(String[] args) {
        int[] input = {1, 1, 9, 1, 1, 1};
        int location = 2;
        System.out.println(solution(input, location));
    }

    public static int solution(int[] priorities, int location) {

        Deque<Integer> deque = new ArrayDeque<>();

        for (int i : priorities) {
            deque.addLast(i);
        }
        int max = Collections.max(deque);
        int answer = 0;
        while (true) {
            if (deque.getFirst() == max) {
                answer++;
                if (location == 0) {
                    break;
                }
                deque.removeFirst();
                max = Collections.max(deque);
            } else {

                deque.addLast(deque.removeFirst());
            }
            if (location == 0) {
                location = deque.size()-1;
            } else {
                location--;
            }
        }

        return answer;
    }
}
