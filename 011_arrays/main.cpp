#include<iostream>

// how to pass the size of array to a function w/o actually passing size of array
template<typename T, size_t N>
void func(T (&arr)[N])
{
    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    std::cout << "Size of arr:" << N << std::endl;
}


int main()
{
    int* arr1 = new int[5];
    for(int i = 0; i < 5; i++)
    {
        arr1[i] = i+5;
    }
    delete[] arr1;
    
    int arr3[]={9,8,7,6,5,4,3,2};
    func(arr3);

    // when array is initialized in stack, its size has to be compile time known constant. Not neccesarily a constant.
    static int size = 5;    // could also be    static const int size = 5;
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