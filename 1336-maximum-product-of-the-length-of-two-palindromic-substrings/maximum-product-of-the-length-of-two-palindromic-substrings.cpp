class Solution {
public:
#define ll long long

    class Manacher {
    private:
        string t;
        vector<ll> p;

    public:
        void mbuild(string t) {
            ll n = t.size();
            vector<ll> p(n, 0);
            ll l = 0, r = 0;

            for (ll i = 0; i < n; i++) {
                if (i < r)
                    p[i] = min(r - i, p[l + r - i]);

                while (i - p[i] >= 0 && i + p[i] < n &&
                       t[i - p[i]] == t[i + p[i]])
                    p[i]++;

                if (i + p[i] > r) {
                    l = i - p[i];
                    r = i + p[i];
                }
            }

            this->p = p;
        }

        Manacher(string s) {
            string t;
            for (ll i = 0; i < s.size(); i++) {
                t += "#";
                t += s[i];
            }
            t += "#";

            this->t = t;
            mbuild(t);
        }

        ll longpalc(ll ind, bool odd) {
            ll nind = 2 * ind + 1 + (!odd);
            return p[nind] - 1;
        }

        ll longpale(ll ind) { return p[ind] - 1; }

        bool ispal(ll l, ll r) {
            return r - l + 1 <= longpalc((l + r) / 2, l % 2 == r % 2);
        }
    };

    long long maxProduct(string s) {
        ll n = s.size();

        Manacher m(s);

        vector<ll> pre(n, 0), suff(n, 0);

        for (ll i = 0; i < n; i++) {
            ll len = m.longpalc(i, true);
            ll rad = (len - 1) / 2;
            ll L = i - rad;
            ll R = i + rad;

            pre[R] = max(pre[R], len);
            suff[L] = max(suff[L], len);
        }

        for (ll i = n - 2; i >= 0; i--)
            pre[i] = max(pre[i], pre[i + 1] - 2);

        for (ll i = 1; i < n; i++)
            suff[i] = max(suff[i], suff[i - 1] - 2);

        for (ll i = 1; i < n; i++)
            pre[i] = max(pre[i - 1], pre[i]);

        for (ll i = n - 2; i >= 0; i--)
            suff[i] = max(suff[i + 1], suff[i]);

        ll ans = 0;

        for (ll i = 0; i < n - 1; i++)
            ans = max(ans, pre[i] * suff[i + 1]);

        return ans;
    }
};