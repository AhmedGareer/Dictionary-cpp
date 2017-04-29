#include "Header.h"

void oper1(char sentence[30],char *ptr,char *ptr1)//function oper1 for operation no.1
{
ptr1=strdup (sentence); //strdup function used to duplicate the contests of sentence variable
            /*strtok and while loop are used
            to seperate sentence into tokens*/
            ptr= strtok (ptr1," ."); /*strtok function check each character untill it
            finds " "or"." and seperate it from the sentence*/
            while (ptr!= NULL) //start of while loop

                {
                    printf ("%s\n",ptr);//printf is used to print the available characters in the pointer (ptr)
                    ptr= strtok (NULL, " .");/*strtok is used with parameter NULL to start
                    from the last Character the pointer stopped at it so it print the next word and soon it it ends*/
                }//end while loop
}
void operation2(char string[256])//function operation2 for operation no.2
  {
      char words[100][256], temp[256];
        int i, j, k, n, count;

        i = j = k = n = 0;




        /* copying each and every word from the string */
        while (string[i] != '\0') {
                if (string[i] == ' ') {
                        words[j][k] = '\0';
                        k = 0;
                        j++;
                } else {
                        words[j][k++] = string[i];
                }
                i++;
        }

        words[j][k] = '\0';
        n = j;

        /* sort the words in the given string */
        for (i = 0; i < n; i++) {
                for (j = i + 1; j <= n; j++) {
                        if (strcmpi(words[i], words[j]) > 0) {
                                strcpy(temp, words[j]);
                                strcpy(words[j], words[i]);
                                strcpy(words[i], temp);
                        }
                }
        }

        printf("\nFrequency of words:\n\n");
        i = 0;

        /* find the frequency of each word and print the results */
        while (i <= n) {
                count = 1;
                if (i != n) {
                        for (j = i + 1; j <= n; j++) {
                                if (strcmpi(words[i], words[j]) == 0) {
                                        count++;
                                }
                        }
                }

                /* count - indicates the frequecy of word[i] */
                printf("%s\t%d\n", words[i], count);

                /* skipping to the next word to process */
                i = i + count;
        }

        printf("\n");
  }




