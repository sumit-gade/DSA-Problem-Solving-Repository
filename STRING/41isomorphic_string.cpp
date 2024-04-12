#include <iostream>
#include <string>

using namespace std;

bool areIsomorphic(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    if (n != m)   // if lengths are not equal, then they cannot be isomorphic
        return false;

    int m1[256] = {0};   // character array for mapping from str1 to str2
    int m2[256] = {0};   // character array for mapping from str2 to str1

    for (int i = 0; i < n; i++) {
        if (!m1[str1[i]] && !m2[str2[i]]) {
            m1[str1[i]] = str2[i];  // mapping from str1 to str2
            m2[str2[i]] = str1[i];  // mapping from str2 to str1
        } else if (m1[str1[i]] != str2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Example usage
    string str1 = "egg";
    string str2 = "add";
    if (areIsomorphic(str1, str2)) {
        cout << str1 << " and " << str2 << " are isomorphic." << endl;
    } else {
        cout << str1 << " and " << str2 << " are not isomorphic." << endl;
    }

    return 0;
}
