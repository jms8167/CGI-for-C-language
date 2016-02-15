# CGI-for-C-language
Apache2에서 C를 통한 CGI 툴


####설치법 
```bash
$ git clone https://github.com/jms8167/CGI-for-C-language
$ cd CGI-for-C-language
$ sudo ./install.pl
```
####CFC파일 작성법
코드의 첫줄은 cfc파일의 경로를 적는다.
코드의 두번째 줄은 컴파일 옵션을 적는다.
`cfc.c`
```bash
#!/usr/bin/cfcf/cfc
#gcc -o %s %s (추가인클루드.c 파일)

#include<stdio.h>
int main(){
	puts("Content-Type: text/html; charset=utf-8\n\n");
	return 0;
}
```

C 언어로 CGI 프로그램을 작성하려면 컴파일된 파일을 만들어야하는 단점이 있다. 하지만, 스크립트 언어는 바로 실행하는 장점이 있는데 C언어에서도 이와 마찬가지로 바로실행할 수 있게 해주는 프로그램이다.


perl과 다르게 C는 CGI 라이브러리를 지원하지않는다. 따라서 form의 request나 cookie를 저장하는 함수가 없다. 기존의 많은 라이브러리들이 있지만 적용하기 쉽지 않아 아래의 라이브러리를 제공한다.

#####1.param 함수
post 메소드로 전송된 form의 데이터를 받아온다.
param의 반환 값은 문자열이며, free를 해줄 필요가 없다. 또한 printf 와 putchar('\n')를 붙인 CGI 매크로를 제공한다. 아래는 CGI 매크로와 param 함수를 사용해 두 수의 합을 출력하는 예시이다. 
`example param function`
```bash
#!/usr/bin/cfcf/cfc
#gcc -std=c99 -o %s %s

#include<stdio.h>
#include<cfc_util.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[],char* envp[]){
	int i=0;
	int sum=0;
	char* aaa=param("aaa");
	char* bbb=param("bbb");
	if(aaa && bbb){
		sum=atoi(aaa)+atoi(bbb);
	}
	CGI("Content-Type: text/html; charset=utf-8\n\n");
	CGI("<html>");
	CGI("<head>");
	CGI("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/index.css\">");
	CGI("	<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />");
	CGI("</head>");
	CGI("<body>");
	CGI("<p>%d</p>",sum);
	CGI("	<form action=\"index.c\" method=\"post\">");
	CGI("		<input name=\"aaa\" type=\"text\"></input>");
	CGI("		<input name=\"bbb\" type=\"text\"></input>");
	CGI("		<input type=\"submit\" value=\"plus\"></input>");
	CGI("	</form>");
	CGI("</body>");
	CGI("</html>");
	return 0;
}
```

