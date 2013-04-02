//============================================================================
// Name        : KMP.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : KMP string search
//============================================================================

#include <stdio.h>
#include <string.h>

int count_compare;


int compare( int compare,int pt,int pp){
	printf("比較結果 = %d pt = %d pp =%d \n",compare,pt,pp);
	count_compare++;
	return compare;
}

int kmp_match(const char txt[],const char pat[]){
    int pt = 1 , pp = 0; //cursor position in text : pt , cursor position in the pattern : pp
	int skip[1024];      //skip table with the information of next comparison position

	skip[pt]=0;          //skip[1] is obviously 0

	while (pat[pt]!='\0') {

        printf("step\npt = %d \n pp = %d \n",pt,pp) ;
		if (pat[pt] == pat[pp]) {
			//skip[++pt]=++pp;  //when any character of the two pattern matches,increase pt and pp by 1 and skip[pt] will be the pp;
		    pt++;
			pp++;
			skip[pt]=pp;
		}
		else if(pp==0) {
			//skip[++pt]=pp;    //if pp is 0 e.g no match yet ,then skip table element of that character will also be 0
		    pt++;
			skip[pt]=pp;
		}
		else {
			pp=skip[pp];
		}

	}
	//show skip table
	for (int i=1; i<=strlen(pat); i++) {
		printf("|%d| ",skip[i]);
	}
	printf("\n");

	pt = pp = 0;

	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (compare(txt[pt] == pat[pp],pt,pp)) {
			pt++;
			pp++;
		}
		else if(pp == 0){
			pt++;
		}
		else {
			pp = skip[pp];
		}
	}

	if (pat[pp] == '\0') {
			return pt-pp;
		}

	return -1;

}


int main (void){

	char txt[100],pat[100];
	int k;
	while(1){
		count_compare=0;
	   if (scanf("%d",&k)!=EOF) {
		   printf("%d番 入力してください\n",k);
	   }
	   else {
		   break;
	   }

	   printf("txt=");
	   scanf("%s",txt);
	   printf("pattern=");
	   scanf("%s",pat);

	   int i=kmp_match(txt,pat);

	   printf("\n比較回数 = %d i = %d文字めに見つかりました\n",count_compare,i);
	   getchar();
	}

    return 0;
}
