#include<bits/stdc++.h>
using namespace std;
int current_array_size = 0;
int main()
{
    int menu;
    int arr[4],i;

    while (1)
start:
    {
        cout << "Max size of SAL is set to 4\n\nMenu\n";
        cout<<"1. Insert New Element in the array:\n";
        cout <<"2. Delete element from the array:\n";
        cout<<"3. Search any element:\n";
        cout <<"4. Print The array:\n";
        cout<<"5. Replace duplicate:\n";
        cout<<"6. Exit\nEnter Choice: ";

        cin >> menu;
        if (menu == 6)
        {
            break;
        }

        switch (menu)
        {
        case 1:
        {
            int pos, val, j, k;

            current_array_size++;

            if (4 >= current_array_size)
            {
new_element:
                for (i = current_array_size - 1; i < 4; i++)
                {
                    printf("Enter the element to insert : ");
                    scanf("%d", & val);

                    printf("Enter index position to insert (current array length is: %d, so choose an index between 0 and %d):", i, i);

                    scanf("%d", & pos);

                    if (pos < 0 || pos > i)
                    {
                        printf("Invalid index position. Please enter a value between 0 and %d\n", i);
                        current_array_size--;
                        goto start;
                    }

                    for (j = i; j >= pos; j--)
                    {
                        arr[j + 1] = arr[j];
                    }

                    arr[pos] = val;
                    printf("%d is inserted at %d position\n", val, pos);
                    printf("Array after inserting the element: ");
                    for (k = 0; k <= i; k++)
                    {
                        printf("%d ", arr[k]);
                    }
                    printf("\n\n\n");
                    goto start;
                }

            }
            else
            {
                current_array_size=current_array_size-1;

                goto new_element;
            }

            break;

        }

        case 2:
        {
            int q;
            cout << "\nThe Current Array list is : ";
            for (i = 0; i < current_array_size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n\n";
            cout << "Enter index to delete from: ";
            cin >> q;
            if (current_array_size == 0) cout << "\nThe Array List is currently empty! \n";
            else if (q >= current_array_size) cout << "\nIncorrect position value\n\n";
            else
            {
                for (i = q; i < current_array_size; i++)
                {
                    arr[i] = arr[i + 1];
                }
                current_array_size--;
                cout << "\nDeleted from position " << q << '\n';
            }
            cout << "\nThe Current Array Lists is : ";
            for (i = 0; i < current_array_size; i++) cout << arr[i] << " ";
            cout << "\n\n";
            break;
        }

        case 3:
        {
            int key, i;
            cout << "Enter the Search Key : ";
            cin >> key;
            for (i = 0; i < 10; i++)
            {
                if (arr[i] == key)
                {
                    cout << "The search key " << key << " is at index " << i << "\n\n\n";
                    goto start;
                }
            }

            break;
        }

        case 4:
        {
            int i;
            cout << "\nThe Current Array list is : ";
            for (i = 0; i < current_array_size; i++)
            {

                cout << arr[i];

            }
            cout << "\n\n";

            break;
        }

        case 5:
        {

            int rep,rep_with,count=0;
            cout<<"Enter the value to replace: ";
            cin>>rep;
            cout<<"\n";
            cout<<"Enter the value to replace with:";
            cin>>rep_with;
            cout<<"\n";
            for ( i = 0; i < current_array_size; i++)
            {
                if(arr[i]==rep)
                {
                    count++;
                }
            }
            if(2<count && count>0)
            {

                cout<<"the duplicate of "<<rep<<" isn't present";
                cout<<"\n";
            }
            else if(count==0)
            {
                cout<<"the value "<<rep<<" doesn't exist";
                cout<<"\n";
            }
            else
            {
                cout<<"Replaced duplicates of "<<rep<<"with"<<rep_with;
                cout<<"\n";

                for ( i = current_array_size; i >= 0; i--)
                {
                    if((arr[i]==rep)&&count>1)
                    {
                        arr[i]=rep_with;
                        count--;
                    }

                }
                cout<<"the new array is: ";
                for ( i = 0; i < current_array_size; i++)
                {
                    cout<<arr[i]<<" ";

                }
                cout<<"\n";

            }
            count=0;

            goto start;
            break;
        }

        case 6:
        {
            return 0;

        }
        default:
        {
            printf("\nWrong input.\n\n");
            break;
        }

        }

    }

    return 0;
}
