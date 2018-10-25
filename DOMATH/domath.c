// your code here
void operation(int n,int a,int b){
	if(n==0){
		printf("child1: %d+%d=%d\n",a,b,a+b);
	}else if(n==1){
		printf("child2: %d*%d=%d\n",a,b,a*b);
	}else if(n==2){
		printf("child3: %d-%d=%d\n",a,b,a-b);
	}else if(n==3){
		printf("child4: %d/%d=%d\n",a,b,a/b);
	}
}

int main(int argc,char* argv[]){
	int a = atoi(argv[1]);//ascii to integer
	int b = atoi(argv[2]);
	for (int i=0;i<4;i++){
		int rc = fork();
			//printf("%d\n",rc); number of process
	        if (rc == 0){
        		operation(i,a,b);
                	exit(0);
        	}
        	else{
        		wait(NULL);//will block parent process until any of its children has finished
        	}
	}

    	for (int i=0;i<4;i++)
        	wait(NULL);
	
    	printf("parent: done\n");
}
