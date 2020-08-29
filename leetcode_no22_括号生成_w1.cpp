/*----------------------------------------------------------------------------------------|
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 |
                                                                                          |
                                                                                          |
                                                                                          |
示例：                                                                                    |
                                                                                          |
输入：n = 3                                                                               |
输出：[                                                                                   |
       "((()))",                                                                          |
       "(()())",                                                                          |
       "(())()",                                                                          |
       "()(())",                                                                          |
       "()()()"                                                                           |
     ]                                                                                    |
                                                                                          |
来源：力扣（LeetCode）                                                                    |
链接：https://leetcode-cn.com/problems/generate-parentheses                               |
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。                      |
-----------------------------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了88.51%的用户
*	内存消耗：7.5 MB, 在所有 C++ 提交中击败了97.16%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> generateParenthesis(int n) 
{
    vector<vector<string>> result(n+1);

    result[0].push_back("");

    for (int i = 1; i < n + 1; i++)                                                     /*  注意i的范围是从1到n的    */
    {
        for (int j = 0; j < i; j++)                                                     /*  j的范围是从0到i-1的    */
        {
            for (string& str1 : result[j])
            {
                for (string& str2 : result[i - j - 1])                                  /*  状态转移方程：result[i] = ( + result[j] + ) + result[i-j-1]    */
                {
                    result[i].push_back( "(" + str2 + ")" + str1);                      /*  题解不允许顺序打乱就很烦，只能按照[i-j--],[i]的顺序操作    */
                }
            }
        }
    }
    return result[n];
}

int main()
{

}