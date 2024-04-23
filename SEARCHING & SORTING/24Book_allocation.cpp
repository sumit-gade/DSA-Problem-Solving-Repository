#include <iostream>
using namespace std;

bool isPossible(int A[], int N, int M, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < N; i++) {
        // If adding this book exceeds `mid`, allocate to new student
        if (pageSum + A[i] > mid) {
            studentCount++;  // Increment student count
            pageSum = A[i];  // Start new sum with current book
            if (studentCount > M || A[i] > mid) {  // If more students needed than available or book page count exceeds `mid`
                return false;
            }
        } else {
            pageSum += A[i];  // Add current book's pages to current sum
        }
    }
    return true;
}

int findPages(int A[], int N, int M) {
    if (N < M) {
        return -1;  // Not enough books to allocate
    }

    int s = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        s = max(s, A[i]);  // Ensuring the start point is the largest single book (as one student might need at least this many pages)
    }

    int e = sum;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(A, N, M, mid)) {
            ans = mid;  // Possible, try for a smaller max page
            e = mid - 1;
        } else {
            s = mid + 1;  // Not possible, increase the number of pages
        }
    }

    return ans;
}

int main() {
    int A[] = {12, 34, 67, 90};
    int N = sizeof(A) / sizeof(A[0]);
    int M = 2;  // Number of students

    int result = findPages(A, N, M);
    cout << "The minimum of the maximum pages is: " << result << endl;

    return 0;
}

