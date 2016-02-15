//CFC 
//cgi for c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char src[65536];
char compile[512];
char name[512],out[512];
char* path="/usr/bin/cfcf/";
int main(int argc,char* argv[]){
	if(argc!=2){
		puts("Usage : [C source]");
		exit(EXIT_FAILURE);
	}
	int len= strlen(path);
	srand(time(0));
	int r = rand();
	sprintf(name,"%sdst%d.c",path,r);
	sprintf(out,"%sout%d",path,rand());
	FILE* fp=fopen(argv[1],"r");
	FILE* dst=fopen(name,"w");
	fgets(src,65535,fp);
	fgets(compile,511,fp);
	while(!feof(fp)){
		memset(src,0,65536);
		fgets(src,65535,fp);
		fputs(src,dst);
	}
	fclose(dst);
	fclose(fp);
	char cmd[512]={0};
	//#gcc -o %s %s
	sprintf(cmd,compile+1,out,name);
	system(cmd);
	chdir(path);
	sprintf(cmd,"./%s",out+len);
	system(cmd);
	
	sprintf(cmd,"rm %s",out+len);
	system(cmd);
	sprintf(cmd,"rm %s",name+len);
	system(cmd);	
	return 0;	
}
/* Cfc usage
Apache2에서 /var/www/cgi-bin 의 폴더안의 실행시킬 C 코드는
반드시 맨앞 두줄에 아래와 같은 옵션을 사용해야 합니다.

#!/usr/bin/cfcf/cfc
#gcc -o %s %s (추가 인클루드 파일)

#include<stdio.h>
int main(){
	...
	return 0;
}

*/

