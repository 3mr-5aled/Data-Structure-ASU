/*#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(100);
    s.insert(50);
    s.insert(120);
    s.insert(100);

    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << endl;

    return 0;
}
*/
// using pairs with vectors
/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<pair<string,string>> v;
    v.push_back(make_pair("Salma","Doctor"));
    v.push_back(make_pair("Ahmed","Engineer"));
    v.push_back(make_pair("Mohamed","Teacher"));

    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;

    return 0;
}*/

// using maps
/*#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string,string> jobs;
    jobs["Salma"]="Doctor";
    jobs["Ahmed"]="Engineer";
    jobs["Mohamed"]="Teacher";

    cout<< jobs["Ahmed"]<<endl;
    return 0;
}
*/
// using iterators with maps
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, string> jobs;
    jobs["Salma"] = "Doctor";
    jobs["Ahmed"] = "Engineer";
    jobs["Mohamed"] = "Teacher";
    map<string, string>::iterator it;
    for (it = jobs.begin(); it != jobs.end(); it++)
        cout << (*it).first << " " << it->second << endl; // or could be written as (*it).first
    return 0;
}
// adding and removing values in maps
/*#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string,string> jobs;
    jobs["Salma"]="Doctor";
    jobs["Ahmed"]="Engineer";
    jobs["Mohamed"]="Teacher";

    jobs.insert(make_pair("Mona","SWE"));
    jobs.erase("Ahmed");
    jobs.insert(make_pair("Alaa", "SWE"));
    map<string,string>::iterator it;
    for(it=jobs.begin();it!=jobs.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    return 0;
}*/