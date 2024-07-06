//Solution 1 makes use of extra space to turn the execution into O(m+n) runtime using the standard 2 ptr approach.
//Solution 2 uses O(1) space, but runs in O(nlogn) time.
class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() == 0){
            return;
        }else if(nums1.size() == n){
            memcpy(&nums1[0], &nums2[0], nums2.size()*sizeof(int));
            return;
        }

        vector<int> nums1Copy(nums1.size(), 0);
        memcpy(&nums1Copy[0], &nums1[0], nums1.size()*sizeof(int));
        uint16_t num1Ptr = 0;
        uint16_t num2Ptr = 0;
        uint16_t resultPtr = 0;

        while(num1Ptr < m && num2Ptr < n){
            //std::cout << "1 = " << nums1Copy[num1Ptr] << " 2 = " << nums2[num2Ptr] << '\n';

            if(nums1Copy[num1Ptr] <= nums2[num2Ptr]){
                nums1[resultPtr] = nums1Copy[num1Ptr];
                num1Ptr++;
            }else{
                //cout << "inserted right \n";
                nums1[resultPtr] = nums2[num2Ptr];
                num2Ptr++;
            }
            resultPtr++;
        }
        if(num1Ptr < m){
            for(num1Ptr; num1Ptr < m; ++num1Ptr){
                nums1[resultPtr] = nums1Copy[num1Ptr];
                resultPtr++;
            }
        }else{
            for(num2Ptr; num2Ptr < n; ++num2Ptr){
                nums1[resultPtr] = nums2[num2Ptr];
                resultPtr++;
            }
        }

    }
};

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() == 0){
            return;
        }else if(nums1.size() == n){
            memcpy(&nums1[0], &nums2[0], nums2.size()*sizeof(int));
            return;
        }
        memcpy(&nums1[nums1.size()-n], &nums2[0], nums2.size()*sizeof(int));
        std::sort(nums1.begin(), nums1.end());
    }
};