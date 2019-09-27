def solution(N):
    answer = 0

    dp = [1, 1]
    for i in range(2, N + 1):
        dp.append(dp[i - 2] + dp[i - 1])

    answer += (dp[N - 1] + dp[N - 2]) * 2
    answer += (dp[N - 2] + dp[N - 3]) * 2

    return answer