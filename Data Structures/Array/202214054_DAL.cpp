#include <iostream>
#include<stdio.h>
#include<cmath>
using namespace std;


class DynamicArray {
private:
    int * d_array;
    int max_size;
    int length;
public:
    DynamicArray()

    {

        max_size = 2;
        d_array = new int[max_size];
        length = 0;
    }


    void add(int item) {
        if (isFull()) {

            max_size = 2 * max_size;
            int * temp_d_array = new int[max_size];
            cout<<"\nDAL Limit reached, new array created, values copied\n"<<endl;

            for (int i = 0; i < length; i++) {
                temp_d_array[i] = d_array[i];
            }


            delete [] d_array;


            d_array = temp_d_array;


        }


        d_array[length] = item;

        length++;
    }

    void printd_array() {
        for (int i = 0; i < length; i++) {
            cout<<d_array[i]<<' ';
        }
        cout<<endl;
    }


    bool isFull() {
        return length == max_size;

    }

    void del(int pos)
    {
        if(pos<0 || pos>length)
        {
            cout << "Invalid index, enter valid one.\n";
            return;
        }
        int val = d_array[pos];
        for (int i = pos; i < length-1; ++i)
        {
            d_array[i]=d_array[i+1];
        }
        length--;
        printf("\nDeleted the value in position %d which was %d\n",pos,val);
        cout << "The current Array is:";
        printd_array();
    }

    void insert(int pos, int val)
    {
        if(pos<0 || pos>length)
        {
            cout << "Invalid index, enter valid one.\n";
            return;
        }
        for (int i = length; i >= pos; --i)
        {
            d_array[i]=d_array[i-1];
        }
        d_array[pos]=val;
        length++;
        printf("\nInserted '%d' at position %d\n",val,pos);
        cout << "The current Array is:";
        printd_array();
    }

    void del_all(int val)
    {
        bool f=false; int c=0;
        for (int i = 0; i < length; ++i)
        {
            if(d_array[i]==val)
            {
                f=true;
                ++c;
                for (int j = i; j < length-1; ++j)
                {
                    d_array[j]=d_array[j+1];
                }
                length--;
            }
        }
        if(d_array[length-1]==val)
        {
            length--;
            ++c;
        }



        int tmp = log2(length)+1;
        max_size = pow(2,tmp);
        int *tmp_array= new int[max_size];

        for (int i = 0; i < length; ++i)
        {
            tmp_array[i] = d_array[i];
        }
        delete [] d_array;
        d_array = tmp_array;



        if(!f) cout << "\nElement already deleted or not present.\n";
        else
        {
            printf("\nDeleted all occurences of '%d'. Total %d items were deleted. Array resized.\n",val,c);
            cout << "Array size: " << sizeof(d_array) << endl;
            cout << "The current Array is:\n";
            printd_array();

        }
    }

    void replace(int val, int r_val)
    {
        bool f=false; int c=0;
        for (int i = 0; i < length; ++i)
        {
            if(d_array[i]==val)
            {
                f=true;
                ++c;
                d_array[i]=r_val;
            }
        }
        if(!f) printf("No occurence of %d was found. No items were replaced", val);
        else
        {
            printf("\n%d replaced with '%d'. Total %d replacement.\n",val, r_val,c);
            cout << "The current Array is:\n";
            printd_array();

        }
    }


    bool is_sorted(int order)
    {
        if(order==0)
        {
            for (int i = 0; i < length-1; ++i)
            {
                if(d_array[i] > d_array[i+1]) return false;
            }
        }
        else
        {
            for (int i = 0; i < length-1; ++i)
            {
                if(d_array[i] < d_array[i+1]) return false;
            }
        }
        return true;
    }


    void sort(int order)
    {
        if(order==0)
        {
            for (int i = 0; i < length-1; ++i)
            {
                if(d_array[i]>d_array[i+1])
                {
                    swap(d_array[i],d_array[i+1]);

                    i=-1;
                }
            }

        }
        else
        {
            for (int i = 0; i < length-1; ++i)
            {
                if(d_array[i]<d_array[i+1])
                {
                    swap(d_array[i],d_array[i+1]);

                    i=-1;
                }
            }
        }
        cout << "Array was sorted first. Below is the current array list.\n";
        for (int i = 0; i < length; ++i)
        {
            cout << d_array[i] << " ";
        }
        cout << endl;
    }


    int lower_bound(int val, int order)
    {
        if(length==0) {cout << "Array is empty."; return -1;}
        if(!(is_sorted(order))) sort(order);
        int low=0, high=length,mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(d_array[mid]==val) return mid;
            else if(d_array[mid]>val)
                (order==0)? high = mid-1 : low=mid+1;
            else (order==0)? low = mid+1 : high=mid-1;
        }
        if(d_array[low]!=val)cout << "Value not present. the closest index we could find: ";
        else printf("The element %d was found at position: ",val);
        return low;
    }

    ~DynamicArray()
    {
        delete [] d_array;
    }


};

int main() {

    DynamicArray dal;
    int a, choice;
    printf("\t\tDynamic Array d_array Implementation using Template Class.\n\t\t\tDo menu options 3-7 on your own.");


   while (1)
{

    printf("\n1.Add an element\n2.See current Elements\n3.Delete an element\n4.Insert element at position\n5.Delete all matching values\n6.Replace matching values\n7.Sort & Search for element\n8.Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);



    if(choice==1)
    {
        printf("\nEnter a num to add: ");
        scanf("%d", &a);
        dal.add(a);

        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }

    else if (choice==2)
    {
        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }

     else if (choice==3)
    {
       cout << "Enter position to Delete from: ";
       int pos; cin >> pos;
       dal.del(pos);
    }

    else if (choice==4)
    {
       cout << "Enter position to Insert into: ";
       int pos; cin >> pos;
       cout << "Enter the value to Insert: ";
       int val; cin >> val;
       dal.insert(pos,val);
    }
    else if (choice==5)
    {
       cout << "Enter value to Delete: ";
       int val; cin >> val;
       dal.del_all(val);
    }
    else if (choice==6)
    {

        cout << "Enter value to replace: ";
        int val, r_val; cin >> val;
        cout << "Enter value to be replaced by: ";
        cin >> r_val;
        dal.replace(val,r_val);


    }
    else if (choice==7)
    {
       //do by yourself
        cout << "Enter value to search for: ";
        int val; cin >> val;
        cout << "Enter order of sorting.\n 0 for ascending & 1 for descending: ";
        int order; cin >> order;
        cout << dal.lower_bound(val, order);

    }

    else
    {
        printf("\n\t\tProgram Terminated\n\n");
        break;
    }


}
    return 0;
}
