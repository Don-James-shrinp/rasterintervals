#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream ifs("../data/lakes.tsv");
    ofstream ofs("../output/out", ios::out | ios::binary);
    int polygon_count = 0;
    string line;
    //  获取Polygons的数量
    while(getline(ifs, line))
    {
        polygon_count++;
    }
    cout << polygon_count << endl;
    ofs.write(reinterpret_cast<const char*>(&polygon_count), sizeof(polygon_count));
    ifs.close();
    ofs.close();
    ifstream fin("../output/out", ios::binary);
    int count;
    fin.read(reinterpret_cast<char*>(&count), sizeof(count));
    cout << "read: " << count << endl;
    return 0;
}