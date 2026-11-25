#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[100], temp[200];
    char pattern[50];
     int pos, i, len;
     printf("Enter first string: ");
     fgets(str1, sizeof(str1), stdin);
     str1[strcspn(str1, "\n")] = '\0';
     printf("Enter second string: ");
     fgets(str2, sizeof(str2), stdin);
     str2[strcspn(str2, "\n")] = '\0';
     /* Length */
     printf("\nLength of first string = %zu", strlen(str1));
     printf("\nLength of second string = %zu\n", strlen(str2));
     /* Concatenation */
     strcpy(temp, str1);
     strcat(temp, str2);
     printf("\nConcatenated String = %s\n", temp);
     /* Comparison */
    if (strcmp(str1, str2) == 0)
    printf("Strings are Equal\n");
    else
    printf("Strings are Not Equal\n");
    /* Insertion */
    printf("\nEnter position for insertion: ");
    scanf("%d", &pos);
    getchar();
    char insertStr[50];
    printf("Enter string to insert: ");
    fgets(insertStr, sizeof(insertStr), stdin);
    insertStr[strcspn(insertStr, "\n")] = '\0';
    len = strlen(str1);
    for(i = len; i >= pos - 1; i--)
    str1[i + strlen(insertStr)] = str1[i];
    for(i = 0; i < strlen(insertStr); i++)
    str1[pos - 1 + i] = insertStr[i];
    printf("String after insertion: %s\n", str1);
    /* Deletion */
    int delPos, delLen;
    printf("\nEnter deletion position: ");
    scanf("%d", &delPos);
    printf("Enter number of characters to delete: ");
    scanf("%d", &delLen);
    len = strlen(str1);
    for(i = delPos - 1; i <= len - delLen; i++)
    str1[i] = str1[i + delLen];
    printf("String after deletion: %s\n", str1);
getchar();
/* Pattern Matching */
    printf("\nEnter pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';
    if(strstr(str1, pattern) != NULL)
        printf("Pattern found in the string.\n");
    else
        printf("Pattern not found in the string.\n");
    return 0;
}
// Created by rvu on 11/25/26.
//
