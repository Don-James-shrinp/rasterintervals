#include <bits/stdc++.h>
using namespace std;
struct Polygon {
    int id;
    int vertexCount;
    vector<pair<float, float>> points;
};

int main()
{
    ifstream ifs("../data/lakes.tsv");
    ofstream ofsBinary("../output/binary.dat", ios::out | ios::binary);
    ofstream ofsOffset("../output/offset.dat", ios::out | ios::binary);

    vector<Polygon> polygons;
    string line;
    // 处理一行数据
    auto processLine = [&](string cur) {
        int posL = cur.find_first_of('(');
        int posR = cur.find_last_of(')');
        stringstream ss{cur};
        
        int polygonId;
        ss >> polygonId;
        string after = cur.substr(posL + 1, posR - posL - 1);
        ss.str(after);
        float x, y;
        vector<pair<float, float>> pos;
        while(getline(ss, line, ','))
        {
            stringstream ss2{line};
            ss2 >> x >> y;
            pos.push_back({x, y});
        }
        polygons.push_back({polygonId, pos.size(), pos});
    };
    int line_count = 0;
    while(getline(ifs, line))
    {
        processLine(line);
    }
    int polygonCount = polygons.size();
    
    ofsBinary.write(reinterpret_cast<const char*>(&polygonCount), sizeof(polygonCount));
    for(int i = 0; i < polygonCount; i++)
    {
        ofsBinary.write(reinterpret_cast<const char*>(&polygons[i].id), sizeof(polygons[i].id));
        ofsBinary.write(reinterpret_cast<const char*>(&polygons[i].vertexCount), sizeof(polygons[i].vertexCount));
        for(int j = 0; j < polygons[i].vertexCount; j++)
        {
            ofsBinary.write(reinterpret_cast<const char*>(&polygons[i].points[j].first), sizeof(polygons[i].points[j].first));
            ofsBinary.write(reinterpret_cast<const char*>(&polygons[i].points[j].second), sizeof(polygons[i].points[j].second));
        }
    }
    ofsBinary.close();
    return 0;
}