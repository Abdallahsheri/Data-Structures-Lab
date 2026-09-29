#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Array
{
private:
    int Size;
    int Length;
    int* Items;

public:
    Array(int ArraySize)
    {
        Size = ArraySize;
        Length = 0;
        Items = new int[ArraySize];
    }

    void Fill()
    {
        int NumberOfItems;
        cout << "How Many Items Do You Want To Fill ?" << endl;
        cin >> NumberOfItems;
        if (NumberOfItems > Size)
        {
            cout << "You Can Not Exceed The Array Size!!" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < NumberOfItems; i++)
            {
                cout << "Please Enter The Item No : " << i + 1 << endl;
                cin >> Items[i];
                Length++;
            }
        }
    }

    void Display()
    {
        cout << "Display Array Content : " << endl;

        for (int i = 0; i < Length; i++)
        {
            cout << Items[i] << "\t";
        }
        cout << endl;
    }

    int GetSize()
    {
        return Size;
    }

    int GetLength()
    {
        return Length;
    }
    
    int Search(int Key)
    {
        int Index = -1;
        for (int i = 0; i < Length; i++)
        {
            if (Items[i] == Key)
            {
                Index = i;
                break;
            }
        }
        return Index;
    }

    void Append(int NewItem)
    {
        if (Length < Size)
        {
            Items[Length] = NewItem;
            Length++;
        }
        else
        {
            cout << "Array Is Full!" << endl;
        }
    }

    void Insert(int Index, int NewItem)
    {
        if (Index >= 0 && Index < Size)
        {
            for (int i = Length; i > Index; i--)
            {
                Items[i] = Items[i - 1];
            }
            Items[Index] = NewItem;
            Length++;
        }

        else
        {
            cout << "Error -- **Index Is Out Of Range** --" << endl;
        }

    }

    void Delete(int Index)
    {
        if (Index >= 0 && Index < Size)
        {
            for (int i = Index; i < Length - 1; i++)
            {
                Items[i] = Items[i + 1];
            }
            Length--;
        }

        else
        {
            cout << "Error -- **Index Is Out Of Range** --" << endl;
        }

    }

    void Enlarge(int NewSize)
    {
        if (NewSize <= Size)
        {
            cout << "The New Size Must Be Larger Than The Current Size" << endl;
            return;
        }

        else
        {
            Size = NewSize;
            int* Old = Items;
            Items = new int[NewSize];
            for (int i = 0; i < Length; i++)
            {
                Items[i] = Old[i];
            }
            delete[] Old;
        }

    }

    void Merge(Array Other)
    {
        int NewSize = Size + Other.GetSize();
        Size = NewSize;
        int* Old = Items;
        Items = new int[NewSize];
        int i;
        for (i = 0; i < Length; i++)
        {
            Items[i] = Old[i];
        }
        
        delete[]Old;

        int j = i;
        for (int i = 0; i < Other.GetLength(); i++)
        {
            Items[j++] = Other.Items[i];
            Length++;
        }
    }

};

int main()
{
    cout << "Hello This Is Array ADT Demo : \n";
    int ArraySize;
    cout << "Enter the Array Size : " << endl;
    cin >> ArraySize;
    Array A1(ArraySize);
    A1.Fill();
    A1.Display();
    cout << "Size Of Array Is : " << A1.GetSize() << endl;
    cout << "Length Of Array Is : " << A1.GetLength() << endl;

    int Key;
    cout << "Please Enter A Value To Search For : " << endl;
    cin >> Key;

    int Index = A1.Search(Key);
    if (Index == -1)
    {
        cout << "Item Not Found" << endl;
    }
    else
    {
        cout << "Item Found At Position : " << Index << endl;
    }


    int NewItem;
    cout << "Please Enter A New Item To Add It In The Array : ";
    cin >> NewItem;

    A1.Append(NewItem);
    cout << endl;
    A1.Display();

    cout << "Please, Enter The Index And Item : " << endl;
    cin >> Index >> NewItem;
    A1.Insert(Index, NewItem);
    cout << endl;
    A1.Display();
    cout << "Size Of Array Is : " << A1.GetSize() << endl;
    cout << "Length Of Array Is : " << A1.GetLength() << endl;

    cout << "Please Enter The Index You Want To Delete : " << endl;
    cin >> Index;
    A1.Delete(Index);
    cout << endl;
    A1.Display();

    int NewSize;
    cout << "Please Enter The New Size : " << endl;
    cin >> NewSize;
    A1.Enlarge(NewSize);
    cout << "Size Of Array Is : " << A1.GetSize() << endl;
    cout << "Length Of Array Is : " << A1.GetLength() << endl;
    A1.Display();

    Array Other(3);
    Other.Fill();
    A1.Merge(Other);
    cout << "Size Of Array Is : " << A1.GetSize() << endl;
    cout << "Length Of Array Is : " << A1.GetLength() << endl;
    A1.Display();
}

