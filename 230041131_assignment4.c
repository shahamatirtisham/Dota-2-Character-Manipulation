#include <stdio.h>
#include <string.h>


void reverseName(char character[]);
void classifyCharacters(char quote[]);
void countwordsofquote(char quote[]);
void reverseQuote(char quote[]);
void countcharacters(char character[]);
void occurenceofletter(char quote[], char toSearch);
void removealloccurenceofletter(char quote[], char toSearch);
void replaceAll(char quote[], char oldChar, char newChar);
void searchWords(char quote[], char word[]);
void removeAll(char quote[], char toRemove[]);
void sortAndPrintHeroes(char heroes[10][50]);

int main()
{
    printf("***************************************************\n");
    printf("                    Join the                       \n");
    printf("              Battle of the Ancients               \n");
    printf("***************************************************\n");

    printf("\n");

    printf("********************  Radiant  ********************\n");

    printf("\n");

    char character[100];
    char quote[200];
    char word[100];

    printf("Enter your character's name: ");
    gets(character);

    printf("Enter your favorite quote: ");
    gets(quote);

    printf("\n");

    reverseName(character);
    classifyCharacters(quote);
    countwordsofquote(quote);
    reverseQuote(quote);
    countcharacters(character);

    printf("\n");

    printf("Well! you have come so far\n\n");

    char letter, letter2;

    printf("Now choose a letter: ");
    scanf("%c", &letter);

    while (getchar() != '\n');

    printf("\n");

    occurenceofletter(quote, letter);
    removealloccurenceofletter(quote, letter);

    printf("\n");

    printf("Now choose another letter (for replace): ");
    scanf("%c", &letter2);

    while (getchar() != '\n');

    replaceAll(quote, letter, letter2);

    printf("Now choose a word: ");
    gets(word);

    searchWords(quote,word);
    removeAll(quote, word);

    printf("\n");

    printf("*********************  Dire   *********************\n");

    printf("\n");

    char heroes[10][50];

    printf("Enter your 10 favorite Dota 2 heroes:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: ", i + 1);
        fgets(heroes[i], 50, stdin);

        heroes[i][strcspn(heroes[i], "\n")] = '\0';
    }

    sortAndPrintHeroes(heroes);

    printf("\n");

    printf("*******************  Vicotry  *********************\n");

    return 0;
}

void reverseName(char character[])
{
    strrev(character);
    printf("Reverse of your character's name: %s\n", character);
    strrev(character);
}

void classifyCharacters(char quote[])
{
    int alphabets = 0, digits = 0, vowel = 0,consonant=0, i = 0;
    while (quote[i] != '\0')
    {
        if ((quote[i] >= 'a' && quote[i] <= 'z') || (quote[i] >= 'A' && quote[i] <= 'Z'))
        {
            alphabets++;
            if(quote[i] =='a' || quote[i]=='e' || quote[i]=='i' || quote[i]=='o' || quote[i]=='u' ||
                    quote[i] =='A' || quote[i]=='E' || quote[i]=='I' || quote[i]=='O' || quote[i]=='U'  )
                vowel++;
            else
                consonant++;
        }
        else if (quote[i] >= '0' && quote[i] <= '9')
        {
            digits++;
        }

        i++;
    }

    printf("Alphabets = %d\n", alphabets);
    printf("Digits = %d\n", digits);
    printf("Vowels = %d\n", vowel);
    printf("Consonants = %d\n", consonant);

}

void countwordsofquote(char quote[])
{
    int i = 0;
    int words = 1;

    while(quote[i] != '\0')
    {
        if(quote[i]==' ' || quote[i]=='\n' || quote[i]=='\t')
        {
            words++;
        }

        i++;
    }

    printf("Total number of words = %d\n", words);
}

void reverseQuote(char quote[])
{
    char reverse[200];
    int len, i, index, wordStart, wordEnd;

    len = strlen(quote);
    index = 0;

    wordStart = len - 1;
    wordEnd = len - 1;

    while (wordStart > 0)
    {
        if (quote[wordStart] == ' ')
        {
            i = wordStart + 1;
            while (i <= wordEnd)
            {
                reverse[index] = quote[i];

                i++;
                index++;
            }
            reverse[index++] = ' ';

            wordEnd = wordStart - 1;
        }

        wordStart--;
    }

    for (i = 0; i <= wordEnd; i++)
    {
        reverse[index] = quote[i];
        index++;
    }

    reverse[index] = '\0';

    printf("Original quote = %s\n", quote);
    printf("Reverse quote = %s\n", reverse);
}

