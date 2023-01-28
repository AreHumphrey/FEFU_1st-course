#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>

#define ABS(a) (a < 0 ? (-a) : (a))

//Это даже не мое решение....

int main() {
    FILE *fin  = fopen("input.txt", "r"),
            *fout = fopen("output.txt", "w");
    int tmpsum = 0, N, M, n_cur = 0, m_cur = 0, n_comp_len = 0, m_comp_len = 0;
    int n_str[2][10000] = {}, m_str[10000] = {};
    char m_prev = -1, in;

    fscanf(fin, "%d%d\n", &N, &M);

    //'0' < 0
    //'1' > 0
    for(int i = 0; i < N; i++) {
        fscanf(fin, "%c", &in);
        if(in == '0') {
            ++n_cur;
        } else {
            if(n_cur) {
                n_str[0][n_comp_len++] = -n_cur;
            }
            n_str[0][n_comp_len++] = 1;
            n_cur = 0;
        }
    }
    if(in == '0') n_str[0][n_comp_len++] = -n_cur;
    fscanf(fin, "\n");

    //'a' < 0
    //'b' > 0
    for(int j = 0; j < M; j++) {
        fscanf(fin, "%c", &in);
        if(in == m_prev) {
            ++m_cur;
        } else {
            if(m_cur) {
                m_str[m_comp_len++] = m_cur * ((m_prev == 'b') ? 1 : -1);
            }
            m_cur = 1;
            m_prev = in;
        }
    }
    m_str[m_comp_len++] = m_cur * ((m_prev == 'b') ? 1 : -1);

    if(m_str[0] < 0) {
        for(int i = 0; tmpsum + ABS(n_str[0][i]) <= -m_str[0] && i < n_comp_len; i++) {
            tmpsum += ABS(n_str[0][i]);
            n_str[1][i] = 1;
        }
    } else {
        for(int i = 0; ++tmpsum <= m_str[0] && i < n_comp_len && n_str[0][i] == 1; n_str[1][i++] = 1);
    }

    for(int j = 1; j < m_comp_len; j++) {
        for(int i = n_comp_len - 1; i >= 0; i--) {
            if(n_str[1][i]) {
                tmpsum = 0;
                if(m_str[j] < 0) {
                    for(int i2 = i + 1; (tmpsum + ABS(n_str[0][i2]) <= -m_str[j]) && i2 < n_comp_len; i2++) {
                        tmpsum += ABS(n_str[0][i2]);
                        n_str[1][i2] = 1;
                    }
                } else {
                    for (int i2 = i + 1; ++tmpsum <= m_str[j] && n_str[0][i2] == 1; n_str[1][i2++] = 1);
                }
                n_str[1][i] = 0;
            }
        }
    }

    fprintf(fout, "%c", n_str[1][n_comp_len - 1] ? 'Y' : 'N');
}
