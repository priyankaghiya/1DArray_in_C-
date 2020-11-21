#include <iostream>
using namespace std;

int user_input_size(int length);
void input_and_print_arrayelements(int arr[],int length);
void  traversal(int arr[],int length);
void insert_begin(int arr[],int length,int value);
void  insert_at_position(int arr[],int length,int position,int value);
void insert_end(int arr[],int length,int value);
void delete_begin(int arr[],int length);
void delete_at_position(int arr[],int length,int position);
void delete_end(int arr[],int length);
int main()
{
    int arr[50],length,ch,value,position;
    length=user_input_size(length);
    input_and_print_arrayelements(arr,length);

    cout<< "\n Press 1 for Traversal \n ";
    cout<< "Press 2 for Insert at Beginning \n";
    cout<< "Press 3 for Insert at given Position \n ";
    cout<< "Press 4 for Insert at End  \n";
    cout<< "Press 5 for Delete at Beginning \n";
    cout<< "Press 6 for Delete at given Position \n ";
    cout<< "Press 7 for Delete at End  \n";

    cin >> ch;

    switch(ch)
    {
        case 1:
        traversal(arr,length);
        break;
    case 2:
        insert_begin(arr,length,value);
        break;
    case 3:
        insert_at_position(arr,length,position,value);
        break;
    case 4:
        insert_end(arr,length,value);
        break;
    case 5:
        delete_begin(arr,length);
        break;
    case 6:
        delete_at_position(arr,length,position);
        break;
    case 7:
        delete_end(arr,length);
        break;
    default:
        cout<< "Invalid key pressed ";

    }



    return 0;
}

int user_input_size(int length)
    {

        cout<<"ENTER THE ARRAY SIZE  :  ";
        cin>>length;


        if(length<=0 || length>50)
        {
            cout<<" INVALID LENGTH ";
        }
        else
        {
            return length;
        }

    }


void input_and_print_arrayelements(int arr[],int length)
{
    cout<< "ENTER THE ARRAY ELEMENTS : \n";
    for (int i=0;i<length;i++)
    {
        cin>> arr[i];
    }
    cout<< "THE ARRAY ELEMENTS ARE :  ";
    for (int i=0;i<length;i++)
    {
        cout<< arr[i] << "\t";
    }

}

void  traversal(int arr[],int length)
{
    cout<< "TRAVERSAL OF AN ARRAY :  ";
    for (int i=0;i<length;i++)
    {
        cout<< arr[i] << "\t";
    }

}

void insert_begin(int arr[],int length,int value)
{
    cout<< "ENTER THE VALUE TO BE INSERTED :  ";
    cin>>value;
    for (int i=length-1;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=value;
    length++;
    cout<< "VALUE INSERTED.....\n";
    traversal(arr,length);
    //here n elements will have to be shifted by one place where n is the length of the array
    //thus the complexity will be O(n)
}
void  insert_at_position(int arr[],int length,int position,int value)
{
    cout<< "ENTER THE POSITION AT WHICH THE VALUE IS TO BE INSERTED :  ";
    cin>>position;

    if(position < 0 || position >=length)
    {
        cout << "POSITION OUT OF RANGE ";
    }
    else
    {
            cout<< "ENTER THE VALUE TO BE INSERTED :  ";
            cin>>value;
            for (int i=length-1;i>=position-1;i--)
            {
                arr[i+1]=arr[i];
            }
            arr[position-1]=value;
            length++;
            cout<< "VALUE INSERTED.....\n";
            traversal(arr,length);

            //here according to the position the number of elements will have to be shifted by one place
            //thus the complexity would be O(n-p) where n is the length of the array and p is the position
    }

}

void insert_end(int arr[],int length,int value)
{
     cout<< "ENTER THE VALUE TO BE INSERTED :  ";
     cin>>value;

     arr[length]=value;
     length++;
     cout<< "VALUE INSERTED.....\n";
    traversal(arr,length);

    //here the complexity will be O(1) as no element in the array is to be shifted by one position
}

/*NOTE
for the array which is not sorted ie. unsorted , for insertion operation we can directly insert the element at the given position
and shift that element at the last  ie. a[length]=a[position-1];  a[position-1]=value; thus here the complexity would be O(1)*/


void delete_begin(int arr[],int length)
{
    cout<<arr[0]<<" DELETED\n";
    for(int i=0;i<length-1;i++)
    {
        arr[i]=arr[i+1];
    }
    length--;
    traversal(arr,length);
}

void  delete_at_position(int arr[],int length,int position)
{
    cout<<"ENTER THE POSITION AT WHICH THE ELEMENT IS TO BE DELETED: ";
    cin>>position;

    cout<<arr[position-1]<<" DELETED\n";
    if(position<=0 || position>length-1)
    {
        cout<<"ENTER VALID POSITION ";
    }
    else
    {
        //if(arr[0]!='\0') here don't need to check the if the array is having elements or not becoz at the initially while creating the error it is checked

            for(int i=position-1;i<length-1;i++)
            {
                arr[i]=arr[i+1];
            }
            length--;
            traversal(arr,length);
    }
}

void  delete_end(int arr[],int length)
{
    cout<<arr[length-1]<<" DELETED\n";
    length--;
    traversal(arr,length);
}

//here the complexity is exactly same as that of the insert
