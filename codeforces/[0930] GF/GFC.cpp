#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N, L;
int flag[100000];
double tx[100000], ty[100000];
int main() {
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> L;
        FOR(i, 0, N) {
            cin >> flag[i];
        }
        double time = 0;
        double v = 1;
        tx[0] = flag[0] / v;
        v = 2;
        FOR(i, 1, N) {
            double dist = flag[i];
            dist -= flag[i - 1];
            tx[i] = tx[i - 1] + (dist) / v;
            v += 1;
        }
        time = 0;
        v = 1;
        ty[N - 1] = L;
        ty[N - 1] -= flag[N - 1];
        ty[N - 1] /= v;
        v = 2;
        for(int i = N-2; i>=0; i--) {
            double dist = flag[i+1];
            dist -= flag[i];
            ty[i] = ty[i + 1] + (dist) / v;
            v += 1;
        }
        int ffx = -1, ffy = L;
        FOR(i, 0, N) {
            if (tx[i] < ty[i]) {
                ffx = i;
            }
        }
        for (int i = N - 1; i >= 0; i--) {
            if (ty[i] <= tx[i])
                ffy = i;
        }
        int fvx, fvy;
        if (ffx == -1)
            fvx = 1;
        else
            fvx = ffx + 2;
        if (ffy == L)
            fvy = 1;
        else
            fvy = N - 1 - ffy + 2;
        double finaltime = 0;
        if (ffx == -1)
            finaltime = max((double)0, finaltime);
        else
            finaltime = max(tx[ffx], finaltime);
        if (ffy == L)
            finaltime = max((double)0, finaltime);
        else
            finaltime = max(ty[ffy], finaltime);
        double resdist;

        double fdisty;
        if (ffy != L)
            fdisty = flag[ffy] - (finaltime - ty[ffy]) * fvy;
        else
            fdisty = L-1 * finaltime;
        double fdistx;
        if (ffx != -1)
            fdistx = flag[ffx] + (finaltime - tx[ffx]) * fvx;
        else
            fdistx = 1 * finaltime;
        resdist = fdisty - fdistx;
        double restime = resdist / ((double)(fvx)+fvy);
        double result = finaltime + restime;
        cout << fixed << setprecision(10);
        cout << result << "\n";
    }
    return 0;
}