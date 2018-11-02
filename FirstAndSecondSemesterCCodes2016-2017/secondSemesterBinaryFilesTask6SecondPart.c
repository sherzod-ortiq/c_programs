#include<stdio.h>     //This code is working well when number of input caracters are at least less by two than array size.
#include<stdlib.h>    //It happens because of fgets() and buffering, for example: if only 10 characters allowed to input into array, 
                      //but you entered 11 characters, fgets() gets 10 and eleventh character remains in buffer.
#define nameSize 30   //If you include statement getchar() or fgets(), they will take character from buffer first!!!
#define authorSize 30 //Remember that fgets() and other like this functions take '\n' as command of return, at the same time as character.
#define dateSize 30

  void search(void);

  void main(void)
  {
    search();//I'll use it for testing when i need.
   /* FILE *file1;
      file1=fopen("1.bin","rb");
      char A[100];
      fgets(A,100,file1);
      printf("%s",A);
      A[0]='\0';
      fgets(A,100,file1);
      printf("%s",A);
      A[0]='\0';
      fgets(A,100,file1);
      printf("%s",A);
      A[0]='\0';
      fclose(file1); */ 
  }

  void search(void)      //This function takes data from file with the help of standart function fgets,
  {                      //then it sorts them and writes into three specified arrays. 
    int a, check2 = 0, searchMode, index = 0,indexPart1=0;
    char check1,name[nameSize],author[authorSize],date[dateSize],name1[nameSize],
         author1[authorSize],date1[dateSize],array[nameSize + authorSize + dateSize + 2];
    FILE *file1;

    

      while(check1 != 'e')
      {
        printf("Press \"1\" to search by author and date,\npress \"2\" to search by name,\npress \"e\" to exit.");
        check1 = getchar();

        while((a = getchar()) != '\n' && a != EOF){}//This statement is for clearing buffer.

          if(check1 != 'e' && (check1 == '1' || check1 == '2'))
          { 
            if(check1 == '1')
            {
              printf("Input the name of author: ");
              fgets(author1,authorSize,stdin);
              printf("Input date of publication: ");
              fgets(date1,dateSize,stdin);
              
                searchMode = 1;
            }

            if(check1 == '2')
            {
              printf("Input the name of book: ");
              fgets(name1,nameSize,stdin);
            
                searchMode = 2;
            }

              file1 = fopen("1.bin","rb");


            while(feof(file1) != 1)
            {

              fgets(array,nameSize + authorSize + dateSize + 2,file1);//Data is being read from file.
                   
                while(array[index] != '\0' && array[index] != '\n')
                {
                  if(check2 == 0)
                  {
                    if(array[index] != '|')
                    {  
                      name[indexPart1] = array[index];
                      index ++;
                      indexPart1 ++;
                    }
                    else
                    {
                      name[indexPart1] = '\0';
                      indexPart1 = 0;
                      index ++;
                      check2 ++;
                    }
                  }
                    
                  if(check2 == 1)
                  {
                    if(array[index] != '|')
                    {  
                      author[indexPart1] = array[index];
                        index ++;
                        indexPart1 ++;
                     }
                     else
                     {
                       author[indexPart1] = '\0';
                       indexPart1 = 0;
                       index ++;
                       check2 ++;
                     }
                  }
                               
                  if(check2 == 2)
                  {
                    if(array[index] != '|')
                    {  
                      date[indexPart1] = array[index];
                      index ++;
                      indexPart1 ++;
                    }
                    else
                    {
                      date[indexPart1] = '\0';
                      indexPart1 = 0;
                      index ++;
                      check2 ++;
                    }
                  }
                }//closing while(array[index] != '\0' && array[index] != '\n')

                  indexPart1=0,check2=0,index=0;
                  int sign1=0,sign2=0,sign3=0,indexKeyWord=0,caseDifference=0;
                  char char1,char2;
         
                  while(name[indexPart1] != '\0')
                  {
                    char1=name[indexPart1];
                    char2=name1[indexKeyWord];

                      if((char1>=65 && char1<=90)&&(char2>=97 && char2<=122))
                      {  caseDifference=-32; }
                      if((char2>=65 && char2<=90)&&(char1>=97 && char1<=122))
                      {  caseDifference=32; }

                        if(name[indexPart1]==name1[indexKeyWord]+caseDifference)
                        {
                          indexKeyWord++;
                          indexPart1++;
                          caseDifference=0;

                            if(name1[indexKeyWord]=='\0' || name1[indexKeyWord]=='\n')
                            {  sign1=1;   }
                         }
                         else
                         {
                           indexPart1 ++;
                           indexKeyWord=0;
                           caseDifference=0;
                         }
                  }

		   
		  indexKeyWord=0;
		  indexPart1=0;
		  caseDifference=0;

                  while(author[indexPart1] != '\0')
                  {
                    char1=author[indexPart1];
                    char2=author1[indexKeyWord];

                      if((char1>=65 && char1<=90)&&(char2>=97 && char2<=122))
                      {  caseDifference=-32; }
                      if((char2>=65 && char2<=90)&&(char1>=97 && char1<=122))
                      {  caseDifference=32; }

                        if(author[indexPart1]==author1[indexKeyWord]+caseDifference)
                        {
                          indexKeyWord++;
                          indexPart1++;
                          caseDifference=0;

                            if(author1[indexKeyWord]=='\0' || author1[indexKeyWord]=='\n')
                            {  sign2=1;   }
                         }
                         else
                         {
                           indexPart1 ++;
                           indexKeyWord=0;
                           caseDifference=0;
                         }
                  }

		   
		  indexKeyWord=0;
		  indexPart1=0;
		  caseDifference=0;


		  while(date[indexPart1] != '\0')
		  {
		    char1=date[indexPart1];
		    char2=date1[indexKeyWord];

		      if((char1>=65 && char1<=90)&&(char2>=97 && char2<=122))
		      {  caseDifference=-32; }
		      if((char2>=65 && char2<=90)&&(char1>=97 && char1<=122))
		      {  caseDifference=32; }

		        if(date[indexPart1]==date1[indexKeyWord]+caseDifference)
		        {
		          indexKeyWord++;
		          indexPart1++;
		          caseDifference=0;

		            if(date1[indexKeyWord]=='\0' || date1[indexKeyWord]=='\n')
		            {  sign3=1;   }
		        }
		        else
		        {
		          indexPart1 ++;
		          indexKeyWord=0;
		          caseDifference=0;
		        }
		  }

 
                    if(searchMode == 1)
                    {
                      if(sign2 ==1 && sign3 ==1)
                      {  printf("Book name: %s\n",name);  }
                    }
            
                    if(searchMode == 2)
                    {   
                      if(sign1 == 1)
                      {  printf("Publication date: %s  , author name: %s\n",date,author);  }
                    }
      
                      sign1=0,sign2=0,sign3=0,indexPart1=0; 
                      name[0]='\0';
                      author[0]='\0';
                      date[0]='\0';
                      array[0]='\0';
 
              
            }//closing while(feof(file1) != 1)

              fclose(file1);

          }//closing if(check1 != 'e')

            name1[0]='\0';//clearing arrays
            author1[0]='\0';
            date1[0]='\0';

    }//closing  while(check1 != 'e')
   
  }//final
