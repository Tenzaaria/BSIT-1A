 #include <stdio.h>
 #include <stdlib.h>

void addstudent();
void studentrecord();
void searchstudent();
void delete();

  struct student {
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
     char vill[20];
    float per;
};

void main(void)
{
    
    int choice;
    while(choice!=5){
        
    printf("\t=====STUDENT DATABASE MANAGEMENT SYSTEM=====");
    printf("\n\n\n\t1. Add Student\n");
    printf("\t2. Students Records\n");
    printf("\t3. Search Student\n");
    printf("\t4. Delete Student\n");
    printf("\t5. Exit\n");
    printf("\t_____________________\n");
    printf("\n\tEnter what to do: ");
    scanf("%d",&choice);
    
   switch(choice){
       case 1:
          system("cls");
          addstudent();
          system("cls");
         break;
     case 2: 
        system("cls");
        
          studentrecord();
          printf("\t  press any key to exit..... \n");
          getch();
          system("cls");
          
         break;
        
     case 3:
         system("cls");
         searchstudent();
         printf("\n\t  Press any key to exit.......\n");
         
          getch();
          system("cls");
        
         break;
  
     case 4:
         system("cls");
        delete();
        printf("\n\tPress any key to exit.......\n");
        getch();
        system("cls");
        break;
     case 5:
          system("cls");
          printf("\n\tThank you, for used this software.\n\n");
          exit(0);
        break;
        
     default :
         system("cls");
         getch();
         printf("\n\tEnter a valid number\n\n");
         printf("\tPress any key to continue.......");
         getch();
        system("cls");
         break;
        }
  
        }
  
        getch();
     }
    
 void addstudent(){
   
     char another;
     FILE *fp;
     int n,i;
     struct student info;
   do{
       system("cls");
       printf("\t=======Add Students Info=======\n\n\n"); 
       fp=fopen("information.txt","a"); //use can give any file name. Give the name with extention or without extention.
         
        printf("\n\tEnter First Name     : ");
          scanf("%s",&info.first_name);
          printf("\n\tEnter Last Name     : ");
          scanf("%s",&info.last_name);
          printf("\n\tEnter Roll-No       : ");
          scanf("%d",&info.roll_no);
          printf("\n\tEnter Class(course) : ");
          scanf("%s",&info.Class);
          printf("\n\tEnter Address       : ");
          scanf("%s",&info.vill);
          printf("\n\tEnter Percentage    : ");
          scanf("%f",&info.per);
          printf("\n\t______________________________\n");
       
      if(fp==NULL){
        fprintf(stderr,"can't open file");
    }else{
        printf("\tRecord stored successfuly\n");
    }
    
    fwrite(&info, sizeof(struct student), 1, fp); 
    fclose(fp);
    
    printf("\tYou want to add another record?(y/n) : ");
    
    
    scanf("%s",&another);
    
    
   }while(another=='y'||another=='Y');
}

 void studentrecord(){
   
     FILE *fp;

    struct student info;
    fp=fopen("information.txt","r");
    
     printf("\t=======STUDENTS RECORD=======\n\n\n");
      
    if(fp==NULL){
        
        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("\tRECORDS :\n");
        printf("\t___________\n\n");
    }
        
        while(fread(&info,sizeof(struct student),1,fp)){
        printf("\n\t Student Name  : %s %s",info.first_name,info.last_name);
        printf("\n\t Roll NO       : %d",info.roll_no);
        printf("\n\t Class         : %s",info.Class);
        printf("\n\t Village/City  : %s",info.vill);
        printf("\n\t Percentage    : %f%",info.per);
        printf("\n\t ________________________________\n");
      
         }
        fclose(fp);
        getch();
      
  }

void searchstudent(){
       struct student info;
      FILE *fp;
      int roll_no,found=0;
     
    fp=fopen("information.txt","r");
    printf("\t=======SEARCH STUDENTS RECORD=======\n\n\n");
    printf("\tEnter the roll no : ");
   
    scanf("%d",&roll_no);
     
    
    
    while(fread(&info,sizeof(struct student),1,fp)>0){
         
        if(info.roll_no==roll_no){
           
        found=1;
        printf("\n\n\tStudent Name : %s %s",info.first_name,info.last_name);
        printf("\n\tRoll NO        : %d",info.roll_no);
        printf("\n\tClass          : %s",info.Class);
        printf("\n\tAddress        : %s",info.vill);
        printf("\n\tPercentage     : %f%",info.per);
        printf("\n\t______________________________________\n");
  
         }
       
    }
     
    if(!found){
       printf("\n\tRecord not found\n");
    }
  
    fclose(fp);
    getch();
    
}


 void delete(){
      struct student info;
      FILE *fp, *fp1;
     
       
    int roll_no,found=0;
    
       printf("\t=======DELETE STUDENTS RECORD=======\n\n\n");
    fp=fopen("information.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\tEnter the roll no : ");
    scanf("%d",&roll_no);
    if(fp==NULL){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }
    
    while(fread(&info,sizeof(struct student),1,fp)){
        if(info.roll_no == roll_no){
          
            found=1;
        
        }else{
           fwrite(&info,sizeof(struct student),1,fp1);
        }
  
    }
     fclose(fp);
     fclose(fp1);

    if(!found){
          printf("\n\tRecord not found\n");
        }
      if(found){ 
    remove("information.txt");
        rename("temp.txt","information.txt");
        
        printf("\n\tRecord deleted succesfully\n");
        }
 
  getch();
  }

