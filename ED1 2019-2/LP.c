int main(int argc, char const *argv[])
{
    int a,b,c;
    c = (3,2);
    c = 2,3;

    b = (a=3, a=a+1);
    b = a = 3, a = a+1;
    b = (a = 3, a = a+1);

    if(x<0) {x=y+2; x++;} else {x=y;x++;}
    printf("A: %i B: %i C: %i\n",a,b,c);
    return 0;
}

    //for(i=0; n=5; i<10;)
