def solution(answers):
    answer = []
    stu1 = [1, 2, 3, 4, 5]  # 5
    stu2 = [2, 1, 2, 3, 2, 4, 2, 5]  # 8
    stu3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]  # 10
    CorrectAnswer = [0, 0, 0]

    for i in range(len(answers)):
        if answers[i] == stu1[i % 5]:
            CorrectAnswer[0] += 1
        if answers[i] == stu2[i % 8]:
            CorrectAnswer[1] += 1
        if answers[i] == stu3[i % 10]:
            CorrectAnswer[2] += 1
    m = max(CorrectAnswer)
    answer = [i + 1 for i, j in enumerate(CorrectAnswer) if j == m]

    return answer