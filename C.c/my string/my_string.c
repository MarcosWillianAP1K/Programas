char *mystrcpy(char *s1, const char *s2)
{
    int c = 0;

    while (s2[c] != '\0')
    {
        s1[c] = s2[c];
        c++;
    }
    s1[c] = '\0';

    return s1;
}

char *mystrncpy(char *s1, const char *s2, int n){}