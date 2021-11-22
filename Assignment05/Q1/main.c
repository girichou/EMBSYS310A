/*
    assignment05 Q1
    Program to swap pointers pointing to values
    Author - Girish Choudankar
    Date - 11/18/2021
*/

void swap_pointer(int **, int **); 

int main()
{
  int x = 2000000, y = 1000000;
  
  int *ip_x = &x;
  int *ip_y = &y;
  
  swap_pointer(&ip_x, &ip_y);
  
    return 0;
}

/*
    swap_pointer functions exchanges the address of pointer
    with the help of temp pointer
*/
void swap_pointer(int **ip_x, int **ip_y)
{
    // create a temp pointer to hold pointer address temporary
    int *temp = 0;
    
    // store the address of first pointer in temp pointer
    temp = *ip_x;
    *ip_x = *ip_y;
    // copy the first pointer to second pointer
    *ip_y = (int *)temp;
}