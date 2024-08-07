#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        cout << "[" << k << "]: " << arr[k];
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            cout << " <- " << L[i];
            i++;
        } else {
            arr[k] = R[j];
            cout << " <- " << R[j];
            j++;
        }
        cout << endl;
        k++;
    }

    while (i < n1) {
        cout << "[" << k << "]: " << arr[k] << " <- " << L[i] << endl;
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        cout << "[" << k << "]: " << arr[k] << " <- " << R[j] << endl;
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);

    cout << "Merge [" << left << ", " << right << "]: ";
    for (int i = left; i <= right; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(int t, int *a) {
    for(int i = 0; i < t; ++i) {
        cout << "Elemento " << i << " = " << a[i] << endl;
    }
    cout << "----------------" << endl;
}

int main(int argc, char** argv) {
    int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
    print(8, v);
    mergeSort(v, 0, 7);
    print(8, v);

    return 0;
}
