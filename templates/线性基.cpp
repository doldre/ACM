
void Gauss_Base() {
    memset(P, 0, sizeof(P));
    for (int i = 62; i >= 0; i--) {
        for (int j = 0; j < sz; j++) {
            if((A[j] >> i) & 1) {
                P[i] = A[j];
                break;
            }
        }
        for (int j = 0; j < sz; j++) {
            if((A[j] >> i) & 1) A[j] ^= P[i];
        }
    }
}

