#include <string>
#include <unordered_map>
#include <sstream>
#include <cctype>

using namespace std;

/*
1507. Reformat Date
*/

class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> months = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };
        string DD;
        string MM;
        string YYYY;
        stringstream(date) >> DD >> MM >> YYYY;
        // "20th Oct 2052"; => "20th" "Oct" "2052"

        string day;
        if (isdigit(DD[1])) {
            day = DD.substr(0, 2);
        } else {
            day = "0" + DD.substr(0, 1);
        }
        return YYYY + "-" + months[MM] + "-" + day;

    }
};