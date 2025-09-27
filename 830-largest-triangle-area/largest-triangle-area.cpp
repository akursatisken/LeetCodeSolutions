class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
            double maxArea = 0;
    for (int i = 0; i < points.size(); ++i)
        for (int j = i + 1; j < points.size(); ++j)
            for (int k = j + 1; k < points.size(); ++k) {
                auto& A = points[i], B = points[j], C = points[k];
                double area = 0.5 * abs((B[0] - A[0]) * (C[1] - A[1]) - 
                                        (C[0] - A[0]) * (B[1] - A[1]));
                maxArea = max(maxArea, area);
            }
    return maxArea;
    }
};