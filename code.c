int maxProfitAssignment(int* d, int s, int* p, int ps, int* w, int ws) {
    int max = 0;
    for (int i = 0; i < ws; i++) {
        max = fmax(w[i], max);
    }
    int* jobs = malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++) {
        jobs[i] = 0;
    }
    for (int i = 0; i < s; i++) {
        if (d[i] <= max)
            jobs[d[i]] = fmax(jobs[d[i]], p[i]);
    }
    for (int i = 1; i < max + 1; i++) {
        jobs[i] = fmax(jobs[i], jobs[i - 1]);
    }
    int ans = 0;
    for (int i = 0; i < ws; i++) {
        ans += jobs[w[i]];
    }
    return ans;
}