void countcharacters(char character[])
{
    int i, len;
    int freq[26];

    len = strlen(character);

    for (i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }

    for (i = 0; i < len; i++)
    {
        if (character[i] >= 'a' && character[i] <= 'z')
        {
            freq[character[i] - 97]++;
        }
        else if (character[i] >= 'A' && character[i] <= 'Z')
        {
            freq[character[i] - 65]++;
        }
    }

    printf("\nFrequency of all characters of your favorite character: \n");
    for (i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            printf("'%c' = %d\n", (i + 97), freq[i]);
        }
    }
}

void occurenceofletter(char quote[], char toSearch)
{
    int i = 0;
    printf("'%c' is found at index : ", toSearch);
    while (quote[i] != '\0')
    {
        if (quote[i] == toSearch)
        {
            printf("%d ", i);
        }

        i++;
    }
    printf("\n");
}

void removealloccurenceofletter(char quote[], char toRemove)
{
    char quote1[300];
    strcpy(quote1, quote);
    int i, j;
    int len = strlen(quote);


    for (i = 0; i < len; i++)
    {
        if (quote1[i] == toRemove)
        {
            for (j = i; j < len; j++)
            {
                quote1[j] = quote1[j + 1];
            }

            len--;

            i--;
        }
    }
    printf("Quote after removing '%c': %s\n", toRemove, quote1);
}

void replaceAll(char quote[], char oldChar, char newChar)
{
    int i = 0;
    char quote1[300];
    strcpy(quote1, quote);

    while(quote1[i] != '\0')
    {
        if(quote1[i] == oldChar)
        {
            quote1[i] = newChar;
        }

        i++;
    }
    printf("Quote after replacing '%c' with '%c': %s\n\n", oldChar,newChar, quote1);

}

void searchWords(char quote[], char word[])
{
    int strLen = strlen(quote);
    int wordLen = strlen(word);
    int found = 0;

    for(int i = 0; i <= strLen - wordLen; i++)
    {
        if((i == 0 || quote[i-1] == ' ') &&
                (i + wordLen == strLen || quote[i + wordLen] == ' '))
        {

            int match = 1;
            for(int j = 0; j < wordLen; j++)
            {
                if(quote[i + j] != word[j])
                {
                    match = 0;
                    break;
                }
            }

            if(match)
            {
                printf("'%s' found at index: %d \n", word, i);
                found = 1;
            }
        }
    }

    if(!found)
    {
        printf("'%s' not found in the quote.\n", word);
    }
}

void removeAll(char quote[], char toRemove[])
{
    char result[300];
    int resultIndex = 0;
    int quoteLen = strlen(quote);
    int removeLen = strlen(toRemove);
    int i = 0;

    while (i < quoteLen)
    {
        int match = 1;
        for (int j = 0; j < removeLen; j++)
        {
            if (quote[i + j] != toRemove[j])
            {
                match = 0;
                break;
            }
        }

        if (match &&
                (i == 0 || quote[i-1] == ' ') &&
                (i + removeLen == quoteLen || quote[i + removeLen] == ' '))
        {
            i += removeLen;

            if (quote[i] == ' ')
            {
                i++;
            }
        }
        else
        {
            result[resultIndex++] = quote[i++];
        }
    }
    result[resultIndex] = '\0';

    printf("\nString after removing '%s': \n%s\n", toRemove, result);
}

void sortAndPrintHeroes(char heroes[10][50]) {
    char temp[50];

    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (strcmp(heroes[j], heroes[j + 1]) > 0) {
                // Swap if out of order
                strcpy(temp, heroes[j]);
                strcpy(heroes[j], heroes[j + 1]);
                strcpy(heroes[j + 1], temp);
            }
        }
    }

    // Print sorted heroes
    printf("\nSorted Heroes (Lexicographical Order):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, heroes[i]);
    }
}
