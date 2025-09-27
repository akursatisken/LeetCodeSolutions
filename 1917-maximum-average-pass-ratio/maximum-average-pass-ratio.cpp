class Solution {
public:
    struct ClassInfo {
        int pass, total;
        double gain() const {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        }
    };
    
    struct Compare {
        bool operator()(const ClassInfo& a, const ClassInfo& b) {
            return a.gain() < b.gain(); // max heap
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<ClassInfo, vector<ClassInfo>, Compare> pq;
        
        for (auto& c : classes) {
            pq.push({c[0], c[1]});
        }
        
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            top.pass++;
            top.total++;
            pq.push(top);
        }
        
        double result = 0.0;
        while (!pq.empty()) {
            auto c = pq.top(); pq.pop();
            result += (double)c.pass / c.total;
        }
        
        return result / classes.size();
    }
};
