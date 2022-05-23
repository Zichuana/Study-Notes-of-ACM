public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // int cot = 1;
        // int len = nums.size();
        // for(int i = 0;i<len ; i++){
        //     int num = 0;
        //     for(int j = i; j<len;j++){
        //         num += nums[j];
        //         if(num%k==0){
        //             cot++;
        //         }
        //     }
        // }
        // return cot;
        int cot = 0;
        map <int , int> mp;
        int sum = 0;
        int len = nums.size();
        for(int i=0; i<len; i++){
            sum += nums[i];
            int mod = sum >= 0 ? sum % k : (k - (-sum) % k) % k;//求余转正骚操作
            mp[mod]++;
        }
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // int cot = 1;
        // int len = nums.size();
        // for(int i = 0;i<len ; i++){
        //     int num = 0;
        //     for(int j = i; j<len;j++){
        //         num += nums[j];
        //         if(num%k==0){
        //             cot++;
        //         }
        //     }
        // }
        // return cot;
        int cot = 0;
        map <int , int> mp;
        int sum = 0;
        int len = nums.size();
        for(int i=0; i<len; i++){
            sum += nums[i];
            int mod = sum >= 0 ? sum % k : (k - (-sum) % k) % k;//求余转正骚操作
            mp[mod]++;
        }
        for( auto&[k, v] : mp){ //map遍历
            cot += v*(v-1)/2;
            if(k==0){
                cot += v;
            }
        }
        return cot;
   }
};
	
