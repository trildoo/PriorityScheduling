#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process
{
    char process_name[100];
    int arrival_time;
    int service_time;
    int priority;
    int overtaken;

}*diergasia;
int main()
{
	int ch,n=0,go=0;
  int counter=0;
  int i=0,j=0,a=0;
	FILE* f_pointer;
	char adress[100];
	printf("Give the adress of the file:");
	scanf("%s",adress);//reads the adress
	f_pointer = fopen(adress,"r");//opens file
	//no real reason to examine if pointer==null since that is a user's fault

	while(ch!=EOF){
		ch = fgetc(f_pointer);
		if(ch=='\n'){
			n++;
		}

	}
 
	fclose(f_pointer);

	diergasia = (struct process*)malloc(sizeof(struct process)*n);

	f_pointer=fopen(adress,"r");
	for(i=0; i<n; i++)
	{

    diergasia[i].overtaken = 0;
		fscanf(f_pointer,"%s %d %d %d",diergasia[i].process_name, &diergasia[i].arrival_time, &diergasia[i].service_time, &diergasia[i].priority);
		go=go+diergasia[i].service_time;
		printf("%s %d %d %d\n",diergasia[i].process_name,diergasia[i].arrival_time,diergasia[i].service_time,diergasia[i].priority);

	}
		fclose(f_pointer);



  //Priority Scheduling
  i=0;
  while(counter < go){
    
    if(diergasia[i].service_time != 0){
      printf("%s|",diergasia[i].process_name);
      counter++;
      diergasia[i].service_time--;
      if(diergasia[i+j].arrival_time <= counter && diergasia[i+j].service_time != 0){//it helps to visualise this with a the process that has value of i.Now we just check the next value and the next,repeating...
        diergasia[i+j].overtaken = 1;//checks if process is overtaken
        j++;
      }
    
    }
                       
      else{
               j = 0; 
                for(a=0; a<n; a++){
                  if((diergasia[a].priority > diergasia[i].priority && diergasia[a].service_time != 0 && diergasia[a].overtaken == 1) )//basically i check for every process left on hold
                  {
                      i=a;
                  }
                }  
              }
              diergasia[i].overtaken = 0;
    }
		return 0;
		}
