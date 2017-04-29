#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
#include <Windows.h>
struct dictionary
{
     char word[100];
     char defination[100];
};
int main()
 {
    system ("color 3F");
    char sentence[256];//variable sentence is used to obtain user's inputed sentence
    int operation,oper2,oper3; //declaring 3 integer variables
    char *ptr,*ptr1; //declaring 2 char pointers
    char words[100][256], temp[256];
        int i, j, k, n, count,checker;
       FILE *fp;
       struct dictionary find;
    do{ //Start outer do..while

            /*user menu of the program*/
    printf ("\n\n                              USER MENU...\n\n\n");
    printf ("1 - Press Number 1 to Separate sentence into tokens.\n\n");
    printf ("2 - Press Number 2 to get the frequency of each word in the sentence.\n\n");
    printf ("3 - Press Number 3 to display the corresponding meaning, from the dictionary.\n\n\n");
    /*  Operation 1 to seperate sentence into tokens
        Operation 2 to get the frequency of each word
        Operation 3 to display the meaning of each word */
    printf("Enter The Sentence First ....\n\n "); //asking the user to enter the sentence which he will apply an operation in it
    sentence[0]='\0';// putting a NULL charachter at the first charachter of the sentence to avoid overlap of the sentence while adding more than 1 sentence
    gets(sentence);
    fflush(stdin); //fflush is used to clear buffer to avoid overlap of the operations
    do { //start inner do..while loop
    printf ("\n[#]Choose the operation you want from USER MENU...\n\n");
    scanf ("%d",&operation); //scanf to check which operation the user want
    fflush(stdin);//fflush is used to clear buffer to avoid overlap of the operations
    /*Starting Switch Case on Variable (Operation)*/
    switch (operation)
    {

        //case 1 for operation 1(seperating sentence into tokens
        case 1:
            oper1(sentence,ptr,ptr1); // function responsible to divided the sentence into tokens
                break;
        case 2:
            operation2(sentence); // function responsible to get the frequency of each word in a sentence
            break;
        case 3:
        /* copying each and every word from the string */
        i=j=k=n=0; // initializing this variable with zero
         while (sentence[i] != '\0') {
                if (sentence[i] == ' ') {
                        words[j][k] = '\0'; // replacing the space with a NULL
                        k = 0;
                        j++; //move now to the next word in a new row
                } else {
                        words[j][k++] = sentence[i]; // putting each charachter of the word in this array
                }
                i++; //moving to the next charachter to be checked
        }

      words[j][k]='\0'; //to make the last charachter NULL
        n = j; // n represent now the number of words in the sentence

        /* sort the words in the given string */
        for (i = 0; i < n; i++) {
                for (j = i + 1; j <= n; j++) {
                        if (strcmpi(words[i], words[j]) > 0) { // swaping the words with each other in alphapitical order , to make getting the freqiency easier
                                strcpy(temp, words[j]);
                                strcpy(words[j], words[i]);
                                strcpy(words[i], temp);
                        }
                }
        }

        i = 0; // intialization the i with zero

        /* Avoid repeated words in the sentence and getting the meaning of each word from the dictionary txt file */
        while (i <= n) {
                count = 1; // means the number of words in the sentence
                checker=0;
                if (i != n) {
                        for (j = i + 1; j <= n; j++) {
                                if (strcmpi(words[i], words[j]) == 0) { // cpmparing two words from the sentence with each other
                                        count++; // if there is a word repeated 1 will adds to count .. depeanding on the number of REPEATATION                                }
                        //check if the word is available in dictionary txt or not
                        }
              }

        }
         fp=fopen("dictionary.txt","r"); // open dictionary txt file
         if (fp==NULL)  // check if the dictionary txt file can be open or not
         {
             printf ("\nDICTIONARY couldn't open\n\n"); // if the compiler couldn't found the dictionary txt file it will print this sentence
             break;
         }
         else{ // if the compiler could found the dictionary txt file

      while(!feof(fp)) // while loop work untill the pointer reach the end of the file
      {
          fscanf(fp," %s %s ",find.word,find.defination); // read the data from the dictionary txt file
          if(strcmpi(find.word,words[i])==0) // compare each UNrepeated word in the sentence with the data in txt file
          {
              printf("\n[*] Word     : %s",find.word); // print the word itself in the sentence
              printf("\n[*] Meaning  : %s\n",find.defination); // print the meaning of the word from the txt file
              printf ("------------------------------------\n");
           checker++; // adds 1 to checker if the compiler found the meaning of a word in the dictionary txt file
          }


      }

       if (checker==0) // if the compiler didn't found the meaning of a word in the dictionary txt file ,this means tha checker will be equal 0
       {
           printf ("[X] the meaning of this word doesn't available in our dictionary : %s\n\n",words[i]); // print that there is no meaning for this wprd in the dictionary txt file
           printf ("------------------------------------\n");
       }

       fclose(fp);// close the dictionart txt file
                /* skipping to the next word to process */
                i = i + count; // this helps to move to the next words according to the number of count
         }
        }

        break; // end of case 3

     default: // if the user enter wrong operation number
        printf ("[X] WRONG Operation ...\n\n");

    }//end switch case
    fflush(stdin);//fflush is used to clear buffer to avoid overlap of the operations

    //Standard Questions after making any operation no.1
    printf ("[#] Do you want to perform any additional operation on this sentence\n-----------\n");
    printf ("[*] If ""YES"" Press 1\n------------\n");
    printf ("[*] If ""NO"" Press 2\n");
    //scanning oper2 variable to determine if the user want to make another operation or not
    scanf ("%d",&oper2);
    fflush(stdin); //fflush is used to clear buffer to avoid overlap of the operations
    if(oper2==2){
    break;
    }
    }//end inner do..while loop
   while (oper2==1);

    //allows the user to enter new sentence
    ntence
    printf ("[#] Do you want to enter a new sentence\n-----------\n");
    printf ("[*] If ""YES"" Press 1\n------------\n");
    printf ("[*] If ""NO"" Press 2\n");

    //scanning oper3 variable to determine if the user want to continue or not
    scanf ("%d",&oper3);
    fflush(stdin); //fflush is used to clear buffer to avoid overlap of the operations
    system("cls");
    }
     while (oper3==1);//end outer do..while loop
    return 0;
}

