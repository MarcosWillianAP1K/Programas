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

char *mystrncpy(char *s1, const char *s2, int n)
{

    for (int i = 0; i < n; i++)
    {
        s1[i] = s2[i];
    }

    s1[n] = '\0';

    return s1;
}

char *mystrcat(char *s1, const char *s2)
{
    int c1 = 0, c2 = 0;

    while (s1[c1] != '\0')
    {
        c1++;
    }

    while (s2[c2] != '\0')
    {
        s1[c1] = s2[c2];
        c1++;
        c2++;
    }

    s1[c1] = '\0';

    return s1;
}

char *mystrncat(char *s1, const char *s2, int n)
{
    int c = 0;

    while (s1[c] != '\0')
    {
        c++;
    }

    for (int i = 0; i < n; i++)
    {
        s1[c] = s2[i];
        c++;
    }

    s1[c] = '\0';

    return s1;
}

int *mystrcmp(char *s1, const char *s2)
{
    int c = 0;
    while (s1[c] != '\0' && s2[c] != '\0')
    {
        if (s1[c] != s2[c])
        {
            if (s1[c] - s2[c] > 0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        c++;
    }

    if (s1[c] == '\0' && s2[c] == '\0')
    {
        return 0;
    }
    else if (s1[c] == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int *mystrncmp(char *s1, const char *s2, int n)
{
    int c = 0;

    while (s1[c] != '\0' && s2[c] != '\0' && c < n)
    {
        if (s1[c] != s2[c])
        {
            if (s1[c] - s2[c] > 0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        c++;
    }

    if (s1[c] != '\0' && s2[c] != '\0')
    {
        return 0;
    }
    else if (s1[c] == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}