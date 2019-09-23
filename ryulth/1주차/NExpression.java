public class NExpression {
    public static int[] ns = new int[8];
    public static int answer = -1;
    public static void main(String[] args){
        solution(2,11);
    }
    public static int solution(int N, int number) {
        ns[0] = N;
        for(int i = 1;i<8;i++){
            ns[i] = Integer.parseInt(ns[i - 1] +String.valueOf(N));
        }
        dfs(0,0,number);
        System.out.println(answer);
        return answer;
    }
    public static void dfs(int count,int num, int number){
        if(count>8){
            return ;
        }
        if(answer != -1 && answer<count){
            return;
        }
        if(num == number){
            if(count<answer || answer == -1){
                answer = count;
            }
            return;
        }
        for(int i = 0; i<8;i++){
            dfs(count + 1 + i,num+ns[i],number);
            dfs(count + 1 + i,num-ns[i],number);
            dfs(count + 1 + i,num*ns[i],number);
            dfs(count + 1 + i,num/ns[i],number);
        }

    }
}
