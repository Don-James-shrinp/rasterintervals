#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream ifs("../data/lakes.tsv");
    ofstream ofsBinary("../output/binary.dat", ios::out | ios::binary);
    ofstream ofsOffset("../output/offset.dat", ios::out | ios::binary);
    
    int polygon_count = 0;
    string line;
    // 处理一行数据
    set<int> id;
    auto processLine = [&](string cur) {
        int posL = cur.find_first_of('(');
        int posR = cur.find_last_of(')');
        stringstream ss{cur};
        
        int polygonId;
        ss >> polygonId;
        id.insert(polygonId);
        string after = cur.substr(posL + 1, posR - posL - 1);
        ss.str(after);
        float x, y;
        while(getline(ss, line, ','))
        {
            stringstream ss2{line};
            ss2 >> x >> y;
        }
    };
    int line_count = 0;
    while(getline(ifs, line))
    {
        processLine(line);
    }
    cout << "number of polygons: " <<  id.size() << endl;
    return 0;
}