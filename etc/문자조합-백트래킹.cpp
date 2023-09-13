#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 메모리 사용 여부와 함수 인자 개수 줄이기 위한 전역변수

// 마스킹문자열
string str;

// 답 저장 리스트
vector<string> result_str;

// 단어들
vector<string> words;

// ? 인덱스 저장 리스트
vector<int> mask_idx;

// 함수    재귀적 사용
void solve(string sentence, int str_len, vector<int>& words_used)
{
    //cout << sentence << endl;
    int len = sentence.length();
    
    // 현재까지 조합한 sentence까지를 입력 마스킹문자열과 비교 하여 불필요한 조합 return
    if (len != 0)
    {
        string sub_str = str.substr(0, len);  
        string tmp = sentence;
        for (int i : mask_idx)
        {
            if (i >= len) { break; }
            tmp[i] = '?';
        }
        if (sub_str != tmp) { return; }
    }

    // 조합중인 문자열 길이가 작을 때, 계속 재귀
    if (len < str_len)
    {
        for (int i = 0; i < words.size(); i++) 
        {
            if (words_used[i] == 1) { continue; }
            else 
            {
                // 조합 문자열 + 사용할 단어 길이 체크
                if (words[i].length() + len <= str_len)
                {
                    // 사용할 단어의 첫 문자 체크
                    if (str[len] != '?')
                    {
                        if (str[len] != words[i][0])
                        {
                            continue;
                        }
                    }
                    // 단어 사용 체크
                    words_used[i] = 1;
                   
                    solve(sentence + words[i], str_len, words_used);
                    // 단어 사용 해제
                    words_used[i] = 0;
                }
            }
        }
    }
    // 조합중인 문자열 길이가 같을 때, 답 리스트에 저장
    else if (len == str_len) 
    {
        result_str.push_back(sentence);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    
    cin >> N >> M;
    cin >> str;

    vector<int> words_used(M);

    for (int i = 0; i < M; i++) 
    {
        string word;
        cin >> word;
        words.push_back(word);
    }

    // 1. 입력 문자열의 ? 인덱스를 찾는다   -> 리스트에 저장.
    for (int i = 0; i < N; i++) 
    {
        if (str[i] == '?') { mask_idx.push_back(i); }
    }

    // 함수 실행    N=마스킹문자열의 길이   ""는 현재 조합중인 sentence    words_used는 사용한 단어 리스트 여부 저장
    solve("", N, words_used);

    cout << endl;

    sort(result_str.begin(), result_str.end());
    // 전체 result 리스트 출력   ->  실제 답은 정렬 후 첫번째 값.
    cout << result_str[0] << endl;

    cout << endl;
    for (string s : result_str) 
    {
        cout << s << endl;
    }

    return 0;
}