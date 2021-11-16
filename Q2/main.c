
int func1(int, int, int, int, int);
int func2(void);

int main()
{
    int sum = func2();
    
    return 0;
}

int func2(void)
{
    int var1 = 1, var2 = 2, var3 = 3, var4 = 4, var5 = 5;
    
    int f2_sum = func1(var1, var2, var3, var4, var5);
    
    return f2_sum;
}

int func1(int var1, int var2, int var3, int var4, int var5)
{
        int f1_sum = var1 + var2 + var3 + var4 + var5;
        
        return f1_sum;
        
}