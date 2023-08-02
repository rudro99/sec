#include<stdio.h>
#include<string.h>

char a[20], b[20];
char encMap[256], decMap[256];
void encrypt(char p[])
{
    for(int i=0; i<strlen(p); i++)
    {
        a[i] = encMap[p[i]];
    }
}

void decrypt(char c[])
{
    for(int i=0; i<strlen(c); i++)
    {
        b[i] = decMap[c[i]];
    }
}

int main(){

    char p[20], c[20], d[20];
    freopen("monosubInput.txt", "r", stdin);


    for(int i=0; i<26; i++)
    {
        char x, y;
        scanf(" %c %c", &x, &y);

        encMap[x] = y;
        decMap[y] = x;
    }
    scanf("%s", p);

    encrypt(p);
    strcpy(c, a);
    printf("Ciphertext: %s\n", c);

    decrypt(c);
    strcpy(d, b);
    printf("Deciphertext: %s\n", d);

    return 0;
}
