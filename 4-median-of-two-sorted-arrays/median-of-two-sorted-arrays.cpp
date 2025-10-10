class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int total = nums1.size() + nums2.size();
    double result;

    // Her zaman küçük olan diziyi ilk parametre olarak gönder
    vector<int>& A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
    vector<int>& B = (nums1.size() <= nums2.size()) ? nums2 : nums1;

    if (total % 2 == 1) {
        // Tek uzunluk → ortadaki eleman
        int k = total / 2 + 1;
        result = kthSmallestInTwoSortedArrays(A, B, k);
    } else {
        // Çift uzunluk → ortadaki iki elemanın ortalaması
        int k1 = total / 2;
        int k2 = total / 2 + 1;
        int a = kthSmallestInTwoSortedArrays(A, B, k1);
        int b = kthSmallestInTwoSortedArrays(A, B, k2);
        result = (a + b) / 2.0;
    }

    return result;
    }

    int kthSmallestInTwoSortedArrays(vector<int>& A, vector<int>& B, int k) {
    int n = A.size(), m = B.size();

    // Binary search aralığı: A dizisinden alınabilecek eleman sayısı
    int low = max(0, k - m), high = min(k, n);

    while (low <= high) {
        int i = (low + high) / 2;  // A dizisinden alınan eleman sayısı
        int j = k - i;             // B dizisinden alınan eleman sayısı

        // Sol ve sağ sınır değerleri (taşmaları engellemek için)
        int Aleft  = (i == 0) ? INT_MIN : A[i - 1];
        int Aright = (i == n) ? INT_MAX : A[i];
        int Bleft  = (j == 0) ? INT_MIN : B[j - 1];
        int Bright = (j == m) ? INT_MAX : B[j];

        // Denge koşulu sağlanmış mı?
        if (Aleft <= Bright && Bleft <= Aright) {
            // k. en küçük eleman sol tarafın en büyüğüdür
            return max(Aleft, Bleft);
        }
        else if (Aleft > Bright) {
            // A'dan fazla eleman aldık → azalt
            high = i - 1;
        }
        else {
            // A'dan az eleman aldık → artır
            low = i + 1;
        }
    }

    // Normalde buraya ulaşılmaz
    return -1;
}

};