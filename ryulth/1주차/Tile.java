public class Tile {
    public static long[] tiles = new long[81];
    public static void main(String[] args){
        System.out.println(solution(6));
    }

    public static long solution(int N) {
        tiles[1] = 1;
        tiles[2] = 1;
        fibo(N);
        long answer = tiles[N]*4 + tiles[N-1]*2;
        return answer;
    }

    public static long fibo(int n) {
        if(n <= 2){
            return tiles[n];
        }
        else if(tiles[n] != 0) {
            return tiles[n];
        }
        else {
            tiles[n] = fibo(n-1) + fibo(n-2);
            return tiles[n];
        }
    }
}
