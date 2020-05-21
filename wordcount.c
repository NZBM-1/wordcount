#include <stdio.h>
#include <string.h>

int getCharNum(char *filename, int totalcharNum){
	FILE *fp; // ָ���ļ���ָ��
	char buffer[1000]; //���������洢��ȡ����ÿ�е�����
	int bufferLen; // ��������ʵ�ʴ洢�����ݵĳ���
	int i; // ��ǰ�����������ĵ�i���ַ�
	char c; // ��ȡ�����ַ�
	int charNum = 0; // ��ǰ�е��ַ���
	if( (fp=fopen(filename, "rb")) == NULL ){
		perror(filename);
		return 0;
	}
	while(fgets(buffer, 1000, fp) != NULL){
		bufferLen = strlen(buffer);
		// ����������������
		for(i=0; i<bufferLen; i++){
			c = buffer[i];
			if(c == '\0'){
				break;
			}
 			charNum++; 
 		}
 		// һ�н������������ַ���
 		totalcharNum += charNum;
 		// ���㣬����ͳ����һ��
 		charNum = 0;
 	}
 	return totalcharNum;
}

int getWordNum(char *filename, int totalwordNum){
	FILE *fp; // ָ���ļ���ָ��
 	char buffer[1000]; //���������洢��ȡ����ÿ�е�����
 	int bufferLen; // ��������ʵ�ʴ洢�����ݵĳ���
 	int i; // ��ǰ�����������ĵ�i���ַ�
 	char c; // ��ȡ�����ַ�
 	int isLast = 0; // �ϸ��ַ��Ƿ��ǿո񣬶��� 
 	int wordNum = 0; // ��ǰ�еĵ�����
 	if( (fp=fopen(filename, "rb")) == NULL ){
 		perror(filename);
 		return 0;
 	}
	while(fgets(buffer, 1003, fp) != NULL){
		bufferLen = strlen(buffer);
		// ����������������
		for(i=0; i<bufferLen; i++){
			c = buffer[i];
			if(c == '\0'){
				break;
			}
			if( (c==' ' || c==',') && !isLast){ // �����ո񶺺����ϸ��ַ����ǿո񶺺ţ���ô��������1
				wordNum++; 
				isLast = 1;
 			}
 			else if(c!=' '&&c!=','){
 				isLast = 0;
 			}
 		}
 		if(!isLast){
		 wordNum++;// ������һ���ַ����ǿո���ô��������1
		} 
 		isLast = 1; // ÿ�λ�������Ϊ1,��ֹ��һ�п�ͷ�Ŀո񶺺���� 
 		// һ�н���
 		totalwordNum += wordNum; // �ܵ�����
 		// ���㣬����ͳ����һ��
 		wordNum = 0;
 	}
return totalwordNum;
}

void main(int argc,char** argv){
	int totalNum = 0;
	if(strcmp(argv[1],"-c")==0){
		printf("�ַ�����%d\n",getCharNum(argv[2], totalNum));
	}
	else if(strcmp(argv[1],"-w")==0){
		printf("��������%d\n",getWordNum(argv[2], totalNum));
	}
} 
