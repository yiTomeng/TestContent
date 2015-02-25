#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readn()
{
	FILE *fp = NULL;
	int len = 0;
	char buf[BUFSIZ];
	memset(buf, 0x00, BUFSIZ);
	if ( 0 > (fp = fopen("read.txt", "r")) )
	{
		printf("file open error\n");
		exit(1);
	}
#if 0
	while(!feof(fp))
	{
		memset(buf, 0x00, BUFSIZ);

		len = fread(buf, 1, 3, fp);
		
		printf("buf:%s\n", buf);
	}
#endif
}
int main(int argc, char *argv[])
{

	/*core*/
	#if 0
	char *p = "Hello Core";

	//p[0] = 'a';				//NG segment fault

	printf("%s\n", p);
	#endif

	/*fread asm*/
	#if 0  //問題なし
	FILE *fp = NULL;
	int len = 0;
	char buf[BUFSIZ];
	memset(buf, 0x00, BUFSIZ);
	
	if ( 0 > (fp = fopen("read.txt", "r")) )
	{
		printf("file open error\n");
		exit(1);
	}

	while(!feof(fp))
	{
		memset(buf, 0x00, BUFSIZ);

		len = fread(buf, 1, 3, fp);
		
		printf("buf:%s\n", buf);
	}

	fclose(fp);
	#endif
	while(1)
	{
		readn();
	}
	return 0;
}
