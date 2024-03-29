#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>  /*sleep for linux*/
#include <Windows.h> /*sleep for windows*/
   
int main()
{
    char fileName[20];
    FILE *file, *temp;
    char i;
    int password;
    
    int choice;
    
  
    printf("\n");
    printf("Welcome to Encryption and Decryption\n");
    printf("\n");

    /*Input file Name*/
    printf("enter file name: ");
    gets(fileName);

    //option
    printf("Please choose your option\n");
    printf("\t1: For Encryption\n");
    printf("\t2: For Decryption\n");

    printf("\n");
    printf("=>  ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1://encryption

            printf("Encrypting...\n");
            sleep(1);

            //password
            printf("Enter password in number: ");
            scanf("%d",&password);

            //openfile
            file = fopen(fileName,"r");
            temp = fopen("temp.txt", "w");

            //NullFile
            if (temp == NULL){
                return 0;
            }

            if (file == NULL)
            {
                printf("wrong file\n");
                return 0;
            }

            //readFile
            i = fgetc(file);
            while (i != EOF)
            {
                /* code */
                i = i + password;//encryption
                fputc(i, temp);//store in temporary
                i = fgetc(file); 
            }

            //file close
            fclose(file);
            fclose(temp);

            //open file
            file = fopen(fileName, "w");
            temp = fopen("temp.txt", "r");

            i = fgetc(temp);
            while(i != EOF)
            {
                i = fputc(i, file);//store in permanent
                i = fgetc(temp);
            }

            /*close File*/
            fclose(file);
            fclose(temp);


            /*Animation*/
            printf("##..................  10%%\n");
            sleep(1);
            printf("####................  20%%\n");
            sleep(1);
            printf("######..............  30%%\n");
            sleep(1);
            printf("########............  40%%\n");
            sleep(1);
            printf("##########..........  50%%\n");
            sleep(1);
            printf("############........  60%%\n");
            sleep(1);
            printf("##############......  70%%\n");
            sleep(1);
            printf("################....  80%%\n");
            sleep(1);
            printf("##################..  90%%\n");
            sleep(1);
            printf("####################  100%%\n\n");
            sleep(1);
            printf("Successfully encrypted fileName\n");
            printf("\n\n");

            break;
        
        case 2://decryption

            printf("Decrypting...\n");
            sleep(1);

            //password
            printf("Enter password in number: ");
            scanf("%d",&password);

            //openfile
            file = fopen(fileName,"r");
            temp = fopen("temp.txt", "w");

            //NullFile
            if (temp == NULL){
                return 0;
            }

            if (file == NULL)
            {
                printf("wrong file\n");
                return 0;
            }

            //readFile
            i = fgetc(file);
            while (i != EOF)
            {
                /* code */
                i = i - password;//encryption
                fputc(i, temp);//store in temporary
                i = fgetc(file); 
            }

            //file close
            fclose(file);
            fclose(temp);

            //open file
            file = fopen(fileName, "w");
            temp = fopen("temp.txt", "r");

            i = fgetc(temp);
            while(i != EOF)
            {
                i = fputc(i, file);//store in permanent
                i = fgetc(temp);
            }

            /*close File*/
            fclose(file);
            fclose(temp);


            /*Animation*/
            printf("##..................  10%%\n");
            sleep(1);
            printf("####................  20%%\n");
            sleep(1);
            printf("######..............  30%%\n");
            sleep(1);
            printf("########............  40%%\n");
            sleep(1);
            printf("##########..........  50%%\n");
            sleep(1);
            printf("############........  60%%\n");
            sleep(1);
            printf("##############......  70%%\n");
            sleep(1);
            printf("################....  80%%\n");
            sleep(1);
            printf("##################..  90%%\n");
            sleep(1);
            printf("####################  100%%\n\n");
            sleep(1);
            printf("Successfully decrypted fileName\n\n\n");
            
            break;

        default://wrong option
            printf("Wrong option\n");
            

    }
    getch();
    return 0;
}
