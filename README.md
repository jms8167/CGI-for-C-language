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
```bash
#!/usr/bin/cfcf/cfc
#gcc -o %s %s (추가인클루드.c 파일)

#include<stdio.h>
int main(){
	char* str="Hello, C";
	puts("Content-Type: text/html; charset=utf-8\n\n");
	puts("\
<html>\
<head>\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\
</head>");
printf("\
<body>\
<p>%s</p>\ 
</body>\
</html>"\
,str);
	return 0;
}
```

#####C 언어로 CGI 프로그램을 작성하려면 컴파일된 파일을 만들어야하는 단점이 있다. 하지만, 스크립트 언어는 바로 실행하는 장점이 있는데 C언어에서도 이와 마찬가지로 바로실행할 수 있게 해주는 프로그램이다.