#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// �޸� ��� ���ο� �Լ� ���� ���� ���̱� ���� ��������

// ����ŷ���ڿ�
string str;

// �� ���� ����Ʈ
vector<string> result_str;

// �ܾ��
vector<string> words;

// ? �ε��� ���� ����Ʈ
vector<int> mask_idx;

// �Լ�    ����� ���
void solve(string sentence, int str_len, vector<int>& words_used)
{
    //cout << sentence << endl;
    int len = sentence.length();
    
    // ������� ������ sentence������ �Է� ����ŷ���ڿ��� �� �Ͽ� ���ʿ��� ���� return
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

    // �������� ���ڿ� ���̰� ���� ��, ��� ���
    if (len < str_len)
    {
        for (int i = 0; i < words.size(); i++) 
        {
            if (words_used[i] == 1) { continue; }
            else 
            {
                // ���� ���ڿ� + ����� �ܾ� ���� üũ
                if (words[i].length() + len <= str_len)
                {
                    // ����� �ܾ��� ù ���� üũ
                    if (str[len] != '?')
                    {
                        if (str[len] != words[i][0])
                        {
                            continue;
                        }
                    }
                    // �ܾ� ��� üũ
                    words_used[i] = 1;
                   
                    solve(sentence + words[i], str_len, words_used);
                    // �ܾ� ��� ����
                    words_used[i] = 0;
                }
            }
        }
    }
    // �������� ���ڿ� ���̰� ���� ��, �� ����Ʈ�� ����
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

    // 1. �Է� ���ڿ��� ? �ε����� ã�´�   -> ����Ʈ�� ����.
    for (int i = 0; i < N; i++) 
    {
        if (str[i] == '?') { mask_idx.push_back(i); }
    }

    // �Լ� ����    N=����ŷ���ڿ��� ����   ""�� ���� �������� sentence    words_used�� ����� �ܾ� ����Ʈ ���� ����
    solve("", N, words_used);

    cout << endl;

    sort(result_str.begin(), result_str.end());
    // ��ü result ����Ʈ ���   ->  ���� ���� ���� �� ù��° ��.
    cout << result_str[0] << endl;

    cout << endl;
    for (string s : result_str) 
    {
        cout << s << endl;
    }

    return 0;
}