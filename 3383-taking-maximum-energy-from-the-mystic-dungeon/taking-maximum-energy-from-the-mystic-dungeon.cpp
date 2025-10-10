class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxEnergy = INT_MIN;

        for (int start = 0; start < k; ++start) {
            int sum = 0;
            for (int i = n - 1 - start; i >= 0; i -= k) {
                sum += energy[i];
                maxEnergy = max(maxEnergy, sum);
            }
        }

        return maxEnergy;
    }
};