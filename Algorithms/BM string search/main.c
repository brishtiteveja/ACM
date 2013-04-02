#include <stdio.h>
#include <string.h>
#include <limits.h>


int count_compare;

int compare(int match,int pt,int pp){
	printf("比較結果 = %d pt = %d pp = %d \n",match,pt,pp);
	return match;
}

//Boyer-Moore 法による文字探索
int bm_match(const char txt[], const char pat[]){
	int pt;    //txtをなぞるカーソル	
	int pp;    //patをなぞるカーソル	
	int txt_len=strlen(txt);//txtの文字数
	int pat_len=strlen(pat);//patの文字数
	
	int skip[UCHAR_MAX +1]; //skip table
	
	//making the skip table
	//the characters which are not included in the pattern the movement will be pattern-length(n) times ,
	//otherwise n-k(last time found position in the array for the character)-1
	
	for (pt = 0; pt <= UCHAR_MAX; pt++) {  
		skip[pt] = pat_len; // putting n for all characters
	}
	for (pt = 0; pt < pat_len-1;  pt++) {
		skip[pat[pt]] = pat_len - pt -1;  // putting n-k-1 for the characters in the pattern in the skip table
	}
	
	for (int i=0; i<=UCHAR_MAX; i++) {
		printf("skip[%c] = %d ",i,skip[i]);
	}
	printf("\n");
	
	// pt = pat_len-1 right at this moment
	while (pt < txt_len) {
		pp = pat_len -1;  //pat の最後の文字に着目
	    
		while (compare((txt[pt] == pat[pp]),pt,pp)) {
		    if (pp==0) {
		    	return pt;
		    }
			pp --;
			pt --;
	    }
		 
		if (skip[txt[pt]] > pat_len - pp) {
			pt += skip[txt[pt]];
		}
		else {
			pt += pat_len - pp;
		}
	}
	
	return -1;
}

int main (int argc, const char * argv[]) {
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
		
		int i=bm_match(txt,pat);
		
		printf("比較回数 = %d i = %d文字めに見つかりました\n",count_compare,i+1);
		getchar();
	}
	
    return 0;
}
