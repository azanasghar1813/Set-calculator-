#include <iostream>
using namespace std;

void inputArray(int arr[], int& n);
void outputArray(int arr[], int n);
void findUnion(int arr1[], int n, int arr2[], int m, int result[], int& size);
void findIntersection(int arr1[], int n, int arr2[], int m, int result[], int& size);
void findComplement(int arr1[], int n, int arr2[], int m, int result[], int& size);
void findDifference(int arr1[], int n, int arr2[], int m, int result[], int& size);
bool isSubset(int arr1[], int n, int arr2[], int m);
void compareCardinality(int arr1[], int n, int arr2[], int m);

int main()
{
    int choice;
    cout<<"Enter Your Choice:"<<endl;
    cout << "/*-----Set Calculator-----*/" << endl;
    cout << "1-Union of Two Sets:" << endl;
    cout << "2-Intersection of Two Sets:" << endl;
    cout << "3-Complement of Two Sets:" << endl;
    cout << "4-Difference of Two Sets:" << endl;
    cout << endl;
    cout << "/*--------Subsets--------*/" << endl;
    cout << "5-Subset Checker:" << endl;
    cout << endl;
    cout << "/*------Cordinallity------*/" << endl;
    cout << "6-Set Cordinallity Comparison:" << endl;
    cin >> choice;

    int arr1[100], arr2[100], result[200];
    int n, m, size = 0;

    cout << "Input first set:\n";
    inputArray(arr1, n);

    cout << "Input second set:\n";
    inputArray(arr2, m);

    if (choice == 1)
    {
        findUnion(arr1, n, arr2, m, result, size);
        cout << "Union: ";
        outputArray(result, size);
    }
    else if (choice == 2)
    {
        findIntersection(arr1, n, arr2, m, result, size);
        cout << "Intersection: ";
        outputArray(result, size);
    }
    else if (choice == 3)
    {
        findComplement(arr1, n, arr2, m, result, size);
        cout << "Complement of first set relative to second set: ";
        outputArray(result, size);
    }
    else if (choice == 4)
    {

        if (isSubset(arr1, n, arr2, m))
            cout << "First set is a subset of the second set." << endl;
        else
            cout << "First set is NOT a subset of the second set." << endl;
    }
    else if (choice == 5)
    {
        compareCardinality(arr1, n, arr2, m);

    }
    return 0;
}

void inputArray(int arr[], int& n)
{
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void outputArray(int arr[], int n)
{
    cout << "{ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}

void findUnion(int arr1[], int n, int arr2[], int m, int result[], int& size)
{
    int i = 0, j = 0;
    size = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            result[size++] = arr1[i++];
        }
        else if (arr2[j] < arr1[i]) {
            result[size++] = arr2[j++];
        }
        else {
            result[size++] = arr1[i++];
            j++;
        }
    }

    while (i < n) {
        result[size++] = arr1[i++];
    }

    while (j < m) {
        result[size++] = arr2[j++];
    }
}

void findIntersection(int arr1[], int n, int arr2[], int m, int result[], int& size)
{
    int i = 0, j = 0;
    size = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if (arr2[j] < arr1[i]) {
            j++;
        }
        else {
            result[size++] = arr1[i++];
            j++;

        }
    }
}

void findComplement(int arr1[], int n, int arr2[], int m, int result[], int& size)
{
    int i = 0, j = 0;
    size = 0;

    while (i < n) {
        if (j < m && arr1[i] == arr2[j]) {
            i++;
            j++;
        }
        else if (j < m && arr1[i] > arr2[j]) {
            j++;
        }
        else {
            result[size++] = arr1[i++];
        }
    }
}
bool isSubset(int arr1[], int n, int arr2[], int m)
{
    int i = 0, j = 0;

   
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
         
            return false;
        }
        else if (arr1[i] == arr2[j]) {
            
            i++;
            j++;
        }
        else {
            
            j++;
        }
    }

    return i == n;
}
void compareCardinality(int arr1[], int n, int arr2[], int m)
{
    cout << "Cardinality of First Set: " << n << endl;
    cout << "Cardinality of Second Set: " << m << endl;

    if (n > m) {
        cout << "First set is larger." << endl;
    }
    else if (n < m) {
        cout << "Second set is larger." << endl;
    }
    else {
        cout << "Both sets have the same cardinality." << endl;
    }
}
void findDifference(int arr1[], int n, int arr2[], int m, int result[], int& size)
{
    int i = 0, j = 0;
    size = 0;

    while (i < n) {
        if (j < m && arr1[i] == arr2[j]) {
            i++;
            j++;
        }
        else if (j < m && arr1[i] > arr2[j]) {
            j++;
        }
        else {
            result[size++] = arr1[i++];
        }
    }
}
