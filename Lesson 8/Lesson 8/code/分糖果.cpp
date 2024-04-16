// 无论如何，遇到最小化最大或者最大化最小时都要想到二分，虽然这题二分不可做，因为没法答案字符串
// 题意：给出 n 个字符，x 个人，每个人至少要被分配到一个字符，每个字符要恰好被分配一次，最小化最大的字符串
// 字典序比较是按位比较，空字符最小，其次是 ASCII 码比较，一般是 '0' < '1' < .... '9' < 'A' < ... 'Z' < 'a' < ... < 'z'
// 这种贪心类似的题目，先思考样例是怎么出来的，再自己多枚举一些样例，构造题也是这样的
// 6 2
// caabdc
// 对于每个人而言，它的字符串的第一个字符肯定要尽量小
// 肯定要将 a 分别分配给每个人作为第一个字符，即 Person 1: a, Person 2: a
// 在此基础上，肯定想第二个字符也尽量小，此时由于 b 只有一个，所以给 Person 2 分配 c 肯定不如不分配，直接全给 Person 1
// Person 1: abccd, Person 2: a
// 基于这个思路，我们有了以下想法：
// 我们肯定先考虑尽量分配最小的字符，把它们尽量放在第一个位置，且已经将 n 个字符排好序了
// 分别是 a_1 <= a_2 <= ... <= a_n
// 那么最优的情况一定是将 a_1, a_2, ..., a_x 分别分配给 x 个人各一个

// 1. a_x != a_1, 也即 a_x > a_1
// 比如 aaaabbccdf，共 5 个人，此时最优方案显然是 abccdf, a, a, a, b
// 对于第 x 个人而言，它收获了 a_x，此时最大的字符串就是第 x 个人，将剩余的字符全给第一个人，最大的还是 a_x (情况一)
// 所以此时答案就是 a_x

// 2. a_x = a_1
// 比如 aaaaaaa, 共 5 个人，此时最优方案是 aa, aa, a, a, a
// 比如 aaaaaab, 共 5 个人，此时最优方案是 aab, a, a, a, a
// 比如 aaaaabb, 共 5 个人，此时最优方案是 ab, ab, a, a, a
// 等价于去掉前 x 个字符，每个人都可以是空字符串，问最优
// 那么我们现在就考虑可以为空字符串怎么做
// 如果只有一种字符，毫无疑问，我们会选择均摊，因为此时等价于比较长度，所以平均地将这个字符分给每个人 (情况二)
// 如果有多种字符，此时均摊的思路还正确吗？不正确了！因为此刻如果均摊了，对于第二种字符而言，它的位置一定会向前移，不会更优 (情况三)
// 比如，我们只有 aaaaaab，分配给 5 个人，aaaaaab, , , , 这样最优

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, x;
    std::cin >> n >> x;
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    if (s[0] != s[x - 1]) { // 情况一
        std::cout << s[x - 1] << '\n';
        return;
    }
    int cnt = 1;
    // 现考虑去掉前 x 个字符，即前 x 个字符一定被均摊
    std::cout << s[0];
    for (int i = x + 1; i < n; i++) {
        if (s[i] != s[i - 1])cnt++;
    }
    // cnt 表示字符种类
    if (cnt == 1) {
        for (int i = x; i < n; i += x) {
            std::cout << s[i];
        }
        std::cout << '\n';
    }
    else {
        for (int i = x; i < n; i++) {
            std::cout << s[i];
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}