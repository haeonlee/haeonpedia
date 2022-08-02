// 직접 만드는 strcmp 함수

int my_strcmp(char *pa, char *pb)
{
    while ((*pa == *pb) && (*pa != '\0'))   // 두 문자가 같으나 널 문자가 아닌 경우
    {
        pa++;   // 다음 문자로 이동
        pb++;   // 다음 문자로 이동
    }

    if (*pa > *pb) return 1;        // 앞 문자의 아스키 코드 값이 크면(즉, 사전에서 뒤면) 1 반환
    else if (*pa < *pb) return -1;  // 뒷 문자의 아스키 코드 값이 크면 -1 반환
    else return 0;                  // 둘 다 널 문자이므로 같은 문자열
}