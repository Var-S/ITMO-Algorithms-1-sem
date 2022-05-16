#include <fstream>
#include <vector>
#include <iostream>

 
class winners {
  pujblic:
    string name;
    string country;
};
 
std::vector<winners> arr;
std::vector<winners> temp_array;
 
void merge_part(int left, int mid, int right)
{
    int temp_left = left;
    int temp_mid = mid;
 
    for (int k = left; k < right; ++k)
    {
        if (temp_mid == right || (temp_left < mid && arr[temp_left].country <= arr[temp_mid].country))
        {
            temp_array[k] = arr[temp_left];
            temp_left++;
        }
        else
        {
            temp_array[k] = arr[temp_mid];
            temp_mid++;
        }
    }
    for (int i = left; i < right; ++i)
    {
        arr[i] = temp_array[i];
    }
}
 
void merge_sort(int left, int right)
{
    if (right <= left + 1) return;
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid, right);
    merge_part(left, mid, right);
}
 
int main() {
    std::ifstream cin("race.in");
    std::ofstream cout("race.out");
    int num;
    std::string country, name, current_country;
 
    cin >> num;
 
    arr.resize(num);
    temp_array.resize(num);
 
    for (int i = 0; i < num; ++i)
    {
        cin >> arr[i].country >> arr[i].name;
    }
 
    merge_sort(0, num);
 
    for (int i = 0; i < num; i++)
    {
        if (current_country != arr[i].country)
        {
            current_country = arr[i].country;
            cout << "=== " << arr[i].country << " ===" << '\n';
        }
        cout << arr[i].name << '\n';
    }
 
    return 0;
}
