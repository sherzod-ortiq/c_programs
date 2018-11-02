#include<stdio.h>     //This code is working well when number of input caracters are at least less by two than array size.
#include<stdlib.h>    //It happens because of fgets() and buffering, for example: if only 10 characters allowed to input into array, 
                      //but you entered 11 characters, fgets() gets 10 and eleventh character remains in buffer.
#define nameSize 30   //If you include statement getchar() or fgets(), they will take character from buffer first!!!
#define authorSize 30 //Remember that fgets() and other like this functions take '\n' as command of return, at the same time as character.
#define dateSize 30

  void dataToFile(void);

  void main(void)
  {
    dataToFile();//I'll use it for testing when i need.
   /* FILE *file1;
      file1=fopen("1.bin","rb");
      char A[100],c;
      int B[10];
      fgets(A,10,file1);
      printf("%s",A);
      c=getc(file1);
      printf("%c",c);
      if(feof(file1) == 1)
      {  printf("Yes");  }     
      fwrite(B,sizeof(int),1,file1);
      printf("%i",B[0]);
      A[0]='\0';
      fgets(A,5,file1);
      printf("%s",A);
      A[0]='\0';
      fgets(A,4,file1);
      printf("%s",A);
      A[0]='\0';   
      fclose(file1);*/   
  }

  void dataToFile(void)  //This function fills binary file with information about book. First it takes three type of data into three arrays,
  {                      //then it copies them in edited form to new array, which will be written into binary file. 
    int a, index = 0,indexPart = 0;
    char c,name[nameSize],author[authorSize],date[dateSize],array[nameSize + authorSize + dateSize + 2];
    FILE *file1;

    file1 = fopen("1.bin","wb");

      while(c!='e')
      {
        printf("Press \"i\" to input data\nor press \"e\" to exit: ");
        c=getchar();
        while((a = getchar()) != '\n' && a != EOF){}//This statement is for clearing buffer.

          if(c != 'e' && c == 'i')
          {
            printf("Input the name of book: ");
            fgets(name,nameSize,stdin);

            
            printf("Input the name of author: ");
            fgets(author,authorSize,stdin);

           
            printf("Input the date of publication: ");
            fgets(date,dateSize,stdin);
 

              while((name[indexPart] != '\0') && (name[indexPart] != '\n'))
              {
                array[index] = name[indexPart];
        
                  index++;
                  indexPart++;
                
              }
                array[index] = '|'; //This is special symbol for further search purpose.
                index++;          
                indexPart = 0;

              while((author[indexPart] != '\0') && (author[indexPart] != '\n'))
              {
                array[index] = author[indexPart];
        
                  index++;
                  indexPart++;
                
              }
                array[index] = '|';
                index++;          
                indexPart = 0;

              while((date[indexPart] != '\0') && (date[indexPart] != '\n'))
              {
                array[index] = date[indexPart];
        
                  index++;
                  indexPart++;
                
              }
                array[index] = '|';
                array[++index] = '\n';
                array[++index] = '\0';  
                indexPart = 0;
                index = 0;
                  
                  
                  fputs(array,file1);//Data is being written into file.
                  


                name[0] = '\0';//Arrays are being cleared. 
                author[0] = '\0';
                date[0] = '\0';
                array[0] = '\0';

               
          }
      }
        fclose(file1);
  }
