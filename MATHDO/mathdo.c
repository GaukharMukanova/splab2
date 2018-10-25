#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void operation(int n,char* a,char* b){
	char *myargs[5];
	if(n==0){
		myargs[0] = "python";
		myargs[1] = "plus.py";		
		myargs[2] = a;		
		myargs[3] = b;
		myargs[4] = NULL;// The array of pointers must be terminated by a NULL pointer.
		execvp(myargs[0], myargs);
	}else if(n==1){
		myargs[0] = "java";
		myargs[1] = "minus";		
		myargs[2] = a;		
		myargs[3] = b;
		myargs[4] = NULL;
		execvp(myargs[0], myargs);
	}else if(n==2){
		myargs[0] = "node";
		myargs[1] = "mul";		
		myargs[2] = a;		
		myargs[3] = b;
		myargs[4] = NULL;
		execvp(myargs[0], myargs);
	}else if(n==3){
		myargs[0] = "bash";
		myargs[1] = "div.sh";		
		myargs[2] = a;		
		myargs[3] = b;
		myargs[4] = NULL;
		execvp(myargs[0], myargs);//The initial argument for these functions is the pathname of a file which is to be executed
	}
}

int main(int argc,char* argv[]){
	char* a = argv[1];//arguments from parent
	char* b = argv[2];
	for (int i=0;i<4;i++){
		int rc = fork();//create new process
	        if (rc == 0){
        		operation(i,a,b);
                	exit(0);//failed
        	}else if(rc>0){
			 wait(NULL);
		}
	}
    	printf("parent: done\n");
}

int main(int argc, char* argv[]){
	int pid = fork(); // child1
	if (pid==0){ // child 1
		execlp("./add.py",":)",argv[1],argv[2],NULL);

	} else // parent
	{
		int pid2 = fork();
		if (pid2==0){ // child 2
			execlp("./div.sh",":)",argv[1],argv[2],NULL);
		} else // parent
		{
			wait(0);
			wait(0);
			printf("parent: done\n");
		}		
	}
}
