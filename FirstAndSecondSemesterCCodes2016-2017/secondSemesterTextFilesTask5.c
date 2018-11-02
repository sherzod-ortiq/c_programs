#include<stdio.h> 

#define columnAmount 23 //There should be odd number                                               
#define center 12 //It is center of columnAmount
#define spaceOf 4 //Space given for one number


  void main(void)
  {
    char space[] = "    ";//Number of spaces in the literal should be equal to "spaceOf"
    int array[2][columnAmount] = { {0},{0} };
    int leftEnd,rightEnd,line1 = 0,line2 = 1,counter = columnAmount / 2;
    FILE *file1;
         										
    file1 = fopen("1.txt","w");

      for(int i = 0; i <= columnAmount / 2 ; i++)
      {
        leftEnd = center - 1 - i;
        rightEnd = center - 1 + i;
    
        array[line1][leftEnd] = 1;
        array[line1][rightEnd] = 1;

          for(int j = 0; j <=  counter; j++)
          {  fprintf(file1,"%s",space);  } 
          
            counter --; 
 
        

        for(int j = 0; j <= rightEnd; j++)
        { 
          if(array[line1][j] != 0)
          {
            fprintf(file1,"%i",array[line1][j]);

              int k = array[line1][j],l = 0;

                while(k != 0)
                {
                  k = k / 10;
                  l ++;
                }
               
                  for(int m = 0; m < spaceOf - l; m ++)
                  {  putc(' ',file1);  }
 
                    if( j != rightEnd)
                    {  fprintf(file1,"%s",space);  }
          }
        }
          putc('\n',file1);
  
          int a1 = 0, a2 = 2;

            while(array[line1][leftEnd + a2] != EOF && array[line1][leftEnd + a1] != 0 && array[line1][leftEnd + a2] != 0)
            {
              array[line2][leftEnd + a1 +1] = (array[line1][leftEnd + a1] + array[line1][leftEnd + a2]);
              a1 += 2;
              a2 += 2;
            }
          
              if(i % 2 == 0)
              {
                line1 = 1;
                line2 = 0;
              }
              else
              {
                line1 = 0;
                line2 = 1;
              }

      }
  }
