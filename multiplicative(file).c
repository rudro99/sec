#include<stdio.h>
#include<string.h>

char a[20], b[20];

int mulInv(int k)
{
    for(int i=1; i<26; i++)
    {
        if((k * i) % 26 == 1)
            return i;
    }
    return -1; 
}

void encrypt(char p[], int k)
{
    for(int i=0; i<strlen(p); i++)
    {
        a[i] = (((p[i]-'a') * k) % 26) + 'A';
    }
}

void decrypt(char c[], int k)
{
    int k_inv = mulInv(k);

    for(int i=0; i<strlen(c); i++)
    {
        b[i] = (((c[i] + 'A') * k_inv) % 26) + 'a';
    }
}

int main(){

    char p[20], c[20], d[20];
    int k;

    freopen("multiplicativeInput.txt", "r", stdin);

    scanf("%s %d", p, &k);
    if(mulInv(k) == -1)
    {
        printf("k does not have multiplicative inverse. Write valid Key values in your text file and run again.\n");
        return 0;
    }

    encrypt(p, k);
    strcpy(c, a);
    printf("Ciphertext: %s\n", c);

    decrypt(c, k);
    strcpy(d, b);
    printf("Deciphertext: %s\n", d);

    return 0;
}


