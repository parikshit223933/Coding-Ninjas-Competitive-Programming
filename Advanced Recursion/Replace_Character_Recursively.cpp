void replaceCharacter(char s[], char c1, char c2)
{
    if(s[0]=='\0')
    {
        return;
    }
    if(s[0]==c1)
    {
        s[0]=c2;
        replaceCharacter(s+1, c1, c2);
    }
    replaceCharacter(s+1, c1, c2);
}