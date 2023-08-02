#include<stdio.h>
#include<string.h>

char a[20], b[20];

void encrypt(char p[], int k)
{
    for(int i=0; i<strlen(p); i++)
    {
        a[i] = ((p[i]-'a'+ k) % 26) + 'A';
    }
}

void decrypt(char c[], int k)
{
    for(int i=0; i<strlen(c); i++)
    {
        b[i] = ((c[i] + 'A' - k) % 26) + 'a';
    }
}

int main(){

    char p[20], c[20], d[20];
    int k;

    freopen("additiveInput.txt", "r", stdin);
    scanf("%s %d", p, &k);

    encrypt(p, k);
    strcpy(c, a);
    printf("Ciphertext: %s\n", c);

    decrypt(c, k);
    strcpy(d, b);
    printf("Deciphertext: %s\n", d);

    return 0;
}



