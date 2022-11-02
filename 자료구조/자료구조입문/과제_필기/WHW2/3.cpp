is = 0; it = 0; sp = -1;

for (is=0; i<n; is++)   // n은 입력 string의 길이
{
    push(S[i]);
    while(1)
    {
        if(isEmpty()) break; // empty stack이면 break, 다시 push 받음

        if(T[it] == top())
        {
            pop();
            j++;
        }

        else break; // top과 T[it]가 같지 않으면 break, 다시 push 받음
    }
}

if(!isEmpty())
{
    printf("원하는 객차 순서를 얻을 수 없음");
}