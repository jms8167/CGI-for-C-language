//CFC
//cgi for c
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
char src[65536];
char compile[512];
char cfile[512],out[512],param[512];
char* path="/var/www/_FOLDER_/";
void generate_file(char* name,char* prev_str){
  do{
    sprintf(name,"%s%s%d.c",path,prev_str,rand());
  }while(!access(name,0));
}
void save_input(){
    generate_file(param,"param");
    FILE* fp=fopen(param,"w");
    char in[65536]={0};
    scanf("%s",in);
    fprintf(fp,"%s",in);
    fclose(fp);  
}
void chsrc(char* src_path,char* dst_path){
    FILE* fp=fopen(src_path,"r");
    FILE* dst=fopen(dst_path,"w");
    fgets(src,65535,fp);        //#!usr/bin/cfcf/cfc
    fgets(compile,511,fp);      //compile option
    while(!feof(fp)){
        memset(src,0,65536);
        fgets(src,65536,fp);
        fputs(src,dst);
    }
    fclose(fp);
    fclose(dst);    
}
int main(int argc,char* argv[]){
	srand(time(0));
	if(argc!=2){
		puts("Usage : [C source]");
		exit(EXIT_FAILURE);
	}
    save_input();
	int len= strlen(path);
	generate_file(cfile,"src");	   
	chsrc(argv[1],cfile);
    generate_file(out,"out");
    char cmd[512]={0};
	//#gcc -o %s %s
	sprintf(cmd,compile+1,out,cfile);
	system(cmd);
	sprintf(cmd,"./%s < %s",out+len,param);
	system(cmd);
	sprintf(cmd,"rm %s",out+len);
	system(cmd);
	sprintf(cmd,"rm %s",cfile+len);
	system(cmd);
	sprintf(cmd,"rm %s",param+len);
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

