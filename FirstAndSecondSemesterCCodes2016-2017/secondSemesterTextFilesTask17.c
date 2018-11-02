#include<stdio.h>

#define lineLength 50
#define initialSpace 50

  void main(void)
  {
    FILE *read,*write;
    char array[lineLength + 2],char1;//+ 2 is for '\n' and '\0'.
    int index = 0,check = 0,check1 = 0,counter = 0;

      read = fopen("1.txt","r");
      write = fopen("2.txt","w");

      while(feof(read) == 0)
      {
        
        while(feof(read) == 0 && (char1 = getc(read)) != '\n' && index < lineLength)
        {
          if((char1 == ' ' && check == 1) || (char1 != ' '))
          {
            array[index] = char1;
            check = 1;
            index ++;            
          }
         
        }
          array[index]='\n';
          array[index + 1]='\0';//fputs works wrongly without it.

            if(array[0] != EOF)
            {
              for(int a = 0; a < (lineLength - index)/2 + initialSpace; a++)
              {  putc(' ',write);  }
 
                fputs(array,write);
            }     
          
              if(index >= lineLength  && array[index] != '\n')
              {  
                array[0] = char1;
                index = 1;     
       	      }
       	      else
      	      {
                index = 0;
                check = 0;
       	      }                
      }
        fclose(read);
        fclose(write);              
  }           
          

