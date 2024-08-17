
long long int solve (vector<int> &nums){

    int n = nums.size();

    long long int prev2 = 0;

    long long int prev = nums[0];

    for(int i=1; i<n; i++){

        long long int incl = prev2+nums[i];
        long long int excl = prev+0;
        long long int ans = max(incl, excl);
        prev2 = prev;
        prev = ans;
    }

  return prev;

}

 

long long int houseRobber(vector<int> &valueInHouse) {

 

    int n = valueInHouse.size();

    

    if (n == 1) return valueInHouse[0];

    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++) {

        if (i != n - 1) {
            temp1.push_back(valueInHouse[i]);
        }

        if (i != 0) {

            temp2.push_back(valueInHouse[i]);

        }

    

    }

    return max(solve(temp1), solve(temp2));

}