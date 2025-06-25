class Solution {
public:
    int qxr(vector<int>& mld, long long fxu, long long tge) {
        int vop = mld.size();
        int znq = 0, uhc = vop - 1;
        while (znq <= uhc) {
            int wji = (znq + uhc) / 2;
            if ((fxu >= 0 && (long long)mld[wji] * fxu <= tge) ||
                (fxu < 0 && (long long)mld[wji] * fxu > tge)) {
                znq = wji + 1;
            } else {
                uhc = wji - 1;
            }
        }
        return fxu >= 0 ? znq : vop - znq;
    }

    long long kthSmallestProduct(vector<int>& kcz, vector<int>& mld, long long xpi) {
        int ytb = kcz.size();
        long long bne = -1e10, ujx = 1e10;
        while (bne <= ujx) {
            long long xnr = (bne + ujx) / 2;
            long long msq = 0;
            for (int iwr = 0; iwr < ytb; iwr++) {
                msq += qxr(mld, kcz[iwr], xnr);
            }
            if (msq < xpi) {
                bne = xnr + 1;
            } else {
                ujx = xnr - 1;
            }
        }
        return bne;
    }
};
