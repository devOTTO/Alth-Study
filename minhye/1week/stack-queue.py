def solution(priorities, location):
    answer = 0
    while (location > -1):
        Flag = True
        for i in range(1, len(priorities)):
            if priorities[0] < priorities[i]:
                Flag = False
                priorities.append(priorities[0])
                priorities = priorities[1:]
                location -= 1
                if location == -1:
                    location = len(priorities) - 1
                break
        if Flag:
            priorities = priorities[1:]
            location -= 1
            answer += 1

    return answer