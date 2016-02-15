#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CGI(STR,...)	printf(STR,##__VA_ARGS__);putchar('\n');
static char* str=NULL;
void param_free(){
	free(str);
}
char* param(char* name){
	static char* ptr[65536]={0};
	static int sz=0;
	if(!str){
		str=(char*)calloc(65536,sizeof(char));
		scanf("%s",str);
		ptr[sz++]=strtok(str,"&");
		while(ptr[sz-1]){
			ptr[sz++]=strtok(NULL,"&");
		}
		atexit(param_free);
	}
	int i;
	char tmp[65536];
	for(i=0;i<sz-1;i++){
		memset(tmp,0,65536);
		//puts(ptr[i]);
		memcpy(tmp,ptr[i],strstr(ptr[i],"=")-ptr[i]);
		if(!strcmp(name,tmp)){
			return strstr(ptr[i],"=")+1;
		}
	}
	return NULL;
}
