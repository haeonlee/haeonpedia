# HTML 인코딩: 한글 깨짐

> 출처: 인코딩 (한글 깨짐) (https://ofcourse.kr/html-course/인코딩)

# 개요
- html 파일을 인코딩 했는데, 한글이 깨졌다면 이는 '파일의 인코딩 방식과 브라우저의 인코딩 방식'이 달라서 생기는 문제
- 하나의 인코딩 방식으로 통일이 필요

# 인코딩 방식

- euc-kr
    - 영어만을 고려해 1byte 길이의 ASCII라는 인코딩 방식을 확장, 한글을 사용할 수 있도록 만든 2byte 길이의 국가 언어 코드
    - problem: 우리나라에서만 사용 가능
        - 다른 언어 사용 환경(외국 등)에서는 한글 페이지를 제대로 볼 수 없음
        - solution: UTF-8을 개발

- UTF-8
    - 가장 보편화된 인코딩 방식(3byte)
    - 표준화 및 글로벌 환경을 고려해 UTF-8 인코딩 방식을 강력하게 권고


# 해결법: 페이지 언어셋이 utf-8임을 브라우저에 알리기

- HTML5의 경우, 다음 코드를 <head> 태그 안에 삽입

```html
<meta charset="utf-8">
```

- XHTML의 경우, 다음 코드를 <head> 태그 안에 삽입

```html
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
```

- 메모장을 사용할 경우, 저장 전에 하단의 인코딩 드롭박스에서 UTF-8을 선택

