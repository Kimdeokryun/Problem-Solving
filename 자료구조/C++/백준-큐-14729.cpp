# include <iostream>
using namespace std;

int scores[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, count = 0;
    double score;
    cin >> N;

    for(int i=0; i< N; i++)
    {
        cin >> score;
        scores[(int)(score * 1000)]++;
    }

    for (int i = 0; i < 100001; i++)
    {   
        if (!scores[i]) { continue; }
        if (count >= 7) { break; }
        while (scores[i]-- && count++ < 7) {
            printf("%.3f\n", (double)i / 1000);
        }
    }

    return 0;
}