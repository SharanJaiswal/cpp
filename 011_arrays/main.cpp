#include<iostream>
int main()
{
    int* arr1 = new int[5];
    for(int i = 0; i < 5; i++)
    {
        arr1[i] = i+5;
    }
    for(int i = 0; i < 5; i++)
    {
        std::cout << arr1[i] << std::endl;
    }
    delete[] arr1;


    // when array is initialized innstack, its size has to be compile time known constant. Not neccesarily a constant.
    static int size = 5;    // couls also be    static const int size = 5;
    int arr2[size];
    for (int i = 0; i < 5; i++)
    {
        arr2[i] = i + 5;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr2[i] << std::endl;
    }
    return 0;
}