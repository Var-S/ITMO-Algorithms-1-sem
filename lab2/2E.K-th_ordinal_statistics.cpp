#include <fstream>
  
void QSort(int* arr, int left, int right, int k) {
    int i = left;
    int j = right;
    int key = arr[(right + left) / 2];
    while (i <= j) {
        while (arr[i] < key)
            i++;
        while (arr[j] > key)
            j--;
        if (i <= j)
            swap(arr[i++], arr[j--]);
    }
    if (j > left and k <= j)
        QSort(arr, left, j, k);
    if (i < right and k >= j)
        QSort(arr, j + 1, right, k);
}
 
int main()
{
    std::ifstream fin("kth.in");
    std::ofstream fout("kth.out");
 
    int n, k;
    int A, B, C;
    fin >> n >> k;
    int* arr = new int[n];
    if (n == 1)
        fin >> A >> B >> C >> arr[0];
    else
        fin >> A >> B >> C >> arr[0] >> arr[1];
    for (int index = 2; index < n; index++)
        arr[index] = A * arr[index - 2] + B * arr[index - 1] + C;
    QSort(arr, 0, n - 1, k - 1);
    fout << arr[k - 1];
    return 0;
}
