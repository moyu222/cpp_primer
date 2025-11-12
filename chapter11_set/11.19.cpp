#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct student
{
    string name;
    string gender;

    student(const string& n, const string& g) : name(n), gender(g) {}
};

bool compareName(const student &s1, const student &s2)
{
    return s1.name < s2.name;
}

int main()
{
    vector<student> v = {{"Alice", "female"}, {"Tom", "male"}, {"Sam", "m"}, {"Snow", "m"}};
    typedef bool (*pf) (const student &, const student &);
    multiset<student, pf> stud_set(compareName);
    std::multiset<student, pf>::iterator it = stud_set.begin();

     // ✅ 插入 vector 中的元素到 multiset
    stud_set.insert(v.begin(), v.end());

    // ✅ 输出 multiset 内容
    for (const auto& s : stud_set)
    {
        cout << s.name << " (" << s.gender << ")" << endl;
    }

    return 0;


}

