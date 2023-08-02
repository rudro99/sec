#include<stdio.h>
#include<string.h>

char a[20], b[20];

int mulInv(int k1) 
{
    for(int i=1; i<26; i++)
    {
        if((k1 * i) % 26 == 1)
            return i;
    }
    return -1;
}

void encrypt(char p[], int k1, int k2)
{
    for(int i=0; i<strlen(p); i++)
    {
        a[i] = (((p[i]-'a')*k1 + k2) % 26) + 'A';
    }
}

void decrypt(char c[], int k1, int k2)
{
    int k1_inv = mulInv(k1);

    for(int i=0; i<strlen(c); i++)
    {
        b[i] = (((c[i] + 'A' - k2) * k1_inv) % 26) + 'a';
    }
}

int main(){

    char p[20], c[20], d[20];
    int k1, k2;

    freopen("affineInput.txt", "r", stdin);
    scanf("%s", p);

    scanf("%d %d",&k1, &k2);
    if(mulInv(k1) == -1)
    {
        printf("k1 does not have multiplicative inverse. Write valid Key values in your text file and run again.\n");
        return 0;
    }

    encrypt(p, k1, k2);
    strcpy(c, a);
    printf("Ciphertext: %s\n", c);

    decrypt(c, k1, k2);
    strcpy(d, b);
    printf("Deciphertext: %s\n", d);

    return 0;
}

