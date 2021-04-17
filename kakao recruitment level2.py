
def getCount(s,temp,start):
    count=0
    length=len(temp)
    for k in range(start,len(s),length):
        if k+length>len(s):
            break
        if s[k:k+length]==temp:
            count+=1
        else: break
    return count

def solution(s):
    answer = len(s)
    size=len(s)
    #1. 문자열 길이의 절반만큼 반복 // 길이: i
    for i in range(1,size//2+1):
        string=""
        #1.1 문자열 순회(j)
        j=0
        while(j<size):
            temp=s[j:j+i]
            #1.1.1. 뒤에 연속한 단어의 개수를 찾는다.
            count=getCount(s,temp,j)
            #1.1.2 개수가 1개라면 j를 1 증가시킨다
            if count==1:
                j+=i

            #1.1.3. 개수가 다수라면 j+=count*i
            else:
                j+=count*i
                string+=str(count)
            string+=temp
        #최소 문자열로 갱신한다.
        answer=min(answer,len(string))
    return answer
print(solution("aabbaccc"))
print(solution("ababcdcdababcdcd"))
print(solution("abcabcdede"))
print(solution("abcabcabcabcdededededede"))
print(solution("xababcdcdababcdcd"))
