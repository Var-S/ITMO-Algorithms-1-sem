#include <fstream>
  
int main()
{
    std::ifstream fin("antiqs.in");
    std::ofstream fout("antiqs.out");
  
    int n;
    fin >> n;
    int arr[n];
  
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;
  
    for(int i = 0; i < n; i++)
        std::swap(arr[i], arr[i / 2]);
  
    for(int i = 0; i < n; i++)
        fout << arr[i] << " ";
}
