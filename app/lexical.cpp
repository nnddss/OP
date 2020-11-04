#include<bits/stdc++.h>
using namespace std;
char sentence[1050];
char sta[1024];
int top,top1,i;
char c;
int matrix[7][7]={{2,2,2,2,2,2},{0,1,-1,-1,1,-1,1},{0,1,1,-1,1,-1,1},{0,-1,-1,-1,0,-1,1},{0,1,1,2,1,2,1},{0,1,1,2,1,2,1},{0,-1,-1,-1,-1,-1,-1}};
int gettype(char c){
	switch (c){
		case '+': return 1;
		case '*': return 2;
		case '(': return 3;
		case ')': return 4;
		case 'i': return 5;
		case 'z': return 5;
		case '#': return 6;
		case 'N': return 7;
		default : return 0;
		}
}
/*
   + * ( ) i #
+
*
(
)
i
#
>=1 <=-1 = = 0 not exit=2
+=1 *=2 (=3 )=4 i=5  
i+i
*/ 
int reduce(){
	if(gettype(sta[top])==5){
		sta[top]='N';
		return 1;
	}
	else if(gettype(sta[top])==1||gettype(sta[top])==2){
		if(sta[top-1]=='N'&&sta[top+1]=='N'){
			top1=top;
			return 1;
		}
		else
			return 0;
	}
	else if(gettype(sta[top])==3){
		sta[top]='N';
		top1=top;
		i++;
		return 1;
	}
	return 0;
}
int main(int argc,char *argv[]){
	FILE *fp;
	
	 fp = fopen(argv[1], "rb");
	 while(fgets(sentence,1024,fp)){
//		while(~scanf("%s",&sentence)){
		sta[0]='#';
		top=0;//top terminal 
		top1=1;// true top
		int l=strlen(sentence);

		sentence[l-2]='#';
		
		for(i=0;i<=l-2;){
			if(gettype(sentence[i])==0){
				printf("E\n");
				return 0;
			}
			for(int j=top1-1;j>=0;j--){
				if(gettype(sta[j])!=0&&gettype(sta[j])!=7){
					top=j;
					break;
				}
			}
			if(top==0||(top!=0&&matrix[gettype(sta[top])][gettype(sentence[i])]==-1)){
				if(sentence[i]=='#')
					return 0;
				sta[top1]=sentence[i];
				top1++; 
				printf("I%c\n",sentence[i]);
				i++;
			}
			else if(matrix[gettype(sta[top])][gettype(sentence[i])]==1||matrix[gettype(sta[top])][gettype(sentence[i])]==0){
				if(reduce()==1)
					printf("R\n");
				else {
					printf("RE\n");
					return 0;
				}
				
			}
			else if(matrix[gettype(sta[top])][gettype(sentence[i])]==2){
				printf("E\n");
				return 0;
			}
			
		}
		memset(sentence,0,1024);
		memset(sta,0,1024);
		top=0;
		top1=0;
	} 
    fclose(fp);
    return 0;
}
