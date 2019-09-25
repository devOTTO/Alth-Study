import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

public class Pretest {
    public static void main(String[] args){

        int[] answers ={1,3,2,4,2};
        System.out.println(solution(answers).toString());
    }
    public static int[] solution(int[] answers) {
        int[] a = {1,2,3,4,5};
        int[] b = {2,1,2,3,2,4,2,5};
        int[] c = {3,3,1,1,2,2,4,4,5,5};

        int[] student = new int[3];

        for(int i = 0;i<answers.length;i++){

            if(answers[i] == a[i%a.length]){
                student[0]++;
            }
            if(answers[i] == b[i%b.length]){
                student[1]++;
            }
            if(answers[i] == c[i%c.length]){
                student[2]++;
            }
        }


        int max = Arrays.stream(student).max().getAsInt();

        List<Integer> integers = new ArrayList<>();
        for(int i =0;i<student.length;i++){
            if(student[i]==max){
                integers.add(i+1);
            }
        }

        int[] answer = integers.stream()
                .filter(Objects::nonNull)
                .mapToInt(Integer::intValue)
                .toArray();

        return answer;
    }

}
