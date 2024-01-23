#include <iostream>
#include <vector>
using namespace std;

 int compress(vector<char>& chars) {
        
      int i = 0;
	for(int j = 1, count = 1; j <= chars.size(); j++, count++) {
		if(j == chars.size() || chars[j] != chars[j - 1]) {    // pichle wale element se compare karte raho agar element equal nahi hao  to 
			chars[i++] = chars[j - 1];             //


			if(count >= 2) // agar do  ya do se jada hai  to 
				for(char digit : to_string(count))   // convert digitto char ini string  
					chars[i++] = digit;
			count = 0;
		}
	}
	return i;
    }


int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int compressedLength = compress(chars);

    std::cout << "Compressed vector: ";
    for (int i = 0; i < compressedLength; ++i) {
        std::cout << chars[i] << " ";
    }

    return 0;
}
