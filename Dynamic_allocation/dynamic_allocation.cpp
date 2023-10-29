// at compile we should be sure how big our array should be
// two memory - stack(small) and heap(big)
 #include<iostream>
 using namespace std;
 int main()
 {
    int *p= new int;
    *p= 10;
    cout<<*p<<endl;


    // for array
     int *pa = new int[10];
     int n;
    cout<<"Enter the num of elements "<<endl;
    cin>>n;
    int *pa2= new int[n];
    for (int i =0;i<n;i++)
    {
        cin>>pa2[i];
    }
    int max=-1;
    for (int i=0;i<n;i++)
    {
        if (max<a[i])
        {
            max=a[i];
        }
    }
    cout<<max<<endl;
 }