// your code here
#include  <stdio.h>
#include  <sys/types.h>
#include  <sys/wait.h>
#include <string.h>

void  execute(char **argv){
          pid_t  pid;
     pid_t pids[100];
     int    status;
     int background = 0;
     int i =0;
          while(argv[i]!= NULL){
          i++;
          }    
     
           
     if(!strcmp(argv[i-1],"&")){
          background = 1;
          argv[i-1] = NULL;
     }
          if ((pid = fork()) < 0) {    
               printf("*** ERROR: forking child process failed\n");
               exit(1);
          }else if (pid == 0) {
          if(background) {
               fclose(stdin);
               fopen("/dev/null", "r");
               execvp(*argv, argv);     
          }else if (execvp(*argv, argv) < 0) {    
                         printf("*** ERROR: exec failed\n");
                         exit(1);
               }
          }
          else { 
          if (background) {
               //execvp(*argv, argv);        
          }else{
               waitpid(pid, &status, 0);
          }                            
     
          }
          
}

void  parse(char *line, char **argv){
     while (*line != '\0') {      
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';    
          *argv++ = line;          
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;            
     }
     *argv = '\0';            
}

void  main(void){
     char  line[1024];            
     char  *argv[64];         
     while (1) {                  
          printf("Enter your command: ");     
          gets(line);              
          parse(line, argv);       
          if (strcmp(argv[0], "exit") == 0)  
               exit(0);           
          execute(argv);          
     }
}
