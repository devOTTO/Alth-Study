package baekjoon;

import java.io.*;

public class Baekjoon17144 {
    static int[][] map;
    static int row;
    static int col;
    static int time;
    static int airMachine;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] options = bufferedReader.readLine().split(" ");
        row = Integer.parseInt(options[0]);
        col = Integer.parseInt(options[1]);
        time = Integer.parseInt(options[2]);

        map = new int[row][col];

        for (int i = 0; i < row; i++) {
            String[] rowData = bufferedReader.readLine().split(" ");
            if ("-1".equals(rowData[0])) {
                airMachine = i;
            }
            for (int j = 0; j < col; j++) {
                map[i][j] = Integer.parseInt(rowData[j]);
            }
        }

        for (int i = 0; i < time; i++) {
            spread();
            wind();
        }
        int answer = countDust();

        System.out.println(answer);
    }

    public static void spread() {
        int[][] newMap = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int dust = map[i][j];
                if (dust == -1) {
                    newMap[i][j] = -1;
                } else {
                    int count = 0;
                    if (i - 1 >= 0 && map[i - 1][j] != -1) { // 위
                        newMap[i - 1][j] += dust / 5;
                        count++;
                    }
                    if (i + 1 < row && map[i + 1][j] != -1) { // 아래
                        newMap[i + 1][j] += dust / 5;
                        count++;
                    }
                    if (j - 1 >= 0 && map[i][j - 1] != -1) { // 왼쪽
                        newMap[i][j - 1] += dust / 5;
                        count++;
                    }
                    if (j + 1 < col && map[i][j + 1] != -1) { // 오른쪽
                        newMap[i][j + 1] += dust / 5;
                        count++;
                    }
                    newMap[i][j] += dust - ((dust / 5) * count);
                }
            }
        }
        map = newMap;

    }

    public static void wind() {
        int[][] newMap = new int[row][col];

        for (int i = 0; i < airMachine; i++) {
            for (int j = 0; j < col; j++) {
                int dust = map[i][j];
                if (dust == -1) {
                    newMap[i][j] = dust;
                    continue;
                }
                if (i == 0 && j - 1 >= 0) {
                    newMap[i][j - 1] = dust;
                }
                if (j == 0 && i + 1 < airMachine) {
                    newMap[i + 1][j] = dust;
                }
                if (j == col - 1 && i - 1 >= 0) {
                    newMap[i - 1][j] = dust;
                }
                if (i == airMachine - 1 && j + 1 < col) {
                    newMap[i][j + 1] = dust;
                }
                if (0 < i && i < airMachine - 1 && 0 < j && j < col - 1) {
                    newMap[i][j] = dust;
                }
            }
        }
        for (int i = airMachine; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int dust = map[i][j];
                if (dust == -1) {
                    newMap[i][j] = dust;
                    continue;
                }
                if (i == airMachine && j + 1 < col) {
                    newMap[i][j + 1] = dust;
                }
                if (j == col - 1 && i + 1 < row) {
                    newMap[i + 1][j] = dust;
                }
                if (j == 0 && i - 1 > airMachine) {
                    newMap[i - 1][j] = dust;
                }
                if (i == row - 1 && j - 1 >= 0) {
                    newMap[i][j - 1] = dust;
                }
                if (airMachine < i && i < row - 1 && 0 < j && j < col - 1) {
                    newMap[i][j] = dust;
                }
            }
        }
        map = newMap;
    }

    public static int countDust() {
        int dust = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dust += map[i][j];

            }
        }
        return dust + 2;
    }
}
