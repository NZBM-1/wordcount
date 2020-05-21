#include <stdio.h>
#include <string.h>

int getCharNum(char *filename, int totalcharNum){
	FILE *fp; // 指向文件的指针
	char buffer[1000]; //缓冲区，存储读取到的每行的内容
	int bufferLen; // 缓冲区中实际存储的内容的长度
	int i; // 当前读到缓冲区的第i个字符
	char c; // 读取到的字符
	int charNum = 0; // 当前行的字符数
	if( (fp=fopen(filename, "rb")) == NULL ){
		perror(filename);
		return 0;
	}
	while(fgets(buffer, 1000, fp) != NULL){
		bufferLen = strlen(buffer);
		// 遍历缓冲区的内容
		for(i=0; i<bufferLen; i++){
			c = buffer[i];
			if(c == '\0'){
				break;
			}
 			charNum++; 
 		}
 		// 一行结束，计算总字符数
 		totalcharNum += charNum;
 		// 置零，重新统计下一行
 		charNum = 0;
 	}
 	return totalcharNum;
}

int getWordNum(char *filename, int totalwordNum){
	FILE *fp; // 指向文件的指针
 	char buffer[1000]; //缓冲区，存储读取到的每行的内容
 	int bufferLen; // 缓冲区中实际存储的内容的长度
 	int i; // 当前读到缓冲区的第i个字符
 	char c; // 读取到的字符
 	int isLast = 0; // 上个字符是否是空格，逗号 
 	int wordNum = 0; // 当前行的单词数
 	if( (fp=fopen(filename, "rb")) == NULL ){
 		perror(filename);
 		return 0;
 	}
	while(fgets(buffer, 1003, fp) != NULL){
		bufferLen = strlen(buffer);
		// 遍历缓冲区的内容
		for(i=0; i<bufferLen; i++){
			c = buffer[i];
			if(c == '\0'){
				break;
			}
			if( (c==' ' || c==',') && !isLast){ // 遇到空格逗号且上个字符不是空格逗号，那么单词数加1
				wordNum++; 
				isLast = 1;
 			}
 			else if(c!=' '&&c!=','){
 				isLast = 0;
 			}
 		}
 		if(!isLast){
		 wordNum++;// 如果最后一个字符不是空格，那么单词数加1
		} 
 		isLast = 1; // 每次换行重置为1,防止下一行开头的空格逗号误记 
 		// 一行结束
 		totalwordNum += wordNum; // 总单词数
 		// 置零，重新统计下一行
 		wordNum = 0;
 	}
return totalwordNum;
}

void main(int argc,char** argv){
	int totalNum = 0;
	if(strcmp(argv[1],"-c")==0){
		printf("字符数：%d\n",getCharNum(argv[2], totalNum));
	}
	else if(strcmp(argv[1],"-w")==0){
		printf("单词数：%d\n",getWordNum(argv[2], totalNum));
	}
} 
